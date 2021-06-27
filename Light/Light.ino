//#define BLYNK_PRINT Serial //uncomment to save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "Your Authentication Code";
char ssid[] = "Your SSID";
char pass[] = "Your Password";
//#define SERVER  IPAddress(xxx, xxx, xxx, xxx)  //uncomment if you are using a local server

int Relay = 3;
int Button = 2;

int state = HIGH;      
int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin
long dtime = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

BLYNK_WRITE(V1){
    int pinVal = param.asInt();

    if(pinVal == 1){
        digitalWrite(Relay,HIGH);
    } else {
        digitalWrite(Relay,LOW);
    }
}

void setup()
{
//    Serial.begin(9600);
    pinMode(Relay,OUTPUT);
    pinMode(Button,INPUT);

    if(SERVER){
        Blynk.begin(auth,wifi, ssid, pass, SERVER, 8080);
    } else{
        Blynk.begin(auth,wifi, ssid, pass);
    }

    digitalWrite(Relay,LOW);
}

void loop()
{
    Blynk.run();
    reading = digitalRead(Button);

    if (reading == HIGH && previous == LOW && millis() - dtime > debounce) {

    if (state == HIGH){
        state = LOW;
        digitalWrite(Relay, LOW);
        Blynk.virtualWrite(V1,LOW);
    }else{
        digitalWrite(Relay, HIGH);
        Blynk.virtualWrite(V1,HIGH);
        state = HIGH;
    }    
    dtime = millis();    
  }
previous = reading;
}
