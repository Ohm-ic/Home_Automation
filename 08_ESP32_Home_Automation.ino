#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define LED_PIN 2  // Assuming LED is connected to GPIO 2
#define BUZZER_PIN 4 // Assuming Buzzer is connected to GPIO 4

const char* ssid = "IP WAN";
const char* password = "Nasa@2023";

const long utcOffsetInSeconds = 19800; // Your timezone offset in seconds
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize NTP
  timeClient.begin();
  timeClient.update();
}

void loop() {
  timeClient.update();
  int currentHour = timeClient.getHours();

  // Dim LED in the evening (5 pm to 9 pm)
  if (currentHour >= 17 && currentHour < 21) {
    int brightness = map(currentHour, 17, 20, 0, 255); // Map hour to brightness value
    analogWrite(LED_PIN, brightness);
  }
  // Turn off LED after 9 pm
  else if (currentHour >= 21) {
    digitalWrite(LED_PIN, LOW);
  }

  // Buzz the alarm at 6 am
  if (currentHour == 6 && timeClient.getMinutes() == 0 && timeClient.getSeconds() == 0) {
    buzzAlarm();
  }

  delay(60000); // Update every minute
}

void buzzAlarm() {
  // Buzz the alarm
  digitalWrite(BUZZER_PIN, HIGH);
  delay(5000); // Buzz for 5 second
  digitalWrite(BUZZER_PIN, LOW);
}
