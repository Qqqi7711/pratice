using UnityEngine;
using UnityEngine.SceneManagement;

public class GameController : MonoBehaviour
{
    public GameObject[] huaObjects;
    //单例
    public static GameController Instance;

    private void Awake()
    {
        DontDestroyOnLoad(gameObject);
        Instance = this;
        foreach (var hua in huaObjects)
        {
            if (hua != null)
            {
                DontDestroyOnLoad(hua);
            }
        }
    }

    private void Start()
    {
        LoadGameData();
    }

    public void LoadGameData()
    {
        Save save = Save.LoadGame();
        if (save != null)
        {
            for (int i = 0; i < huaObjects.Length; i++)
            {
                if (huaObjects[i] != null)
                {
                    huaObjects[i].SetActive(save.activatedHua[i]);
                }
            }
        }
        else
        {
            Debug.LogWarning("Save data is null.");
        }
    }

    public void LoadSceneAndSetPlayerPosition(string sceneName)
    {
        SceneManager.LoadScene(sceneName);
        SceneManager.sceneLoaded += OnSceneLoaded;
    }

    private void OnSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        LoadGameData();
        SetPlayerPosition();
        // 取消订阅，防止多次调用
        SceneManager.sceneLoaded -= OnSceneLoaded; 
    }

    private void SetPlayerPosition()
    {
        GameObject player = GameObject.FindGameObjectWithTag("Player");
        GameObject birthPoint = GameObject.Find("birthPoint");
        if (player != null && birthPoint != null)
        {
            player.transform.position = birthPoint.transform.position;
        }
    }
}

























































