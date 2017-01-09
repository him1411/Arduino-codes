int lm1=6;
int lm2=9;
int rm1=11;
int rm2=10;


void setup()
{
pinMode(lm1,OUTPUT);
pinMode(lm2,OUTPUT);
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);
}

void loop()
{
digitalWrite(rm1,HIGH);
digitalWrite(rm2,LOW);
digitalWrite(lm1,HIGH);
digitalWrite(lm2,LOW);
}
