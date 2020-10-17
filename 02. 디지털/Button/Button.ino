/*
  Button

 디지털 2번 핀에 연결된 푸시버튼을 눌렀을 때, 디지털 13번 핀에
 연결된 LED(빛을 내는 다이오드:light emitting diode)를 키고 끕니다.

 회로:
 * LED를 보호할 저항 220 Ohm을 13번 핀에 연결하고, LED의 아노드와 저항을
   연결하고 LED 캐소드를 GND에 연결합니다.
 * 푸시버튼을 +5V와 디지털 2번 핀과 연결합니다
 * 10K 저항을 디지털 2번 핀과 접지에 연결합니다
 
 * 노트: 대부분의 아두이노 보드들은 LED가 이미 있으며, 핀 13에 연결
         되어 있습니다. 아두이노 보드의 LED를 이용한다면, 별도의 LED와
         저항 그리고 점퍼선들이 필요없습니다.
         
 2005년 DojoDave <http://www.0j0.org>에 의하여 창작되었으며
 2011년 8월 30일에 Tom Igoe에 의하여 수정되었습니다

 이 예제 코드는 공유 저작물입니다.

 http://www.arduino.cc/en/Tutorial/Button
 */

// 
// constants로 선언된 값들은 변경되지 않습니다. 여기에선 핀 번호를
// 나타내기 위한 변수들로 사용되었습니다. 
const int buttonPin = 2;     // 푸시 버튼 핀 번호
const int ledPin =  13;      // LED 핀 번호

// 값이 변화되는 변수들:
int buttonState = 0;         // 푸시버튼 상태를 읽어 들이기 위한 변수

void setup() {
  // LED 핀을 출력으로 초기화합니다:
  pinMode(ledPin, OUTPUT);
  // 푸시버튼 핀을 입력으로 초기화합니다:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // 푸시버튼 상태 값을 읽습니다:
  buttonState = digitalRead(buttonPin);

  // 푸시버튼이 눌렸는지를 buttonState 값이 
  // HIGH인지를 확인하여 조사합니다:
  if (buttonState == HIGH) {
    // buttonState 값이 HIGH이면 눌린 것으로 LED를 킵니다:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // 만약 푸시버튼이 눌리지 않았다면, LED를 끔니다:
    digitalWrite(ledPin, LOW);
  }
}
