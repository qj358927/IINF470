
int motorLeft = 9;
int motorRight= 10;
int lightRight = 2;
int lightLeft = 1;
void setup()
{
  // Set up the motor pin to be an output:

  pinMode(motorLeft, OUTPUT);
  pinMode(motorRight,OUTPUT);
  // Set up the serial port:

  Serial.begin(9600);
}

void loop(){
  motorOn(motorLeft,lightLeft);
  motorOn(motorRight,lightRight); 
}

void motorOn(int motorPin,int lpin){
  int lightLevel = analogRead(lpin);
  Serial.print(lightLevel);
  Serial.print("\n");
  if(lightLevel > 700){
    digitalWrite(motorPin, HIGH); // turn the motor on (full speed)
  }else
     digitalWrite(motorPin,LOW);
}
