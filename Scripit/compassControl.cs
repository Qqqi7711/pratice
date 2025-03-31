using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class compassControl : MonoBehaviour
{
    public Transform endPoint;

    void Update()
    {
        if (endPoint != null)
        {
            transform.LookAt(endPoint);
        }
    }
}



