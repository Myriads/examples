/*
  Switch statement (switch 문)

 이 스케치는 switch 문의 사용법을 보여주는 한 예입니다. switch 문은
 변수의 값이 여러 개일 경우, 각각의 값을 선택적으로 처리할 수 있게 
 합니다. if 문 여러 개를 연속하여 사용한 것과 같습니다.

 이 스케치가 동작하는 것을 관찰 하기 위해서는 보드와 센서를 조명이 밝은
 곳에 놓고, 시리얼 모니터 창을 열고 손을 센서 위에서 밑으로 서서히 내려
 주면 됩니다.
 
 회로:
 * 아날로그 핀 0에 포토레지스터를 한 핀을 연결하고, 다른 핀은 +5V
   에 연결합니다. 
 * 아날로그 핀 0에 10KΩ 저항을 PULL-DOWN으로 연결합니다. 

 2009년 07월 01일에 창작되었으며,
 2012년 04월 09일에 Tom Igoe에 의하여 수정되었습니다.

 이 예제 코드는 공유 저작물입니다.

 http://www.arduino.cc/en/Tutorial/SwitchCase
 */

// 이 상수 변수들은 결코 변하지 않으며, 이 값들은 센서로부터 얻은
// 가장 낮은 값과 가장 높은 값들입니다:
const int sensorMin = 560;    // 실험을 통하여 얻은 센서 최소 값
const int sensorMax = 896;    // 실험을 통하여 얻은 센서 최대 값

void setup() {
  // 시리얼 통신을 위하여 초기화합니다:
  Serial.begin(9600);
}

void loop() {
  // 센서를 읽어 들입니다:
  int sensorReading = analogRead(A0);
  sensorReading = constrain(sensorReading, sensorMin, sensorMax);
  
  // 읽어들인 센서 값들을 0 ~ 3 사이의 한 값으로 변환합니다:
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
 
  // range 변수의 여러 경우의 값에 따라 다르게 처리합니다:
  switch (range) {
    case 0:    // 센서를 완전히 가렸을 때
      Serial.println("깜깜함");
      break;
    case 1:    // 센서에 아주 가까이 있을 때
      Serial.println("어두움");
      break;
    case 2:    // 센서에 조금 떨어져 있을 때
      Serial.println("보통");
      break;
    case 3:    // 센서에 떨어져 있을 때
      Serial.println("밝음");
      break;
  }
  delay(1);        // ADC의 다음 동작을 위하여 휴식을 잠시 갖습니다 
}

