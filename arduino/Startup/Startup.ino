
#include <Keypad.h>
#include <String.h>
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
const byte ROWS = 4; //four rows
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
              // defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
 //three columns
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8,9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
// defines variables
long duration;
int distance;
int buzzer = 4;
int red_led = 3;
int green_led = 5;
int yellow_led = 13 ;
char key ;

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
Serial.begin(9600);
lcd.print("smart things");
lcd.setCursor(0,0);
  
}
int counter = 0;
  int counter2 = 0;
void loop() 
{
  key = keypad.getKey();
  if(key == 'C')
  {
    
    Serial.println("settings");
    while(key != 'D')
    {
      key = keypad.getKey();
     if(key)
     {
     Serial.print(key);
     }
    }
   
    Serial.println("out");
  }
 
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
   lcd.println("   Dead Level ");
  lcd.setCursor(0,0);
  while(counter <=10)
  {
  
  digitalWrite(red_led,HIGH);
  tone(buzzer,200);
  delay(50);
  digitalWrite(red_led,LOW);
  noTone(buzzer);
  delay(50);
  digitalWrite(red_led,HIGH);
  tone(buzzer,200);
  delay(50);
   digitalWrite(red_led,LOW);
  noTone(buzzer);
  delay(50);
   digitalWrite(red_led,HIGH);
  tone(buzzer,200);
 
 
  counter++;
  }
   digitalWrite(red_led,HIGH);
  
 
  noTone(buzzer);
   digitalWrite(yellow_led,LOW);
  digitalWrite(green_led,LOW);
 
  
}

if(distance>3 && distance <=7)
{
  lcd.print("   Half Level ");
  lcd.setCursor(0,0);
  digitalWrite(yellow_led,HIGH);
 
  digitalWrite(red_led,LOW);
  digitalWrite(green_led,LOW);
  noTone(buzzer);
  
  
}

if (distance <=3 )
{
   lcd.print("  Over flow  ");
  lcd.setCursor(0,0);
  while(counter2 <=10)
  {
  
 digitalWrite(green_led,HIGH);
  tone(buzzer,200);
  delay(50);
 digitalWrite(green_led,LOW);
  noTone(buzzer);
  delay(50);
 digitalWrite(green_led,HIGH);
  tone(buzzer,200);
  delay(50);
  digitalWrite(green_led,LOW);
  noTone(buzzer);
  delay(50);
  digitalWrite(green_led,HIGH);
  tone(buzzer,200);
 
 
  counter2++;
  }
   digitalWrite(green_led,HIGH);
   
 
  noTone(buzzer);
   digitalWrite(yellow_led,LOW);
  digitalWrite(red_led,LOW);
 
  
 
}



}
