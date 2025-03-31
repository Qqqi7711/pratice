using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class menuControl : MonoBehaviour
{
    // ����
    public static menuControl Instance { get; private set; } 

    public Button beginButton;
    public Button introduceButton;
    public Button instructionButton;

    private PlayerControl playerControl;
    public GameObject jiemian;
    private GameObject introduceCanvas;
    private GameObject instructionCanvas;
    private bool ishide = false;

    private void Awake()
    {
        // ȷ��ֻ��һ��ʵ��
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
        }
    }

    private void Start()
    {
        // ��ʼ������ҿ��ƽű�
        playerControl = FindObjectOfType<PlayerControl>();
        playerControl.enabled = false;

        // ���ҽ���UI
        introduceCanvas = transform.Find("introduce").gameObject;
        instructionCanvas = transform.Find("instruction").gameObject;

        // ���ؽ���UI
        introduceCanvas.SetActive(false);
        instructionCanvas.SetActive(false);

        // ���������ť����¼�
        beginButton.onClick.AddListener(this.onBeginButtonClick);
        introduceButton.onClick.AddListener(this.onIntroduceButtonClick);
        instructionButton.onClick.AddListener(this.onInstructionButtonClick);
    }

    private void Update()
    {
        if(ishide)
        {
            Cursor.lockState = CursorLockMode.Locked;
            Cursor.visible = false;
            hide();
        }
        else
        {
            Cursor.lockState = CursorLockMode.None;
            Cursor.visible = true;
        }
    }

    private void hide()
    {
        gameObject.SetActive(false);
        jiemian.SetActive(true);
    }

    private void onBeginButtonClick()
    {
        ishide = true;
        playerControl.enabled = true;
    }

    private void onIntroduceButtonClick()
    {
        introduceCanvas.SetActive(true);
        //�������������
        if (Input.anyKeyDown)
        {
            introduceCanvas.SetActive(false);
            instructionCanvas.SetActive(false);
        }
    }

    private void onInstructionButtonClick()
    {
        instructionCanvas.SetActive(true);
        //�������������
        if (Input.anyKeyDown)
        {
            introduceCanvas.SetActive(false);
            instructionCanvas.SetActive(false);
        }
    }
}








