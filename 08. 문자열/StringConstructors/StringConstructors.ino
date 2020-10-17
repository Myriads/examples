/*
   String 객체 생성자들

 이 스케치는 어떻게 다른 데이터 유형들로부터 String 객체를
 만드(생성하)는지를 보여주는 예제들입니다

 2010년 07월 27일에 창작되었으며
 2011년 08월 30일에 Tom Igoe에 의하여 수정되었습니다
 2016년 06월 12일에 수정되었습니다

 http://www.arduino.cc/en/Tutorial/StringConstructors

 이 예제 코드는 공유 저작물입니다.
 */

void setup() {
  // 시리얼 통신 포트를 열고 연결되기를 기다립니다:
  Serial.begin(9600);
  while (!Serial) {
    ; // 시리얼 포트가 연결되길 기다립니다. 실제 USB 포트에서만 필요
  }

  // 시작을 알리는 글을 화면에 출력합니다:
  Serial.println("\n\nString 생성자들:");
  Serial.println();
}

void loop() {
  // 상수 문자열을 이용하여 생성:
  String stringOne = "안녕 String";
  Serial.println(stringOne);      // "Hello String" 출력

  // 상수 문자(char)를 String 문자열로 변환:
  stringOne =  String('a');
  Serial.println(stringOne);       // "a" 출력

  // 상수 문자열을 String 객체로 변환:
  String stringTwo =  String("이것은 문자열");
  Serial.println(stringTwo);      // "이것은 문자열" 출력

  // 두 문자열들을 연결하여 합침:
  stringOne =  String(stringTwo + "입니다");
  // "이것은 문자열입니다":
  Serial.println(stringOne);

  // 정수 상수를 이용하여 생성:
  stringOne =  String(13);
  Serial.println(stringOne);      // "13" 출력

  // 정수와 진수(base)를 10진수(decimal)로 생성:
  stringOne =  String(analogRead(A0), DEC);
  // 559 <- analogRead(A0)에서 읽은 정수 값 출력
  Serial.println(stringOne);

  // 정수와 진수를 16진수(hexadecimal)로 생성:
  stringOne =  String(45, HEX);
  // 10진수 45의 16진수 값인 2d 출력:
  Serial.println(stringOne);

  // 정수와 진수를 2진수(binary)로 생성:
  stringOne =  String(255, BIN);
  // 255의 2진수 값인 "11111111" 출력
  Serial.println(stringOne);

  // long 정수를 10진수로 생성:
  stringOne =  String(millis(), DEC);
  // 54 <- millis()의 long 정수 값이 출력:
  Serial.println(stringOne);

  // float 실수와 소수점 이하 자리수를 같게 생성:
  stringOne = String(5.698, 3);
  Serial.println(stringOne);

  // float 실수와 소수점 이하 자리수를 적게하여 반올림하여 생성:
  stringOne = String(5.698, 2);
  Serial.println(stringOne);

  // 한번만 시리얼 모니터에 출력하고 멈추게 계속 기다립니다:
  while (true);

}
