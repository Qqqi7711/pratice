using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class shipEnd : MonoBehaviour
{
    private GameObject Player;
    private ShipMove shipMove;
    public Transform destination;

    private void Start()
    {
        Player = GameObject.Find("Player");
        shipMove= FindObjectOfType <ShipMove>();
    }
    private void OnCollisionEnter(Collision collision)
    {
        //�������λ�ù������
        shipMove .enabled = false;
        Player.transform.position = destination.position;
    }
}
