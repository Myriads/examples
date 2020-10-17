/*
  State change detection (상태 변화 감지 또는 에지 감지)
 	
 간혹, 디지털 입력 상태를 항상 알아야 할 필요는 없고, 한 상태에서
 다른 상태로 변화될 때만 감지할 필요가 있을 수 있습니다. 예를 들어
 버튼이 OFF 상태에서 ON 상태로 변화되는 것을 알고자 한다면, 이것이
 바로 상태 변화 감지 또는 에지 감지(탐지)라고 할 수 있습니다.
 
 이 예제는 버튼이 ON에서 OFF로 OFF에서 ON으로 변화되는 것을 탐지하는 
 방법을 보여줍니다.
 
 회로:
 * 푸시버튼을 +5V와 디지털 2번 핀과 연결합니다
 * 10K 저항을 디지털 2번 핀과 접지에 연결합니다
 * 아두이노 보드에 기본으로 제공되는 디지털 13번 핀에 연결되어 있는
   LED를 사용합니다.
 
 2005년 09월 27일에 창작되었고
 2011년 08월 30일에 Tom Igoe에 의하여 수정되었습니다
 
 이 예제 코드는 공유 저작물입니다.
 	
 http://arduino.cc/en/Tutorial/ButtonStateChange
 
 */

// constants로 선언된 값들은 변경되지 않습니다:
const int  buttonPin = 2;    // 푸시 버튼이 연결된 핀 번호
const int ledPin = 13;       // LED가 연결된 핀 번호

// 값이 변화되는 변수들:
int buttonPushCounter = 0;   // 버튼이 눌린 수를 세기 위한 카운터 
int buttonState = 0;         // 현재의 버튼 상태
int lastButtonState = 0;     // 전 버튼 상태

void setup() {
  // 버튼 핀을 입력(INPUT)으로 초기화합니다:
  pinMode(buttonPin, INPUT);
  // LED 핀을 출력(OUTPUT)으로 초기화합니다:
  pinMode(ledPin, OUTPUT);
  // 시리얼 통신 속도를 9600bps(bits per second)로 초기화합니다:
  Serial.begin(9600);
}


void loop() {
  // 푸시 버튼의 상태를 읽어 buttonState에 보관합니다:
  buttonState = digitalRead(buttonPin);

  // 현재의 버튼 상태와 전에 저장한 버튼 상태를 비교합니다
  if (buttonState != lastButtonState) {
    // 만약 상태가 변하였다면, 카운터 값을 증가시킵니다
    if (buttonState == HIGH) {
      // 현재 버튼 상태가 HIGH이면 즉 버튼이 눌려진 것이며
      // OFF에서 ON으로 된 것입니다:
      buttonPushCounter++;
      Serial.print("ON");
      Serial.print(" 버튼이 눌린 수:  ");
      Serial.println(buttonPushCounter);
    } 
    else {
      // 만약 현재 버튼 상태가 LOW이면 버튼이 ON에서 OFF로
      // 간 것입니다:
      Serial.println("OFF"); 
    }
  }
  // 현재의 상태를 전 버튼 상태로 저장하여 놓습니다, 
  // loop()에서 계속 반복 실행될 때 활용하기 위함입니다.
  lastButtonState = buttonState;

  
  // 버튼이 4번 눌렀을 때마다 LED를 켭니다. 4번 눌린 것을 알아내는 방법은
  // 카운터 값을 4로 나눠 나머지 값이 0가 되는 가를 확인하는 '%' modulo 
  // 함수를 이용하는 것입니다. modulo 함수는 두 수를 나눠 나머지 값을
  // 결과값으로 줍니다: 
  if (buttonPushCounter % 4 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
   digitalWrite(ledPin, LOW);
  }  
}

