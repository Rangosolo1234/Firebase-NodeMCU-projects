#include <ESP8266WiFi.h>

int LedPin = 2;

// WiFi details
const char* ssid = "Chireka";
const char* password = "Pf68630..@";

// Function to blink LED
void blinkLED(int times, int speedDelay) {
  for (int i = 0; i < times; i++) {

    digitalWrite(LedPin, LOW);
    delay(speedDelay);

    digitalWrite(LedPin, HIGH);  // OFF
    delay(speedDelay);
  }
}

void setup() {
  pinMode(LedPin, OUTPUT);

  digitalWrite(LedPin, HIGH);

  Serial.begin(115200);

  Serial.println("\nConnecting to WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  // Blink 5 times
  blinkLED(5, 200);

  // Wait 5 seconds
  delay(5000);

  // Blink 2 times
  blinkLED(3, 1000);

  // Wait 5 seconds
  delay(5000);
}