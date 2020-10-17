/*
  Blink
  LED를 1초 동안 켜고, 그리고 나서 1초 동안 LED를 끄는 것을 반복합니다.

  대부분의 아두이노 보드들은 ON/OFF할 수 있는 LED를 지니고 있습니다. 
  우노, 메가와 제로는 LED가 디지털 13번 핀에, MKR1000는 6번 핀에 연결
  되어 있습니다. LED_BUILTIN은 어떤 보드를 이용하더라도 올바른 LED 핀을
  사용하게끔 해줍니다.
  
  이용하고 있는 보드의 LED가 어떤 핀을 사용하고 있는지 알려면, 
  https://www.arduino.cc/en/Main/Products 에 보드 관련 기술 규격들
  (Technical Specs)을 살펴 보기 바랍니다.
  
  
  이 예제 코드는 공유 저작물입니다.

  2014년 05월 08일 Scott Fitzgerald에 의하여 수정되었으며

  2016년 09월 02일 Arturo Guadalui에 의하여 수정 되었습니다.
*/


// 이 setup 루틴은 reset 스위치를 누를 때 한번만 실행됩니다.
void setup() {
  // 디지털 LED_BUILTIN 핀을 출력 핀으로 초기화합니다.
  pinMode(LED_BUILTIN, OUTPUT);
}

// 이 loop 루틴은 영원히 반복 실행됩니다.
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // LED를 켭니다(HIGH는 전압 레벨입니다)
  delay(1000);                       // 1초 동안 기다립니다.
  digitalWrite(LED_BUILTIN, LOW);    // LED를 전압을 LOW로 만들어 끔니다
  delay(1000);                       // 1초 동안 기다립니다
}

