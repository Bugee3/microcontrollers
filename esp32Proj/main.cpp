#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "yourSSID";
const char* password = "yourPassword";

WiFiClient client;
HTTPClient http;

void setup() {
    Serial.begin(115200);

    // Connect to WiFi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}

void loop() {
    if (WiFi.status() == WL_CONNECTED) {
        http.begin(client, "http://yourserverip:5000/add_data");  // Server URL
        http.addHeader("Content-Type", "application/x-www-form-urlencoded");

        // Sending ADC value to the server
        String postData = "adc_value=" + String(adc_value);
        int httpResponseCode = http.POST(postData); // POST request

        if (httpResponseCode == 200) {
            Serial.println("Data sent successfully");
        } else {
            Serial.println("Error sending data");
        }

        http.end();
    }

    delay(5000); // Send every 5 seconds
}
