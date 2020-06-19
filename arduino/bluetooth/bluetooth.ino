String voice;
#define led 13
#define relay 7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(relay,OUTPUT);
  digitalWrite(relay,HIGH);
  voice = "";
}

void loop() { 
  
  // put your main code here, to run repeatedly:
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  } 
  
  if (voice.length() > 0) {
    Serial.println(voice);
//-----------------------------------------------------------------------//   
  //----------Control Multiple Pins/ LEDs----------// 
       if(voice == "on") {
        digitalWrite(led,HIGH);
        digitalWrite(relay,LOW);
       voice = "";
       }  
        if(voice == "reset") {
        digitalWrite(led,HIGH);
        digitalWrite(relay,HIGH);
       voice = "";
       Serial.end();
       Serial.begin(9600);
        }
  else if(voice == "of"){
    digitalWrite(led,LOW);
    digitalWrite(relay,HIGH);
    voice = "";
    }
 


voice=""; //Reset the variable after initiating
}

}
