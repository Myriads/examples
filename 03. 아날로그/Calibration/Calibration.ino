/*
  Calibration (교정 | 보정 | 영점 조정)
 
 센서 입력 값을 교정하는 하나의 기법을 보여주는 예제입니다.
 스케치가 실행될 때 최초 5초 동안 센서 핀에 연결된 센서의
 기대치의 최대 최소 값을 결정하기 위하여 센서를 읽어 들입니다.
 
 센서의 최대 값과 최소 값의 초기 값은 서로 반대로(거꾸로) 되어
 있습니다. 시작할 때, 최소 값을 높게 놓고 낮은 센서 값이 읽히면
 이 값을 새로운 최소 값으로 놓습니다. 이와 같이 최대 값은 낮게
 놓고 새로운 높은 값이 읽히면 이를 새로운 최대 값으로 놓습니다.
 
 회로:
 * 아날로그 센서(포토레지스터)을 아날로그 입력 핀 A0에 연결합니다.
 * 220Ω 저항 한쪽을 디지털 9번 핀에 연결하고 저항 다른 한쪽을 LED의
   아노드(다리가 긴쪽)에 연결합니다. LED의 캐소드(다리가 짧은 쪽)를
   GND에 연결합니다
 
 David A Mellis에 의하여 2008년 10월 29에 창작되었으며
 2011년 08월 30일에 Tom Igoe에 의하여 수정되었습니다.
 
 http://arduino.cc/en/Tutorial/Calibration
 
 이 예제 코드는 공유 저작물입니다.
 
 */

// 이 상수 값들은 결코 변하지 않으며, 사용된 핀들에 이름을 붙여
// 주기 위하여 사용되었습니다:
const int sensorPin = A0;    // 센서가 연결된 핀
const int ledPin = 9;        // LED가 연결된 핀

// 변수들:
int sensorValue = 0;         // 센서 값
int sensorMin = 1023;        // 센서 최소값
int sensorMax = 0;           // 센서 최대값


void setup() {
  // 교정 중이라른 것을 알리기 위하여 LED를 ON합니다:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // 최초 5초 동안 교정을 진행합니다 
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    // 센서 최대값을 기록합니다
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // 센서 최소값을 기록합니다
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  // 교정이 끝났음을 알립니다
  digitalWrite(13, LOW);
}

void loop() {
  // 센서 값을 읽습니다:
  sensorValue = analogRead(sensorPin);

  // 읽어들인 센서 값에 교정값을 적용합니다
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // 교정중에 범위가 넘어간 센서값인 경우에는 0 ~ 255 값으로 제한합니다
  sensorValue = constrain(sensorValue, 0, 255);

  // 교정된 값을 이용하여 PWM 신호를 만들어 LED에 공급합니다:
  analogWrite(ledPin, sensorValue);
}
