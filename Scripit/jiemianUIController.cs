using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;

public class jiemianUIController : MonoBehaviour
{
    public Button musicToggleButton;
    public Button returnButton;

    private bool isMusicPlaying = true;
    private AudioSource backgroundMusic;
    private PlayerControl playerControl;
    private PlayerController playerController;
    private bool isTKeyPressed = false;

    void Start()
    {
        // ���ҵ�ǰ���ڲ��ŵ�����
        AudioSource[] audioSources = FindObjectsOfType<AudioSource>();
        foreach (AudioSource audioSource in audioSources)
        {
            if (audioSource.isPlaying)
            {
                backgroundMusic = audioSource;
                break;
            }
        }

        // ������ҿ��ƽű�
        playerControl = FindObjectOfType<PlayerControl>();
        playerController = FindObjectOfType<PlayerController>();

        // ��Ӱ�ť����¼�������
        musicToggleButton.onClick.AddListener(ToggleMusic);
        returnButton.onClick.AddListener(ReturnToPosition);
    }

    private void Update()
    {
        // ������� T ����������ҿ��ƽű�����ʾ���
        if (Input.GetKeyDown(KeyCode.T))
        {
            isTKeyPressed = true;
            if (playerControl != null)
            {
                playerControl.enabled = false;
            }
            if (playerController != null)
            {
                playerController.enabled = false;
            }
            Cursor.lockState = CursorLockMode.None;
            Cursor.visible = true;
        }

        // ��������
        if (isTKeyPressed && Input.GetMouseButtonDown(0))
        {
            // ���������Ƿ��ڰ�ť��Χ��
            if (IsPointerOverUIElement())
            {
                Debug.Log("Mouse clicked on UI element");
            }
            else
            {
                Debug.Log("Mouse clicked outside UI element");
                // ������ڰ�ť��Χ�ڣ�����������ҿ��ƽű������ع��
                if (playerControl != null)
                {
                    playerControl.enabled = true;
                }
                if (playerController != null)
                {
                    playerController.enabled = true;
                }
                Cursor.lockState = CursorLockMode.Locked;
                Cursor.visible = false;
                isTKeyPressed = false;
            }
        }
    }

    private bool IsPointerOverUIElement()
    {
        // ��� EventSystem �Ƿ����
        if (EventSystem.current == null)
        {
            Debug.LogWarning("EventSystem.current is null");
            return false;
        }

        // �������Ƿ��� UI Ԫ����
        PointerEventData eventData = new PointerEventData(EventSystem.current);
        eventData.position = Input.mousePosition;
        List<RaycastResult> results = new List<RaycastResult>();
        EventSystem.current.RaycastAll(eventData, results);
        return results.Count > 0;
    }

    private void ToggleMusic()
    {
        if (backgroundMusic != null)
        {
            if (isMusicPlaying)
            {
                backgroundMusic.Pause();
            }
            else
            {
                backgroundMusic.Play();
            }
            isMusicPlaying = !isMusicPlaying;
        }
    }

    private void ReturnToPosition()
    {
        Save save = Save.LoadGame();
        if (save != null)
        {
            GameController.Instance.LoadSceneAndSetPlayerPosition(save.returnScene);
        }
    }
}


