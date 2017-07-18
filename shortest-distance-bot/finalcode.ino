#include<Servo.h>

int lm1=8;
int lm2=9;
int rm1=11;
int rm2=12;
long d1,d2;
int s=4;
int trig1=3;
int echo1=2;
int trig2=6;
int echo2=5;
Servo alu;

void setup()
{
Serial.begin(9600);
pinMode(lm1,OUTPUT);
pinMode(lm2,OUTPUT);
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);
pinMode(s,OUTPUT);
pinMode(trig1,OUTPUT);
pinMode(trig2,OUTPUT);
pinMode(echo1,INPUT);
pinMode(echo2,INPUT);
alu.attach(4);
alu.write(85);
 
}

void loop() 
{
int smallest,align_angle,i=0,j=0;
float objects[64];
float w= 189.47,sp=24.73;
alu.write(85);

                    for(i=0;i<32;i++)
                      {
                         alu.write(i*5);
                         delay(250);
                         objects[i]=distance(trig1,echo1);
                         objects[i+32]=distance(trig2,echo2);  
                         Serial.println(i);
                      }
                      Serial.println("Hello");
float x=objects[0],ang;
for (i=0;i<63;i++)
{
   Serial.println(objects[i]);
}
for (i=0;i<63;i++)
{
  x=objects[i];
  if(x!=0)
  {
    break;
  }
  
}
  for(j=1;j<63;j++)
  {
    if (objects[j]==0)
    {
      continue;
    }
    else
    {
      if (objects[j]<x)
      {
      x=objects[j];
      ang=j*5;
      }
  }}
  Serial.println(x);
int l;                    
  for(l=0;l<68;l++)
   { 
    // Serial.println(objects[l]);
   }
align_angle=ang-85;
if (align_angle<0)
{
  align_angle=align_angle*(-1);
}
float num=align_angle/w;
if(align_angle>0)
        {
          Serial.println(num);
          digitalWrite(rm1,LOW);
          digitalWrite(rm2,HIGH);
          digitalWrite(lm1,HIGH);
          digitalWrite(lm2,LOW);
          delay((num*1000));  
          
        }
if(align_angle<0)
        { 
          Serial.println(num);
          digitalWrite(rm1,HIGH);
          digitalWrite(rm2,LOW);
          digitalWrite(lm1,LOW);
          digitalWrite(lm2,HIGH);
          delay((num*8000)); 
          
        }
float ti=x/sp;
Serial.println(ti);
{ 
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  delay(ti*5000 ); 
}


Serial.println("end");
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  delay(1000);

}


float distance(int trigPin,int echoPin)
{
  double duration;
  long distance;
  digitalWrite(trigPin,LOW); 
  delayMicroseconds(2); 

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100); 
  
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
 

  distance = duration/58.2;
  return distance;  
}

