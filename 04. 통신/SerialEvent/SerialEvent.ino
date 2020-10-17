/*
  Serial Event example (시리얼 이벤트의 예)
 
 새로운 시리얼 데이터가 도착하면, 받고 있는 문자열에 추가합니다.
 새줄 문자(0x0A 혹은 '\n' 값을 갖는 LF:Line Feed)가 들어오면,
 loop()에서 시리얼 포트로 출력하고 문자열을 새로 받을 수 있게
 받았던 문자열을 지웁니다.
 
 이 예제를 NMEA 0183 문들을 내보내는 GPS 수신기와 시험을 하면
 좋은 결과를 얻을 수 있을 것입니다. 
 
 2011년 05월 09일 Tom Igoe에 의하여 창작되었습니다
 
 이 예제 코드는 공유 저작물입니다.
 
 http://www.arduino.cc/en/Tutorial/SerialEvent
 
 */

String inputString = "";         // 받은 데이터들을 보관할 String 객체
boolean stringComplete = false;  // 한 줄을 데이터를 모두 받았는지를
                                 // 나타내는 플래그

void setup() {
  // 시리얼 포트를 초기화합니다:
  Serial.begin(250000);
  // 200 바이트 데이터를 받을 수 있게 메모리 공간을 확보합니다:
  inputString.reserve(200);
}

void loop() {
  // 새줄 문자를 받으면 받은 문자열을 출력합니다:
  if (stringComplete) {
    Serial.println(inputString); 
    // 다음 문자열을 받을 수 있게 받은 문자열을 지웁니다:
    inputString = "";
    stringComplete = false;
  }
}

/*
  시리얼 이벤트는 하드웨어 시리얼 포트의 수신(RX:Receive)단에
 새로운 데이터가 들어올 때마다 발생합니다. 이 루틴은 loop()이
 실행된 후에 실행되기 때문에 loop()에 delay() 함수를 사용하면
 응답 처리가 늦게 됩니다. 여러 바이트의 데이터가 들어올 수
 있습니다.
 */
void serialEvent() {
  while (Serial.available()) {
    // 새로운 바이트를 받습니다:
    char inChar = (char)Serial.read(); 
    // inputString 객체의 끝에 붙여 넣습니다:
    inputString += inChar;
    // 새줄 문자를 받았을 경우, 이를 플래그에 표시하여
    // 주 처리를 담당하는 loop()에서 처리할 수 있게 합니다:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}

