#include <LiquidCrystal_I2C.h>

#define TEMP_PIN A0
#define LDR_PIN A1
#define VIB_PIN 2

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

pinMode(VIB_PIN, INPUT_PULLUP);

lcd.init();
lcd.backlight();

Serial.begin(9600);
}

void loop() {

int leituraTemp = analogRead(TEMP_PIN);

float tensao = leituraTemp * (5.0 / 1023.0);
float temperatura = (tensao - 0.5) * 100;

int luminosidade = analogRead(LDR_PIN);

int vibracao = digitalRead(VIB_PIN);

lcd.clear();

lcd.setCursor(0,0);
lcd.print("Temp:");
lcd.print(temperatura,1);
lcd.print("C");

lcd.setCursor(0,1);
lcd.print("Luz:");
lcd.print(luminosidade);

delay(2000);

lcd.clear();

lcd.setCursor(0,0);
lcd.print("Vibracao:");

lcd.setCursor(0,1);

if (vibracao == LOW) {
  lcd.print("NORMAL");
} else {
  lcd.print("ALERTA");
}

delay(2000);
}
