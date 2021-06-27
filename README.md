# Blynk-Light-Button
Controls a output(Relay Module) With The Blynk App And An External Button With A Latch Function

Controls a relay module for an ESP8266 like this one : 
![image](https://user-images.githubusercontent.com/81090239/123534986-306e8300-d74b-11eb-9811-d2525b3959d3.png)

The relay output is in ESP8266 pin 3
the button input is connected to pin 2 and ground,the button acts like a latch switch that could control the relay and update the blynk app.
the blynk button (configured as a switch,swing between 0(LOW) 1(HIGH) is attached to virtual pin V1,it will directly control the light and overrides the button input.

Note:
I haven't checked if the esp8266 disconnects from the server,if the button still works or not. (i am using a blynk local server)

