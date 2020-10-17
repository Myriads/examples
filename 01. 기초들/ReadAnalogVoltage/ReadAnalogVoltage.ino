/*
  ReadAnalogVoltage
  
  아나로그 입력 핀 A0를 읽고 그 값을 전압으로 바꿔 시리얼 모니터에 출력합니다.
  가변 저항기(포텐셔미터)의 가운데 핀을 A0 핀과 연결하고 바깥 핀들을 +5V와 접지(그라운드)에
  연결합니다.
 
 이 예제 코드는 공유 저작물입니다.
 */

// 이 setup 루틴은 리셋 스위치를 누를 때, 한번만 실행됩니다:
void setup() {
  // 시리얼 통신 속도를 9600bps(bits per second)로 초기화합니다:
  Serial.begin(9600);
}

// 이 loop 루틴은 영원히 반복 실행됩니다:
void loop() {
  // 아나로그 0번 핀에서 입력 값을 읽습니다: 
  int sensorValue = analogRead(A0);
  // 0 ~ 1023 사이의 아나로그 입력 값을 0 ~ 5V 사이의 전압으로 바꿉니다:
  float voltage = sensorValue * (5.0 / 1023.0);
  // 전압으로 바꾼 값을 시리얼 모니터로 출력합니다:
  Serial.println(voltage);
  // 지연 시간을 갖습니다.
  delay(100);
}
