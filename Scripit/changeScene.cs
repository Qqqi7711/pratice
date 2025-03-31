using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class changeScene : MonoBehaviour
{
    // ʵ�ֿ糡������
    public string SceneName;
    private GameObject Player;
    public Interactable interactable;

    private void Start()
    {
        Player = GameObject.FindGameObjectWithTag("Player");
    }
    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            interactable.Do();
            StartCoroutine(WaitAndLoadScene());
        }
    }

    private IEnumerator WaitAndLoadScene()
    {
        // wait�Ի����
        yield return new WaitUntil(() => !DialogueUI.Instance.gameObject.activeSelf);
        // ����Ҫ���ͳ���
        SceneManager.LoadScene(SceneName);
        SceneManager.sceneLoaded += onSceneLoaded;
    }

    private void onSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        Transform targetTransform;
        if (SceneName == "scene")
        {
            // ��ȡ��Ϊ "birthPoint" ��Ŀ��λ��
            targetTransform = GameObject.Find("birthPoint").transform;
        }
        else
        {
            // ��ȡĿ��λ��
            targetTransform = GameObject.FindGameObjectWithTag("Point").transform;
        }
        // �����
        Player.transform.position = targetTransform.position;
        SceneManager.sceneLoaded -= onSceneLoaded;
    }
}




