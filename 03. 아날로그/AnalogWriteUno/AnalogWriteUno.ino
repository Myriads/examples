/*
  Uno analogWrite() test (우노 analogWrite() 시험)
 	
  이 스케치는 아두이노 메가 보드용으로 쓰여져 우노에서는 동작하지 않는
  것을 우노에서도 동작하게 수정한 것입니다. 디지털 핀 3, 5, 6, 9, 10 
  그리고 11번 핀에 연결된 LED들을 차례로 3번 핀에 연결된 LED부터 서서히
  밝게 하고, 반대로 서서히 어둡게 만드는 예제입니다.

  참고로 메가 보드는 디지털 핀 2번에서 13번까지 진폭변조(PWM: Pulse 
  Width Modulation) 출력이 가능한 반면, 우노는 디지털 핀 3, 5, 6, 9,
  10, 그리고 11번 핀들만 가능합니다.
  
  회로:
  * 220Ω 저항을 3 번핀에 연결하고 저항 다른 쪽 다리를 LED의 아노드에 
    연결합니다. 그리고 LED의 캐소드를 GND로 연결합니다. 다른 모든 핀들에
    같이 저항과 LED를 연결합니다.

  2009년 02월 08일 Tom Igoe에 의하여 창작되었습니다
  2014년 09월 05일 Wayfarer에 의하여 수정되었습니다
  
  이 예제 코드는 공유 저작물입니다.
  
  http://arduino.cc/en/Tutorial/AnalogWriteMega
  
 */

#define TEST false

// PWM 신호를 발생할 수 있는 핀들:
byte pins[] = { 3, 5, 6, 9, 10, 11 };

void setup() {
  // pins[]의 핀들을 모두 출력 핀으로 정의합니다:
  for (int i = 0; i < sizeof(pins)/sizeof(byte); i++) { 
    pinMode(pins[i], OUTPUT); 
  }
}

void loop() {
  // 모든 핀들을 차례로 반복합니다:
  for (int i = 0; i < sizeof(pins)/sizeof(byte); i++) { 
    // LED를 OFF 상태에서 점점 최고의 밝은 상태로 만듭니다:
    for (int brightness = 0; brightness < 255; brightness++) {
      analogWrite(pins[i], brightness);
      delay(2);
    } 

    // LED를 최고의 밝은 상태에서 점점 OFF 상태로 만듭니다:
    for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(pins[i], brightness);
      delay(2);
    } 
    // 다음 LED로 넘어갈 때 잠시 멈춥니다:
    delay(100);
  }
#if TEST
  // 모든 핀들을 차례로 반복합니다:
  for (int i = 0; i < sizeof(pins)/sizeof(byte); i++) { 
    // LED를 OFF 상태에서 점점 최고의 밝은 상태로 만듭니다:
    for (int brightness = 0; brightness < 255; brightness++) {
      analogWrite(pins[i], brightness);
      delay(2);
    } 

    // 앞의 LED를 끕니다
    byte n = i - 1;
    if(n == 0xFF) {
      n = sizeof(pins)/sizeof(byte) - 1;
    }
    analogWrite(pins[n], 0);
    
    // 다음 LED로 넘어갈 때 잠시 멈춥니다:
    delay(100);
  }
  analogWrite(pins[sizeof(pins)/sizeof(byte) - 1], 0);
#endif
}
