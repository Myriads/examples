/* 노크 센서

   이 스케치는 피에조 부품을 이용하여 노크 소리를 알아내는
   예제입니다. 설정된 임계값과 아날로그 핀에 연결된 피에조의
   읽은 값과 비교하여 읽은 값이 크면, 시리얼 모니터에 "똑똑
   계세요?"를 출력하고 13번 핀에 연결된 LED를 토글합니다.
   
   회로:
	* 피에조 +를 아날로그 A0 핀에 연결합니다
	* 피에조 -를 GND에 연결합니다
	* 1MΩ 저항을 아날로그 A0핀과 GND로 연결합니다

   http://www.arduino.cc/en/Tutorial/Knock
   
   2007년 03월 25일 David Cuartielles <http://www.0j0.org>에
                    의하여 창작되었으며,
   2011년 08월 30일 Tom Igoe에 의하여 수정되었습니다
   
   이 예제 코드는 공유 저작물입니다.

 */
 

// 값이 변하지 않는 상수들:
const int ledPin = 13;      // 디지털 13번 핀에 LED가 연결되었습니다
const int knockSensor = A0; // 피에조 +는 A0에 연결되었습니다
const int threshold =  100; // 노크 소리로 판단하기 위한 임계값


// 값이 변하는 변수들:
int sensorReading = 0;      // 센서 핀으로부터 읽은 값을 저장
int ledState = LOW;         // LED를 토클하기 위한 LED의 최근 상태

void setup() {
 pinMode(ledPin, OUTPUT);   // ledPin을 OUTPUT으로 선언
 Serial.begin(9600);        // 시리얼 포트 초기화
}

void loop() {
  // 센서 값을 읽어 sensorReading 변수에 저장합니다:
  sensorReading = analogRead(knockSensor);

  // 만약 읽은 값이 임계값보다 크면:
  if (sensorReading >= threshold) {
    // ledPin 상태를 바꾸고:
    ledState = !ledState;   
    // 상태에 맞게 LED 핀에 값을 씁니다:        
    digitalWrite(ledPin, ledState);
    // 시리얼 모니터에 메시지를 출력하고 줄을 바꿔줍니다
    Serial.println("똑똑! 계세요?");         
  }
  
  delay(100);  // 시리얼 포트에 과부하가 걸리지 않게 지연 시간을
               // 갖습니다
}

