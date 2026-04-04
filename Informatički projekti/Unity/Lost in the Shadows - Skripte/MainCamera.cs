using UnityEngine;

public class MainCamera : MonoBehaviour
{
    [SerializeField] private Transform player;
    [SerializeField] private float cameraHeight;
    [SerializeField] private float aheadDistance;
    [SerializeField] private float cameraSpeed;

    [Header("Limit camera")]
    [SerializeField] private Vector2 xLimit;
    [SerializeField] private Vector2 yLimit;
    private float lookAhead;

    private void Update()
    {
        transform.position = new Vector3(Mathf.Clamp(player.position.x + lookAhead, xLimit.x, xLimit.y), Mathf.Clamp(player.position.y + cameraHeight, yLimit.x, yLimit.y), transform.position.z);
        lookAhead = Mathf.Lerp(lookAhead, (aheadDistance * player.localScale.x), Time.deltaTime * cameraSpeed);
    }
}

