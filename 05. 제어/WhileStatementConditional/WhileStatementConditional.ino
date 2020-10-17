/*
  Conditionals - while statement
  (조건문들 - while 문)
 
 이 스케치는 while() 문의 사용법을 보여주는 한 예입니다.
 
 푸시 버튼이 눌려지고 있는 동안, 스케치는 포토레지스터의 최소, 최대
 값을 결정하기 위한 calibration 루틴을 실행합니다.
 
 이 예제는 03.Control | Calibration 예제와 같은 영점 조정을 하는 다른
 한 예입니다.
  
 회로:
 * 포토레지스터의 한 핀을 +5V에 연결하고 다른 한 핀은 아날로그 0핀에
   연결합니다
 * 10KΩ 저항을 아날로그 0 핀에 PULL-DOWN으로 연결합니다
 * LED 아노드 핀을 디지털 9번 핀에 연결하고 캐소드 핀을 220Ω 저항을
   통하여 GND로 연결합니다
 * 푸시 버튼을 디지털 2번 핀에 연결하고 다른 핀을 +5V에 연결합니다
 * 10KΩ 저항을 디지털 2번 핀에 PULL-DOWN으로 연결합니다
 
 2009년 01월 17일에 창작 되었으며
 2011년 08월 30일에 Tom Igoe에 의하여 수정되었습니다
 
 이 예제 코드는 공유 저작물입니다

 http://arduino.cc/en/Tutorial/WhileLoop
 http://blog.naver.com/msyang59/220143672619
 
 */


// 이 상수(const) 변수들은 값이 결코 변하지 않습니다:
const int sensorPin = A0;       // 센서가 연결된 핀
const int ledPin = 9;           // LED가 연결된 핀
const int indicatorLedPin = 13; // 아두이노 보드 LED가 연결된 핀
const int buttonPin = 2;        // 버튼이 연결된 핀


// 값이 변하는 변수들:
int sensorMin = 1023;  // 센서 최소 값
int sensorMax = 0;     // 센서 최대 값
int sensorValue = 0;   // 읽어들인 센서 값


void setup() {
  // LED 핀들은 출력핀으로 버튼 핀은 입력핀으로 설정합니다:
  pinMode(indicatorLedPin, OUTPUT);
  pinMode (ledPin, OUTPUT);
  pinMode (buttonPin, INPUT);
}

void loop() {
  // 버튼이 눌려있는 동안은 영점 조정을 실행합니다:
  while (digitalRead(buttonPin) == HIGH) {
    calibrate(); 
  }
  // 영점 조정이 끝났다는 것을 알려주기 위한 신호로 아두이노 보드에
  // 있는 LED를 끕니다
  digitalWrite(indicatorLedPin, LOW);  

  // 센서 값을 읽어 들입니다:
  sensorValue = analogRead(sensorPin);

  // 영점 조정한 값을 적용하여 0 ~ 255 사이의 값으로 변환합니다
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // 변환한 값이 0 ~ 255 값을 벗어나지 않게 합니다
  sensorValue = constrain(sensorValue, 0, 255);

  // 영점 조정된 값을 이용하여 LED의 밝기를 설정합니다:
  analogWrite(ledPin, sensorValue);
}

void calibrate() {
  // 영점 조정이 진행되고 있음을 나타내기 위하여 아두이노 보드의 LED를
  // 켭니다:
  digitalWrite(indicatorLedPin, HIGH);
  // 센서를 읽어들입니다:
  sensorValue = analogRead(sensorPin);

  // 최대 값을 기록합니다
  if (sensorValue > sensorMax) {
    sensorMax = sensorValue;
  }

  // 최소 값을 기록합니다
  if (sensorValue < sensorMin) {
    sensorMin = sensorValue;
  }
}


