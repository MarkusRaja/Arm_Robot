#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int degree1,stat,degree2,degree3,degree4,clickable,ma=0;
int delayau = 20;
void setup()
{
  pinMode(6, INPUT);
  servo1.attach(7);
  servo2.attach(8);
  servo3.attach(9);
  servo4.attach(10);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(5, INPUT);
  digitalWrite(6,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(5,HIGH);
  Serial.begin(9600);
}
void loop()
{
  if(digitalRead(5)==LOW){//manual
    ma = 0;
  }
  else if(digitalRead(5)==HIGH){//matic
    ma = 1;
  }
  if (ma == 0){
    degree1 = ManageButton(4,degree1);
    degree2 = ManageButton(11,degree2);
    degree3 = ManageButton(12,degree3);
    degree4 = ManageButton(3,degree4);
    if(digitalRead(6)==LOW){// to change the direction manually (example : clockwise to counter-clockwise)
      if(clickable == 0){
        if(stat == 1){
         stat = 0;
        }
        else if(stat == 0){
         stat = 1;
        }
        clickable = 1;
      }
    }
    else if(digitalRead(6)==HIGH){
      clickable = 0;
    }
    servo1.write(degree1);
    servo2.write(degree2);
    servo3.write(degree3);
    servo4.write(degree4);
  }
  else{
    
    for(int i = degree4; i <= 30; i++){//kedua dari bawah
      if(digitalRead(5)==LOW){
        ma = 0;
        break;
      }
      servo4.write(i);
      degree4 = i;
      delay(delayau);
    }
    for(int i = degree3; i <= 180; i++){//claw
      if(digitalRead(5)==LOW){
        ma = 0;
        break;
      }
      servo3.write(i);
      degree3 = i;
      delay(delayau);
    }
    for(int i = degree2; i <= 70; i++){//sebelum claw
      if(digitalRead(5)==LOW){
        ma = 0;
        break;
      }
      servo2.write(i);
      degree2 = i;
      delay(delayau);
    }
    for(int i = degree1; i <= 90; i++){//base
      if(digitalRead(5)==LOW){
        ma = 0;
        break;
      }
      servo1.write(i);
      degree1 = i;
      delay(delayau);
    }
    for(int i = degree3; i >= 25; i--){//claw
      if(digitalRead(5)==LOW){
        ma = 0;
        break;
      }
      servo3.write(i);
      degree3 = i;
      delay(delayau);
    }
    for(int i = degree2; i >= 0; i--){//sebelum claw
      if(digitalRead(5)==LOW){
        ma = 0;
        break;
      }
      servo2.write(i);
      degree2 = i;
      delay(delayau);
    }
    for(int i = degree4; i <= 90; i++){//kedua dari bawah
      if(digitalRead(5)==LOW){
        ma = 0;
        break;
      }
      servo4.write(i);
      degree4 = i;
      delay(delayau);
    }
    for(int i = degree1; i <= 135; i++){//base
      if(digitalRead(5)==LOW){
        ma = 0;
        break;
      }
      servo1.write(i);
      degree1 = i;
      delay(delayau);
    }
    for(int i = degree4; i >= 0; i--){//kedua dari bawah
      if(digitalRead(5)==LOW){
        ma = 0;
        break;
      }
      servo4.write(i);
      degree4 = i;
      delay(delayau);
    }
    for(int i = degree2; i <= 70; i++){//sebelum claw
      if(digitalRead(5)==LOW){
        ma = 0;
        break;
      }
      servo2.write(i);
      degree2 = i;
      delay(delayau);
    }
    for(int i = degree3; i <= 180; i++){//claw
      if(digitalRead(5)==LOW){
        ma = 0;
        break;
      }
      servo3.write(i);
      degree3 = i;
      delay(delayau);
    }
    if(ma==1){
       degree1 = 0;
       degree2 = 0;
       degree3 = 0;
       degree4 = 0;
       servo1.write(degree1);
        servo2.write(degree2);
        servo3.write(degree3);
        servo4.write(degree4);
     }
  }
  
}
int ManageButton(int buttonPin, int degree)
{
  if(digitalRead(buttonPin)==LOW){
    if(degree == 0){
        stat = 0;
    }
    else if(degree == 180){
        stat = 1;
    }
    if(stat == 1){
      degree--;
    }
    else if(stat == 0){
      degree++;
    }
    delay(20);
  }return degree;
}
