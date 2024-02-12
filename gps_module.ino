#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

const int RXPin = 3, TXPin = 4;
const uint32_t baud = 9600;
char c;

TinyGPSPlus gps;
SoftwareSerial gpsSerial(RXPin, TXPin);
unsigned long start = 0;


LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  Serial.begin(baud);
  gpsSerial.begin(baud);
  Serial.println("GPS MODULE:");
  lcd.init();
  lcd.backlight();
}

void loop() {
    afisare();
}

void afisare(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("sateliti: " + String(gps.satellites.value()));
  lcd.setCursor(0, 1);
  lcd.print("ora: " + String(gps.time.hour()) + ":" + String(gps.time.minute()) + ":" + String(gps.time.second()));

  delay(700);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("lat: " + String(gps.location.lat()));
  lcd.setCursor(0, 1);
  lcd.print("long: " + String(gps.location.lng()));
  delay(1500);
}
