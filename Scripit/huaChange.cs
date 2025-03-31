using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class huaChange : MonoBehaviour
{
    public int huaIndex; // Ҫ���ĵ�hua������

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            ChangeHuaState();
        }
    }

    private void ChangeHuaState()
    {
        Save save = Save.LoadGame();
        if (save != null && huaIndex >= 0 && huaIndex < save.activatedHua.Length)
        {
            save.activatedHua[huaIndex] = true; // �л�hua��״̬Ϊtrue
            save.SaveGame(); // ʹ�� Save ��� SaveGame ��������״̬
        }
        else
        {
            Debug.LogWarning("Save data is null");
        }
    }
}

































