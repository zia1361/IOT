#include <Keypad.h>
#define trigPin 10
#define echoPin 13
 
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
void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
int counter2 = 0;
  int counter = 0;
  double bottom_length1 = 0;
  double base1 = 0;
  double base2 = 0;
  double middle2 = 0;
  
void loop(){
   key = keypad.getKey();
  if(key == 'D')
  {
    Serial.println("setting wizzard");
    
    Serial.println("set the basement length");
   
    
    
        while(key != 'C')
    {
      
      key = keypad.getKey();
      if(key)
      {
      if(key != 'C' && all_keys.length() <=2)
      {
        Serial.print(key);
        all_keys += key;
      }
      if(all_keys.length() >2)
      {
        Serial.println("length is greaer than 2");
      }
      }
      
      
    }
       if(all_keys.length() == 2)
    {
      if(all_keys[0] == '0')
    {
      bottom_length1 = 0;
    }
    if(all_keys[0] == '1')
    {
      bottom_length1 = 10;
    }
    if(all_keys[0] == '2')
    {
      bottom_length1 = 20;
    }
    if(all_keys[1] == '1')
    {
      bottom_length1 = bottom_length1 + 1;
    }
     if(all_keys[1] == '2')
    {
      bottom_length1 = bottom_length1 + 2;
    }
     if(all_keys[1] == '3')
    {
      bottom_length1 = bottom_length1 + 3;
    }
     if(all_keys[1] == '4')
    {
      bottom_length1 = bottom_length1 + 4;
    }
     if(all_keys[1] == '5')
    {
      bottom_length1 = bottom_length1 + 5;
    }
     if(all_keys[1] == '6')
    {
      bottom_length1 = bottom_length1 + 6;
    }
     if(all_keys[1] == '7')
    {
      bottom_length1 = bottom_length1 + 7;
    }
     if(all_keys[1] == '8')
    {
      bottom_length1 = bottom_length1 + 8;
    }
     if(all_keys[1] == '9')
    {
      bottom_length1 = bottom_length1 + 9;
    }



    
   }
   if(all_keys.length()==1)
   {
    if(all_keys == "1")
    {
      bottom_length1 = 1;
    }
    if(all_keys == "2")
    {
      bottom_length1 = 2;
    }
    if(all_keys == "3")
    {
      bottom_length1 = 3;
    }
    if(all_keys == "4")
    {
      bottom_length1 = 4;
    }
    if(all_keys == "5")
    {
      bottom_length1 = 5;
    }
    if(all_keys == "6")
    {
      bottom_length1 = 6;
    }
    if(all_keys == "7")
    {
      bottom_length1 = 7;
    }
    if(all_keys == "8")
    {
      bottom_length1 = 8;
    }
    if(all_keys == "9")
    {
      bottom_length1 = 9;
    }
   }
   base2 = bottom_length1*30.48;
   Serial.println();
   Serial.print(" the length of basement is: ");
   Serial.println(base2);
   Serial.println("set the upper length");
   
       key = all_keys[0];
    all_keys = "";
    bottom_length1 = 0;
        while(key != 'C')
    {
      
      key = keypad.getKey();
      if(key)
      {
      if(key != 'C' && all_keys.length() <=2)
      {
        Serial.print(key);
        all_keys += key;
      }
      if(all_keys.length() >2)
      {
        Serial.println("length is greaer than 2");
      }
      }
      
      
    }
       if(all_keys.length() == 2)
    {
      if(all_keys[0] == '0')
    {
      bottom_length1 = 0;
    }
    if(all_keys[0] == '1')
    {
      bottom_length1 = 10;
    }
    if(all_keys[0] == '2')
    {
      bottom_length1 = 20;
    }
    if(all_keys[1] == '1')
    {
      bottom_length1 = bottom_length1 + 1;
    }
     if(all_keys[1] == '2')
    {
      bottom_length1 = bottom_length1 + 2;
    }
     if(all_keys[1] == '3')
    {
      bottom_length1 = bottom_length1 + 3;
    }
     if(all_keys[1] == '4')
    {
      bottom_length1 = bottom_length1 + 4;
    }
     if(all_keys[1] == '5')
    {
      bottom_length1 = bottom_length1 + 5;
    }
     if(all_keys[1] == '6')
    {
      bottom_length1 = bottom_length1 + 6;
    }
     if(all_keys[1] == '7')
    {
      bottom_length1 = bottom_length1 + 7;
    }
     if(all_keys[1] == '8')
    {
      bottom_length1 = bottom_length1 + 8;
    }
     if(all_keys[1] == '9')
    {
      bottom_length1 = bottom_length1 + 9;
    }



    
   }
   if(all_keys.length()==1)
   {
    if(all_keys == "1")
    {
      bottom_length1 = 1;
    }
    if(all_keys == "2")
    {
      bottom_length1 = 2;
    }
    if(all_keys == "3")
    {
      bottom_length1 = 3;
    }
    if(all_keys == "4")
    {
      bottom_length1 = 4;
    }
    if(all_keys == "5")
    {
      bottom_length1 = 5;
    }
    if(all_keys == "6")
    {
      bottom_length1 = 6;
    }
    if(all_keys == "7")
    {
      bottom_length1 = 7;
    }
    if(all_keys == "8")
    {
      bottom_length1 = 8;
    }
    if(all_keys == "9")
    {
      bottom_length1 = 9;
    }
   }
   middle2 = bottom_length1*30.48;
   Serial.println();
   Serial.print(" the upper length is: ");
    Serial.println(middle2);
    Serial.println();
   
    
    
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
 
 
  if (distance <= middle2 ) {
     Serial.println("green");
  }
  if(distance >middle2 && distance <=base2)
  {
    Serial.println("yellow");
  }
  if(distance >=base2 )
  {
    Serial.println("red");
  }
  

  delay(500);

   }
   
