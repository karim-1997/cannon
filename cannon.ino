#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
float posa,po=0,pos1,pos2,pos3=0;
const int trigpin = 9;
const int echopin = 11;
float g = 9.81 ;
float v0 = 4.42; 
float duration ,d,distance,dist=0,dista;
int i=0;
int posa1;
void setup() {
  myservo1.attach(3);
   myservo2.attach(5);
   myservo3.attach(6);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
 myservo2.write(90);
     delay(100);
     myservo3.write(0);
     delay(100);
}

void loop() { 
  myservo2.write(80);
    
     myservo3.write(0);
    delay(100);
  for (pos1 = 0;pos1 <= 180;pos1++){
    {myservo1.write(pos1);
    delay(180);
   digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  duration = pulseIn(echopin, HIGH);
  distance = duration *0.034/2; // speed of sound 
    Serial.print("\n ---->  pos1   ");
   Serial.print(pos1);
   
  distance = distance/100;
  Serial.print("\n -------> distance cm  ");
   Serial.print(distance);
       if(distance > 0.4 && distance < 0.6){   po=po+pos1;
                                               i=i+1;
                                               dist=dist+distance;}
                                               
   
  } dista = dist/i;
    posa = po/i;
   
     
    Serial.print("\n ---->  dista   ");
   Serial.print (dista);
   Serial.print("\n ---->  angle   ");
   Serial.print(posa);
     pos2 = asin((g*dista)/(v0*v0))/2;  //EN RADIAN
  pos2 =80-pos2*180/PI;
  Serial.print("\n ---->  2 servo   ");
   Serial.print(pos2);}
 for(posa1 = 180;posa1 > posa;posa1=posa1-1){
                                              myservo1.write(posa1);
                                              delay(100);}
                
                                          myservo2.write(pos2);
                                          delay(1000);
                                          myservo3.write(150);
                                          delay(5000);
  
   
 
}
