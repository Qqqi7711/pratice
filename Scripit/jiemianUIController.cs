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
        // 查找当前正在播放的音乐
        AudioSource[] audioSources = FindObjectsOfType<AudioSource>();
        foreach (AudioSource audioSource in audioSources)
        {
            if (audioSource.isPlaying)
            {
                backgroundMusic = audioSource;
                break;
            }
        }

        // 查找玩家控制脚本
        playerControl = FindObjectOfType<PlayerControl>();
        playerController = FindObjectOfType<PlayerController>();

        // 添加按钮点击事件监听器
        musicToggleButton.onClick.AddListener(ToggleMusic);
        returnButton.onClick.AddListener(ReturnToPosition);
    }

    private void Update()
    {
        // 如果按下 T 键，禁用玩家控制脚本并显示光标
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

        // 检查鼠标点击
        if (isTKeyPressed && Input.GetMouseButtonDown(0))
        {
            // 检查鼠标点击是否在按钮范围内
            if (IsPointerOverUIElement())
            {
                Debug.Log("Mouse clicked on UI element");
            }
            else
            {
                Debug.Log("Mouse clicked outside UI element");
                // 如果不在按钮范围内，重新启用玩家控制脚本并隐藏光标
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
        // 检查 EventSystem 是否存在
        if (EventSystem.current == null)
        {
            Debug.LogWarning("EventSystem.current is null");
            return false;
        }

        // 检查鼠标是否在 UI 元素上
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


