# 💓 Rhythmiq – Smart ECG Monitoring System

An IoT-based ECG monitoring system using **ESP8266**, **AD8232 sensor**, and **Machine Learning** to detect heart irregularities like tachycardia and bradycardia. It features real-time data visualization via **ThingSpeak** and instant alerts through a custom-built **Android app**.

---

## 🚀 Features

- 📡 Real-time ECG monitoring with AD8232  
- 🔌 Wireless data transmission using ESP8266  
- 🧠 ML-based prediction of cardiac issues  
- 📲 Android app (built in Kodular) for emergency alerts  
- 📊 ThingSpeak integration for live dashboards  
- ⚙️ Portable, low-cost & efficient remote health solution

---

## 🛠 Tech Stack

- **Hardware:** ESP8266, AD8232, I2C LCD  
- **IoT Platform:** ThingSpeak  
- **Programming Languages:** C++ (Arduino), Python (ML)  
- **App Builder:** Kodular  
- **Cloud Integration:** ThingSpeak API

---

## ⚙️ How to Set Up

1. **Connect the Hardware:**
   - Connect AD8232 to ESP8266 as per the circuit diagram.
   - (Optional) Connect I2C LCD for local feedback display.

2. **Upload Code:**
   - Open `ecg_monitoring.cpp` in Arduino IDE.
   - Install required libraries:
     - `ESP8266WiFi.h`
     - `ThingSpeak.h`
     - `LiquidCrystal_I2C.h` (if using LCD)
   - Replace Wi-Fi credentials and ThingSpeak API key in the code.
   - Upload to ESP8266.

3. **Set Up ThingSpeak:**
   - Create a channel.
   - Copy API keys and paste into your Arduino code.
   - View real-time ECG data on your dashboard.

4. **Run Android App:**
   - Use Kodular to build and run the Android app.
   - Integrate with ESP8266 using webhooks or APIs for real-time alerts.

---

## 📷 Screenshots

### 🔌 Circuit Diagram  
![Circuit Diagram](assets/circuit_diagram.png)

### 📱 Android App  
![App Screenshot](assets/app_screenshot.png)

### 📊 ThingSpeak Dashboard  
![ThingSpeak](assets/thingspeak_dashboard.png)

---

## 🙋‍♀️ Author

**Vishwa Shah**  
📧 [vishwashah003@gmail.com](mailto:vishwashah003@gmail.com)  
🔗 [LinkedIn](https://linkedin.com/in/vishwashah151003)  
🌐 GitHub: [@VishwaShah1510](https://github.com/VishwaShah1510)

---

## 🤝 Contributions

This is a personal academic project.  
Feel free to fork it, suggest improvements, or use parts of it in your own health-tech experiments.

---

## 📌 License

This project is open-source and available under the [MIT License](LICENSE).
