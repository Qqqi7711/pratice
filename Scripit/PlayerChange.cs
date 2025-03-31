using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerChange : MonoBehaviour
{
    private GameObject player;
    public GameObject player1;
    public GameObject[] enemies;
    private Camera playerCamera;
    private Camera player1Camera;
    public GameObject jiemian;

    private bool hasTriggered = false;

    void Start()
    {
        player = GameObject.Find("Player");
        if (player != null)
        {
            playerCamera = player.GetComponentInChildren<Camera>();
        }
        if (player1 != null)
        {
            player1Camera = player1.GetComponentInChildren<Camera>();
            player1.SetActive(false);
            if (player1Camera != null)
            {
                player1Camera.gameObject.SetActive(false);
            }
        }
        SetEnemiesActive(false);
    }

    private void OnTriggerEnter(Collider other)
    {
        if (!hasTriggered && other != null && other.gameObject.name == "Player")
        {
            // 设置为 true，确保只触发一次
            hasTriggered = true; 
            jiemian.SetActive (true);
            if (player != null)
            {
                player.SetActive(false);
                if (playerCamera != null)
                {
                    playerCamera.gameObject.SetActive(false);
                }
            }
            if (player1 != null)
            {
                player1.SetActive(true);
                if (player1Camera != null)
                {
                    player1Camera.gameObject.SetActive(true);
                }
            }
            SetEnemiesActive(true);
        }
    }

    private void Update()
    {
        if (AllEnemiesDestroyed())
        {
            if (player != null)
            {
                player.SetActive(true);
                if (playerCamera != null)
                {
                    playerCamera.gameObject.SetActive(true);
                }
            }
            if (player1 != null)
            {
                Destroy(player1);
                // 禁用 PlayerChange 脚本
                this.enabled = false; 
            }
        }
    }

    private void SetEnemiesActive(bool isActive)
    {
        foreach (var enemy in enemies)
        {
            if (enemy != null)
            {
                enemy.SetActive(isActive);
            }
        }
    }

    private bool AllEnemiesDestroyed()
    {
        foreach (var enemy in enemies)
        {
            if (enemy != null )
            {
                return false;
            }
        }
        return true;
    }
}






































