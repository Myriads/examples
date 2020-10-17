/*
  Switch statement with serial input 
  (switch 문을 이용한 시리얼 입력 처리)

 switch 문의 사용 방법을 보여주는 예제입니다. switch 문은 변수가
 각기 다른 여러 개의 값을 가질 수 있는 경우, 각각의 값들에 따라
 다른 일을 처리할 수 있게 합니다. if 문을 여러개 연속하여 사용한
 것과 같습니다.

 이 스케치가 동작하는 것을 보기 위해서는, 시리얼 모니터 창을 열고
 영문 소문자 a, b, c, d, 그리고 e를 보내면, 이에 해당된 LED를 켜고
 만약 다른 글자들을 보내면 모든 LED들을 끄는 작업을 수행합니다.

 회로:
 * 5개의 LED들을 220Ω 저항을 통하여 디지털 2번 핀에서 6번 핀까지 
   연결합니다
   
 2009년 07월 01에 Tom Igoe에 의하여 창작되었습니다

 이 예제 코드는 공유 저작물입니다.

 http://www.arduino.cc/en/Tutorial/SwitchCase2
 */

void setup() {
  // 시리얼 통신을 위하여 초기화합니다:
  Serial.begin(9600);
  // LED에 연결된 핀들을 출력 핀으로 설정합니다:
  for (int thisPin = 2; thisPin < 7; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  // 시리얼 포트에 받을 데이터가 있는지 확인합니다:
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    // 받은 문자에 따라 다른 작업을 실행합니다. switch 문에 사용된
    // case 문은 뒤에 사용된 숫자 값과 일치되어야 동작합니다:
    // 여기에서는 작은(홑) 따옴표가 사용되어 ASCII 문자(char)
    // 값이 사용됨을 알려 주고 있습니다. 예를 들면 'a'는 97, 'b'는
    // 98, 등등

    switch (inByte) {
      case 'a':
        digitalWrite(2, HIGH);
        break;
      case 'b':
        digitalWrite(3, HIGH);
        break;
      case 'c':
        digitalWrite(4, HIGH);
        break;
      case 'd':
        digitalWrite(5, HIGH);
        break;
      case 'e':
        digitalWrite(6, HIGH);
        break;
      case '\r':
      case '\n':
        break;
        
      default:
        // 모든 LED를 끕니다:
        for (int thisPin = 2; thisPin < 7; thisPin++) {
          digitalWrite(thisPin, LOW);
        }
    }
  }
}

