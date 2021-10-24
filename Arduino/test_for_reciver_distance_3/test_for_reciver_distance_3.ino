#include "nRF24L01.h" // NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"
#include <Servo.h>

#define trigPin 3
#define echoPin 2

int sens_dist_beg=65,distanc_limit=50;
int pwmL,pwmR,rate=1,time_delay=80;
int rc_elevator_pulsewidth_max_out = 2000;
int rc_elevator_pulsewidth_min_out = 1200;
int pwmT= rc_elevator_pulsewidth_min_out,pwm[3];
float distance1,duration,distance2;
int ReceivedMessage[3] = {000}; // Used to store value received by the NRF24L01
RF24 radio(9,10); // NRF24L01 SPI pins. Pin 9 and 10 on the Nano
Servo throttleRIGHT;
Servo throttleLEFT;
const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 

void setup(void)
{ 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  radio.begin(); // Start the NRF24L01
  radio.openReadingPipe(1,pipe); // Get NRF24L01 ready to receive
  radio.startListening(); // Listen to see if information received
  throttleRIGHT.attach(7);
  throttleLEFT.attach(5);
  Serial.begin (9600);
   
}

void loop(void)
{ 
  while (radio.available())
  {
  
    if(distance()>sens_dist_beg){
      radio_fun();
      red_raise(pwmT,pwm[0]);
      turn();
      
    }
       //throttleRIGHT.writeMicroseconds(pwmR);
       
    else{
        
       //radio_fun();
       //pwmT=pwm[0];
       while(distance()<sens_dist_beg){
         float max_speed= 11.5*distance()+rc_elevator_pulsewidth_min_out-distanc_limit;
         radio_fun();
         if (pwm[0]> max_speed & pwmT>max_speed){
             red_raise(pwmT,max_speed);
             turn();
           
         }
//         else if (pwm[0]> max_speed & pwmT<=max_speed){
//            red_raise(pwmT,pwmT);
//            turn();
//         }
         else{
            //pwmT=pwm[0];
            red_raise(pwmT,pwm[0]);
            turn();
        
          
        }
            
       } 
       //throttle.writeMicroseconds(pwm);
    }

    
 }
}
float distance()
{  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance2 = (duration / 2) * 0.0344;
  
//  if (distance2 >= 2000 || distance2 <= 2){
//    Serial.print("Distance = ");
//    Serial.print("Out of range");
//    return 800;
//  }
//  
//  else {
    
    return distance2;
    //}
}
void turn()
{ 
  
  int turn1 = abs(ReceivedMessage[1]-76);
  if (ReceivedMessage[1]>=80) {
      pwmL=constrain(pwmT+turn1,rc_elevator_pulsewidth_min_out-(50+distanc_limit),rc_elevator_pulsewidth_max_out);
      pwmR=constrain(pwmT-turn1,rc_elevator_pulsewidth_min_out-(50+distanc_limit),rc_elevator_pulsewidth_max_out);
      throttleLEFT.writeMicroseconds(pwmL);
      throttleRIGHT.writeMicroseconds(pwmR);
    }

  else if (ReceivedMessage[1]<=74){
      pwmL=constrain(pwmT-turn1,rc_elevator_pulsewidth_min_out-(50+distanc_limit),rc_elevator_pulsewidth_max_out);
      pwmR=constrain(pwmT+turn1,rc_elevator_pulsewidth_min_out-(50+distanc_limit),rc_elevator_pulsewidth_max_out);
      throttleLEFT.writeMicroseconds(pwmL);
      throttleRIGHT.writeMicroseconds(pwmR);
    }
  else {
    pwmL=pwmT;
    pwmR=pwmT;
    throttleLEFT.writeMicroseconds(pwmL);
    throttleRIGHT.writeMicroseconds(pwmR);
  }
  Serial.print(pwmL);
  Serial.print("/");
  Serial.print(pwmR);
  Serial.print("/");
  Serial.print(distance());
  Serial.print("/");
  Serial.print(pwm[0]);
  Serial.print("/");
  Serial.print(ReceivedMessage[0]);
  Serial.print("/");
  Serial.print(ReceivedMessage[1]);
  Serial.print("/");
  Serial.print(ReceivedMessage[2]);
  Serial.println("/");
   
      
}
void radio_fun()
{ 
  radio.read(ReceivedMessage, sizeof(ReceivedMessage)); // Read information from the NRF24L01
  pwm[0] = map(ReceivedMessage[0],0,179,rc_elevator_pulsewidth_min_out,rc_elevator_pulsewidth_max_out);
  
}
void red_raise(int start1,int end1)
{if (start1>end1+5){
  pwmT = start1-rate;
  rate=rate+1;
  delay(time_delay);
  if (start1-end1<=rate){
    rate=int (rate/2);
      }
    }
 else if (start1<end1-5){
  pwmT = start1+rate;
  rate=rate+1;
  delay(time_delay);
   if (end1-start1<=rate){
    rate=int (rate/2);
      }
     }
 else{
  pwmT = end1;
  rate=1;
 }
  
}
  
