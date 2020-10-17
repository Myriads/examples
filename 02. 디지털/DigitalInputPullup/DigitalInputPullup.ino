/*
 Input Pullup Serial
 
 이 예제는 pinMode(INPUT_PULLUP)의 사용법을 보여주기 위한 것으로서,
 디지털 2번 핀을 읽고 그 결과 값을 시리얼 모니터에 출력합니다. 디지털
 13번 핀에 연결되어 있는 LED를 버튼이 눌렸을 때 켜고, 떼어졌을 때
 끕니다.

 회로:
 * 푸시 버튼 스위치와 아두이노 디지털 2번 핀과 연결하고, 스위치의 
   한 핀은 GND에 연결합니다.
 * 아두이노 보드에 기본으로 제공되는 디지털 13번 핀에 연결되어 있는
   LED를 사용합니다.
 
 pinMode(INPUT)과 다르게 풀다운 저항을 사용하지 않고, 아두이노 MCU
 내부에 5V와 연결되어 있는 20K Ohm 저항을 사용합니다. 이러한 구성은
 스위치를 누르지 않을 때 HIGH로 읽히고, 스위치를 눌렀을 때 LOW로
 읽히게 됩니다.
 
 2012년 03월 14일 Scott Fitzgerald에 의하여 창작되었습니다.
 
 http://www.arduino.cc/en/Tutorial/InputPullupSerial
 
 이 예제 코드는 공유 저작물입니다.
 
 */

void setup(){
  // 시리얼 통신 연결을 시작합니다
  Serial.begin(9600);
  // 디지털 2번 핀을 입력으로 설정하고 풀업 저항을 활성화합니다.
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT); 
}

void loop(){
  // 푸시 버튼 값을 sensorVal 변수로 읽어 들입니다
  int sensorVal = digitalRead(2);
  // 푸시 버튼 값을 시리얼 모니터로 출력합니다
  Serial.println(sensorVal);
  
  // 풀업으로 푸시 버튼의 로직이 바뀌었다는 것을 염두에 두고, 버튼을 눌러
  // 연결되었을 때, LOW가 되고, 누르지 않으면 HIGH가 됩니다. 디지털 13번 핀을
  // 눌렀을 때 켜고, 뗬을 때 꺼야 합니다:
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  } 
  else {
    digitalWrite(13, HIGH);
  }
}

