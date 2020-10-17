/*
  String 클래스의 startWith()과 endsWith() 멤버 함수들

 String 객체에서 startsWith()과 endsWith() 함수들을 사용하는 방법을
 보여주는 예제들입니다

 2010년 07월 27일 창작되었으며
 2012년 04월 02일 Tom Igoe에 의하여 수정되었습니다
 2016년 06월 16일 수정되었습니다

 http://www.arduino.cc/en/Tutorial/StringStartsWithEndsWith

 이 예제 코드는 공유 저작물입니다.
 */

void setup() {
  // 시리얼 통신 포트를 열고 연결되기를 기다립니다:
  Serial.begin(9600);
  while (!Serial) {
    ; // 시리얼 포트가 연결되길 기다립니다. 실제 USB 포트에서만 필요
  }

  // 시작을 알리는 글을 화면에 출력합니다:
  Serial.println("\n\nString 클래스 startsWith()과 endsWith() "
                  "멤버 함수들:");
  Serial.println();
}

void loop() {
  // startsWith() 함수는 문자열이 특정 문자열로 시작하는지 알아보기
  // 위하여 사용합니다:
  String stringOne = "HTTP/1.1 200 OK";
  Serial.println(stringOne);
  if (stringOne.startsWith("HTTP/1.1")) {
    Serial.println("서버는 HTTP 버전 1.1을 사용하고 있습니다");
  }
  
  // 문자열의 특정 시작 위치(offset position)에서 startsWith()을
  // 사용할 수 있습니다:
  stringOne = "HTTP/1.1 200 OK";
  if (stringOne.startsWith("200 OK", 9)) {
    Serial.println("서버로부터 OK를 받았습니다");
  }

  // endsWith()을 이용하여 문자열이 특정 문자로 끝나는지 확인할
  // 수 있습니다:
  String sensorReading = "센서 = ";
  sensorReading += analogRead(A0);
  Serial.print(sensorReading);
  if (sensorReading.endsWith("0")) {
    Serial.println(". 이 값은 10으로 나눌 수 있습니다");
  } else {
    Serial.println(". 이 값은 10으로 나눌 수 없습니다");
  }

  // 한번만 시리얼 모니터에 출력하고 멈추게 계속 기다립니다:
  while (true);
}
