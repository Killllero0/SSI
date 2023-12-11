#include <Arduino.h>

// Настройки WiFi
// Имя Wi-Fi
const char* WIFI_SSID = "wifi_ssid";
// Пароль Wi-Fi
const char* WIFI_PASSWORD =  "wifi_password";


// Настройки MQTT

// Адрес сервера
const char* MQTT_ADDRESS = "mqtt.dealgate.ru";
// Порт сервера
const int MQTT_PORT = 1883;
// ID устройства
const char* MQTT_ID = "mqtt_id";
// Пользователь
const char* MQTT_USER  = "mqtt_user";
// Пароль пользователя
const char* MQTT_PASSWORD = "mqtt_password";
// Топик для чтения
const char* MQTT_READ_TOPIC = "mqtt_topic";

const int DegreesRevolution = 720;

// Продвинутые настройки
// Включение вывода отладочной информации
#define DEBUG true

// Пины мотора
const int IN1 = 19;
const int IN2 = 18;
const int IN3 = 5;
const int IN4 = 17;

// Кол-во шагов для полного оборота мотора
const int stepsPerRevolution = 2048;

void callback(char* topic, byte* payload, unsigned int length);
void mqttconnect();