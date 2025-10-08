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

- Analysis of Room Temp Byte Stream

For this data extraction, I used a channel pin to send a pattern generator function which pulsed between high and low voltage. The sensor starts transmission when the MCU pulls the data voltage low, then pull up the voltage for 10 microseconds, and then the sensor starts transmission. The analysis of the 40 bit tranmission are shown below:
<img width="818" height="165" alt="image" src="https://github.com/user-attachments/assets/3240a6a6-23ec-4cd0-a4e1-9f77c4dbef8f" />
Byte 0: 00111100 -> 60% humidity
Byte 1: 00000011 -> .3% humidity -> 60.3% humidity
Byte 2: 00010111 -> 23 degrees celcius
Byte 3: 00001001 -> .9 degrees celcius -> 23.9 degrees celcius
Byte 4: CHECKSUM -> 01011111 = (60 + 3 + 23 + 9) & 0xFF -> 01011111
