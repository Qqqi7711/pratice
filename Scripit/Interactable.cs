using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Interactable : MonoBehaviour
{
    public string Name;
    public string[] contentList;
    private DialogueUI dialogue;
    public GameObject Magic;
    private bool isDialogueActive = false;
    private PlayerControl playerControl;

    private void Start()
    {
        playerControl = FindObjectOfType<PlayerControl>();
        dialogue = DialogueUI.Instance;
    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.CompareTag("Player"))
        {
            Magic.SetActive(false);
            Do();
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            Magic.SetActive(false);
            Do();
        }
    }

    public void Do()
    {
        dialogue.show(Name, contentList);
        isDialogueActive = true;
        playerControl.enabled = false;
    }

    private void Update()
    {
        if (isDialogueActive && !DialogueUI.Instance.gameObject.activeSelf)
        {
            isDialogueActive = false;
            playerControl.enabled = true;
        }
    }
}


















