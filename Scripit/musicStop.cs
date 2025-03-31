using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class musicStop : MonoBehaviour
{
    public AudioSource audioSource;

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
            audioSource.Stop();
    }

    private void OnCollisionEnter(Collision collision)
    {
        audioSource.Stop();
    }
}
