int motorLeft = 9;
int motorRight= 10;
int lightRight = 2;
int lightLeft = 1;
int pwrLevel = 200;
int button = 4;
int red = 6, green=5, blue =3;


int limit;
int normal;
void setup()
{
  // Set up the motor pin to be an output:
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(motorLeft, OUTPUT);
  pinMode(motorRight,OUTPUT);
  // Set up the serial port:
  pinMode(button,INPUT);
   
  con();
  Serial.begin(9600);
}

void loop(){
  motorOn(motorLeft,lightLeft,700);
  motorOn(motorRight,lightRight,700); 
}

void motorOn(int motorPin,int lpin,int limit){
  int lightLevel = analogRead(lpin);
  Serial.print(lightLevel);
  Serial.print("\n");
  if(lightLevel > limit){
    analogWrite(motorPin, pwrLevel); // turn the motor on (full speed)
  }else
     analogWrite(motorPin,LOW);
}

void con(){
  digitalWrite(red,HIGH); 
  limit = getLevel(blue); 
  digitalWrite(red,LOW);
  delay(1000);
  normal = getLevel(green);
  digitalWrite(blue,LOW);
   
 }

int getLevel(int led){
  int lvl = 0;
  int btn;
  while(1){
     btn = digitalRead(button); //read from the button input
     
     if(btn == LOW){
      digitalWrite(led,HIGH);
      delay(1000);
      lvl += analogRead(lightRight);
      lvl += analogRead(lightLeft);
      lvl = lvl/2 + 1;
      break; 
     }
  }
  return lvl;
}

