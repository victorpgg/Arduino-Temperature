#include <OneWire.h>
#include <DallasTemperature.h>
 
#define K1 4
#define K2 5
#define K3 6
#define sensorProx 2
#define ONE_WIRE_BUS 3

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress sensor1;
float temp=0;
float kp=50, ki=0.1, kd=1;
float p=0, i=0, d=0, pid=0;
float  erro=0, t=0, setpoint=70;
 
void setup()
{
    Serial.begin(9600);
    sensors.begin();  
    pinMode(K1, OUTPUT);
    pinMode(K2, OUTPUT);
    pinMode(K3, OUTPUT);
    pinMode(sensorProx, INPUT_PULLUP);
    digitalWrite(K1, LOW);
    digitalWrite(K2, LOW);
    digitalWrite(K3, LOW);
    attachInterrupt(digitalPinToInterrupt(sensorProx), flag, FALLING);
}

void loop()
{
    if(millis()%10000==0)
    {
      sensors.requestTemperatures();
      temp = sensors.getTempC(sensor1);
      Serial.print(temp);
      erro=setpoint-temp;
      float delta = ((millis()-t))/1000;
      t = millis();
      p = kp*erro;
      i = ki*erro*delta;
      d = (kd*erro)/delta;
      pid = p + i + d;
      if(pid<0)
      {
        digitalWrite(K1, LOW);
        digitalWrite(K2, LOW);
        digitalWrite(K3, LOW);
      }
      else if((pid>0)&&(pid<10))
      {
        digitalWrite(K1, HIGH);
        digitalWrite(K2, LOW);
        digitalWrite(K3, LOW);
      }
      else if((pid>10)&&(pid<50))
      {
        digitalWrite(K1, HIGH);
        digitalWrite(K2, HIGH);
        digitalWrite(K3, LOW);
      }
      else
      {
        digitalWrite(K1, HIGH);
        digitalWrite(K2, HIGH);
        digitalWrite(K3, HIGH);
      }
    }   
}

void flag()
{
  Serial.print("FLAG");
}
