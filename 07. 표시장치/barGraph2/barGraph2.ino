/*
  LED 막대 그래프2 (Bar Graph)

  아날로그 센서 값을 읽어 들이고, 값의 크기에 따라 LED들을 ON하는
  예제입니다. 막대 그래프 표시 장치를 만드는 간단한 방법입니다. 이
  예제에서는 10개의 LED들을 사용하였지만, LED 갯 수 값을 고치고, 
  배열에 있는 핀들 값을 수정하여 키우거나 줄일 수 있습니다.

  이 방법은 아날로그 입력 값에 따라 일련의 디지털 출력 값들을 제어
  하는 용도로 활용될 수 있습니다.

  회로:
    * LED 10개의 어노드(애노드, anode) 핀들을 각각 디지털 핀 2번에서 
     11번까지 연결하고, 각각의 LED 캐소드 핀들을 220Ω 저항들과 연결
     하여 GND로 연결합니다.
    * 가변 저항 1번은 GND, 3번은 +5V, 2번은 A0와 연결합니다.

 2010년 09월 04일 Tom Igoe에 의하여 창작되었으며
 2016년 06월 19일에 수정되었습니다

 이 예제 코드는 공유 저작물입니다.

 http://www.arduino.cc/en/Tutorial/BarGraph
 */


// 상수 값들은 변하지 않습니다:
const int analogPin = A0;   // 가변 저항과 연결된 핀
const int ledCount = 10;    // 막대 그래프에 사용된 LED 수

int ledPins[] = {
  2, 3, 4, 5, 6, 7, 8, 9, 10, 11
};   // LED와 연결된 디지털 출력 핀 번호들


void setup() {
  // LED와 연결된 디지털 핀들을 출력 핀으로 반복하면서 설정합니다:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
}

void loop() {
  // 가변 저항의 값을 읽어 들입니다:
  int sensorReading = analogRead(analogPin);
  // map 함수를 사용하여 센서 값을 0에서 LED 수 사이의 값으로 변환
  // 합니다:
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);

  // 핀 배열 위치 값이 ledLevel 보다 작으면 LED을 ON하고
  // 크면 OFF하는 작업을 진행합니다:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    // 핀 배열 인덱스 값이 ledLevel 값 보다 작으면 ON:
    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    }
    // 핀 배열 인덱스 값이 ledLevel 값 보다 큰 LED들은 모두 OFF:
    else {
      digitalWrite(ledPins[thisLed], LOW);
    }
  }
}

