int data =0;
#define motor 5

void setup() {
  Serial.begin(9600);
  pinMode(motor,OUTPUT);
}

void loop() {
  if (Serial.available()>0){
    data = Serial.read();
    analogWrite(motor,data);
    Serial.println(data);
  }
}
