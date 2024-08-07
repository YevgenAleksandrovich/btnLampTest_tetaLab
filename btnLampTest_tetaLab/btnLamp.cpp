#include <Arduino.h>

// іни
const int ledPin = 2;        // Пін для світлодіода (на ESP32)
const int buttonPin = 0;     // Пін для кнопки (P2)

// Налаштування PWM
const int pwmChannel = 0;
const int pwmFrequency = 1000; // Частота PWM
const int pwmResolution = 8;   // Розширення PWM

// Змінні для керування кнопкою
bool ledState = false;        // Статус світлодіода
unsigned long lastButtonPress = 0;  // Час останнього натискання кнопки
const unsigned long debounceDelay = 50;  // Затримка для дебаунсу

// Змінні для PWM
int brightness = 0;         // Яскравість світлодіода
int fadeAmount = 5;         // Крок зміни яскравості
unsigned long lastUpdate = 0;   // Час останнього оновлення яскравості
const unsigned long fadeInterval = 20; // Інтервал оновлення яскравості

void setup() {
  // Налаштування пінів
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  // Налаштування PWM
  ledcSetup(pwmChannel, pwmFrequency, pwmResolution);
  ledcAttachPin(ledPin, pwmChannel);

  // Ініціалізація послідовного порту
  Serial.begin(115200);
}

void loop() {
  // Обробка кнопки
  int buttonState = digitalRead(buttonPin);
  unsigned long currentMillis = millis();
  
  // Перевірка на натискання кнопки
  if (buttonState == LOW && (currentMillis - lastButtonPress) > debounceDelay) {
    lastButtonPress = currentMillis;
    // Перемикання стану світлодіода
    ledState = !ledState;
  }
  
  // Налаштування PWM
  if (ledState) {
    if (currentMillis - lastUpdate >= fadeInterval) {
      lastUpdate = currentMillis;
      brightness += fadeAmount;
      if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
      }
      ledcWrite(pwmChannel, brightness);
    }
  } else {
    // Вимикаємо світлодіод
    ledcWrite(pwmChannel, 0);
  }
}
