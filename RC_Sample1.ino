//
// See. https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/

#include <SoftwareSerial.h>

#define LEFT_WHEEL_PIN1 3
#define LEFT_WHEEL_PIN2 9
#define RIGHT_WHEEL_PIN1 10
#define RIGHT_WHEEL_PIN2 11

#define BT_RX_PIN 8
#define BT_TX_PIN 7

SoftwareSerial bt(BT_RX_PIN, BT_TX_PIN);

void setup() {
  Serial.begin(9600);
  bt.begin(9600);

  pinMode(LEFT_WHEEL_PIN1, OUTPUT);
  pinMode(RIGHT_WHEEL_PIN1, OUTPUT);
  pinMode(LEFT_WHEEL_PIN2, OUTPUT);
  pinMode(RIGHT_WHEEL_PIN2, OUTPUT);

    analogWrite(LEFT_WHEEL_PIN1, 0);
    analogWrite(RIGHT_WHEEL_PIN1, 0);
    analogWrite(LEFT_WHEEL_PIN2, 0);
    analogWrite(RIGHT_WHEEL_PIN2, 0);
}

unsigned long lastChecked = 0;
void loop() {
  unsigned long now = millis();
  if (now - lastChecked > 3000) {
    Serial.println(".");

    analogWrite(LEFT_WHEEL_PIN1, 0);
    analogWrite(RIGHT_WHEEL_PIN1, 0);
    analogWrite(LEFT_WHEEL_PIN2, 0);
    analogWrite(RIGHT_WHEEL_PIN2, 0);

    lastChecked = now;
  }

  if (bt.available()) {
    // Serial.write(bt.read());
    int ch = bt.read();

    switch (ch) {
    case 'L':
      Serial.println("Left");
      analogWrite(LEFT_WHEEL_PIN1, 1023);
      break;
    case 'R':
      Serial.println("Right");
      analogWrite(RIGHT_WHEEL_PIN1, 1023);
      break;
    default:
      Serial.println(ch);
    }
  }
}
