//
// See. https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/

#include <SoftwareSerial.h>

#define LEFT_WHEEL_PIN1 10
#define LEFT_WHEEL_PIN2 11
#define RIGHT_WHEEL_PIN1 3
#define RIGHT_WHEEL_PIN2 9

#define BT_RX_PIN 8
#define BT_TX_PIN 7

// 0~255
#define POWER_MAX 255
#define POWER_MID 127
#define POWER_OFF 0

SoftwareSerial bt(BT_RX_PIN, BT_TX_PIN);

void setup() {
  // 디버깅을 위한 Serial 오픈
  Serial.begin(9600);

  // 블루투스 모듈 시작
  bt.begin(9600);

  // 바퀴 핀 모드를 출력으로 설정
  pinMode(LEFT_WHEEL_PIN1, OUTPUT);
  pinMode(RIGHT_WHEEL_PIN1, OUTPUT);
  pinMode(LEFT_WHEEL_PIN2, OUTPUT);
  pinMode(RIGHT_WHEEL_PIN2, OUTPUT);

  // 정지
  analogWrite(LEFT_WHEEL_PIN1, POWER_OFF);
  analogWrite(RIGHT_WHEEL_PIN1, POWER_OFF);
  analogWrite(LEFT_WHEEL_PIN2, POWER_OFF);
  analogWrite(RIGHT_WHEEL_PIN2, POWER_OFF);
}

unsigned long checked = 0;
void loop() {
  // 2초 동안 추가 입력이 없으면 정지
  unsigned long now = millis();
  if (now - checked > 2000) {
    Serial.println(".");

    analogWrite(LEFT_WHEEL_PIN1, POWER_OFF); // Off
    analogWrite(RIGHT_WHEEL_PIN1, POWER_OFF);
    analogWrite(LEFT_WHEEL_PIN2, POWER_OFF);
    analogWrite(RIGHT_WHEEL_PIN2, POWER_OFF);

    checked = now;
  }

  // 블루투스로 읽어들일 내용이 존재하는 경우
  if (bt.available()) {
    int ch = bt.read();

    switch (ch) {
      case 'U': // 전진
        checked = now;
        Serial.println("UP");
        analogWrite(LEFT_WHEEL_PIN1, POWER_MAX); // On(MAX!)
        analogWrite(RIGHT_WHEEL_PIN1, POWER_MAX);
        break;
      case 'L': // 좌회전
        checked = now;
        Serial.println("Left");
        analogWrite(LEFT_WHEEL_PIN1, POWER_MAX);
        analogWrite(RIGHT_WHEEL_PIN1, POWER_MID);
        break;
      case 'R': // 우회전
        checked = now;
        Serial.println("Right");
        analogWrite(LEFT_WHEEL_PIN1, POWER_MID);
        analogWrite(RIGHT_WHEEL_PIN1, POWER_MAX);
        break;
      default:
        Serial.println(ch);
    }
  }
}

// @TODO. 양쪽 바퀴에 걸리는 힘 차이를 보정하기 위해 양쪽 바퀴에 대한 analogWrite 값을 다르게 설정. POWER_MID를 0으로 변경하면 확인이 용이
// @TODO. 후진 기능 추가
// @TODO. Bluetooth STAT 핀을 이용해 연결 여부 표시
