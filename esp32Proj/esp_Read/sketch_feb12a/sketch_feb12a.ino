#include <ESP8266WiFi.h>

const char* ssid = "TurkTelekom_TPBA34_5GHz";  // Ваш WiFi SSID
const char* password = "emALczfXEt7X";  // Ваш WiFi пароль

void setup() {
  Serial.begin(115200);  // Настроить скорость обмена на 9600
  Serial.println();
  Serial.print("duck");
  Serial.print(ssid);
  delay(1000); // Ожидание перед началом работы

  // Подключение к WiFi
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");
}

void loop() {
  // В этот цикл можно добавить код для работы с WiFi и другими модулями
  Serial.println("ESP8266 is running at 9600 bps");
  delay(2000);  // Задержка 2 секунды
}
