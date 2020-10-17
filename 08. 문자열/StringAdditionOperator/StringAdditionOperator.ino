/*
  String들 합치기

 이 스케치는 2 String을 어떻게 합치는지를 보여주는 예제이며, 또한
 여기에서 보여준 것과 같이 다양한 데이터 유형들을 문자열에 합칠 수
 도 있습니다. 

 2010년 07월 27일에 창작되었으며,
 2012년 04월 02일에 Tom Igoe에 의하여 수정되었습니다.
 
 http://www.arduino.cc/en/Tutorial/StringAdditionOperator

 이 예제는 공유 저작물입니다.
 */

// 3개의 String을 선언합니다:
String stringOne, stringTwo, stringThree;

void setup() {
  // 시리얼 통신 포트를 초기화하고 통신 포트가 열리기를 기다립니다:
  Serial.begin(9600);
  while (!Serial) {
    ; // 시리얼 통신 포트가 연결되기를 기다립니다. 원래의 USB 포트에서만 필요
  }

  stringOne = String("문자열 3 = ");
  stringTwo = String("문자열 2");
  stringThree = String();
  // 시작을 알리는 글을 화면에 출력합니다:
  Serial.println("\n\n문자열들 합치기 (연결:concatenation):");
  Serial.println();
}

void loop() {
  // 상수를 문자열에 더하기:
  stringThree =  stringOne + 123;
  Serial.println(stringThree);    // "문자열 3 = 123"을 출력

  // long 정수를 문자열에 더하기:
  stringThree = stringOne + 123456789;
  Serial.println(stringThree);    // "문자열 3 = 123456789"를 출력

  // 문자를 문자열에 더하기:
  stringThree =  stringOne + 'A';
  Serial.println(stringThree);    // "문자열 3 = A"를 출력

  // 상수 문자열 더하기:
  stringThree =  stringOne +  "\"상수 문자열\"";
  Serial.println(stringThree);    // 문자열 3 = "상수 문자열"을 출력 

  stringThree = stringOne + stringTwo;
  Serial.println(stringThree);    // "문자열 3 = 문자열 2"를 출력

  // 문자열에 정수 변수 값을 더하기:
  int sensorValue = analogRead(A0);
  stringOne = "센서 값: ";
  stringThree = stringOne  + sensorValue;
  Serial.println(stringThree);    // "센서 값: 399" 혹은 analogRead(A0)의 값이 출력

  // 문자열에 long 정수 변수 값 더하기:
  long currentTime = millis();
  stringOne = "millis() 값: ";
  stringThree = stringOne + millis();
  Serial.println(stringThree);    // "millis() 값: 131" 혹은 현재 millis() 값을 출력
 
  // 한번만 시리얼 모니터에 출력하고 멈추게 계속 기다리게 합니다:
  while (true);
}
