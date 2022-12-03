#include <SoftwareSerial.h>
#define led 12

int in1 = 8; 
int in2 = 9; 
int in3 = 10; 
int in4 = 11;

SoftwareSerial mySerial(3, 2);
int st;
void setup() {
  pinMode(4,INPUT);
  pinMode(3, INPUT);
  pinMode(2, OUTPUT);
  pinMode (led, OUTPUT);
  pinMode (in1, OUTPUT); 
  pinMode (in2, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  mySerial.println("AT");
  mySerial.println("AT+CMGF=1");
  delay(1000);
}

void loop() {
  st = digitalRead(4);
  if(st == 1){
    digitalWrite(led, LOW);
    digitalWrite(in1, HIGH); 
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH); 
    digitalWrite(in4, LOW);
   
  }
  else{
    Serial.println("OK");
    SendSMS("ALERT!! DRUNKEN STATE");
    digitalWrite(led, HIGH);
    digitalWrite(in1, LOW); 
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW); 
    digitalWrite(in4, LOW);

    
  }
}
void SendSMS(String msg) {
  mySerial.println("AT+CMGS=\"+919032270322\"\r"); 
  delay(1000);
  mySerial.println(msg);
  delay(200);
  mySerial.println((char)26);
  delay(1000); 
}
