/*
 Encoding:
 
 윈도우 메모장에서 EUC-KR 코드로 작성된 스케치를
 아두이노 IDE로 읽어 들여 UTF-8 코드로 변경하여
 컴파일하는 과정을 보여 주기 위한 예제입니다:

*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("한글로 메시지를 출력합니다");
  delay(1000);
}

