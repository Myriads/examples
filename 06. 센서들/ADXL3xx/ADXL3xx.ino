
/*
 ADXL3xx

 이 예제 스케치에서는 아날로그 장치인 ADXL3xx 가속도계의 값을 읽어 컴퓨터로 전송
 하며, 시리얼 모니터 창을 열어 읽은 값들을 관찰할 수 있습니다. 
 
 ADXL335B 칩을 탑재한 GY-61 브레이크아웃 보드를 이용하였습니다.
 
 http://www.arduino.cc/en/Tutorial/ADXL3xx
 http://www.analog.com/en/products/mems/accelerometers/adxl335.html#product-overview
 http://www.analog.com/media/en/technical-documentation/application-notes/AN-1057.pdf
 

회로:

 GY-61 보들을 아두이노 우노 보드에 바로 꽂아 연결하였습니다.
 
 아날로그 1번 핀: GND
 아날로그 2번 핀: Z 축
 아날로그 3번 핀: Y 축
 아날로그 4번 핀: X 축
 아날로그 5번 핀: VCC

 2008년 07월 02일 David A. Mellis에 의하여 창작되었으며
 2011년 08월 30일 Tom Igoe에 의하여 수정되었습니다
 2016년 08월 03일 수정되었습니다.

 이 예제 코드는 공유 저작물입니다.

*/

// 이 상수 값들은 사용된 핀들을 정의하고 있으며, 변경되지 않습니다:
const int groundpin = A1;             // 아날로그 1번 핀 -- GND
const int powerpin = A5;              // 아날로그 5번 핀 -- VCC
const int xpin = A4;                  // 가속도계의 X 축 센서
const int ypin = A3;                  // 가속도계의 Y 축 센서
const int zpin = A2;                  // 가속도계의 Z 축 센서(3축 모델에서만)

void setup() {
  // 시리얼 통신을 위하여 초기화합니다:
  Serial.begin(9600);

  // 일반적인 디지털 핀들과 같이 아날로그 핀을 이용하여 GND와 전원을
  // 공급합니다.  이와 같이 하여 아두이노에 브레이크아웃 보드를 직접
  // 연결할 수 있습니다.  만약 아두이노의 일반 5V와 GND를 이용한다면,
  // 이 연결들을 없앨 수 있습니다.
  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  digitalWrite(groundpin, LOW);
  digitalWrite(powerpin, HIGH);
}

void loop() {
  int x, y, z;
  
  // 센서 값들을 출력합니다:
  x = analogRead(xpin);
  Serial.print("x: ");
  Serial.print(x);
  
  // 값들 사이에 탭을 출력합니다:
  y = analogRead(ypin);
  Serial.print("\ty: ");
  Serial.print(y);
  
  // 값들 사이에 탭을 출력합니다:
  z = analogRead(zpin);  
  Serial.print("\tz: ");
  Serial.print(z);  
  Serial.println();

  // 다음 센서 값을 읽을 때까지 100ms 기다렸다가 다시 시작합니다:
  delay(100);
}

