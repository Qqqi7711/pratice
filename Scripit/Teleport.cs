using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Teleport : MonoBehaviour
{
    public Transform teleportTarget; // ����Ŀ��λ��
    public GameObject player; // ��Ҷ���
    public Interactable interactable;

    // ����ҽӴ���������ʱ����
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
            // wait�Ի����
            yield return new WaitUntil(() => DialogueUI.Instance != null && !DialogueUI.Instance.gameObject.activeSelf);
            // ������ҵ�Ŀ��λ��
            player.transform.position = teleportTarget.position;
        }
        else
        {
            Debug.LogWarning("Interactable instance is null.");
        }
    }
}





