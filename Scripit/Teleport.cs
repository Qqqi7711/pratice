using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Teleport : MonoBehaviour
{
    public Transform teleportTarget; // 传送目标位置
    public GameObject player; // 玩家对象
    public Interactable interactable;

    // 当玩家接触到触发器时调用
    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            StartCoroutine(TeleportPlayer());
        }
    }

    private IEnumerator TeleportPlayer()
    {
        if (interactable != null)
        {
            interactable.Do();
            // wait对话完成
            yield return new WaitUntil(() => DialogueUI.Instance != null && !DialogueUI.Instance.gameObject.activeSelf);
            // 传送玩家到目标位置
            player.transform.position = teleportTarget.position;
        }
        else
        {
            Debug.LogWarning("Interactable instance is null.");
        }
    }
}





