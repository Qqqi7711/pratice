using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class menuControl : MonoBehaviour
{
    // 单例
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
        // 确保只有一个实例
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
        // 开始禁用玩家控制脚本
        playerControl = FindObjectOfType<PlayerControl>();
        playerControl.enabled = false;

        // 查找介绍UI
        introduceCanvas = transform.Find("introduce").gameObject;
        instructionCanvas = transform.Find("instruction").gameObject;

        // 隐藏介绍UI
        introduceCanvas.SetActive(false);
        instructionCanvas.SetActive(false);

        // 添加三个按钮点击事件
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
        //按下任意键返回
        if (Input.anyKeyDown)
        {
            introduceCanvas.SetActive(false);
            instructionCanvas.SetActive(false);
        }
    }

    private void onInstructionButtonClick()
    {
        instructionCanvas.SetActive(true);
        //按下任意键返回
        if (Input.anyKeyDown)
        {
            introduceCanvas.SetActive(false);
            instructionCanvas.SetActive(false);
        }
    }
}








