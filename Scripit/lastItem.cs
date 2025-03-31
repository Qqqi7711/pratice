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
        //��ȡ���д���effect��ǩ������
        GameObject[] effectObjects = GameObject.FindGameObjectsWithTag("effect");
        //����Ƿ����е�effect��ǩ�����嶼������
        bool allEffectsDisabled = true;
        foreach (GameObject effectObject in effectObjects)
        {
            if (effectObject.activeSelf)
            {
                allEffectsDisabled = false;
                break;
            }
        }

        //���е�effect��ǩ�����嶼�����ã����ǰ����
        if (allEffectsDisabled)
        {
            Item.SetActive(true);
        }
    }
}

