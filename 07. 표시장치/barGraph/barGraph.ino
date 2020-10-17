/*
  LED 막대 그래프(Bar Graph)

  여러개의 LED들을 이용하여 값을 나타내는 예제입니다. 원래는
  가변 저항을 A0에 연결하고 이 값을 읽어들여 막대 그래프와 같이
  표시하였지만, 0에서 LED 숫자까지 올려가면서 LED를 ON하고, LED
  숫자에서 0까지 줄여가면서 OFF하는 것으로 바꿔 보았습니다^^

  LED를 추가할 때는 ledPins[]에 새로 추가한 LED와 연결한 디지털
  핀 값을 넣으면 되며, 반대로 빼낼 때에는 디지털 핀 값을 없애면
  됩니다.
   
  이 방법을 아날로그 입력 값을 일련의 디지털 출력 값들을 제어하는
  용도로 활용할 수 있습니다. 

  회로:
   * LED 10개의 어노드(애노드, anode) 핀들을 각각 디지털 핀 2번에서 
     11번까지 연결하고, 각각의 캐소드 핀들을 220Ω 저항들과 연결하여
     GND로 연결합니다.

 2010년 09월 04일 Tom Igoe에 의하여 창작되었으며
 2016년 06월 19일에 수정되었습니다

 이 예제 코드는 공유 저작물입니다.

 http://www.arduino.cc/en/Tutorial/BarGraph
 */

int ledPins[] = {
  2, 3, 4, 5, 6, 7, 8, 9, 10, 11
};   // LED와 연결된 디지털 핀들의 배열

// 상수 값은 변하지 않습니다:
// 막대 그래프에서 사용된 LED 갯 수
const int ledCount = sizeof(ledPins) / sizeof(int);
const int DELAY = 1000; // 1 second


void setup() {
  // LED 핀 배열에 들어 있는 디지털 핀들을 모두 출력 핀 모드로
  // 설정합니다:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
}

void loop() {  
  
  // 첫 번째 LED에서 10 번째 LED를 차례로 ON합니다:
  for(int i = 0; i < ledCount; i++) {
    displayBarGraph(i);
  }

  // 10 번째 LED부터 0번째 LED를 차례로 OFF합니다:  
  for(int i = ledCount; i >= 0; i--) {
    displayBarGraph(i);
  }
}

void displayBarGraph(int level) {
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    // level 값이 LED 핀 배열의 차례(인덱스: index, 혹은 위치: position)
    // 값보다 크면 그 밑에 있는 LED들은 ON:
    if (thisLed < level) {
      digitalWrite(ledPins[thisLed], HIGH);
    }
    // LED 핀 배열의 차례 값보다 작은 LED들은 OFF:
    else {
      digitalWrite(ledPins[thisLed], LOW);
    }
  }
  delay(DELAY);
}

