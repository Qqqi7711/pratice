using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class bianzhong : MonoBehaviour
{
    private AudioSource audioSource;
    public Interactable interactable;
    private void Start()
    {
        audioSource = GetComponent<AudioSource>();
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            audioSource.Play();
            interactable.Do();
        }
    }
}
