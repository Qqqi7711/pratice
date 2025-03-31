using System.IO;
using UnityEngine;

[System.Serializable]
public class Save
{
    public bool[] activatedHua = new bool[3];
    public string returnScene = "scene"; // ³õÊ¼³¡¾°Ãû³Æ

    private static string saveFilePath = Application.persistentDataPath + "/savefile.json";

    public void SaveGame()
    {
        string json = JsonUtility.ToJson(this);
        File.WriteAllText(saveFilePath, json);
    }

    public static Save LoadGame()
    {
        if (File.Exists(saveFilePath))
        {
            string json = File.ReadAllText(saveFilePath);
            Save save = JsonUtility.FromJson<Save>(json);
            return save;
        }
        else
        {
            Save newSave = new Save();
            newSave.SaveGame();
            return newSave;
        }
    }
}








































