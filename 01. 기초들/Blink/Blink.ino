/*
  Blink
  LED를 1초 동안 켜고, 그리고 나서 1초 동안 LED를 끄는 것을 반복합니다.

  이 예제 코드는 공유 저작물입니다.
*/

// 디지털 13번 핀은 거의 모든 아두이노 보드들에서 LED와 연결되어 있습니다.
// 디지털 13번 핀에 led란 이름을 붙였습니다.
int led = PA1; // LED_BUILTIN;

// 이 setup 루틴은 reset 스위치를 누를 때 한번만 실행됩니다.
void setup() {

  Serial.begin(115200);
  
  // 디지털 13번 핀을 출력 핀으로 초기화합니다.
  pinMode(led, OUTPUT);
  
}


// 이 loop 루틴은 영원히 반복 실행됩니다.
void loop() {
  #define EUC 0
  #if EUC
    /*
     * 아두이노 IDE를 시작하기 전에 미리 preferences.txt 파일에 있는 
     * serial.charset을 다음과 같이 설정
     *  
     *  serial.charset=euc-kr
     * 
     */
    char msg_off[] = {0x4C, 0x45, 0x44, 0xB8, 0xA6, 0x20, 0xB2, 0xFB, 0xB4, 0xCF, 0xB4, 0xD9, 0x00};
    char msg_on[]  = {0x4C, 0x45, 0x44, 0xB8, 0xA6, 0x20, 0xC4, 0xD5, 0xB4, 0xCF, 0xB4, 0xD9, 0x00};
  #else
    /*
     * 아두이노 IDE를 시작하기 전에 미리 preferences.txt 파일에 있는 
     * serial.charset을 다음과 같이 설정
     *  
     * serial.charset=utf-8
     * 
     */
    char msg_off[] = {0x4C, 0x45, 0x44, 0xEB, 0xA5, 0xBC, 0x20, 0xEB, 0x81, 0x94, 0xEB, 0x8B, 0x88, 0xEB, 0x8B, 0xA4, 0x00};
    char msg_on[]  = {0x4C, 0x45, 0x44, 0xEB, 0xA5, 0xBC, 0x20, 0xEC, 0xBC, 0xAD, 0xEB, 0x8B, 0x88, 0xEB, 0x8B, 0xA4, 0x00};
  #endif
  
  Serial.println(msg_off);
  digitalWrite(led, HIGH);   // LED를 켭니다(HIGH는 전압 레벨입니다)
  delay(1000);               // 1초 동안 기다립니다.

  Serial.println(msg_on);
  digitalWrite(led, LOW);    // LED를 전압을 LOW로 만들어 끔니다
  delay(1000);               // 1초 동안 기다립니다

}
