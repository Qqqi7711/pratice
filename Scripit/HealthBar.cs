using UnityEngine;
using UnityEngine.UI;

public class HealthBar : MonoBehaviour
{
    public Image healthBarImage;
    private float currentHealth;
    private float maxHealth;

    public void SetMaxHealth(float health)
    {
        maxHealth = health;
        currentHealth = maxHealth;
        healthBarImage.fillAmount = currentHealth / maxHealth;
    }

    public void SetHealth(float health)
    {
        currentHealth = health;
        healthBarImage.fillAmount = currentHealth / maxHealth;
    }

    public void TakeDamage(float damage)
    {
        currentHealth -= damage;
        currentHealth = Mathf.Clamp(currentHealth, 0f, maxHealth);
        healthBarImage.fillAmount = currentHealth / maxHealth;
    }
}


