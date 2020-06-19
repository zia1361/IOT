

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display 
byte degree_symbol[8] = 
              {
                0b00111,
                0b00101,
                0b00111,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000
              };
              // defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
int buzzer = 4;
int red_led = 3;
int green_led = 6;
int yellow_led = 2;

void setup() 
{
 lcd.init();                       // initialize the lcd
 lcd.init();
 lcd.backlight(); 
 
// lcd.setCursor(0,1);
// 
// 
// lcd.setCursor(9,0);
//// lcd.write(1);
// 
// lcd.setCursor(13,1);
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer,OUTPUT);
pinMode(green_led,OUTPUT);
pinMode(yellow_led,OUTPUT);
pinMode(red_led,OUTPUT);
 
}

void loop() 
{
digitalWrite(trigPin, LOW);
delay(2000);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delay(2000);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
if(distance > 7 )
{
  lcd.print(" Dead Level ");
  lcd.setCursor(0,0);
  digitalWrite(red_led,HIGH);
  tone(buzzer,200);
  delay(30);
  digitalWrite(red_led,LOW);
  noTone(buzzer);
  delay(30);
  digitalWrite(red_led,HIGH);
  tone(buzzer,200);
  digitalWrite(buzzer,200);
  digitalWrite(yellow_led,LOW);
  digitalWrite(green_led,LOW);
 
  
}
if(distance>3 && distance <=7)
{
  lcd.print(" Half Level ");
  lcd.setCursor(0,0);
  digitalWrite(yellow_led,HIGH);
  delay(30);
  digitalWrite(yellow_led,LOW);
  delay(30);
  digitalWrite(yellow_led,HIGH);
  digitalWrite(red_led,LOW);
  digitalWrite(green_led,LOW);
  noTone(buzzer);
  
  
}
if (distance <=3 )
{
  lcd.print(" Over Flow ");
  lcd.setCursor(0,0);
  digitalWrite(green_led,HIGH);
  digitalWrite(buzzer,200);
  delay(30);
  digitalWrite(green_led,LOW);
  digitalWrite(buzzer,200);
  delay(30);
  digitalWrite(green_led,HIGH);
  digitalWrite(buzzer,200);
  digitalWrite(yellow_led,LOW);
  digitalWrite(red_led,LOW);
 
}

}
