/*
  Analog Input (아날로그 입력)
  
 아날로그 핀 A0에 연결된 아날로그 센서를 analogRead() 함수를 이용하여
 읽어 들이고, 디지털 13번 핀에 LED를 읽어들인 값만큼 ON하고 OFF하는
 예제입니다.
 
 회로:
 * 가변 저항의 가운데 핀을 아날로그 0핀에 연결하고, 가변 저항의 한쪽
   핀은 GND에 다른 한쪽은 +5V에 연결합니다.
 * 220Ω 저항 한쪽을 디지털 13번 핀에 연결하고 저항 다른 한쪽을 LED의
   아노드(다리가 긴쪽)에 연결합니다. LED의 캐소드(다리가 짧은 쪽)를
   GND에 연결합니다
 
 * 노트: 대부분의 아두이노 보드들은 기본적으로 LED가 13번 핀에 연결되어
         있어 별도의 LED를 연결하는 것은 선택 사항입니다.
 
 
 David Cuartielles에 의하여 창작되었으며,
 2011년 08월 30일 Tom Igoe에 의하여 수정되었습니다.
 
 이 예제 코드는 공유 저작물입니다.
 
 http://arduino.cc/en/Tutorial/AnalogInput
 
 */

int sensorPin = A0;   // 가변 저항(potentiometer)를 읽기 위한 입력 핀
int ledPin = 13;      // LED를 위한 출력 핀
int sensorValue = 0;  // 센서로부터 읽은 값을 저장하기 위한 변수

void setup() {
  // ledPin을 OUTPUT으로 선언:
  pinMode(ledPin, OUTPUT);  
}

void loop() {
  // 센서로부터 값을 읽어들입니다:
  sensorValue = analogRead(sensorPin);    
  // ledPin을 ON 합니다
  digitalWrite(ledPin, HIGH);  
  // 읽어들인 센서 값 sensorValue 만큼 ms 단위로 기다립니다:
  delay(sensorValue);          
  // ledPin를 OFF 합니다:
  digitalWrite(ledPin, LOW);   
  // 읽어들인 센서 값 sensorValue 만큼 ms 단위로 기다립니다:
  delay(sensorValue);
}
