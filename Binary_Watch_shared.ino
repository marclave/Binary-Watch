#include <Time.h>

/*
* Written by Marc Poul Joseph Laventure & Jordan Vlieg
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

// Temp time variables
int temp_hour;
int temp_min;

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

// Procedure to turn all LED's off
void setOFF(){
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
   
}

void loop(){
 delta_time_state = digitalRead(delta_time); // Read user control for delta time pin 12
 display_time_state = digitalRead(display_time); // Read user control display time pin 13
 time_t t = now(); // Store the current time in time
 
 
 setOFF(); // Turn LED's off when display_time button not pushed
 
 while(display_time_state == HIGH){
   time_t t = now(); // Store the current time in time 
   display_time_state = digitalRead(display_time); // Read user control for displaying time
   delta_time_state = digitalRead(delta_time); // Read user control for changing time
   
   if(delta_time_state == HIGH){
      adjustTime(1); // Adjust time
   }
      
   temp_hour = hour(t); // Temp hour to check which LED's should be on
   temp_min = minute(t); // Temp minute to check which LED's should be on
   
   if((temp_min - 32) >= 0){
      temp_min = temp_min - 32;
      digitalWrite(led_min6, HIGH);
   } else {
     digitalWrite(led_min6, LOW);
   }
    
   if((temp_min - 16) >= 0){
      temp_min = temp_min - 16;
      digitalWrite(led_min5, HIGH);
   } else {
    digitalWrite(led_min5, LOW);
   } 
   
   if((temp_min - 8) >= 0){
      temp_min = temp_min - 8;
      digitalWrite(led_min4, HIGH);
   } else {
    digitalWrite(led_min4, LOW);
   } 
   
   if((temp_min - 4) >= 0){
     temp_min = temp_min - 4; 
     digitalWrite(led_min3, HIGH);
   } else {
    digitalWrite(led_min3, LOW);
   }  
   
   if((temp_min - 2) >= 0){
     temp_min = temp_min - 2;      
      digitalWrite(led_min2, HIGH);
   } else {
    digitalWrite(led_min2, LOW);
   }  
   
   if((temp_min - 1) >= 0){
     temp_min = temp_min - 1;
      digitalWrite(led_min1, HIGH);
   } else {
    digitalWrite(led_min1, LOW);
   }  
   
   if( temp_hour > 12 ){
      temp_hour = temp_hour - 12;
   }     
   
   if((temp_hour - 8) >= 0){
    temp_hour = temp_hour - 8;
    digitalWrite(led_hour4, HIGH);
   } else {
    digitalWrite(led_hour4, LOW);
   }  
   
   if((temp_hour - 4) >= 0){
     temp_hour = temp_hour - 4;
     digitalWrite(led_hour3, HIGH);
   } else {
    digitalWrite(led_hour3, LOW);
   }
   
   if((temp_hour - 2) >= 0){
      digitalWrite(led_hour2, HIGH);
      temp_hour = temp_hour - 2;
   } else {
    digitalWrite(led_hour2, LOW);
   } 
   
   if((temp_hour - 1) >= 0){
     digitalWrite(led_hour1, HIGH);
     temp_hour = temp_hour - 1;
   } else {
    digitalWrite(led_hour1, LOW);
   }
    
  }// End while 
  
}
