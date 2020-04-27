#include<SoftwareSerial.h>
#include<String.h>
SoftwareSerial BT (2,3);// RX,TX
char com; 
String input;
class motor{
  public:
  int in1,in2;
  motor(int a,int b){
    in1 = a; in2 =b;    
  }
  void drive(int a,int b){
    analogWrite(in1,a);
    analogWrite(in2,b);
  }
};

motor moto1(10,11),moto2(5,6);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Good Morning");
  BT.begin(9600);
  BT.print("Good Morning");
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}       

void loop() {
  if(BT.available()>0){
    input="";
    while(BT.available()>0){
      com = BT.read();//Serial.println(com);
    
    input = input + com;}}
   // Serial.println(com); //control signals from external bluetooth device.   
  
  
  else{
    Serial.println(input);
  //Serial.print(com);
  
  if((input)=="*forward#")
   // case "*forward#":
   { moto1.drive(255,0);moto2.drive(255,0);}
    else if((input)=="*left#")
    //case "*left#":
   { moto1.drive(255,0);moto2.drive(0,0);}
    else if((input)=="*right#")
    //case "*right#":
   { moto1.drive(0,0);moto2.drive(255,0);}
    else if((input)=="*stop#")
    { moto1.drive(0,0);moto2.drive(0,0); }  
    //case "*back#":
    else if((input)=="*back#")
   { moto1.drive(0,255);moto2.drive(0,255);}
   else if((input)=="*slow#")
   {moto1.drive(127,0);moto2.drive(127,0);}
   }
} 
