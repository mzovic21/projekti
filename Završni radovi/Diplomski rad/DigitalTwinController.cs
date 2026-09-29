using TMPro;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.InputSystem;
using UnityEngine.UI;

public class DigitalTwinController : MonoBehaviour
{
    [System.Serializable]
    public class SharedMaterials
    {
        public Material redMaterial;
        public Material grayMaterial;
        public Material bulbOnMaterial;
    }

    [System.Serializable]
    public class SmartLight
    {
        public Renderer glassRenderer;
        public Collider collider;
        [HideInInspector] public bool isOn;
    }

    [System.Serializable]
    public class SmartFan
    {
        public Transform rotor;
        public Collider collider;
        public Vector3 rotationAxis = Vector3.forward;
        public float rotationSpeed = 250f;
        [HideInInspector] public bool isOn;
    }

    [System.Serializable]
    public class SmartDoor
    {
        public Transform doorPivot;
        public Collider doorCollider;
        public Collider servoCollider;
        public Vector3 rotationAxis = Vector3.up;
        public float openAngle = 90f;
        public float rotationSpeed = 180f;

        [HideInInspector] public bool isOpen;
        [System.NonSerialized] public Quaternion closedRotation;
        [System.NonSerialized] public Quaternion openRotation;
    }

    [System.Serializable]
    public class SmartBuzzer
    {
        public GameObject model;
        public Collider collider;

        [HideInInspector] public bool isOn;
        [System.NonSerialized] public Renderer[] renderers;
        [System.NonSerialized] public Material[][] originalMaterials;
    }

    [System.Serializable]
    public class SmartDoorbell
    {
        public Transform buttonCap;
        public Collider collider;
        public Vector3 pressAxis = Vector3.down;
        public float pressDistance = 0.15f;
        public float pressDuration = 0.35f;

        [HideInInspector] public bool isPressed;
        [System.NonSerialized] public Vector3 startPosition;
        [System.NonSerialized] public float timer;
        [System.NonSerialized] public bool buzzerWasOn;
    }

    [System.Serializable]
    public class DeviceGroup
    {
        [Header("Rasvjeta")]
        public SmartLight bedroom1Light;
        public SmartLight wcLight;
        public SmartLight bedroom2Light;

        [Header("Ostali uredaji")]
        public SmartFan fan;
        public SmartDoor door;
        public SmartBuzzer buzzer;
        public SmartDoorbell doorbell;
    }

    [System.Serializable]
    public class SmartPhotoresistor
    {
        public Collider collider;
        public GameObject whitePart;
        public float dayLightLevel = 100f;
        public float nightLightLevel = 20f;
        public float darknessThreshold = 50f;

        [HideInInspector] public bool isDark;
        [HideInInspector] public float currentLightLevel;
        [HideInInspector] public string currentCondition = "DAN";
        [System.NonSerialized] public Renderer[] renderers;
        [System.NonSerialized] public Material[][] originalMaterials;
    }

    [System.Serializable]
    public class SmartDHT11
    {
        public GameObject model;
        public Collider collider;
        public float normalTemperature = 24f;
        public float highTemperature = 32f;
        public float humidity = 50f;
        public float fanTemperatureThreshold = 28f;

        [HideInInspector] public float currentTemperature;
        [HideInInspector] public bool highTemperatureActive;
        [System.NonSerialized] public Renderer[] renderers;
        [System.NonSerialized] public Material[][] originalMaterials;
    }

    [System.Serializable]
    public class SensorGroup
    {
        public SmartPhotoresistor photoresistor;
        public SmartDHT11 dht11;
    }

    [System.Serializable]
    public class UIButtonGroup
    {
        [Header("Rasvjeta")]
        public Button bedroom1Button;
        public Button wcButton;
        public Button bedroom2Button;

        [Header("Uredaji")]
        public Button fanButton;
        public Button doorButton;
        public Button buzzerButton;
        public Button doorbellButton;

        [Header("Senzori")]
        public Button dht11Button;
        public Button photoresistorButton;

        [Header("Boje stanja")]
        public Color inactiveColor = new Color32(62, 70, 82, 255);
        public Color activeColor = new Color32(77, 139, 112, 255);
        public Color highlightedColor = new Color32(83, 97, 113, 255);
        public Color pressedColor = new Color32(217, 97, 122, 255);
    }

    [Header("Kamera i korisnicko sucelje")]
    public Camera mainCamera;
    public TMP_Text statusText;

    [Header("Zajednicki materijali")]
    public SharedMaterials materials;

    [Header("UREDAJI")]
    public DeviceGroup devices;

    [Header("SENZORI")]
    public SensorGroup sensors;

    [Header("GUMBI KORISNICKOG SUCELJA")]
    public UIButtonGroup uiButtons;

    [Header("ESP32 POVEZIVANJE")]
    // Referenca na komunikacijsku skriptu, Ako ESP32 nije povezan,
    // ovaj kontroler zadrzava promjene samo unutar Unity simulacije
    [SerializeField] private ESP32Connection esp32Connection;

    private void Start()
    {
        if (mainCamera == null)
        {
            mainCamera = Camera.main;
        }

        SetLight(devices.bedroom1Light, false);
        SetLight(devices.wcLight, false);
        SetLight(devices.bedroom2Light, false);
        SetFan(false);

        InitializeDoor();
        InitializeBuzzer();
        InitializeDoorbell();
        InitializePhotoresistor();
        InitializeDHT11();
        UpdateButtonColors();
        UpdateStatusText();
    }

    private void Update()
    {
        CheckMouseClick();
        RotateFan();
        RotateDoor();
        UpdateDoorbell();
        UpdateButtonColors();
        UpdateStatusText();
    }

    // Klikovi na objekte modela

    private void CheckMouseClick()
    {
        if (Mouse.current == null)
        {
            return;
        }

        if (!Mouse.current.leftButton.wasPressedThisFrame)
        {
            return;
        }

        if (EventSystem.current != null && EventSystem.current.IsPointerOverGameObject())
        {
            return;
        }

        if (mainCamera == null)
        {
            return;
        }

        Ray ray = mainCamera.ScreenPointToRay(Mouse.current.position.ReadValue());

        if (!Physics.Raycast(ray, out RaycastHit hit))
        {
            return;
        }

        Collider clicked = hit.collider;

        if (clicked == devices.bedroom1Light.collider)
        {
            ToggleLight(devices.bedroom1Light);
        }
        else if (clicked == devices.wcLight.collider)
        {
            ToggleLight(devices.wcLight);
        }
        else if (clicked == devices.bedroom2Light.collider)
        {
            ToggleLight(devices.bedroom2Light);
        }
        else if (clicked == devices.fan.collider)
        {
            ToggleFan();
        }
        else if (clicked == devices.door.doorCollider ||
                 clicked == devices.door.servoCollider)
        {
            ToggleDoor();
        }
        else if (clicked == devices.doorbell.collider)
        {
            PressDoorbell();
        }
        else if (clicked == devices.buzzer.collider)
        {
            ToggleBuzzer();
        }
        else if (clicked == sensors.photoresistor.collider)
        {
            ToggleDayNight();
        }
        else if (clicked == sensors.dht11.collider)
        {
            ToggleTemperature();
        }
    }

    // Rasvjeta

    private void ToggleLight(SmartLight light)
    {
        // Kod aktivne veze klik se prvo salje fizickom modelu. Unity ne mijenja
        // stanje unaprijed, nego ceka stvarni status koji ESP32 vrati.
        if (esp32Connection != null && esp32Connection.IsConnected)
        {
            if (light == devices.bedroom1Light)
            {
                esp32Connection.ToggleBedroom1FromUnity();
            }
            else if (light == devices.wcLight)
            {
                esp32Connection.ToggleWCFromUnity();
            }
            else if (light == devices.bedroom2Light)
            {
                esp32Connection.ToggleBedroom2FromUnity();
            }

            return;
        }

        SetLight(light, !light.isOn);
    }

    private void SetLight(SmartLight light, bool turnOn)
    {
        light.isOn = turnOn;

        if (light.glassRenderer == null)
        {
            return;
        }

        if (turnOn)
        {
            light.glassRenderer.material = materials.bulbOnMaterial;
        }
        else
        {
            light.glassRenderer.material = materials.grayMaterial;
        }
    }

    // Ventilator

    private void ToggleFan()
    {
        if (esp32Connection != null && esp32Connection.IsConnected)
        {
            esp32Connection.ToggleFanFromUnity();
            return;
        }

        SetFan(!devices.fan.isOn);
    }

    public void SetFan(bool turnOn)
    {
        devices.fan.isOn = turnOn;
    }

    private void RotateFan()
    {
        SmartFan fan = devices.fan;

        if (!fan.isOn || fan.rotor == null)
        {
            return;
        }

        float amount = fan.rotationSpeed * Time.deltaTime;
        Vector3 axis = fan.rotor.TransformDirection(fan.rotationAxis.normalized);

        if (fan.collider != null)
        {
            fan.rotor.RotateAround(fan.collider.bounds.center, axis, amount);
        }
        else
        {
            fan.rotor.Rotate(fan.rotationAxis.normalized, amount, Space.Self);
        }
    }

    // Vrata

    private void InitializeDoor()
    {
        SmartDoor door = devices.door;

        if (door.doorPivot == null)
        {
            return;
        }

        door.isOpen = false;
        door.closedRotation = door.doorPivot.localRotation;
        door.openRotation = door.closedRotation *
                            Quaternion.AngleAxis(door.openAngle, door.rotationAxis.normalized);
    }

    private void ToggleDoor()
    {
        if (esp32Connection != null && esp32Connection.IsConnected)
        {
            esp32Connection.ToggleDoorFromUnity();
            return;
        }

        devices.door.isOpen = !devices.door.isOpen;
    }

    public void SetDoor(bool open)
    {
        devices.door.isOpen = open;
    }

    private void RotateDoor()
    {
        SmartDoor door = devices.door;

        if (door.doorPivot == null)
        {
            return;
        }

        Quaternion targetRotation;

        if (door.isOpen)
        {
            targetRotation = door.openRotation;
        }
        else
        {
            targetRotation = door.closedRotation;
        }

        door.doorPivot.localRotation = Quaternion.RotateTowards(
            door.doorPivot.localRotation,
            targetRotation,
            door.rotationSpeed * Time.deltaTime
        );
    }

    // Zujalica

    private void InitializeBuzzer()
    {
        SmartBuzzer buzzer = devices.buzzer;

        if (buzzer.model != null)
        {
            buzzer.renderers = buzzer.model.GetComponentsInChildren<Renderer>(true);
            buzzer.originalMaterials = SaveMaterials(buzzer.renderers);
        }

        SetBuzzer(false);
    }

    private void ToggleBuzzer()
    {
        if (esp32Connection != null && esp32Connection.IsConnected)
        {
            esp32Connection.ToggleBuzzerFromUnity();
            return;
        }

        SetBuzzer(!devices.buzzer.isOn);
    }

    public void SetBuzzer(bool turnOn)
    {
        SmartBuzzer buzzer = devices.buzzer;
        buzzer.isOn = turnOn;

        if (turnOn)
        {
            ApplyMaterial(buzzer.renderers, materials.redMaterial);
        }
        else
        {
            RestoreMaterials(buzzer.renderers, buzzer.originalMaterials);
        }
    }

    // Zvono

    private void InitializeDoorbell()
    {
        SmartDoorbell doorbell = devices.doorbell;

        if (doorbell.buttonCap != null)
        {
            doorbell.startPosition = doorbell.buttonCap.localPosition;
        }

        doorbell.isPressed = false;
    }

    private void PressDoorbell()
    {
        SmartDoorbell doorbell = devices.doorbell;

        if (doorbell.isPressed)
        {
            return;
        }

        if (esp32Connection != null && esp32Connection.IsConnected)
        {
            esp32Connection.PressDoorbellFromUnity();
        }

        doorbell.isPressed = true;
        doorbell.timer = doorbell.pressDuration;
        doorbell.buzzerWasOn = devices.buzzer.isOn;

        if (doorbell.buttonCap != null)
        {
            Vector3 movement = doorbell.pressAxis.normalized * doorbell.pressDistance;
            doorbell.buttonCap.localPosition = doorbell.startPosition + movement;
        }

        SetBuzzer(true);
    }

    private void UpdateDoorbell()
    {
        SmartDoorbell doorbell = devices.doorbell;

        if (!doorbell.isPressed)
        {
            return;
        }

        doorbell.timer -= Time.deltaTime;

        if (doorbell.timer > 0f)
        {
            return;
        }

        doorbell.isPressed = false;

        if (doorbell.buttonCap != null)
        {
            doorbell.buttonCap.localPosition = doorbell.startPosition;
        }

        SetBuzzer(doorbell.buzzerWasOn);
    }

    // Fotootpornik i prikaz dana/noci

    private void InitializePhotoresistor()
    {
        SmartPhotoresistor photoresistor = sensors.photoresistor;

        if (photoresistor.whitePart != null)
        {
            photoresistor.renderers =
                photoresistor.whitePart.GetComponentsInChildren<Renderer>(true);
            photoresistor.originalMaterials = SaveMaterials(photoresistor.renderers);
        }

        SetLightLevel(photoresistor.dayLightLevel);
    }

    private void ToggleDayNight()
    {
        SmartPhotoresistor photoresistor = sensors.photoresistor;

        if (photoresistor.isDark)
        {
            SetLightLevel(photoresistor.dayLightLevel);
        }
        else
        {
            SetLightLevel(photoresistor.nightLightLevel);
        }
    }

    public void SetLightLevel(float lightLevel)
    {
        SmartPhotoresistor photoresistor = sensors.photoresistor;
        photoresistor.currentLightLevel = lightLevel;
        photoresistor.isDark = lightLevel < photoresistor.darknessThreshold;
        photoresistor.currentCondition = photoresistor.isDark ? "MRAK" : "DAN";

        if (photoresistor.isDark)
        {
            ApplyMaterial(photoresistor.renderers, materials.grayMaterial);
        }
        else
        {
            RestoreMaterials(photoresistor.renderers, photoresistor.originalMaterials);
        }

        SetLight(devices.bedroom1Light, photoresistor.isDark);
        SetLight(devices.wcLight, photoresistor.isDark);
        SetLight(devices.bedroom2Light, photoresistor.isDark);
    }

    public void SetPhotoresistorStatus(float lightPercent, string lightCondition)
    {
        SmartPhotoresistor photoresistor = sensors.photoresistor;

        photoresistor.currentLightLevel = Mathf.Clamp(lightPercent, 0f, 100f);
        photoresistor.currentCondition = string.IsNullOrEmpty(lightCondition)
            ? "DAN"
            : lightCondition;
        photoresistor.isDark = string.Equals(
            photoresistor.currentCondition,
            "MRAK",
            System.StringComparison.OrdinalIgnoreCase
        );

        if (photoresistor.isDark)
        {
            ApplyMaterial(
                photoresistor.renderers,
                materials.grayMaterial
            );
        }
        else
        {
            RestoreMaterials(
                photoresistor.renderers,
                photoresistor.originalMaterials
            );
        }
    }

    // DHT11 i lokalna simulacija temperature

    private void InitializeDHT11()
    {
        SmartDHT11 dht = sensors.dht11;

        if (dht.model != null)
        {
            dht.renderers = dht.model.GetComponentsInChildren<Renderer>(true);
            dht.originalMaterials = SaveMaterials(dht.renderers);
        }

        SetDHT11Values(dht.normalTemperature, dht.humidity);
    }

    private void ToggleTemperature()
    {
        SmartDHT11 dht = sensors.dht11;

        if (dht.highTemperatureActive)
        {
            SetDHT11Values(dht.normalTemperature, dht.humidity);
        }
        else
        {
            SetDHT11Values(dht.highTemperature, dht.humidity);
        }
    }

    public void SetDHT11Values(float temperature, float humidity)
    {
        SmartDHT11 dht = sensors.dht11;
        dht.currentTemperature = temperature;
        dht.humidity = humidity;
        dht.highTemperatureActive = temperature >= dht.fanTemperatureThreshold;

        if (dht.highTemperatureActive)
        {
            ApplyMaterial(dht.renderers, materials.redMaterial);
            SetFan(true);
        }
        else
        {
            RestoreMaterials(dht.renderers, dht.originalMaterials);
            SetFan(false);
        }
    }

    // Pomocne metode za materijale

    private Material[][] SaveMaterials(Renderer[] renderers)
    {
        if (renderers == null)
        {
            return null;
        }

        Material[][] saved = new Material[renderers.Length][];

        for (int i = 0; i < renderers.Length; i++)
        {
            if (renderers[i] != null)
            {
                saved[i] = renderers[i].materials;
            }
        }

        return saved;
    }

    private void RestoreMaterials(Renderer[] renderers, Material[][] originalMaterials)
    {
        if (renderers == null || originalMaterials == null)
        {
            return;
        }

        int count = Mathf.Min(renderers.Length, originalMaterials.Length);

        for (int i = 0; i < count; i++)
        {
            if (renderers[i] != null && originalMaterials[i] != null)
            {
                renderers[i].materials = originalMaterials[i];
            }
        }
    }

    private void ApplyMaterial(Renderer[] renderers, Material material)
    {
        if (renderers == null || material == null)
        {
            return;
        }

        for (int i = 0; i < renderers.Length; i++)
        {
            if (renderers[i] == null)
            {
                continue;
            }

            Material[] rendererMaterials = renderers[i].materials;

            for (int j = 0; j < rendererMaterials.Length; j++)
            {
                rendererMaterials[j] = material;
            }

            renderers[i].materials = rendererMaterials;
        }
    }

    // Gumbi i tekst na statusnom panelu

    private void UpdateButtonColors()
    {
        if (uiButtons == null)
        {
            return;
        }

        SetButtonColor(uiButtons.bedroom1Button, devices.bedroom1Light.isOn);
        SetButtonColor(uiButtons.wcButton, devices.wcLight.isOn);
        SetButtonColor(uiButtons.bedroom2Button, devices.bedroom2Light.isOn);
        SetButtonColor(uiButtons.fanButton, devices.fan.isOn);
        SetButtonColor(uiButtons.doorButton, devices.door.isOpen);
        SetButtonColor(uiButtons.buzzerButton, devices.buzzer.isOn);
        SetButtonColor(uiButtons.doorbellButton, devices.doorbell.isPressed);
        SetButtonColor(uiButtons.dht11Button, sensors.dht11.highTemperatureActive);
        SetButtonColor(uiButtons.photoresistorButton, sensors.photoresistor.isDark);
    }

    private void SetButtonColor(Button button, bool isActive)
    {
        if (button == null)
        {
            return;
        }

        Color normalColor = uiButtons.inactiveColor;

        if (isActive)
        {
            normalColor = uiButtons.activeColor;
        }

        ColorBlock colors = button.colors;
        colors.normalColor = normalColor;
        colors.selectedColor = normalColor;
        colors.highlightedColor = uiButtons.highlightedColor;
        colors.pressedColor = uiButtons.pressedColor;
        colors.colorMultiplier = 1f;
        button.colors = colors;
    }

    private void UpdateStatusText()
    {
        if (statusText == null)
        {
            return;
        }

        string dayNight;
        string doorState;
        string fanState;
        string buzzerState;
        int activeLights = 0;

        dayNight = string.IsNullOrEmpty(sensors.photoresistor.currentCondition)
            ? (sensors.photoresistor.isDark ? "MRAK" : "DAN")
            : sensors.photoresistor.currentCondition;

        if (devices.door.isOpen)
        {
            doorState = "otvorena";
        }
        else
        {
            doorState = "zatvorena";
        }

        if (devices.fan.isOn)
        {
            fanState = "uključen";
        }
        else
        {
            fanState = "isključen";
        }

        if (devices.buzzer.isOn)
        {
            buzzerState = "aktivna";
        }
        else
        {
            buzzerState = "miruje";
        }

        if (devices.bedroom1Light.isOn)
        {
            activeLights++;
        }

        if (devices.wcLight.isOn)
        {
            activeLights++;
        }

        if (devices.bedroom2Light.isOn)
        {
            activeLights++;
        }

        statusText.text =
            "<color=#E66B83><b>OKOLINA</b></color>\n" +
            "Temperatura: " + sensors.dht11.currentTemperature.ToString("0.0") + " °C\n" +
            "Vlažnost: " + sensors.dht11.humidity.ToString("0") + " %\n" +
            "Relativno osvjetljenje: " + sensors.photoresistor.currentLightLevel.ToString("0") + " %\n" +
            "Svjetlosni uvjeti: " + dayNight + "\n\n" +
            "<color=#E66B83><b>UREĐAJI</b></color>\n" +
            "Aktivna rasvjeta: " + activeLights + " / 3\n" +
            "Ventilator: " + fanState + "\n" +
            "Zujalica: " + buzzerState + "\n" +
            "Ulazna vrata: " + doorState;
    }

    // Metode povezane s UI gumbima

    public void ToggleBedroom1FromUI()
    {
        ToggleLight(devices.bedroom1Light);
    }

    public void ToggleWCFromUI()
    {
        ToggleLight(devices.wcLight);
    }

    public void ToggleBedroom2FromUI()
    {
        ToggleLight(devices.bedroom2Light);
    }

    public void ToggleFanFromUI()
    {
        ToggleFan();
    }

    public void ToggleDoorFromUI()
    {
        ToggleDoor();
    }

    public void ToggleBuzzerFromUI()
    {
        ToggleBuzzer();
    }

    public void PressDoorbellFromUI()
    {
        PressDoorbell();
    }

    public void TogglePhotoresistorFromUI()
    {
        ToggleDayNight();
    }

    public void ToggleDHT11FromUI()
    {
        ToggleTemperature();
    }

    // Ove metode poziva ESP32Connection nakon primljenog statusa

    public void SetBedroom1Light(bool turnOn)
    {
        SetLight(devices.bedroom1Light, turnOn);
    }

    public void SetWCLight(bool turnOn)
    {
        SetLight(devices.wcLight, turnOn);
    }

    public void SetBedroom2Light(bool turnOn)
    {
        SetLight(devices.bedroom2Light, turnOn);
    }
}
