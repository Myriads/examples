/* Blink without Delay
 
 디지털 핀에 연결된 LED를 delay() 함수를 사용하지 않고 ON/OFF 합니다.
 delay() 함수를 사용하면 기다리는 동안에 다른 일을 처리하지 못하는데,
 여기에서는 delay() 함수를 사용하지 않고, 다른 작업을 처리할 수 있게
 만든 예제입니다.
 
 회로:
 * LED를 보호할 저항 220 Ohm을 13번 핀에 연결하고, LED의 아노드와 저항을
   연결하고 LED 캐소드를 GND에 연결합니다.
 * 노트: 대부분의 아두이노 보드들은 LED가 이미 있으며, 핀 13에 연결
         되어 있습니다. 아두이노 보드의 LED를 이용한다면, 별도의 LED와
         저항 그리고 점퍼선들이 필요없습니다.
         
 2005년 David A. Mellis에 의하여 창작
 2010년 2월 8일 Paul Stoffregen에 의하여 수정
 
 이 예제 코드는 공유 저작물입니다.
 
 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

// constants로 선언된 값들은 변경되지 않습니다. 여기에서는 핀 번호를 설정하기
// 위하여 사용되었습니다: 
const int ledPin =  13;      // LED 핀 번호 값

// 값이 변화되는 변수들:
int ledState = LOW;             // LED를 켜고 끄기 위하여 사용되는 ledState 변수
long previousMillis = 0;        // LED를 깜빡인 시간을 저장

// 다음 변수들은 ms(milliseconds)으로 측정된 시간 값이라 int로 저장할 수
// 있는 최대 값보다 빨리 커기지 때문에 long을 사용하였습니다. 
long interval = 1000;           // LED를 깜빡이는 간격(단위는 ms)이며, 1초입니다

// 이 setup 루틴은 리셋 스위치를 누를 때, 한번만 실행됩니다:
void setup() {
  // LED 핀을 출력 핀으로 설정합니다:
  pinMode(ledPin, OUTPUT);      
}

void loop()
{
  // 항상 실행되어야 할 필요가 있는 코드들을 이곳에 넣는 곳입니다.

  // LED를 켜거나 꺼야할 시간인지를 알아봅니다; 즉 전에 LED를 ON/OFF한
  // 시간과 현재 시간의 차가 LED를 ON/OFF할 시간 차보다 크다면, LED를 
  // ON/OFF합니다. 
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    // LED를 ON/OFF한 시간을 저장합니다
    previousMillis = currentMillis;   

    // LED가 꺼져 있으면, 키고 반대면 끕니다:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // ledState 값으로 LED 핀에 씀니다:
    digitalWrite(ledPin, ledState);
  }
  /*
   * 여기에 다른 처리할 일들을 넣어주면 됩니다.
   */
}

