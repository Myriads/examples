/*
  String 클래스의 replace() 멤버 함수

 문자열의 문자(character)들이나 문자열의 부분(substring)을
 바꾸는 방법을 보여주는 예제들입니다

 2010년 07월 27일 창작되었으며
 2012년 04월 02일 Tom Igoe에 의하여 수정되었습니다
 2016년 06월 15일 수정되었습니다

 http://www.arduino.cc/en/Tutorial/StringReplace

 이 예제 코드는 공유 저작물입니다.
 */

void setup() {
  // 시리얼 통신 포트를 열고 연결되기를 기다립니다:
  Serial.begin(9600);
  while (!Serial) {
    ; // 시리얼 포트가 연결되길 기다립니다. 실제 USB 포트에서만 필요
  }

  // 시작을 알리는 글을 화면에 출력합니다:
  Serial.println("\n\nString 클래스 replace() 멤버 함수:\n");
}

void loop() {
  String stringOne = "<html><head><body>";
  Serial.println(stringOne);
  // replace()는 문자열에 들어 있는 모든 바꾸고자 하는 문자열들을 원하는
  // 문자열로 바꿔 버립니다:
  // 먼저 원본 문자열을 복사하여 놓습니다:
  String stringTwo = stringOne;
  // 그리고 바꾸기를 실행합니다:
  stringTwo.replace("<", "</");
  // 원본 문자열을 출력합니다:
  Serial.println("원본 문자열: " + stringOne);
  // 그리고 바뀐 문자열을 출력합니다:
  Serial.println("바뀐 문자열: " + stringTwo);

  // 그리고 replace()로 한 문자(character)들만 바꿀 수 있습니다:
  String normalString = "bookkeeper";
  Serial.println("일반적인 표현: " + normalString);
  String leetString = normalString;
  leetString.replace('o', '0');
  leetString.replace('e', '3');
  Serial.println("인터넷   표현: " + leetString);
  Serial.println(" (l33tspeak)");

  // 한번만 시리얼 모니터에 출력하고 멈추게 계속 기다립니다:
  while (true);
}
