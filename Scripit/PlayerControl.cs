using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerControl : MonoBehaviour
{
    public float speed = 5.0f; //����Ĭ���ٶ�
    public float shipSpeeed = 10.0f; //���ô����ٶ�
    public float mouseSensitivity = 100.0f; //���������
    public float jumpForce = 5.0f; //��Ծ��
    private float xRotation = 0f;
    private Rigidbody rb;
    private bool IsWalkable = false;

    public Transform birthPoint;

    private void Awake()
    {
        DontDestroyOnLoad(gameObject);
    }
    void Start()
    {
        transform.position=birthPoint.position;
        //��������겢����
        Cursor.lockState = CursorLockMode.Locked;
        rb = GetComponent<Rigidbody>();
    }
    void Update()
    {
        MovePlayer();
        RotatePlayer();
        Jump();
    }

    void MovePlayer()
    {
        float horizontal = Input.GetAxis("Horizontal");
        float vertical = Input.GetAxis("Vertical");
        Vector3 movement = transform.right * horizontal + transform.forward * vertical;
        rb.MovePosition(rb.position + movement * speed * Time.deltaTime);
    }

    void RotatePlayer()
    {
        float mouseX = Input.GetAxis("Mouse X") * mouseSensitivity * Time.deltaTime;
        float mouseY = Input.GetAxis("Mouse Y") * mouseSensitivity * Time.deltaTime;

        xRotation -= mouseY;
        xRotation = Mathf.Clamp(xRotation, -90f, 90f); // ���ƴ�ֱ��ת�Ƕ�

        // ��ת������Ĵ�ֱ����
        Camera.main.transform.localRotation = Quaternion.Euler(xRotation, 0f, 0f);
        // ��ת��ɫ��ˮƽ����
        transform.Rotate(Vector3.up * mouseX);
    }

    void Jump()
    {
        if (Input.GetKeyDown(KeyCode.Space ) && IsWalkable)
        {
            rb.AddForce(Vector3.up * jumpForce, ForceMode.Impulse);
        }
    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.CompareTag("Walkable")|| collision.gameObject.CompareTag("ship"))
        {
            IsWalkable = true;
            //��һ���ж��Ƿ��Ǵ�
            if (collision.gameObject.CompareTag("ship"))
            {
                //����Ǵ����ٶ�����
                speed = shipSpeeed;
            }

        }
        
       
        
    }
}



