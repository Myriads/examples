/*
  Pitch follower (음 추종기)
 
 변화하는 아날로그 입력에 따라 변화되는 음을 연주합니다
 
 회로:
 * 8Ω 스피커를 100Ω 저항을 통하여 디지털 9번 핀에 연결합니다.
   스피커의 다른 한 선은 GND에 연결합니다
 * 포토레지스터 한 핀을 아날로그 0핀에 연결합니다. 다른 한 핀은 +5V에
   연결합니다
 * 4.7KΩ 저항을 아날로그 0핀에 Pull Down(저항 한 쪽을 GND에 연결)으로
   연결합니다
 
 2010년 01월 21일에 창작되었으며,
 2012년 05월 31일에 Michael Flynn의 제안에 TomIgoe에 의하여 수정되었습니다.
 2014년 08월 28일에 Wayfarer에 의하여 수정되었습니다
 
 이 예제 코드는 공유 저작물입니다.
 
 http://arduino.cc/en/Tutorial/Tone2
 
 */

int minSensorValue=1023, maxSensorValue=0;

void setup() {
  // 시리얼 통신을 초기화합니다 (포토레지스터 센서의 최소, 최대값을
  // 얻기 위함):
  Serial.begin(9600);
}

void loop() {
  // A0에 연결된 센서를 읽어 들입니다:
  int sensorReading = analogRead(A0);
  
  // 최소, 최대값을 얻습니다:
  if(sensorReading < minSensorValue)
    minSensorValue = sensorReading;
  if(sensorReading > maxSensorValue)
    maxSensorValue = sensorReading;
    
  // 범위를 알 수 있게 시리얼 모니터로 출력합니다
  Serial.print(String("최소:" + String(minSensorValue) + " "));
  Serial.print(String("최대:" + String(maxSensorValue) + " "));
  Serial.println(sensorReading);
  
  // 아날로그 입력 값(이 경우에는, 포토레지스터로부터 얻은 400 - 1000)을
  // 출력할 음의 주파수 값(120 - 1500Hz)으로 바꿉니다
  // map 함수에 사용되는 최소값과 최대값을 포토레지스터에서 얻은 최소값과
  // 최대값으로 바꿔주어야 합니다:
  int thisPitch = map(sensorReading, 283, 768, 120, 1500);

  // 음을 연주합니다:
  tone(9, thisPitch, 10);
  delay(1);        // 안정된 값을 읽기 위하여 지연시간을 갖습니다
}

