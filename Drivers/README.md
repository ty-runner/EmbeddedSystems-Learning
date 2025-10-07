This is a stash of the hardware drivers I have worked on to further my firmware knowledge.

# DHT11 Temperature Sensor, half duplex driver

Using the [DHT11 Sensor Datasheet](https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf?srsltid=AfmBOopYyIpQbWHyQOEwbU6UUyl6GhCKcvGwhau5AbW7I2dsqLuaHiVZ), I read through the documentation to understand the half duplex communication scheme of the device.

The first approach to understand the communication was to use a logic analyzer and pattern generator to visualize the response packet of the device.

- Wiring:
![IMG_4483](https://github.com/user-attachments/assets/b4a76fb8-facb-4b2a-a7bb-47f6f0b66ab7)

- Logic Pattern of Packet (Room temp)
![[Pasted image 20251007142149.png]]
- Logic Pattern of Packet (Hot temp)
![[Pasted image 20251007142235.png]]
