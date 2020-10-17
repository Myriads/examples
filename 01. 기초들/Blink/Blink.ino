/*
  Blink
  
  LED를 1초 동안 켜고, 그리고 나서 1초 동안 LED를 끄는 것을 반복합니다.

  대부분의 아두이노들은 보드에 제어할 수 있는 LED를 가지고 있습니다. 
  우노, 메가 그리고 제로는 디지털 핀 13에 연결되어 있고, MKR1000은 핀
  6에 연결되어 있습니다. LED_BUILTIN 이 어떤 보드를 이용하든 독립적인
  올바른 LED 핀입니다.
  사용하고 있는 모델의 보드에 있는 LED를 알고 싶다면, 다음 사이트에서
  보드의 기술 스펙을 알아보세요:
  https://www.arduino.cc/en/Main/Products
  
  이 예제 코드는 공유 저작물입니다.
*/


// 이 setup 루틴은 reset 스위치를 누를 때 한번만 실행됩니다.
void setup() {

  // 디지털 핀 LED_BUILTIN을 출력 핀으로 초기화합니다.
  pinMode(LED_BUILTIN, OUTPUT);
}


// 이 loop 루틴은 영원히 반복 실행됩니다.
void loop() {
  digitalWrite(led, HIGH);   // LED를 켭니다(HIGH는 전압 레벨입니다)
  delay(1000);               // 1초 동안 기다립니다.
  digitalWrite(led, LOW);    // LED를 전압을 LOW로 만들어 끔니다
  delay(1000);               // 1초 동안 기다립니다
}
