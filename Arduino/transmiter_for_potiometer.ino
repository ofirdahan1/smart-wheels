#include <SPI.h>                      //the communication interface with the modem
#include "RF24.h"                     //the library which helps us to control the radio modem

int msg[1];
const int BUTTON = 5;
int BUTTONstate = 0;

RF24 radio(9,10);                     //5 and 10 are a digital pin numbers to which signals CE and CSN are connected.
                                      
const uint64_t pipe = 0xE8E8F0F0E1LL; //the address of the modem, that will receive data from Arduino.


void setup(void){
  Serial.begin (9600);
  pinMode(BUTTON, INPUT);
  radio.begin();                      //it activates the modem.
  radio.openWritingPipe(pipe);        //sets the address of the receiver to which the program will send data.
}

void loop(void){
  BUTTONstate = digitalRead(BUTTON);
  msg[0] =  map (analogRead(1), 0, 1023, 0, 179); 
  radio.write(msg, 1);
  Serial.print(msg[0]);
  Serial.print("/");
  Serial.print(BUTTONstate);
  Serial.print("/");
  Serial.print(analogRead(1));
  Serial.print("/");
  Serial.println(analogRead(2));
}
