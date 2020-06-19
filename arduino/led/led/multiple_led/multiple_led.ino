int led = 13;
int led2 = 12;
int led3 = 11;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
}
int counter = 0;
void loop() {
  // put your main code here, to run repeatedly:
  
digitalWrite(led,HIGH);
delay(50);
digitalWrite(led,LOW);
delay(50);
digitalWrite(led,HIGH);
delay(50);
digitalWrite(led,LOW);
delay(50);
digitalWrite(led2,HIGH);
delay(50);
digitalWrite(led2,LOW);
delay(50);
digitalWrite(led2,HIGH);
delay(50);
digitalWrite(led2,LOW);
delay(50);
digitalWrite(led3,HIGH);
delay(50);
digitalWrite(led3,LOW);
delay(50);
digitalWrite(led3,HIGH);
delay(50);
digitalWrite(led3,LOW);
delay(50);
}
