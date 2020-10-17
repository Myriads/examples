/*
  Character analysis operators
  (문자 분석 함수들)

 이 스케치는 문자 유형을 알아내기 위한 함수들의 사용
 방법을 보여주는 예제입니다. 시리얼 모니터로 어떠한 
 문자 하나를 보내면 스케치는 그것이 어떠한 유형인지를
 알려 줍니다.

 2010년 11월 29일에 창작되었으며,
 2012년 04월 02일에 Tom Igoe에 의하여 수정되었습니다.

 이 예제는 공유 저작물입니다.
 */

void setup() {
  // 시리얼 포트를 초기화하고 통신 포트가 열리기를 기다립니다:
  Serial.begin(9600);
  while (!Serial) {
    ; // 통신 포트가 연결되길 기다립니다. 원래의 USB 포트에서만 필요
  }

  // 화면에 시작을 알리는 글을 출력합니다:
  Serial.println("아무 문자 하나를 보내세요. 보낸 문자에 대하여 모든 것을 알려 드립니다");
  Serial.println();
}

void loop() {
  // 보낸 문자를 읽어 들입니다:
  if (Serial.available() > 0) {
    int thisChar = Serial.read();

    // 보낸 문자에 대하여 설명합니다:
    Serial.print("보낸 글자: \'");
    Serial.write(thisChar);
    Serial.print("\'  ASCII 값: ");
    Serial.println(thisChar);

    // 보낸 문자에 대한 분석:
    if (isAlphaNumeric(thisChar)) {
      Serial.println("이 문자는 영문숫자입니다");
    }
    if (isAlpha(thisChar)) {
      Serial.println("이 문자는 영문자입니다");
    }
    if (isAscii(thisChar)) {
      Serial.println("이 문자는 ASCII입니다");
    }
    if (isWhitespace(thisChar)) {
      Serial.println("이 문자는 공백 문자입니다");
    }
    if (isControl(thisChar)) {
      Serial.println("이 문자는 컨트롤 문자입니다");
    }
    if (isDigit(thisChar)) {
      Serial.println("이 문자는 숫자입니다");
    }
    if (isGraph(thisChar)) {
      Serial.println("이 문자는 출력 가능하며 공백 문자가 아닙니다");
    }
    if (isLowerCase(thisChar)) {
      Serial.println("이 문자는 소문자입니다");
    }
    if (isPrintable(thisChar)) {
      Serial.println("이 문자는 출력 가능합니다");
    }
    if (isPunct(thisChar)) {
      Serial.println("이 문자는 구두점입니다");
    }
    if (isSpace(thisChar)) {
      Serial.println("이 문자는 스페이스 문자입니다");
    }
    if (isUpperCase(thisChar)) {
      Serial.println("이 문자는 대문자입니다");
    }
    if (isHexadecimalDigit(thisChar)) {
      Serial.println("이 문자는 16진수 값입니다 (예: 0 - 9, a - f, 혹은 A - F)");
    }

    // 여백을 띄우고, 다음 문자를 받아들입니다:
    Serial.println();
    Serial.println("다른 문자를 보내세요:");
    Serial.println();
  }
}
