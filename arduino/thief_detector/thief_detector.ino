#define trigPin 10
#define echoPin 13

 
float duration, distance;
int buzzer = 11;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer,OUTPUT);
}
 
void loop() {
   
  // Write a pulse to the HC-SR04 Trigger Pin
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the response from the HC-SR04 Echo Pin
 
  duration = pulseIn(echoPin, HIGH);
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  
 distance = (duration / 2) * 0.0343;
  
  
  // Send results to Serial Monitor
 
  Serial.println("Distance = ");
  Serial.println(distance);
  if (distance >= 5) {
     Serial.println("Thief");
     tone(buzzer,200);
     delay(50);
     noTone(buzzer);
     delay(50);
     tone(buzzer,200);
     
  }
  else {
    Serial.println(distance);
    Serial.println(" no thief");
    delay(500);
  }
  delay(500);
}
