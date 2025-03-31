using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class changeScene : MonoBehaviour
{
    // 实现跨场景传送
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
        // wait对话完成
        yield return new WaitUntil(() => !DialogueUI.Instance.gameObject.activeSelf);
        // 加载要传送场景
        SceneManager.LoadScene(SceneName);
        SceneManager.sceneLoaded += onSceneLoaded;
    }

    private void onSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        Transform targetTransform;
        if (SceneName == "scene")
        {
            // 获取名为 "birthPoint" 的目标位置
            targetTransform = GameObject.Find("birthPoint").transform;
        }
        else
        {
            // 获取目标位置
            targetTransform = GameObject.FindGameObjectWithTag("Point").transform;
        }
        // 传玩家
        Player.transform.position = targetTransform.position;
        SceneManager.sceneLoaded -= onSceneLoaded;
    }
}




