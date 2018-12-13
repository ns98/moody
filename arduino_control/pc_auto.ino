const int trig1=2;
const int echo1=3;
const int trig2=4;
const int echo2=5;
long t;
int d,dl,dr,drpr;


void setup() {
  pinMode(trig1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  Serial.begin(9600);

}

void loop() {

  dl=distance(trig1,echo1); // get distance of left sensor
  /*Serial.println(dl);
  delay(500);*/

  
  dr=distance(trig2,echo2); // get distance of right sensor

  if((dl>10&&dr>10)&&(dl<20&&dr<20))
  { 
    Serial.println("Play/Pause");
    delay(800);
  }

   dl=distance(trig1,echo1); 
  dr=distance(trig2,echo2);

  if((dl>40&&dl<50)&&dr==50)
  {
    Serial.println("Rewind");
    delay(500);
  }

   dl=distance(trig1,echo1); 
  dr=distance(trig2,echo2);

  if((dr>40&&dr<50)&&dl==50)
  {
    Serial.println("Forward");
    delay(500);
  }

   dl=distance(trig1,echo1);
  dr=distance(trig2,echo2);

  if(dr<=38&&dl==50)
  { 
    delay(100);
    dr=distance(trig2,echo2);
    if(dr<=38&&dl==50)
    {
      Serial.println("rightlocked");
      drpr=dr;
      while(dr<=40&&dl==50)
      {
        dr=distance(trig2,echo2);
        if((dr-drpr<0))
        {
          Serial.println("Vup");
          delay(500);
        }
        /*if((dr-drpr<0)&&(dr<20))
        {
          Serial.println("Vup");
          delay(500);
         }*/
        if((dr-drpr>0))
        {
          Serial.println("Vdown");
          delay(500);
        }
       /* if((dr-drpr>0)&&(dr>20))
        {
          Serial.println("Vdown");
          delay(500);
        }*/
       if((dr-drpr==0))
        {
          if(dr<20)
          {
            Serial.println("Vup");
            delay(500);
          }
          if(dr>20)
          {
            Serial.println("Vdown");
            delay(500);
          }
        }
        drpr=dr;
      }
    }
    
    
  }
  
   
 
}

// to calculate distance using ultrasonic sensor
int distance(int trig,int echo)
{
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  t=pulseIn(echo,HIGH);
  d=t*0.034/2;
  if(d>50)
  d=50;

  return d;
}
