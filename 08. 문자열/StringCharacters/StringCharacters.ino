/*
  String 문자열 charAt()과 setCharAt() 멤버 함수들

 String 객체의 글자들을 가져오고 넣는 예제입니다.
 
 2010년 07월 27일 창작되었으며
 2012년 04월 02일 Tom Igoe에 의하여 수정되었습니다.
 2016년 06월 10일에 수정되었습니다.
 
 http://www.arduino.cc/en/Tutorial/StringCharacters

 이 예제 코드는 공유 저작물입니다.
 */

void setup() {
  // 시리얼 통신 포트를 열고 연결되기를 기다립니다:
  Serial.begin(9600);
  while (!Serial) {
    ; // 시리얼 포트가 연결되길 기다립니다. 원래의 USB 포트에서만 필요
  }

  Serial.println("\n\nString 클래스의 charAt()과 setCharAt():");
  Serial.println();
}

void loop() {
  // 읽은 센서 값을 보내기 위한 문자열을 준비합니다:
  String reportString = "센서 읽은 값: ";
  int pos = reportString.length();
  
  reportString += analogRead(A0);
  Serial.println(reportString);
  Serial.println();

  char buf[4];

  // String 문자열의 char를 HEX로 출력합니다
  // 1. 위치 값 출력
  for(int i=0; i < reportString.length(); i++){
    sprintf(buf, "%2d ", i);
    Serial.print(buf);
  }
  Serial.println();

  // 2. HEX 값 출력
  for(int i=0; i < reportString.length(); i++) {
    sprintf(buf, "%02hhX ", (unsigned char)reportString.charAt(i));
    Serial.print(buf);
  }
  Serial.println("\n");
  
  // reportString의 pos(0에서 시작) 위치에 있는 문자가
  // 최상위 디지트(MSD) 숫자입니다:
  char mostSignificantDigit = reportString.charAt(pos);

  String message = "센서 읽은 값의 최상위 디지트 값: ";
  Serial.println(message + mostSignificantDigit);

  // 빈 줄을 넣습니다:
  Serial.println();

  // 문자열에 문자를 넣을 수 있습니다. ":"를 "=" 문자로 바꿉니다
  reportString.setCharAt(pos - 2, '=');
  Serial.println(reportString);

  // 한번만 시리얼 모니터에 출력하고 멈추게 계속 기다립니다:
  while (true);
}

