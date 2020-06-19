String voice;

int room1_light = 7;
int room1_fan = 8;
int room2_light = 9;
int room2_fan = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(room1_light,OUTPUT);
  pinMode(room2_light,OUTPUT);
  pinMode(room1_fan,OUTPUT);
   pinMode(room2_fan,OUTPUT);
  digitalWrite(room1_light,LOW);
  digitalWrite(room1_fan,LOW);
  digitalWrite(room2_light,LOW);
  digitalWrite(room2_fan,LOW);
  
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
       if(voice == "room one light on") {
        digitalWrite(room1_light,HIGH);
       voice = "";
       }  
        if(voice == "room one light off") {
        digitalWrite(room1_light,LOW);
       voice = "";
       } 
        if(voice == "room one fan on") {
        digitalWrite(room1_fan,HIGH);
       voice = "";
       } 
        if(voice == "room one fan off") {
        digitalWrite(room1_fan,LOW);
       voice = "";
       } 
        if(voice == "room to light on") {
        digitalWrite(room2_light,HIGH);
       voice = "";
       } 
        if(voice == "room to light off") {
        digitalWrite(room2_light,LOW);
       voice = "";
       }
       if(voice == "room tu fan off") {
        digitalWrite(room2_fan,LOW);
       voice = "";
       } 
       if(voice == "room to fan on") {
        digitalWrite(room2_fan,HIGH);
       voice = "";
       }  
        if(voice == "reset") {
        digitalWrite(room1_light,LOW);
  digitalWrite(room1_fan,LOW);
  digitalWrite(room2_light,LOW);
  digitalWrite(room2_fan,LOW);
       voice = "";
       Serial.end();
       Serial.begin(9600);
        }
   
 


voice=""; //Reset the variable after initiating
}

}
