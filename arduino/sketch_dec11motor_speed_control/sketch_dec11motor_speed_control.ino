int Motor_Pin =9;

int Motor_value=0;

String BluetoothData;

void setup()
{
  pinMode(Motor_Pin,OUTPUT);

  Serial.begin(9600);
}
int counter = 0;
void loop()
{
  while(Serial.available()){
    char get_char = Serial.read();

  BluetoothData += get_char;
  
  }
 
  if(BluetoothData.length() >=2)
  {
        Motor_value=BluetoothData.toInt();
  }
         
  
    Serial.println(Motor_value);
analogWrite(Motor_Pin,Motor_value);
delay(5000);
analogWrite(Motor_Pin,0);
delay(4000);
counter++;

  
}

 

 
