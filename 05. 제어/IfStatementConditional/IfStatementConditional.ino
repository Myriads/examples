/*
  Conditionals - If statement
  (조건문들 - if 문)
  
 이 예제는 if() 조건문의 사용법을 보여 주고 있습니다. 아날로그 입력
 핀에 연결되어 있는 가변저항 센서 값을 읽어 들여, 값이 특정 임계치
 (threshold) 값 보다 크면 LED를 켭니다. 그리고 값의 크기에 상관없이
 시리얼 모니터로 출력합니다.
  
 회로:
 * 가변저항의 가운데 핀을 아날로그 핀 0에 연결하고, 옆에 있는 2핀은
 각각 +5V와 GND에 연결합니다.
 * LED를 디지털 13번 핀에 연결하고 LED 캐소드를 GND에 연결합니다.
 
 * 노트: 대부분의 아두이노 보드에는 디지털 13번 핀에 LED가 이미
 연결되어 있어, 이 예제에서는 LED를 따로 준비할 필요가 없습니다.
 
 2009년 01월 17일 창작되었으며,
 2012년 04월 09일에 Tom Igoe에 의하여 수정되었습니다

이 예제 코드는 공유 저작물입니다.

http://arduino.cc/en/Tutorial/IfStatement
 
 */
 
// 이 상수들(constant)은 결코 변하지 않습니다:
const int analogPin = A0;    // 가변저항 센서가 연결된 핀
const int ledPin = 13;       // LED가 연결된 핀
const int threshold = 400;   // 아날로그 입력 값의 범위에 있는 임의의
                             // 임계치 값

void setup() {
  // LED 핀을 출력핀으로 설정합니다:
  pinMode(ledPin, OUTPUT);
  // 시리얼 통신을 위하여 초기화합니다:
  Serial.begin(9600);
}

void loop() {
  // 가변저항 값을 읽어 들입니다:
  int analogValue = analogRead(analogPin);

  // 아날로그 입력 값이 임계치 값보다 크면, LED를 켭니다:
  if (analogValue > threshold) {
    digitalWrite(ledPin, HIGH);
  } 
  else {
    digitalWrite(ledPin,LOW); 
  }

  // 읽어들인 아날로그 센서 값을 출력합니다:
  Serial.println(analogValue);
  delay(1);        // ADC(Analog-Digital Converter)가 다음
                   // 동작을 할 수 있게 쉬는 시간을 갖습니다.
}

