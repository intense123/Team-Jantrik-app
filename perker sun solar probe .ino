#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
LiquidCrystal lcd2(13, 12, 11, 10, 9, 8);

#define echoPin 1  
#define trigPin 0

long duration;  
int distance;


void setup(){
lcd.begin(20,4);
lcd2.begin(16,2);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 

}

void loop(){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 mili
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in mili 
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  lcd.setCursor(0,0);
  lcd.print("Launch date:12-08-18   ");

  lcd.setCursor(2,1);
  lcd.print("Duration: 7 years ");

  lcd.setCursor(0,2);
  lcd.print("Launch mass: 685 kg   ");

  lcd.setCursor(0,3);
  lcd.print("Rocket:DeltaIV Heavy ");


  lcd2.setCursor(0,0);
  lcd2.print("Rotation:        ");
  
  lcd2.setCursor(10,0);
  lcd2.print(distance);

  lcd2.setCursor(0,1);
  lcd2.print("Speed: 692,000km ");

}