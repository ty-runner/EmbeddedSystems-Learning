This is a stash of the hardware drivers I have worked on to further my firmware knowledge.

# DHT11 Temperature Sensor, half duplex driver

Using the [DHT11 Sensor Datasheet](https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf?srsltid=AfmBOopYyIpQbWHyQOEwbU6UUyl6GhCKcvGwhau5AbW7I2dsqLuaHiVZ), I read through the documentation to understand the half duplex communication scheme of the device.
- Simple Wiring Application:
<img width="587" height="381" alt="image" src="https://github.com/user-attachments/assets/6fc59e84-8604-4806-be76-5b31f8fa553d" />

- Communication Process:
Single-bus data format is used for communication and synchronization between MCU and DHT11 sensor. One communication process is about 4ms.
Data consists of decimal and integral parts. A complete data transmission is 40bit, and the sensor sends higher data bit first.
Data format: 8bit integral RH data + 8bit decimal RH data + 8bit integral T data + 8bit decimal T data + 8bit check sum. 
If the data transmission is right, the check-sum should be the last 8bit of "8bit integral RH data + 8bit decimal RH data + 8bit integral T data + 8bit decimal T data".

- Communication Process Diagram:
<img width="637" height="383" alt="image" src="https://github.com/user-attachments/assets/0134fddf-27a8-4acc-836e-d4b500377142" />

The first approach to understand the communication was to use a logic analyzer and pattern generator to visualize the response packet of the device.

- Wiring:
![IMG_4483](https://github.com/user-attachments/assets/b4a76fb8-facb-4b2a-a7bb-47f6f0b66ab7)

- Logic Pattern of Packet (Room temp)
<img width="782" height="174" alt="image" src="https://github.com/user-attachments/assets/a1955d56-fed3-4c80-ba92-2a3c82433eab" />

- Logic Pattern of Packet (Hot temp)
<img width="786" height="143" alt="image" src="https://github.com/user-attachments/assets/bd35a7c6-f137-45ba-a74f-5a7acb335981" />

