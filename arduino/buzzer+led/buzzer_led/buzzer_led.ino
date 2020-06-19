int buzzer = 13;
int led = 11;
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(11,OUTPUT);
}

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
digitalWrite(led,HIGH);









}
