/*
 * Echo Hex
 * 
 * 시리얼 모니터에서 받은 메시지를 2 자리수의 HEX 값으로 바꿔
 * 시리얼 모니터로 보냅니다.
 * 
 */
void setup() {
  // 시리얼 통신을 위한 초기화를 합니다:
  Serial.begin(9600);

}

void loop() {
  static int count = 1;       // 줄 번호를 위한 변수
  static bool prompt = true;  // 줄 번호를 출력하기 위한 변수

  char temp[8];               // sprint 버퍼
  unsigned char c;            // 시리얼 모니터에서 받은 문자
  bool isPrinted = false;     // 시리얼 모니터로 출력했는지를 위한 변수
  
  // 시리얼 포트에 데이터가 있으면, 이를 읽어 들입니다:
  while(Serial.available() > 0) {
    // 줄 번호를 출력하여야 하는지 조사하여 출력
    if(prompt) {

      Serial.print(count);
      Serial.print(" ");
      prompt = false;
    }

    // 시리얼 모니터로부터 메시지를 받아 이를 출력
    c = Serial.read();
    sprintf(temp, "0x%02X ", c);
    Serial.print(temp);
    delay(10);
    isPrinted = true;
  }

  // 모니터로 출력하였다면, 새로운 줄 번호를 출력하기 위한 준비
  if (isPrinted) {
    isPrinted = false;
    Serial.println();
    
    prompt = true;
    ++count;
  }
}

