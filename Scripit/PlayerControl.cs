using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerControl : MonoBehaviour
{
    public float speed = 5.0f; //设置默认速度
    public float shipSpeeed = 10.0f; //设置船的速度
    public float mouseSensitivity = 100.0f; //鼠标灵敏度
    public float jumpForce = 5.0f; //跳跃力
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
        //锁定鼠标光标并隐藏
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
        xRotation = Mathf.Clamp(xRotation, -90f, 90f); // 限制垂直旋转角度

        // 旋转摄像机的垂直方向
        Camera.main.transform.localRotation = Quaternion.Euler(xRotation, 0f, 0f);
        // 旋转角色的水平方向
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
            //进一步判断是否是船
            if (collision.gameObject.CompareTag("ship"))
            {
                //如果是船则速度增大
                speed = shipSpeeed;
            }

        }
        
       
        
    }
}



