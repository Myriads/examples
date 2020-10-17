/* PING))) 센서
  
   이 스케치는 PING))) 초음파 거리 측정기의 초음파를 읽어 가까운
   거리에 있는 물체의 거리를 측정하는 예제입니다. 물체의 거리는
   센서에서 초음파를 물체로 쏘고, 물체에서 반사된 초음파를 센서가
   감지한 시간을 재면, 거리를 측정할 수 있습니다. 측정된 시간은
   물체의 거리와 비례합니다.

   여기에서는 HC-SR04 초음파 센서를 사용하였습니다.
     
   회로:
	* HC-SR04의 +V를 아두이노 +5V에 연결
	* HC-SR04의 GND를 아두이노 GND에 연결
	* HC-SR04의 Trig 신호를 아두이노 디지털 7번 핀에 연결
  * HC-SR04의 Echo 신호를 아두이노 디지털 6번 핀에 연결

   http://www.arduino.cc/en/Tutorial/Ping
   
   2008년 11월 03일 David A. Mellis에 의하여 창작되었으며
   2011년 08월 30일 Tom Igoe에 의하여 수정되었습니다
   2016년 08월 05일에 수정되었습니다
 
   이 예제 코드는 공유 저작물입니다.

 */
 
// 이 상수는 값이 변하지 않으며, 센서에게 초음파를 내보내게
// 하고, 반사된 초음파를 감지하기 위하여 핀들이 사용됩니다:
const int trigPin = 7;
const int echoPin = 6;

void setup() {
  // 시리얼 통신을 위하여 초기화합니다:
  Serial.begin(9600);
  
  // 사용할 핀들을 용도에 맞게 설정합니다:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  // 핑 주기와 측정 거리를 센티미터와 인치로 나타내기 위한 변수들을 
  // 정의합니다:
  long duration, inches, cm;

  // 초음파 센서에의 trigPin에 10us 보다 긴 HIGH 신호를 주면 초음파를
  // 내보냅니다. HIGH 신호를 주기 전에 미리 LOW 신호를 주어, 명확한
  // HIGH 신호가 되게 합니다:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 초음파 센서로 부터 반사된 초음파를 감지하기 위하여 echoPin 핀이
  // 사용됩니다: 초음파을 내보내고 물체로부터 반사된 초음파을 
  // 받을 때까지 HIGH 값이 들어옵니다.
  duration = pulseIn(echoPin, HIGH);

  // 시간을 거리로 바꿉니다
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("\"(인치), ");
  Serial.print(cm);
  Serial.print("cm(센티)");
  Serial.println();
  
  delay(100);
}

long microsecondsToInches(long microseconds)
{
  // Parallax 사의 PING))) 데이터 시트에 따르면, 인치당 73.746us가 
  // 걸립니다(즉 소리는 초당 1130 피트를 가게됩니다). 핑을 보내고,
  // 받은 시간 즉 왕복에 걸린 시간이기 때문에 2로 나눠주어야 합니다.
  // 참조: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // 소리의 속도는 340 m/s 혹은 29 us/cm 입니다. 핑을 보내고 받은 시간
  // 이라, 측정된 시간의 반 값이 물체와의 거리입니다.
  return microseconds / 29 / 2;
}
