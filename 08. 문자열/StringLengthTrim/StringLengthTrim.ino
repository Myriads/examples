/*
  String 클래스의 length()와 trim() 멤버 함수

 String 객체에서 length()와 trim() 멤버 함수의 사용법을 보여 주는
 예제입니다.
 
 2010년 07월 27일 창작되었으며
 2012년 04월 02일 Tom Igoe에 의하여 수정되었습니다.
 2016년 06월 14일 수정되었습니다

 http://www.arduino.cc/en/Tutorial/StringLengthTrim

 이 예제 코드는 공유 저작물입니다.
 */

void setup() {
  // 시리얼 통신 포트를 열고 연결되기를 기다립니다:
  Serial.begin(9600);
  while (!Serial) {
    ; // 시리얼 포트가 연결되길 기다립니다. 실제 USB 포트에서만 필요
  }

  // 시작을 알리는 글을 화면에 출력합니다:
  Serial.println("\n\nString 클래스 length()와 trim() 멤버 함수들:");
  Serial.println();
}

void loop() {
  // 끝에 빈 스페이스들(공백문자, white space, 라고 불리우는)이 있는
  // String 객체:
  String stringOne = "     안녕!       ";
  Serial.print(stringOne);
  Serial.print("<------- 문자열 끝. 길이: ");
  Serial.println(stringOne.length());

  // 문자열에서 공백문자들을 없앱니다:
  stringOne.trim();
  Serial.print(stringOne);
  Serial.print("<--- 공백문자를 없앤 문자열 끝. 길이: ");
  Serial.println(stringOne.length());

  // 한번만 시리얼 모니터에 출력하고 멈추게 계속 기다립니다:
  while (true);
}
