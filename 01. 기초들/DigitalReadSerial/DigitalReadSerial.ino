/*
  DigitalReadSerial
 디지털 2번 핀을 읽고 결과 값을 시리얼 모니터에 출력합니다.
 
 이 예제 코드는 공유 저작물입니다.
 */

// 디지털 2번 핀에 푸시 버튼을 연결하고 pushButton이라고 이름을 붙였습니다:
int pushButton = 2;

// 이 setup 루틴은 reset 스위치를 누를 때 한번만 실행됩니다:
void setup() {
  // 시리얼 통신 속도를 9600bps(bits per second)로 초기화합니다.
  Serial.begin(9600);
  // 푸시 버튼의 핀을 입력 핀으로 만듭니다:
  pinMode(pushButton, INPUT);
}

// 이 loop 루틴은 영원히 반복 실행됩니다:
void loop() {
  // 입력 핀을 읽습니다:
  int buttonState = digitalRead(pushButton);
  // 버튼의 상태를 출력합니다:
  Serial.println(buttonState);
  delay(100);          // 안정된 값을 얻기 위하여 지연 시간을 줍니다.
}
