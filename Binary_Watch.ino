#include <Time.h>

/*
* Written by Marc Poul Joseph Laventure
* Date: February 9th, 2014
* Purpose: Binary watch code with LED Interaction, used
* the Time Library to make more efficient.
*
*/

// Initialize binary minute LED's
int led_hour1 = 2; // Binary to Decimal:1
int led_hour2 = 3; // Binary to Decimal:2
int led_hour3 = 4; // BInary to Decimal:4
int led_hour4 = 5; // Binary to Decimal:8

// Initialize binary min LED's
int led_min1 = 6; // Binary to Decimal:1
int led_min2 = 7; // Binary to Decimal:2
int led_min3 = 8; // Binary to Decimal:4
int led_min4 = 9; // Binary to Decimal:8
int led_min5 = 10; // Binary to Decimal:16
int led_min6 = 11; // Binar6 to Decimal:32

// Declare buttons
const int delta_time = 12; // Increase in time by minutes
const int display_time = 13; // Display time

// Button states
int delta_time_state = 0;
int display_time_state = 0;


void setup(){
  Serial.begin(9600);
  // Hour binary digital pin set to output
  pinMode(led_hour1, OUTPUT);
  pinMode(led_hour2, OUTPUT);
  pinMode(led_hour3, OUTPUT);
  pinMode(led_hour4, OUTPUT);
  
  // Minute binary digital pin set to output
  pinMode(led_min1, OUTPUT);
  pinMode(led_min2, OUTPUT);
  pinMode(led_min3, OUTPUT);
  pinMode(led_min4, OUTPUT);
  pinMode(led_min5, OUTPUT);
  pinMode(led_min6, OUTPUT);
  
  // Initialize buttons
  pinMode(delta_time, OUTPUT);
  pinMode(display_time, OUTPUT);
}

void loop(){
 delta_time_state = digitalRead(delta_time); // Read user control for delta time pin 12
 display_time_state = digitalRead(display_time); // Read user control display time pin 13
 time_t t = now(); // Store the current time in time
 
 // Turn LED's off when display_time button not pushed
 digitalWrite(led_min1, LOW);
 digitalWrite(led_min2, LOW);
 digitalWrite(led_min3, LOW);
 digitalWrite(led_min4, LOW);
 digitalWrite(led_min5, LOW);
 digitalWrite(led_min6, LOW);
 digitalWrite(led_hour1, LOW);
 digitalWrite(led_hour2, LOW);
 digitalWrite(led_hour3, LOW);
 digitalWrite(led_hour4, LOW);
 
 while(display_time_state == HIGH){
 time_t t = now(); // Store the current time in time 
 display_time_state = digitalRead(display_time);
 delta_time_state = digitalRead(delta_time); // Read user control for delta time
 if(delta_time_state == HIGH){
  adjustTime(1);
   } 
 if(minute(t) == 0){
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, LOW);
   }
   
 if(minute(t) == 1){
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, LOW);
   }
   
 if(minute(t) == 2){
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, LOW);
   }
   
  if(minute(t) == 3){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, LOW);
  }
  
   if(minute(t) == 4){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, LOW);
  }
  
   if(minute(t) == 5){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, LOW);
  }
  
  if(minute(t) == 6){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, LOW);
  }
  
  if(minute(t) == 7){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, LOW);
  }
  
  if(minute(t) == 8){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, LOW);
  }
  
  if(minute(t) == 9){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, LOW);
  }
  
  if(minute(t) == 10){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, LOW);
  }
  
  if(minute(t) == 11){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, LOW);
     
  }
  
  if(minute(t) == 12){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, LOW);
  
  }
  
  if(minute(t) == 13){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 14){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 15){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 16){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 17){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 18){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 19){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 20){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 21){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 23){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 24){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 25){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 26){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 27){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 28){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 29){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 30){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 31){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, LOW);

  }
  
  if(minute(t) == 32){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, HIGH);

  }
  
  if(minute(t) == 33){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, HIGH);

  }
  
  if(minute(t) == 34){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, HIGH);

  }
  
  if(minute(t) == 35){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, HIGH);
     
     }
  
  if(minute(t) == 36){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, HIGH);
;
  }
  
  if(minute(t) == 37){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, HIGH);

  }
  
  if(minute(t) == 38){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, HIGH);

  }
  
  if(minute(t) == 39){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, HIGH);

  }
  
  if(minute(t) == 40){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, HIGH);

  }
  
  if(minute(t) == 41){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, HIGH);

  }
  
  if(minute(t) == 42){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, HIGH);

  }
  
  if(minute(t) == 43){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, HIGH);

  }
  
  if(minute(t) == 44){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, HIGH);
  }
  
  if(minute(t) == 45){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, HIGH);
  }
  
  if(minute(t) == 46){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, HIGH);
  }
  
  if(minute(t) == 47){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, LOW);
     digitalWrite(led_min6, HIGH);
  }
  
  if(minute(t) == 48){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, HIGH);
  }
  
  if(minute(t) == 49){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, HIGH);
  }
  
  if(minute(t) == 50){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, HIGH);
  }
  
  if(minute(t) == 51){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, HIGH);
  }
  
  if(minute(t) == 52){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, HIGH);
  }
  
  if(minute(t) == 53){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, HIGH);
  }
  
  if(minute(t) == 54){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, HIGH);
  }
  
  if(minute(t) == 55){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, LOW);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, HIGH);
  }
  
  if(minute(t) == 56){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, HIGH);
  }
  
  if(minute(t) == 57){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, HIGH);
  }
  
  if(minute(t) == 58){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, HIGH);
  }
  
  if(minute(t) == 59){ 
     digitalWrite(led_min1, HIGH);
     digitalWrite(led_min2, HIGH);
     digitalWrite(led_min3, LOW);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, HIGH);
  }
  
  if((minute(t) + 1) == 60){ 
     digitalWrite(led_min1, LOW);
     digitalWrite(led_min2, LOW);
     digitalWrite(led_min3, HIGH);
     digitalWrite(led_min4, HIGH);
     digitalWrite(led_min5, HIGH);
     digitalWrite(led_min6, HIGH);
  }
  
  if(hour(t) == 0){
    digitalWrite(led_hour1, LOW);
    digitalWrite(led_hour2, LOW);
    digitalWrite(led_hour3, LOW);
    digitalWrite(led_hour4, LOW);

  }

  if( (hour(t) == 1) || (hour(t) == 13) ){
    digitalWrite(led_hour1, HIGH);
    digitalWrite(led_hour2, LOW);
    digitalWrite(led_hour3, LOW);
    digitalWrite(led_hour4, LOW);
  }

  if( (hour(t) == 2) || (hour(t) == 14) ){
    digitalWrite(led_hour1, LOW);
    digitalWrite(led_hour2, HIGH);
    digitalWrite(led_hour3, LOW);
    digitalWrite(led_hour4, LOW);
  } 
 
 if( (hour(t) == 3) || (hour(t) == 15) ){
    digitalWrite(led_hour1, HIGH);
    digitalWrite(led_hour2, HIGH);
    digitalWrite(led_hour3, LOW);
    digitalWrite(led_hour4, LOW);
 }
 
 if( (hour(t) == 4) || (hour(t) == 16) ){
    digitalWrite(led_hour1, LOW);
    digitalWrite(led_hour2, LOW);
    digitalWrite(led_hour3, HIGH);
    digitalWrite(led_hour4, LOW);
 }
 
 if( (hour(t) == 5) || (hour(t) == 17) ) {
    digitalWrite(led_hour1, HIGH);
    digitalWrite(led_hour2, LOW);
    digitalWrite(led_hour3, HIGH);
    digitalWrite(led_hour4, LOW);
 }
 
 if( (hour(t) == 6) || (hour(t) == 18) ){
    digitalWrite(led_hour1, LOW);
    digitalWrite(led_hour2, HIGH);
    digitalWrite(led_hour3, HIGH);
    digitalWrite(led_hour4, LOW);
 }
 
 if( (hour(t) == 7) || (hour(t) == 19) ){
    digitalWrite(led_hour1, HIGH);
    digitalWrite(led_hour2, HIGH);
    digitalWrite(led_hour3, HIGH);
    digitalWrite(led_hour4, LOW);
 }
 
 if( (hour(t) == 8) || (hour(t) == 20) ){
    digitalWrite(led_hour1, LOW);
    digitalWrite(led_hour2, LOW);
    digitalWrite(led_hour3, LOW);
    digitalWrite(led_hour4, HIGH);
 }
 
 if( (hour(t) == 9) || (hour(t) == 21) ){
    digitalWrite(led_hour1, HIGH);
    digitalWrite(led_hour2, LOW);
    digitalWrite(led_hour3, LOW);
    digitalWrite(led_hour4, HIGH);
 }
 
 if( (hour(t) == 10) || (hour(t) == 22) ){
    digitalWrite(led_hour1, LOW);
    digitalWrite(led_hour2, HIGH);
    digitalWrite(led_hour3, LOW);
    digitalWrite(led_hour4, HIGH);
 }
 
 if( (hour(t) == 11) || (hour(t) == 23) ) {
    digitalWrite(led_hour1, HIGH);
    digitalWrite(led_hour2, HIGH);
    digitalWrite(led_hour3, LOW);
    digitalWrite(led_hour4, HIGH);
 }
 
 if( (hour(t) == 12) ||( (hour(t) +1) == 24) ) {
    digitalWrite(led_hour1, LOW);
    digitalWrite(led_hour2, LOW);
    digitalWrite(led_hour3, HIGH);
    digitalWrite(led_hour4, HIGH);
 }
 
} 
  
}
