/*
  Multiple tone player (여러 음 연주기)
 
 차례로 핀에 연결되어 있는 여러 스피커로 여러 음을 연주합니다
 
 회로:
 * 8Ω 스피커 3개를 100Ω 저항을 통하여 디지털 6, 7, 11번 핀에
   연결합니다. 스피커의 다른 한 선은 GND에 연결합니다.
 
 2010년 03월 08일에 Greg Borenstein의 정보에 따라 Tom Igoe에 의하여
 창작되었습니다. 

 이 예제 코드는 공유 저작물입니다.
 
 http://arduino.cc/en/Tutorial/Tone4
 
 */

void setup() {

}

void loop() {
   // 디지털 11번 핀의 tone 기능을 OFF 합니다:
   noTone(11);			
  // 디지털 6번 핀에서 200ms 동안 음을 발생시킵니다:
  tone(6, 440, 200);
  delay(200);

  // 디지털 6번 핀의 tone 기능을 OFF 합니다:
  noTone(6);
  // 디지털 7번 핀에서 500 ms 동안 음을 연주합니다:
  tone(7, 494, 500);
  delay(500);
  
  // 디지털 7번 핀의 tone 기능을 OFF 합니다:
  noTone(7);  
  // 디지털 11번 핀에서 300 ms 동안 음을 연주합니다:
  tone(11, 523, 300);
  delay(300);

}
