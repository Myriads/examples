/*
  Renaming Serial Ports(시리얼 포트 이름 바꾸기)

 시리얼 포트 1(Serial1)에 데이터가 있으면 이를 받아 메인 시리얼(Serial)
 포트로 보내고, 메인 시리얼 포트에 데이터가 있으면 이를 받아 시리얼 포트
 1로 보내는 작업을 반복합니다.
 
  이 예제 스케치는 1개 이상의 시리얼 통신 포트를 지닌 아두이노 메가, 두에
  혹은 제로와 같은 보드에서 동작하는 것을 소프트 시리얼 포트를 사용하게
  하여 우노와 나노 보드들에서도 동작하게 수정하였으며, 시리얼 포트 이름을
  다르게 바꿔 사용하였습니다.
 
 회로:
 * 시리얼1 포트에 시리얼 통신을 할 수 있는 장치를 연결합니다. 아두이노의
   USB2Serial 보드나 FTDI USB 2 Serial 보드를 연결합니다.
   
 * 메인 시리얼 포트에 시리얼 모니터를 나타나게 PC에 연결합니다:

 2008년 12월 30일에 창작되었으며,
 2012년 05월 20일에 Tom Igoe와 Jed Roach에 의하여 수정되었으며,
 2015년 11월 27일에 Arturo Guadalupi에 의하여 수정되었습니다.
 2016년 06월 06일에 수정되었습니다.

 이 예제 코드는 공유 저작물입니다.

 */
#define CR  0x0D
#define LF  0x0A

// 주(main) 시리얼 통신 포트인 H/W Serial을 "Monitor"로 사용
HardwareSerial& Monitor = Serial;
HardwareSerial *p = &Serial;

// H/W 시리얼 1포트가 있으므로 이를 "Terminal"로 사용
#if defined(UBRR1H)
  HardwareSerial& Terminal = Serial1;

// H/W 시리얼 1포트가 없으므로 S/W 시리얼을 "Terminal"로 사용
#else
  #include <SoftwareSerial.h>

  SoftwareSerial Terminal(10, 11);  // 10 : RX, 11: TX
#endif // UBRR1H

void setup() {
  // 2 시리얼 통신 포트들을 9600bps로 초기화합니다:
  Monitor.begin(9600);
  Terminal.begin(9600);

  Serial.println((int)&p, HEX);
  Serial.println((int)&Serial, HEX);
  
}

void loop() {  
  // "Terminal"에서 데이터를 읽어, "Monitor"로 보냅니다:
  if (Terminal.available()) {
    int inByte = Terminal.read();
    
    if(inByte == CR) {
      Monitor.write(CR);
      Monitor.write(LF);
    }
    else if (inByte != LF)
      Monitor.write(inByte);
  }

  // "Monitor" 포트에서 데이터를 읽어, "Terminal" 포트로 보냅니다:
  if (Monitor.available()) {
    int inByte = Monitor.read();
    
    if(inByte == CR) {
      Terminal.write(CR);
      // Terminal.write(LF);
    }
    else if (inByte != LF)
      Terminal.write(inByte);
  }
}
