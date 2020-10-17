/*
  += 연산자와 concat()를 이용하여 문자열 붙이기
  
 문자열들에 다른 데이터 유형들을 붙이는 예제들입니다

 2010년 07월 27일에 창작되었으며
 2012년 04월 02일에 Tom Igoe에 의하여 수정되었습니다

 http://www.arduino.cc/en/Tutorial/StringAppendOperator

 이 예제 코드는 공유 저작물입니다.
 */

String stringOne, stringTwo;

void setup() {
  // 시리얼 통신 포트를 초기화하고 열리기를 기다립니다:
  Serial.begin(9600);
  while (!Serial) {
    ; // 시리얼 포트가 연결되길 기다립니다. 원래의 USB 포트에서만 필요
  }

  stringOne = String("센서 ");
  stringTwo = String("값");
  // 시작을 알리는 글을 화면에 출력합니다:
  Serial.println("\n\n문자열에 덧 붙이기:");
  Serial.println();
}

void loop() {
  Serial.println(stringOne);  // "센서 " 출력

  // 문자열 stringOne에 문자열 stringTwo 덧 붙이기:
  stringOne += stringTwo;
  Serial.println(stringOne);  // "센서 값" 출력

  // 문자열에 상수 문자열 덧 붙이기:
  stringOne += "(입력 ";
  Serial.println(stringOne);  // "센서 값(입력 " 출력

  // 문자열에 상수 문자 덧 붙이기:
  stringOne += 'A';
  Serial.println(stringOne);   // "센서 값(입력 A" 출력 

  // 문자열에 상수 정수 덧 붙이기:
  stringOne += 0;
  Serial.println(stringOne);   // "센서 값(입력 A0" 출력

  // 문자열에 상수 문자열 덧 붙이기:
  stringOne += "): ";
  Serial.println(stringOne);  // "센서 값(입력 A0):" 출력

  // 문자열에 변수 값 덧 붙이기:
  stringOne += analogRead(A0);
  Serial.println(stringOne);   // "센서 값(입력 A0): 429" 혹은 analogRead(A0)에서 읽은 값

  Serial.println("\n\n문자열들 값 바꾸기");
  stringOne = "long 정수: ";
  stringTwo = "millis(): ";

  // 문자열에 상수 long 정수 값 덧 붙이기:
  stringOne += 123456789;
  Serial.println(stringOne);   // "long 정수: 123456789" 출력

  // concat() 멤버 함수를 이용하여 long 변수를 문자열에 덧 붙이기:
  stringTwo.concat(millis());
  Serial.println(stringTwo); // "millis(): 164" 혹은 millis()의 값

  // 한번만 시리얼 모니터에 출력하고 멈추게 계속 기다립니다:
  while (true);
}

