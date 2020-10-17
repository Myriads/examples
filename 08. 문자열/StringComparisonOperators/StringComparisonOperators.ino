/*
  문자열들 비교

 비교 연산자들을 이용하여 문자열들을 비교하는 예제들입니다
  

 2010년 07월 27일 창작되었으며
 2012년 04월 02일 Tom Igoe에 의하여 수정되었습니다.
 2016년 06월 10일에 수정되었습니다.

 http://www.arduino.cc/en/Tutorial/StringComparisonOperators

 이 예제 코드는 공유 저작물입니다.
 */

String stringOne, stringTwo;

void setup() {
  // 시리얼 통신 포트를 열고 연결되기를 기다립니다:
  Serial.begin(9600);
  while (!Serial) {
    ; // 시리얼 포트가 연결되길 기다립니다. 원래의 USB 포트에서만 필요
  }


  stringOne = String("이것");
  stringTwo = String("저것");
  
  // 시작을 알리는 글을 화면에 출력합니다:
  Serial.println("\n\n문자열들 비교:");
  Serial.println();

}

void loop() {
  // 두 문자열이 같은지 검사:
  if (stringOne == "이것") {
    Serial.println("StringOne == \"이것\"");
  }
  // 두 문자열이 다른지 검사:
  if (stringOne != stringTwo) {
    Serial.println(stringOne + " =! " + stringTwo);
  }

  // 두 문자열이 다른지 검사 (대소문자 비교):
  stringOne = "This";
  stringTwo = "this";
  if (stringOne != stringTwo) {
    Serial.println(stringOne + " =! " + stringTwo);
  }
  // String의 equals() 멤버 함수를 이용하여 비교할 수 있습니다:
  if (stringOne.equals(stringTwo)) {
    Serial.println(stringOne + "과 " + stringTwo + "는 같습니다");
  } else {
    Serial.println(stringOne + "과 " + stringTwo + "는 다릅니다");
  }

  // 대소문자 무시하고 비교:
  if (stringOne.equalsIgnoreCase(stringTwo)) {
    Serial.println(stringOne + "과 " + stringTwo + "는 같습니다(대소문자 무시)");
  } else {
    Serial.println(stringOne + "과 " + stringTwo + "는 다릅니다(대소문자 무시)");
  }

  // 숫자 문자열과 숫자 값과 비교:
  stringOne = "1";
  int numberOne = 1;
  if (stringOne.toInt() == numberOne) {
    Serial.println(stringOne + " = " + numberOne);
  }

  // 두 숫자 문자열 크기 비교:
  stringOne = "2";
  stringTwo = "1";
  if (stringOne >= stringTwo) {
    Serial.println(stringOne + " >= " + stringTwo);
  }

  // 비교 연산자를 문자열을 정렬(sorting)하기 위하여 사용할 수 있습니다:
  stringOne = String("일지매");
  if (stringOne < "홍길동") {
    Serial.println(stringOne + " < 홍길동");
  }

  if (stringOne > "손오공") {
    Serial.println(stringOne + " > 손오공");
  }

  if (stringOne <= "저팔계") {
    Serial.println(stringOne + " <= 저팔계");
  }

  // String 클래스의 compareTo() 멤버 함수 또한 문자열들을
  // 비교하는데 사용할 수 있습니다. 첫 번째 문자열의 영문자
  // 값이 두 번째 문자열의 영문자 값보다 크면 0보다 큰 값이
  // 작으면 0보다 작은 값이, 같으면 0 값이 주어집니다
  stringOne = "홍길동";
  stringTwo = "홍두깨";
  if (stringOne.compareTo(stringTwo) < 0) {
    Serial.println(stringOne + "이 " + stringTwo + " 앞에 있습니다");
  } else {
    Serial.println(stringOne + "이 " + stringTwo + " 뒤에 있습니다");
  }

  delay(10000);  // 다음 부분이 while 반복문이라 오래 기다리게 합니다:

  // compareTo() 숫자를 포함한 문자열일 경우 사용하면 편리합니다:

  while (true) {
    stringOne = "센서: ";
    stringTwo = "센서: ";

    stringOne += analogRead(A0);
    stringTwo += analogRead(A5);

    if (stringOne.compareTo(stringTwo) < 0) {
      Serial.println(stringOne + " 값이 " + stringTwo + " 보다 작습니다");
    } else {
      Serial.println(stringOne + " 값이 " + stringTwo + " 보다 큽니다");
    }
  }
}
