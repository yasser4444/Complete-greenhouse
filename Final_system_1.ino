#include <dht.h>
int pumb = 8;
const int moisture_Sensor_pin= A0;
 float moisture_percentage;
  int moisture_sensor_analog_reading;
  #define dht_apin   11 
dht DHT;  // sensor pin S to pin11
void setup() {
  pinMode(pumb,OUTPUT);
  digitalWrite(pumb,LOW);
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  DHT.read11(dht_apin);
  moisture_sensor_analog_reading= analogRead(moisture_Sensor_pin);
  moisture_percentage=(100-(moisture_sensor_analog_reading/1023.00) * 100 ) ;
  delay(5000);
if (moisture_percentage<17 && DHT.temperature<24&& DHT.humidity<30 ){
    Serial.println("Start Pumping\n Irrigation Conditions Violated Note The Plant Immediately");
    digitalWrite(pumb, HIGH);
    
}
}
