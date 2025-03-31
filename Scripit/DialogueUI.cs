using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class DialogueUI : MonoBehaviour
{
    // ʹ�õ���ģʽ
    public static DialogueUI Instance { get; private set; }

    public TextMeshProUGUI nameText;
    public TextMeshProUGUI contentText;
    public Button continueButton;
    private List<string> contentList;
    private int contentIndex; // ��������

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
        //���ؼ�����
        if (Input.GetKeyDown(KeyCode.Return))
        {
            OnContinueButtonClick();
        }
    }


    public void show(string name, string[] content)
    {
        // �ȳ�ʼ������
        contentIndex = 0;
        nameText.text = name;
        contentList = new List<string>();
        // ���������ݼ����б���
        contentList.AddRange(content);
        // ����ʾ��һ��
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














