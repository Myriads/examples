
/*
   Melody (멜로디)
  
  이 스케치는 tone() 함수를 이용하여 멜로디를 연주하는 예제입니다.
  멜로디를 "학교종이" 한 소절로 바꾸었습니다.
  
  회로:
 * 8Ω 스피커를 100Ω 저항을 통하여 디지털 8번 핀에 연결합니다. 스피커의
   다른 한 선은 GND에 연결합니다.
  
 2010년 01월 21일에 창작되었고,
 2012년 04월 09일에 Tom Igoe에 의하여 수정되었습니다.
 2014년 08월 28일에 Wayfarer에 의하여 수정되었습니다.

 이 예제 코드는 공유 저작물입니다.
  
  http://arduino.cc/en/Tutorial/Tone
  
  */
#include "pitches.h"

// 멜로디를 위한 음표들:
int melody[] = {
   NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_E4,
   NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_D4, 0,
};

// 음표 길이들: 4 = 4분(1/4) 음표, 8 = 8분(1/8) 음표, 그밖의 것들.:
int noteDurations[] = {
   4, 4, 4, 4, 4, 4, 2,
   4, 4, 4, 4, 2, 2,
};

void setup() {
   // melody[] 배열(array)에 있는 모든 음표들을 연주합니다:
   for (int thisNote = 0; thisNote < sizeof(noteDurations)/sizeof(int); thisNote++) {

     // 음표 길이를 계산하기 위하여, 1초를 음표 타입으로 나눕니다. 
     // 예를 들어, 4분 음표 = 1000 / 4,  8분 음표 = 1000/8 등과 같이
     // 합니다.
     int noteDuration = 1000/noteDurations[thisNote];
     tone(8, melody[thisNote],noteDuration);

     // 음표들을 구분하기 위하여, 음표 사이에 최소한의 지연 시간을
     // 음표 길이 + 30%가 잘 동작하는 것 같습니다:
     int pauseBetweenNotes = noteDuration * 1.30;
     delay(pauseBetweenNotes);
     // 음 발생하는 것을 멈춤니다:
     noTone(8);
   }
}

void loop() {
   // 멜로디 연주를 반복할 필요는 없습니다.
}


