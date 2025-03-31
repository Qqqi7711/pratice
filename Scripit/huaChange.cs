using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class huaChange : MonoBehaviour
{
    public int huaIndex; // 要更改的hua的索引

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
            save.activatedHua[huaIndex] = true; // 切换hua的状态为true
            save.SaveGame(); // 使用 Save 类的 SaveGame 方法保存状态
        }
        else
        {
            Debug.LogWarning("Save data is null");
        }
    }
}

































