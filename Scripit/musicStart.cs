using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class musicStart : MonoBehaviour
{
    public GameObject jiemian;

    void Update()
    {
        if (gameObject.activeInHierarchy )
        {
            jiemian.SetActive(true);
        }
    }
}














