/*
 Fade
 
 이 예제는 디지털 9번 핀에 연결된 LED를 analogWrite 함수를 사용하여
 서서히 밝게하다 점차 어둡게 하는 것을 보여 줍니다. 
 
 이 예제 코드는 공유 저작물입니다.
 */

int led = 9;           // LED가 연결된 핀
int brightness = 0;    // LED 밝기 값
int fadeAmount = 5;    // LED를 점차 밝게 혹은 어둡게 할 값

// 이 setup 루틴은 리셋 스위치를 누를 때, 한번만 실행됩니다:
void setup()  { 
  // 9번 핀을 출력 핀으로 선언합니다:
  pinMode(led, OUTPUT);
} 

// 이 loop 루틴은 영원히 반복 실행됩니다:
void loop()  { 
  // 디지털 핀 9에 LED 밝기 값을 씁니다
  analogWrite(led, brightness);    

  // 반복 실행될 때, 다음에 사용할 LED 밝기 값을 변경합니다 
  brightness = brightness + fadeAmount;

  // 255나 0 값이 되면 밝게 하는 것을 어둡게, 어둡게 하였던 것을 밝게 하는
  // 방향으로 바꿉니다. fadeAmount 값을 + 값으로 하여 밝기 값을 증가시키거나
  // - 값으로 만들어 밝기 값을 감소시켜 밝기를 점차 변하게 만듭니다:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }
  // 현상을 관찰할 수 있게 하기 위하여 100ms 동안 기다립니다
  delay(100);                            
}

