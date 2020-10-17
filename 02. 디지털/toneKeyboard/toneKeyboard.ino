/*
  keyboard
 
 이 스케치는 아날로그 입력 핀들의 변화된 상태를 감지하여 그 핀에 해당된
 음을 들려주는 예제입니다.
 
 회로:
 * 3개의 힘 감지 저항기(force-sensing resistor)를 아날로그 0번 핀에서
   2번 핀까지 각각 연결하며, 다른 한 핀은 +5V에 연결합니다.
 * 3개의 10K 저항을 각각 아날로그 0번 핀에서 2번 핀에 연결하고 저항의
   다른 쪽은 GND에 연결합니다.
 * 8Ω 스피커를 100Ω 저항을 통하여 디지털 8번 핀에 연결합니다. 스피커의
   다른 한 선은 GND에 연결합니다.
 
 2010년 01월 21일에 창작되었고,
 2012년 04월 09일에 Tom Igoe에 의하여 수정되었습니다.
 2014년 08월 27일에 Wayfarer에 의하여 수정되었습니다.

 이 예제 코드는 공유 저작물입니다.
 
 http://arduino.cc/en/Tutorial/Tone3
 
 */

#include "pitches.h"

#define THRESHOLD_OK true

// const int threshold = 10;    // 음을 생성할 센서들의 최소 입력 값
const int threshold = 900;    // 음을 생성할 센서들의 최소 입력 값

// 각각 3개의 센서에 해당된 연주할(들려줄) 음(음표)들:
int notes[] = {
  NOTE_A4, NOTE_B4,NOTE_C5 };

void setup() {
#if(!THRESHOLD_OK)
  Serial.begin(9600);
#endif
}

void loop() {

#if(!THRESHOLD_OK)
    Serial.println(analogRead(A0));
#endif

#if(THRESHOLD_OK)
  for (int thisSensor = 0; thisSensor < 3; thisSensor++) {
    // 3개의 센서중 1개의 센서를 읽어들입니다:
    int sensorReading = analogRead(thisSensor);
    
    // 센서가 강하게 눌렸는지 확인합니다:
    if (sensorReading > threshold) {
      // 눌려진 센서에 해당된 음을 연주합니다(들려줍니다):
      tone(8, notes[thisSensor], 20);
    }
  }
#endif    
}
