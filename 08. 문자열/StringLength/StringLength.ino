/*
  String 클래스의 length() 멤버 함수

 String 객체에서 length()를 어떻게 사용하는지 보여주는 예제입니다.
 시리얼 모니터를 열고 글자들을 보내기 시작하면 결과를 볼 수 있습니다.

 2010년 08월 01일 Tom Igoe에 의하여 창작되었으며
 2016년 06월 14일 수정되었습니다

 http://www.arduino.cc/en/Tutorial/StringLengthTrim

 이 예제 코드는 공유 저작물입니다.
 */

String txtMsg = "";                         // 입력 문자를 위한 문자열
int lastStringLength = txtMsg.length();     // 바로 전의 문자열 길이

void setup() {
  // 시리얼 통신 포트를 열고 연결되기를 기다립니다:
  Serial.begin(9600);
  while (!Serial) {
    ; // 시리얼 포트가 연결되길 기다립니다. 실제 USB 포트에서만 필요
  }

  // 시작을 알리는 글을 화면에 출력합니다:
  Serial.println("\n\nString 클래스 length() 멤버 함수:");
  Serial.println();
}

void loop() {
  // 입력 문자들이 있으면 String 객체인 txtMsg에 덧 붙입니다:
  while (Serial.available() > 0) {
    char inChar = Serial.read();
    txtMsg += inChar;
    delay(2);
  }

  // 바뀌었다면 메시지를 출력하고 이를 알립니다:
  if (txtMsg.length() != lastStringLength) {
    Serial.println(txtMsg);
    Serial.println(txtMsg.length());
    // 문자열이 140 문자보다 크면, 이를 호소합니다:
    if (txtMsg.length() < 140) {
      Serial.println("완벽하게 받아들일 수 있는 문자 메시지입니다");
    } else {
      Serial.println("너무 긴 문자 메시지입니다.");
    }
    // 다음 입력 메시지는 다음 줄(line)로 합니다:
    txtMsg += '\n';
    // loop() 함수가 다시 반복 실행될 때 사용하기 위하여 txtMsg 문자열
    // 길이를 기록하여 놓습니다:
    lastStringLength = txtMsg.length();
  }
}
