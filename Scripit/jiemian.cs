using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class jiemian : MonoBehaviour
{
    public GameObject jiemain;

    private void OnTriggerEnter(Collider other)
    {
        jiemain.SetActive(true);
    }
}
