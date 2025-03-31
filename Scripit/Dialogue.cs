using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dialogue : MonoBehaviour
{
    private DialogueUI dialogueUI;
    private bool isDialogueActive = false;
    private PlayerControl playerControl;
    public GameObject Magic;

    private void Start()
    {
        //找到玩家控制脚本
        playerControl = FindObjectOfType<PlayerControl>();
        dialogueUI = DialogueUI.Instance;
    }

    [System.Serializable]
    public class DialogueEntry
    {
        public string speakerName;
        public string[] contentList;
    }

    public List<DialogueEntry> dialogueEntries;

    private Queue<DialogueEntry> dialogueQueue;

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            Magic.SetActive(false);
            StartDialogue();
        }
    }

    public void StartDialogue()
    {
        dialogueQueue = new Queue<DialogueEntry>(dialogueEntries);
        ShowNextDialogue();
        isDialogueActive = true;
        playerControl.enabled = false;
    }

    public void ShowNextDialogue()
    {
        if (dialogueQueue.Count == 0)
        {
            EndDialogue();
            return;
        }

        DialogueEntry entry = dialogueQueue.Dequeue();
        dialogueUI.show(entry.speakerName, entry.contentList);
    }

    private void EndDialogue()
    {
        isDialogueActive = false;
        playerControl.enabled = true;
    }

    private void Update()
    {
        if (isDialogueActive && !DialogueUI.Instance.gameObject.activeSelf)
        {
            ShowNextDialogue();
        }
    }
}













