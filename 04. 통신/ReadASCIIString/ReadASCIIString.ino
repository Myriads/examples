/*
  Reading a serial ASCII-encoded string.
  시리얼 통신으로 ASCII 코드 문자열을 읽어 들임 
 
 이 스케치는 Serial 객체의 parseInt() 함수 사용법을 보여 주는
 예제입니다. ','로 분리된 ASCII 문자열이 들어오길 기다렸다가,
 이를 정수로 바꾸고, RGB LED의 밝기를 조절하는데 사용합니다.
 
 회로: 공통 캐소드 RGB LED를 다음과 같이 연결합니다:
 * Red 아노드: 디지털 3번 핀
 * Green 아노드: 디지털 5번 핀
 * Blue 아노드: 디지털 6번 핀
 * 캐소드: GND
 
 예제에는 공통 아노드 타입의 RGB LED를 사용하여 아노드를 +5V에 
 연결하였는데, 여기에서는 공통 캐소드 타입을 사용하여 캐도드를
 GND로 연결하였습니다.

 회로: 공통 아노드 RGB LED를 다음과 같이 연결합니다:
 * Red 캐소드: 디지털 3번 핀
 * Green 캐소드: 디지털 5번 핀
 * Blue 캐소드: 디지털 6번 핀
 * 아노드: +5V
 
 2012년 04월 13일 Tom Igoe에 의하여 창작되었습니다
 
 이 예제 코드는 공유 저작물입니다.
 
 http://arduino.cc/en/Tutorial/ReadASCIIString
 */

// 공통 아노드 LED를 사용할 경우에는 true로 선언합니다:
#define  COMMON_ANODE  false

// RGB LED 연결을 위한 핀들:
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;

void setup() {
  // 시리얼 통신을 위한 초기화를 합니다:
  Serial.begin(9600);
  // 핀들을 출력으로 선언합니다:
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 

}

void loop() {
  // 시리얼 포트에 데이터가 있으면, 읽어 들이고:
  while (Serial.available() > 0) {

    // 시리얼 통신 포트로부터 들어온 스트림 데이터에서 유효한
    // 정수 값을 읽어 들여 빨간색 값으로 넣습니다:
    int red = Serial.parseInt(); 
    // 다음 정수 값을 읽어 들여 녹색 값으로 넣습니다:
    int green = Serial.parseInt(); 
    // 다음 정수 값을 읽어 들여 청색 값으로 넣습니다:
    int blue = Serial.parseInt(); 

    // 입력된 문장(문자열)이 끝났음을 알리는 새줄 문자(LF)
    // 를 기다립니다:
    if (Serial.read() == '\n') {
      // 0 ~ 255사이의 값으로 제한하고 값을 255 ~ 0 값으로 뒤집습니다
      // 만약 공통 캐소드 LED를 사용하면, "constrain(color, 0, 255);"만
      // 사용하여도 됩니다.

#if COMMON_ANODE       
      red = 255 - constrain(red, 0, 255);
      green = 255 - constrain(green, 0, 255);
      blue = 255 - constrain(blue, 0, 255);
#else
      red = constrain(red, 0, 255);
      green = constrain(green, 0, 255);
      blue = constrain(blue, 0, 255);
#endif

      // LED의 RGB 밝기를 red, green, blue 값으로 설정합니다: 
      analogWrite(redPin, red);
      analogWrite(greenPin, green);
      analogWrite(bluePin, blue);

      // 3 숫자를 16 진수(HEX) 값으로"RGB(red, green, blue)" 형태로
      // 시리얼 모니터에 출력합니다:
      Serial.print("RGB(");
      Serial.print(red, HEX);
      Serial.print(",");
      Serial.print(green, HEX);
      Serial.print(",");
      Serial.print(blue, HEX);
      Serial.println(")");
    }
  }
}

