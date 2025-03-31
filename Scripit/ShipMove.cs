using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShipMove : MonoBehaviour
{
    private Transform PlayerTransform;
    public Transform point;
    public GameObject jiemian;
    private Vector3 offset;
    private bool playerAtPoint;
    private AudioSource audioSource;

    // Start is called before the first frame update
    void Start()
    {
        PlayerTransform = GameObject.FindGameObjectWithTag("Player").transform;
        offset = transform.position - point.position;
        audioSource = GetComponent<AudioSource>();
    }

    // Update is called once per frame
    void Update()
    {
        if (playerAtPoint)
        {
            Vector3 targetTransform = PlayerTransform.position + offset;
            targetTransform.y = transform.position.y;
            transform.position = targetTransform;
            

            // 使船的旋转方向跟随玩家的视角
            transform.rotation = Quaternion.Euler(0, PlayerTransform.eulerAngles.y, 0);
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            audioSource.Play();
            playerAtPoint = true;
            jiemian .SetActive(true);
        }
    }
}

