const int button1 = 8; //switched
const int button2 = 12;
const int button3 = 13;//switched
const int light1 = 7;
const int light2 = 4;
const int light3 = 2;
const int speaker = 11;

int freq1 = 150;
int freq2 = 300;
int freq3 = 450;

int light[3] = {
  light1, light2, light3};
int button[3] = {
  button1, button2, button3};
int i = 0;
int array[5];

void setup()
{
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(light3, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(speaker, OUTPUT);
}



void loop()
{
  int k=0;
  int temp;

  
  tone(speaker,1000,500);
  delay(500);
  tone(speaker,750,500);
  delay(500);
  tone(speaker,1110,500);
  delay(500);
  
  for(int i = 0; i< 5; i++){
    temp = random(3);
    array[i] = temp;
    digitalWrite(light[temp],HIGH);
    delay(1000);
    digitalWrite(light[temp],LOW);
    delay(100);
  }  
  //LIGHTS
  /*
  while(i < 5){
   
   int temp =  random(3);
   array[i] = temp;
   
   if(temp == 0){
   digitalWrite(light1,HIGH);
   delay(1000);
   digitalWrite(light1,LOW);
   delay(1000);      
   }
   else if(temp == 1){
   digitalWrite(light2,HIGH);
   delay(1000);
   digitalWrite(light2,LOW);
   delay(1000);      
   }
   else{
   digitalWrite(light3,HIGH);
   delay(1000);
   digitalWrite(light3,LOW);
   delay(1000);
   }
   i++;
   }*/

  boolean btn1Last = false;
  boolean btn2Last = false;
  boolean btn3Last = false;
  while(k < 5){  
    //BUTTONS
    int btn1 = digitalRead(button[0]);
    int btn2 = digitalRead(button[1]);
    int btn3 = digitalRead(button[2]);
    if(btn1 != LOW)
      btn1Last = false;
    if(btn2 != LOW)
      btn2Last = false;
    if(btn3 != LOW)
      btn3Last = false;



    if(btn1 == LOW && btn1Last != true){
      btn1Last = true;
      lightSound(light3,freq3);
      if(array[k++] == 2)
        delay(100);
      else{
        i=0;
        fail();
        k = 6; 
      }
    }
    if(btn2 == LOW && btn2Last != true){
      lightSound(light2,freq2);
      if(array[k++] == 1)
        delay(100);
      else{
        i=0;
        k = 6;
        fail();
      }
    }
    if(btn3 == LOW && btn3Last != true){
      lightSound(light1,freq1);
      if(array[k++] == 0)
        delay(100);
      else{
        fail();
        i=0;
        k = 6;
      }
    }//end ifblocks
  }//end while
  if(k == 5){
    party(); 
  }

}

void lightSound(int light,int freq){
  digitalWrite(light,HIGH);
  tone(speaker,freq,500);
  delay(1000);
  digitalWrite(light,LOW);
  delay(100); 
}

void fail(){


  digitalWrite(light1,HIGH);
  digitalWrite(light2,HIGH);
  digitalWrite(light3,HIGH);
  delay(500);
  tone(speaker,500,500);
  delay(500);
  tone(speaker,100,500);
  delay(500);
  tone(speaker,50,500);
  delay(500);
  digitalWrite(light1,LOW);
  digitalWrite(light2,LOW);
  digitalWrite(light3,LOW);
  delay(100);
}

void party(){
  for(int k = 0;k<10;k++)
  {
    digitalWrite(light1,HIGH);
    delay(100);
    digitalWrite(light1,LOW);
    tone(speaker,650,50);
    delay(100);
    digitalWrite(light2,HIGH);
    delay(100);
    digitalWrite(light2,LOW);
    tone(speaker,750,50);
    delay(100);
    digitalWrite(light3,HIGH);
    delay(100);
    digitalWrite(light3,LOW);
    tone(speaker,650,50);
    delay(100);
  }  
}

