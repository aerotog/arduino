# ESP8266

The [ESP8266 is a WiFi enabled microcontroller](https://en.wikipedia.org/wiki/ESP8266).

I am currently using a [NodeMCU](https://en.wikipedia.org/wiki/NodeMCU) clone from [HiLetgo purchased on Amazon](https://www.amazon.com/gp/product/B081CSJV2V).

Current working Arduino IDE settings:
- Board: NodeMCU 1.0 (ESP-12E Module)
- Builtin Led: "2"
- Upload Speed "921600"
- CPU Frequency: "80 MHz"
- Flash Size "4MB (FS:3MB OTA:~512KB)
- Debug port: "Disabled"
- Debug Level: "None"
- IwIP Variant: "v2 Lower Memory"
- VTables: "Flash"
- Exceptions: "Legacy (new can return nullptr)"
- Erase Flash: "Only Sketch"
- SSL Support: "All SSL ciphers (most compatible)"
- Port: "COM5"


# Development and Debugging
Autoodesk's [Tinkercad](https://www.tinkercad.com/) can be used for code and circuit design without having to flash a physical board.

This web app is quite capable but only supports single file sketches. For more complex projects like `carLeds`, the multiple .cpp and .h files can be flattened into a single sketch file using the python script `ino_flatten.py`.