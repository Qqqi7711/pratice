using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class DialogueUI : MonoBehaviour
{
    // 使用单例模式
    public static DialogueUI Instance { get; private set; }

    public TextMeshProUGUI nameText;
    public TextMeshProUGUI contentText;
    public Button continueButton;
    private List<string> contentList;
    private int contentIndex; // 内容索引

    private void Awake()
    {
        DontDestroyOnLoad(gameObject);
        Instance = this;
    }

    private void Start()
    {
        continueButton.onClick.AddListener(this.OnContinueButtonClick);
        hide();
    }

    private void Update()
    {
        //返回键返回
        if (Input.GetKeyDown(KeyCode.Return))
        {
            OnContinueButtonClick();
        }
    }


    public void show(string name, string[] content)
    {
        // 先初始化索引
        contentIndex = 0;
        nameText.text = name;
        contentList = new List<string>();
        // 把数组内容加入列表中
        contentList.AddRange(content);
        // 先显示第一条
        contentText.text = contentList[contentIndex];
        gameObject.SetActive(true);
    }

    public void hide()
    {
        gameObject.SetActive(false);
    }

    private void OnContinueButtonClick()
    {
        contentIndex++;
        if (contentIndex >= contentList.Count)
        {
            hide();
            return;
        }
        contentText.text = contentList[contentIndex];
    }
}














