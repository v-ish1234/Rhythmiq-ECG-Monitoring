#include <ESP8266WiFi.h> 
#include <ThingSpeak.h> 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
 
#define ECG_PIN A0 
#define THRESHOLD 550  // Adjust based on your ECG signal 
 
const char* ssid = "ECG"; 
const char* password = "12345678"; 
unsigned long myChannelNumber = 2924543; 
const char * myWriteAPIKey = "H2ATSRUGF6NG5JBJ"; 
 
WiFiClient client; 
LiquidCrystal_I2C lcd(0x27, 16, 2); 
 
unsigned long lastBeatTime = 0; 
int bpm = 0; 
String condition = "Unknown"; 
bool beatDetected = false; 
 
void setup() { 
  Serial.begin(115200); 
  lcd.begin(); 
  lcd.backlight(); 
 
  lcd.setCursor(0, 0); 
  lcd.print("Connecting WiFi"); 
 
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500); 
    Serial.print("."); 
  } 
 
  Serial.println("WiFi Connected"); 
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print("WiFi Connected"); 
  delay(2000); 
  lcd.clear(); 
 
  ThingSpeak.begin(client); 
} 
 
void loop() { 
  int ecgRaw = analogRead(ECG_PIN); 
  float voltage = ecgRaw * (3.3 / 1023.0); 
 
 
  unsigned long currentTime = millis(); 
 
  // Detect heartbeat based on signal threshold 
  if (ecgRaw > THRESHOLD && !beatDetected) { 
    unsigned long beatInterval = currentTime - lastBeatTime; 
    lastBeatTime = currentTime; 
 
    bpm = 60000 / beatInterval; // BPM from beat-to-beat interval 
    Serial.print("BPM: "); 
    Serial.println(bpm); 
 
    // Determine heart condition 
    if (bpm > 100) { 
      condition = "Tachycardia"; 
    } else if (bpm < 60) { 
      condition = "Bradycardia"; 
    } else { 
      condition = "Normal"; 
    } 
 
    beatDetected = true; 
  } 
 
  if (ecgRaw < THRESHOLD) { 
    beatDetected = false; // Reset detection flag 
  } 
 
  // Display ECG & BPM info 
  lcd.setCursor(0, 0); 
  lcd.print("BPM: "); 
  lcd.print(bpm); 
  lcd.print(" "); 
 
  lcd.setCursor(0, 1); 
  lcd.print(condition); 
  lcd.print("       "); // Clear leftover chars 
 
  // Send to ThingSpeak every 15s 
  static unsigned long lastSend = 0; 
  if (currentTime - lastSend > 15000) { 
    ThingSpeak.setField(1, bpm); 
    ThingSpeak.setField(2, condition); 
    int response = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey); 
    Serial.println(response == 200 ? "Sent to ThingSpeak" : "Error 
sending"); 
 
    lastSend = currentTime; 
  } 
 
  delay(10); // Small delay for loop stability 
} 
