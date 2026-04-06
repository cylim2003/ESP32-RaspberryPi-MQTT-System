ESP32 MQTT IoT System
📌 Project Overview

This project implements a complete IoT communication system based on MQTT protocol, using an ESP32 as the client device and a Raspberry Pi as the MQTT broker.

The system demonstrates how embedded devices communicate through a lightweight messaging protocol in a real-world scenario.

ESP32 ---> MQTT ---> Raspberry Pi (Local Broker)
                         |
                         | ngrok TCP Tunnel
                         ↓
                   Subscriber (PC / ESP32) 

🚀 Features
📡 ESP32 publishes sensor / user-defined data via MQTT
🖥️ Raspberry Pi acts as a local MQTT broker
🔄 Real-time publish/subscribe communication
🔌 Easy deployment using shell scripts
🔁 Supports basic testing with MQTT CLI tools

🧪 How to Run
1️⃣ Setup MQTT Broker (Raspberry Pi)
chmod +x mqtt_setup.sh ./mqtt_setup.sh

2️⃣ Start Broker
chmod +x mqtt_start_broker.sh ./start_broker.sh

3️⃣ Test MQTT Communication
Open two terminals:
Terminal 1:
chmod +x test_sub.sh
./test_sub.sh
Terminal 2:
chmod +x test_pub.sh
./test_pub.sh

4️⃣ Setup ngrok
chmod +x ngrok_setup.sh
./ngrok_setup.sh

Add your token:
ngrok config add-authtoken YOUR_TOKEN

5️⃣  Start ngrok
chmod +x ngrok_start.sh
./ngrok_start.sh
You will see:
Forwarding tcp://0.tcp.ngrok.io:xxxxx -> localhost:1883

⚠️ Notes
ngrok port changes every time
Broker must be running before ngrok

6️⃣ Run ESP32
Configure WiFi and broker IP in ESP32 firmware
Flash using ESP-IDF:
idf.py build
idf.py flash monitor

⚠️ Notes
// Update broker address with ngrok TCP endpoint
.broker.address.uri = "mqtt://0.tcp.ngrok.io:xxxxx"


📈 Future Improvements
Add QoS level support
Implement MQTT over TLS (Security)
Add Web Dashboard (Node-RED / Web UI)
Multi-device communication
Cloud integration (AWS IoT / EMQX)
