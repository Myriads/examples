/*
  String 클래스의 substring() 멤버 함수

 String 객체에서 substring 함수를 사용하는 방법을 보여주는
 예제들입니다

 2010년 07월 27일 창작되었으며,
 2012년 04월 02일 Zach Eveland에 의하여 수정되었습니다
 2016년 06월 17일 수정되었습니다

 http://www.arduino.cc/en/Tutorial/StringSubstring

 이 예제 코드는 공유 저작물입니다.
 */

void setup() {
  // 시리얼 통신 포트를 열고 연결되기를 기다립니다:
  Serial.begin(9600);
  while (!Serial) {
    ; // 시리얼 포트가 연결되길 기다립니다. 실제 USB 포트에서만 필요
  }

  // 시작을 알리는 글을 화면에 출력합니다:
  Serial.println("\n\nString 클래스의 substring() 멤버 함수:");
  Serial.println();
}

void loop() {
  // 사용할 문자열을 상수 문자열로 만듭니다:
  String stringOne = "Content-Type: text/html";
  Serial.println(stringOne);

  // substring(index)은 인덱스 값부터 문자열 끝까지 부분 문자열을
  // 찾아 줍니다:
  if (stringOne.substring(19) == "html") {
    Serial.println("HTML 파일입니다");
  }
  // 문자열 중간에서 부분 문자열을 찾을 수 있습니다:
  if (stringOne.substring(14, 18) == "text") {
    Serial.println("또한 텍스트 기반의 파일입니다");
  }

  // 한번만 시리얼 모니터에 출력하고 멈추게 계속 기다립니다:
  while (true);
}
