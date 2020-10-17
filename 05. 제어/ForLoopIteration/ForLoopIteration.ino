/*
  For Loop Iteration (for 루프문을 이용한 반복)
 
 for 반복문의 사용 방법을 보여주는 예제입니다. 차례로 여러 LED들을
 켜고 그리고 반대로 끄는 것을 for 반복문을 이용하여 실행합니다.
 
회로:
 * LED를 디지털 2번 핀에서 7번 핀에 연결하고 GND에 연결합니다
 
 2006년 David A. Mellis에 의하여 창작되었으며
 2011년 08월 30일 Tom Igoe에 의하여 수정되었습니다 

이 예제 코드는 공유 저작물입니다.
 
 http://www.arduino.cc/en/Tutorial/ForLoop
 */

int timer = 100;           // 값이 클수록, 시간이 느려집니다.

void setup() {
  // for 반복문을 이용하여 각 핀들을 출력핀으로 설정(초기화)합니다:
  for (int thisPin = 2; thisPin < 8; thisPin++)  {
    pinMode(thisPin, OUTPUT);      
  }
}

void loop() {
  // 가장 낮은 핀에서 가장 높은 핀으로 반복합니다:
  for (int thisPin = 2; thisPin < 8; thisPin++) { 
    // LED를 켭니다:
    digitalWrite(thisPin, HIGH);   
    delay(timer);                  
    // LED를 끕니다:
    digitalWrite(thisPin, LOW);    
  }

  // 가장 높은 핀에서 가장 낮은 핀으로 반복합니다:
  for (int thisPin = 7; thisPin >= 2; thisPin--) { 
    // LED를 켭니다:
    digitalWrite(thisPin, HIGH);
    delay(timer);
    // LED를 끕니다:
    digitalWrite(thisPin, LOW);
  }
}
