using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class lastItem : MonoBehaviour
{
    public GameObject Item;
    private void Start()
    {
        Item.SetActive(false);
    }

    private void Update()
    {
        //获取所有带有effect标签的物体
        GameObject[] effectObjects = GameObject.FindGameObjectsWithTag("effect");
        //检查是否所有的effect标签的物体都被禁用
        bool allEffectsDisabled = true;
        foreach (GameObject effectObject in effectObjects)
        {
            if (effectObject.activeSelf)
            {
                allEffectsDisabled = false;
                break;
            }
        }

        //所有的effect标签的物体都被禁用，激活当前物体
        if (allEffectsDisabled)
        {
            Item.SetActive(true);
        }
    }
}

