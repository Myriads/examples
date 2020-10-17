/*
  Arrays (배열)
 
 핀 번호를 저장하고 있는 배열의 사용법을 보여주는 예제이며,
 차례로 핀들에 연결되어 있는 LED를 켜고 다시 끄는 것을 보여
 줍니다.
 
 Loop 예제(강좌)에서는 핀 번호들이 연속 되어 있어야 하는
 것과는 다르게, 여기에서는 핀 번호들이 섞여 있어도 됩니다.
 
 회로:
 * LED를 디지털 2번 핀에서 7번 핀에 연결하고 GND에 연결합니다
 
 2006년 David A. Mellis에 의하여 창작되었으며
 2011년 08월 30일 Tom Igoe에 의하여 수정되었습니다 

이 예제 코드는 공유 저작물입니다.
 
 http://www.arduino.cc/en/Tutorial/Array
 */

int timer = 100;            // 값이 클수록, 시간이 느려집니다.
int ledPins[] = { 
  2, 7, 4, 6, 5, 3 };       // LED가 연결된 핀들 번호를 지닌 배열
// int pinCount = 6;        // 핀들 수 (즉 배열의 크기를 의미)

// 핀들 수를 직접 숫자로 넣는 것보다 배열의 크기를 바로 얻어 이를 
// 이용하는 방법이 있습니다. 바로 sizeof() 함수를 이용하는 것입니다.
// sizeof(int)로 나누어 준 것은 ledPins의 요소들이 integer 값이기
// 때문입니다.
int pinCount = sizeof(ledPins)/sizeof(int);

void setup() {
  // 배열의 요소들에 0에서 (pinCount - 1)의 번호를 부여하고,
  // for 반복문을 이용하여 각 핀들을 출력핀으로 설정합니다:
  for (int thisPin = 0; thisPin < pinCount; thisPin++)  {
    pinMode(ledPins[thisPin], OUTPUT);
  }
}

void loop() {
  // 배열의 맨 앞에 있는 핀에서 맨 끝에 있는 핀까지 반복합니다:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) { 
    // 핀을 HIGH로 만들어 LED를 켭니다:
    digitalWrite(ledPins[thisPin], HIGH);   
    delay(timer);                  
    // LED를 끕니다:
    digitalWrite(ledPins[thisPin], LOW);
  }

  // 배열의 맨 끝에 있는 핀에서 맨 앞에 있는 핀까지 반복합니다:
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) { 
    // LED를 켭니다:
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer);
    // LEd를 끕니다:
    digitalWrite(ledPins[thisPin], LOW);
  }
}
