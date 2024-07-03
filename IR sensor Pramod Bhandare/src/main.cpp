#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

// WiFi credentials
const char* ssid = "Airtel_BhandGogi";
const char* password = "admin@123";

// ThingSpeak API credentials
unsigned long myChannelNumber = 2588151;
const char* myWriteAPIKey = "6K6EAO54QDM2KH0C";

// IR Sensor pin
const int irSensorPin = D5;

// ThingSpeak client
WiFiClient client;

void setup() {
  Serial.begin(115200);
  pinMode(irSensorPin, INPUT);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  int irValue = digitalRead(irSensorPin);
  Serial.print("IR Sensor Value: ");
  Serial.println(irValue);

  // Upload data to ThingSpeak
  ThingSpeak.setField(1, irValue);
  int responseCode = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  if (responseCode == 200) {
    Serial.println("Data uploaded successfully");
  } else {
    Serial.println("Failed to upload data. HTTP error code: " + String(responseCode));
  }

  // Wait for 5 seconds before uploading again
  delay(5000);
}
