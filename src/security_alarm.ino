#include <LiquidCrystal.h>

#define LED_PIN 2
#define BUTTON_PIN 3
#define ALARM_PIN 4

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
bool alarmTriggered = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(ALARM_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Alarm Secur");
}

void loop() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    alarmTriggered = true;
  }
  if (alarmTriggered) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(ALARM_PIN, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Alarm Breached");
  }
  else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(ALARM_PIN, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Alarm Secure");
  }
}
