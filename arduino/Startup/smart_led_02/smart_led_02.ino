#define LIGHT 2 // define pint 2 for sensor
#define RELAY 9 // define pin 9 as for relay

/*
 * 
// Writeen by Ahmad S. for Robojax.com on 
// on Freb 10, 2018 at 13:43 at city of Ajax, Ontario, Canada
 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 * 
 */



// LDR, Light Dependant Resistor


boolean digital = true;// set true to use digital and control the sensitiviety with poentiometer on the module
                  // set to false to control with A0 value on Arduino
unsigned int LightValue = 350;// LightValue to determine
                      // at what value the realy should be ON                      

void setup() {
  // Light LDR Sensor Code by Robojax.com 20180210
  Serial.begin(9600);// setup Serial Monitor to display information
  pinMode(LIGHT, INPUT_PULLUP);// define pin as Input  sensor
  pinMode(RELAY, OUTPUT);// define pin as OUTPUT for relay
  digitalWrite(RELAY,HIGH);
}

void loop() {

  delay(500);
  relay();// call the realay() method
 // Light LDR Sensor Code by Robojax.com 20180210
}

void relay()
{
   if(digital == true)
   {
  // Light LDR Sensor Code by Robojax.com 20180210
  int L =digitalRead(LIGHT);// read the sensor 
  
      if(L == 1){
        Serial.println(" light is ON");
        digitalWrite(RELAY,LOW);// turn the relay ON
      }else{
         Serial.println("  === light is OFF");
         digitalWrite(RELAY,HIGH);// turn the relay OFF
      } // if   
   }// if digital end
   else
   {
    int a0Value = analogRead(A0);// read A0 value
    
      if( a0Value >= LightValue){
        Serial.print(analogRead(A0));
        Serial.println(" Light is ON");
        digitalWrite(RELAY,LOW);// turn the relay ON
      }else{
         Serial.print(analogRead(A0));
         Serial.println("  === light OFF");
         digitalWrite(RELAY,HIGH);// turn the relay OFF
      } // if      
   }
}
