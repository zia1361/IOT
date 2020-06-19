#include <EEPROM.h>
#include <Keypad.h>
#define trigPin 10
#define echoPin 13
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
float duration, distance;

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8,9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char key;
String all_keys = ""; 
int red_led = 11;
int green_led = 12;
int yellow_led = 1;
int buzzer = A0;
double dead = 0;
  double half = 0;
  double extreme = 0;
  double most_extreme = 0;
  double division;
void setup(){
  lcd.init();                       // initialize the lcd
  lcd.init();
  lcd.backlight(); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(green_led,OUTPUT);
   pinMode(red_led,OUTPUT);
    pinMode(yellow_led,OUTPUT);
  lcd.print(" SMART  WIDGETS ");  
  EEPROM.get(0,division);
  dead = division*3 + (division*0.5);
  dead = dead*30.48;
  half = division*3;
  half = half*30.48;
  extreme = division*2;
  extreme = extreme*30.48;
  most_extreme = division;
  most_extreme = most_extreme*30.48;
  lcd.setCursor(0,0);
}
int counter2 = 0;
  int counter = 0;
  int counter3 = 0;
  int counter4 = 0;
  
void loop(){
  int counter = 0;
  int counter2 = 0;
   key = keypad.getKey();
  if(key == 'D')
  {
    lcd.init();
    lcd.setCursor(0,0);
    lcd.println("    SETTINGS    ");
    delay(2000);
    lcd.init();
    lcd.setCursor(0,0);
    lcd.println("  ENTER LENGTH  ");
    
   
      lcd.setCursor(0,1);
    
        while(key != 'C')
    {
      
      key = keypad.getKey();
      if(key)
      {
      if(key != 'C' && all_keys.length() <=2 && key != 'D' && key != 'A' && key != 'B')
      {
        if(all_keys.length() >2)
      {
        lcd.init();
        lcd.setCursor(0,0);
        lcd.println(" LENGTH CANT BE ");
        lcd.setCursor(0,1);
        lcd.println(" GREATER THAN 2 ");
        all_keys = "";
        delay(100);
        
        lcd.init();
        lcd.setCursor(0,0);
        lcd.println(" RE ENTER VALUE ");
        lcd.setCursor(0,1);
      }
        lcd.print(key);
        all_keys += key;
      }
      
      }
      
      
    }
       if(all_keys.length() == 2)
    {
      if(all_keys[0] == '0')
    {
      division = 0;
    }
    if(all_keys[0] == '1')
    {
      division = 10;
    }
    if(all_keys[0] == '2')
    {
      division = 20;
    }
     if(all_keys[0] == '3')
    {
      division = 30;
    }
     if(all_keys[0] == '4')
    {
      division = 40;
    }
    if(all_keys[1] == '1')
    {
      division = division + 1;
    }
     if(all_keys[1] == '2')
    {
      division = division + 2;
    }
     if(all_keys[1] == '3')
    {
      division = division + 3;
    }
     if(all_keys[1] == '4')
    {
      division = division + 4;
    }
     if(all_keys[1] == '5')
    {
      division = division + 5;
    }
     if(all_keys[1] == '6')
    {
      division = division + 6;
    }
     if(all_keys[1] == '7')
    {
      division = division + 7;
    }
     if(all_keys[1] == '8')
    {
      division = division + 8;
    }
     if(all_keys[1] == '9')
    {
      division = division + 9;
    }

  }
   if(all_keys.length()==1)
   {
    if(all_keys == "1")
    {
      division = 1;
    }
    if(all_keys == "2")
    {
      division = 2;
    }
    if(all_keys == "3")
    {
      division = 3;
    }
    if(all_keys == "4")
    {
      division = 4;
    }
    if(all_keys == "5")
    {
      division = 5;
    }
    if(all_keys == "6")
    {
      division = 6;
    }
    if(all_keys == "7")
    {
      division = 7;
    }
    if(all_keys == "8")
    {
      division = 8;
    }
    if(all_keys == "9")
    {
      division = 9;
    }
   }
  division = division*0.25;
  EEPROM.put(0,division);
   dead = division*3 + (division*0.5);
  dead = dead*30.48;
  half = division*3;
  half = half*30.48;
  extreme = division*2;
  extreme = extreme*30.48;
  most_extreme = division;
  most_extreme = most_extreme*30.48;
   lcd.init();
   lcd.setCursor(0,0);
   lcd.print("   DEAD  LEVEL  ");
   lcd.setCursor(0,1);
   lcd.println(dead);
   delay(100);
   lcd.init();
   lcd.setCursor(0,0);
   lcd.print("   HALF  LENGTH   ");
   lcd.setCursor(0,1);
    lcd.println(half);
    delay(100);
     lcd.init();
   lcd.setCursor(0,0);
   lcd.print(" EXTREME LENGTH ");
   lcd.setCursor(0,1);
    lcd.println(extreme);
    delay(100);
     lcd.init();
   lcd.setCursor(0,0);
   lcd.print("  MOST EXTREME  ");
   lcd.setCursor(0,1);
    lcd.println(most_extreme);
    delay(100);
    
   
    
    
  }
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the response from the HC-SR04 Echo Pin
 
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0343;
  
  // Send results to Serial Monitor
 
 
  if (distance <= most_extreme ) {
    noTone(buzzer);
   digitalWrite(yellow_led,LOW);
  digitalWrite(red_led,LOW);
    lcd.init();
    lcd.setCursor(0,0);
     lcd.print("   OVER  FLOW   ");
  lcd.setCursor(0,0);
  if(counter3 == 0)
  {
   
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
  }
  counter3 = 1;
  counter4 = 0;
   digitalWrite(green_led,HIGH);
   
 
  
  }
  if(distance >half && distance <=dead)
  {
     digitalWrite(red_led,LOW);
  digitalWrite(green_led,LOW);
  noTone(buzzer);
    lcd.init();
    lcd.setCursor(0,0);
    lcd.print("   HALF LEVEL   ");
  lcd.setCursor(0,0);
  digitalWrite(yellow_led,HIGH);
 
 
  
  }
   if(distance >extreme && distance <=half)
  {
     digitalWrite(red_led,LOW);
  digitalWrite(green_led,LOW);
  noTone(buzzer);
    lcd.init();
    lcd.setCursor(0,0);
    lcd.print(" EXTREME  LEVEL ");
  lcd.setCursor(0,0);
  digitalWrite(yellow_led,HIGH);
 
 
  
  }
  if(distance >=dead )
  {
    
  noTone(buzzer);
   digitalWrite(yellow_led,LOW);
  digitalWrite(green_led,LOW);
    lcd.init();
    lcd.setCursor(0,0);
    lcd.println("   DEAD LEVEL   ");
  lcd.setCursor(0,0);
  if (counter4 == 0)
  {
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
  }
  counter4 = 1;
  counter3 = 0;
   digitalWrite(red_led,HIGH);
  
 
  }
  

  delay(500);

   }
   
