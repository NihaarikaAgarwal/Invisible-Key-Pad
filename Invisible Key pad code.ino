#include <Servo.h>
Servo myservo; 
int pos = 0;   
int a[4];
int set[4] = {1,2,2,1} ;
int digitNo =0 ;
int flag =0 ; 
int entered = 0 ;
int present_time = 0 ;
int period = 6000; 
void setup() {
  //pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(5,INPUT);
  pinMode(11,INPUT);
 // myservo.attach(11);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //int IRS1 = digitalRead(5);
  int IRS1 = digitalRead(5);
  int IRS2 = digitalRead(6);
  int IRS3 = digitalRead(7);
  int IRS4 = digitalRead(8);
  int IRS5 = digitalRead(9);
  int IRS6 = digitalRead(11);
 if(IRS1==0){
  if(IRS4==0)
  {
      entered =1;
      flag++;
    }
    if(IRS5==0)
    {
      entered =2;
      flag++;
    }
    if(IRS6==0)
    {
      entered =3;
      flag++;
    }
 }
  if(IRS2==0){
  if(IRS4 == 0){
      entered=3;
      flag++;
    }
    if(IRS5 == 0){
     entered=4;
      flag++;
    }
    if(IRS6 == 0){
      entered=6;
      flag++;
    }
}
else if(IRS3==0){
  if(IRS4 == 0){
      entered=7;
      flag++;
    }
    if(IRS5 == 0){
      entered=8;
      flag++;
    }
    if(IRS6 == 0){
      entered =9;
      flag++;
  }
}
else{
    flag=0;
      
}
if (flag==1){
 a[digitNo]= entered;
 Serial.print(" a[entered] = ");Serial.print( a[digitNo]);Serial.print( "at");Serial.println( digitNo); 
 flag = 0;
 digitNo ++;
}
if(digitNo == 4){

  int check =0 ;
  flag  = 0;
  digitNo = 0;
  for(int i=0;i<4;i++){
    if(a[i] == set[i]){
      check ++;
    }
    else{
      Serial.print( "incorrect pin" );
      break;
    }
    if(check == 4){
      Serial.println("correct pin");
      for (pos = 0; pos <= 180; pos += 1)
      {
        myservo.write(pos);              
       delay(15);                       
      }
      for (pos = 180; pos >= 0; pos -= 1) 
      {
       myservo.write(pos);              
       delay(15); 
      }                     
    }
  }
}

//delay(1500);
while(millis() > present_time + period){
  present_time = millis();
  Serial.println("session expired");
  digitNo = 0;
  break ;
}
delay(100);
}
