# Blynk-Light-Button
Controls a output(Relay Module) With The Blynk App And An External Button With A Latch Function

Controls a relay for an ESP8266 like this circuit : 

![sch](https://user-images.githubusercontent.com/81090239/123535846-e25c7e00-d750-11eb-85c8-03eb0c2be18e.png)


The relay output is in ESP8266 pin 3
the button input is connected to pin 2 and ground,the button acts like a latch switch that could control the relay and update the blynk app.
the blynk button (configured as a switch,swing between 0(LOW) 1(HIGH) is attached to virtual pin V1,it will directly control the light and overrides the button input.

You could also use a esp8266 relay board and just change the GPIO relay pinout and state in the code.

Note:
I haven't checked if the esp8266 disconnects from the server,if the button still works or not. (i am using a blynk local server)

