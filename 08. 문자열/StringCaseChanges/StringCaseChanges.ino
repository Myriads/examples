/*
  String 문자열 대소문자 변경하는 방법들

 이 스케치는 문자열의 대소문자를 바꾸는 방법들을 보여주는 예제들입니다

 2010년 07월 27일 창작되었으며
 2012년 04월 02일 Tom Igone에 의하여 수정되었습니다.

 http://www.arduino.cc/en/Tutorial/StringCaseChanges

 이 예제 코드는 공유 저작물입니다.
 */

void setup() {
  // 시리얼 통신 포트를 열고 연결되기를 기다립니다:
  Serial.begin(9600);
  while (!Serial) {
    ; // 시리얼 포트가 연결되길 기다립니다. 원래의 USB 포트에서만 필요
  }

  // 시작을 알리는 글을 화면에 출력합니다:
  Serial.println("\n\nString 문자열 대소문자 바꾸기:");
  Serial.println();
}

void loop() {
  // toUpperCase()는 모든 문자들을 대문자로 바꿉니다:
  String stringOne = "<html><head><body>";
  Serial.print("toUpperCase() 전: "); Serial.println(stringOne);
  stringOne.toUpperCase();
  Serial.print("toUpperCase() 후: ");Serial.println(stringOne);

  // toLowerCase()는 모든 문자들을 소문자로 바꿉니다:
  String stringTwo = "</BODY></HTML>";
  Serial.print("toLowerCase() 전: ");Serial.println(stringTwo);
  stringTwo.toLowerCase();
  Serial.print("toLowerCase() 후: ");Serial.println(stringTwo);


  // 한번만 시리얼 모니터에 출력하고 멈추게 계속 기다립니다:
  while (true);
}
