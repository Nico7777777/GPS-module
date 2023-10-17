#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

const int RXPin = 3, TXPin = 4;
const uint32_t baud = 9600;
char c;

TinyGPSPlus gps;
SoftwareSerial gpsSerial(RXPin, TXPin);
unsigned long start = 0;

/*static void smartDeplay(unsigned long ms){
  unsigned long start = millis();
  do{
    while(gpsSerial.available())
      gpsSerial.encode(gpsSerial.read());
  }while(start - millis() < ms);
}*/

void setup() {
  Serial.begin(baud);
  gpsSerial.begin(baud);
  Serial.println("GPS MODULE:");
}

void loop() {

  Serial.println("numar sateliti: " + String(gps.satellites.value()));
  Serial.println("latitudine: " + String(gps.location.lat()));
  Serial.println("longitudine: " + String(gps.location.lng()));
  Serial.println("altitudine: " + String(gps.altitude.feet()));

  delay(500);
  
}

void afisare(){
    Serial.println("numar de sateliti:" + String(gps.satellites.value()));
    Serial.print("  ora: " + String(gps.time.hour()) + ":" + String(gps.time.minute()) + ":" + String(gps.time.second()));
    Serial.print("  latitudine:" + String(gps.location.lat()));
    Serial.print("  longitudine: " + String(gps.location.lng()));
}
