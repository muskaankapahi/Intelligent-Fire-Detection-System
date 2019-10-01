#include<DHT.h>
#include<SoftwareSerial.h>
SoftwareSerial bt(0,1);
int buzzer=8;
int LED= 7;
//int flame_sensor=4;
int flame_detected;
String input;
DHT dht(4, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bt.begin(9600);
  dht.begin();
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(2, INPUT);
  //pinMode(A2, INPUT);
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(4, INPUT);
  //Serial.begin(96000);
  Serial.println("Testing Now");
  delay(1000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.println("SYSTEM IS ON");
 digitalWrite(10, HIGH);
 delay(1000);
 digitalWrite(10, LOW);
 delay(1000);
 int m=0, temp=0;
m= analogRead(A0);
temp= (m*500)/1023;
 
  flame_detected = digitalRead(2);
  if(flame_detected!=1)
  {
    Serial.println("FLAME DETECTED!! TAKE ACTION IMMEDIATELY");
    //input=bt.readString();
    //Serial.println("FLAME DETECTED!! TAKE ACTION IMMEDIATELY");    
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED, HIGH);
    //delay();
    //digitalWrite(LED, LOW);
    //delay(200);
  }
  else
  {
    Serial.println("NO FLAME DETECTED!! STAY COOL!!");
    digitalWrite(buzzer, LOW);
    digitalWrite(LED, LOW);
  }
delay(1000);

Serial.println("THE TEMPERATURE MEASURED BY DHT 11 IS");
float t= dht.readTemperature();
int tem= (int) t;
Serial.println(t);
Serial.println("THE HUMIDITY MEASURED BY DHT 11  IS");
float h= dht.readHumidity();
int hum= (int) h;
Serial.println(h);
      if(temp<60)
{
  Serial.println("Temperature Recorded by LM-35=>");
  Serial.print(temp);
  Serial.println("   ");
  Serial.println("NO FIRE");
  digitalWrite(9, HIGH);
  delay(1000);  
  digitalWrite(9, LOW);
  delay(1000);
}
if(temp>60)
{
  Serial.println("Temperature Recorded=>");
  Serial.print(temp);
  Serial.println("   ");
  Serial.println("FIRE");
  digitalWrite(buzzer, HIGH);
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
}
}
