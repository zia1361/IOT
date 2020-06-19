void setup() {
Serial.begin(9600);
 
  pinMode(7, OUTPUT);
  digitalWrite(7,HIGH);// put your setup code here, to run once:
 }

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
   {     
      char data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case 'a': digitalWrite(7,LOW);break; // when a is pressed on the app on your smart phone
        case 'b': digitalWrite(7,HIGH);break; // when d is pressed on the app on your smart phone
        default : break;
      }
   
   }
  
}
