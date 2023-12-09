// Файл с настройками
#include <settings.h>
// Подключение библиотек
#include "WiFi.h"
#include "PubSubClient.h"
#include <GyverStepper.h>

// Клиент Wi-Fi
WiFiClient espClient;

// MQTT клиент
PubSubClient client(espClient);

GStepper<STEPPER4WIRE> stepper(stepsPerRevolution, IN4, IN2, IN3, IN1);


void setup() {

  #if DEBUG
  Serial.begin(115200);
  #endif

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);

    #if DEBUG
    Serial.println("Подключаемся к WiFi-сети...");
    #endif
  }

  #if DEBUG
  Serial.println("Есть подключение к WiFi-сети");
  Serial.print("IP адрес: ");
  Serial.println(WiFi.localIP());
  #endif

  client.setServer(MQTT_ADDRESS, MQTT_PORT);
  client.setSocketTimeout(50000);
  client.setCallback(callback);

  if (client.connect(MQTT_ID, MQTT_USER, MQTT_PASSWORD))
  {
    #if DEBUG
    Serial.println("Успешное подключение к MQTT серверу");
    #endif
    client.subscribe(MQTT_READ_TOPIC);
  }

  stepper.setSpeed(120);
  stepper.setRunMode(FOLLOW_POS);

}

void loop() {
  client.loop();
  stepper.tick();
}

void callback(char* topic, byte* payload, unsigned int length)
{
  #if DEBUG
  Serial.print("Пришло сообщение [");
  Serial.print(topic);
  Serial.println("]");

  Serial.print("Сообщение: ");
  for (unsigned int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println("");
  #endif
  stepper.setTargetDeg(360);
}