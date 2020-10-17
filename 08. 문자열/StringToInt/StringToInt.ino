/*
  String 문자열을 정수(Integer)로 변환

 새줄 기호가 나올 때까지 시리얼 포트로부터 입력을 받아
 문자들이 디지트들이라면 이를 숫자로 바꿉니다.
 
 회로:
 외부 부품들이 필요없습니다.

 2010년 11월 29일 Tom Igoe에 의하여 창작되었습니다.
 2016년 06월 17일 수정되었습니다

 https://www.arduino.cc/en/Tutorial/StringToInt
 
 이 예제 코드는 공유 저작물입니다.
 */

String inString = "";    // 입력을 받아들일 String 변수

void setup() {
  // 시리얼 통신 포트를 열고 연결되기를 기다립니다:
  Serial.begin(9600);
  while (!Serial) {
    ; // 시리얼 포트가 연결되길 기다립니다. 실제 USB 포트에서만 필요
  }

  // 시작을 알리는 글을 화면에 출력합니다:
  Serial.println("\n\nString 클래스의 toInt() 멤버 함수:");
  Serial.println();
}

void loop() {
  // 시리얼 포트로부터 입력을 받습니다:
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // 읽은 바이트 데이터를 문자로 변환하여
      // String 문자열에 붙입니다:
      inString += (char)inChar;
    }
    // 새줄 기호이면, 문자열을 숫자로 바꾼 값을 출력하고,
    // 시리얼 포트에서 읽어들인 문자열을 출력합니다:
    if (inChar == '\n') {
      Serial.print("값: ");
      Serial.println(inString.toInt());
      Serial.print("문자열: ");
      Serial.println(inString);
      // 새로운 입력을 받기 위하여 입력을 위한 문자열을 비웁니다:
      inString = "";
    }
  }
}

