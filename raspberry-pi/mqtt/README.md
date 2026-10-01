\# Raspberry Pi MQTT Telemetry



A small C++ MQTT experiment using the Eclipse Paho MQTT C++ library.



\## What this program does



The Raspberry Pi acts as an MQTT client.



It:



1\. Connects to an MQTT broker running on `localhost:1883`

2\. Authenticates with a username and password

3\. Publishes its status as `ONLINE`

4\. Subscribes to an LED command topic

5\. Periodically publishes simulated telemetry data

6\. Uses MQTT QoS 1 for telemetry and commands

7\. Uses a retained status message

8\. Uses a Last Will and Testament (LWT) message to report `OFFLINE`

9\. Prints received commands to the terminal



\---



\## MQTT Topics



\### Telemetry



```text

device/pi4/telemetry

