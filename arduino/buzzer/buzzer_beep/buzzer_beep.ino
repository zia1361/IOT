int buzzer = 13;
int led = 11;
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
noTone(buzzer);

delay(1000);
digitalWrite(led,HIGH);
tone(buzzer,15);

delay(1000);
noTone(buzzer);
}
