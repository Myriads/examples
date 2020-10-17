/*
  Analog input, analog output, serial output (아날로그 입력, 아날로그
  출력, 시리얼 출력)
 
 아날로그 입력 핀 값을 읽어 들여 값을 0에서 255 사이의 값으로 바꾸고
 진폭변조(PWM: Pulse Width Modulation)하여 아날로그 핀으로 출력하고,
 시리얼 모니터로도 출력합니다.
 
 회로:
 * 가변 저항의 가운데 핀을 아날로그 0핀에 연결하고, 가변 저항의 한쪽
   핀은 GND에 다른 한쪽은 +5V에 연결합니다.
 * 220Ω 저항 한쪽을 디지털 9번 핀에 연결하고 저항 다른 한쪽을 LED의
   아노드에 연결합니다. LED의 캐소드를 GND에 연결합니다
 
 2008년 12월 29일에 창작되었으며,
 2012년 04월 09일에 Tome Igoe에 의하여 수정되었습니다
 
 이 예제 코드는 공유 저작물입니다.
 
 http://arduino.cc/en/Tutorial/AnalogInOutSerial
 
 */

// 이 상수(constant) 값들은 값이 변하지 않으며, 사용되는 핀들에 이름을
// 붙여 주기 위하여 사용되었습니다:
const int analogInPin = A0; // 가변 저항이 연결된 아날로그 입력 핀
const int analogOutPin = 9; // LED가 연결된 아날로그 출력 핀

int sensorValue = 0;        // 가변 저항에서 읽은 값
int outputValue = 0;        // PWM으로 변환된 출력 값

void setup() {
  // 시리얼 통신 속도를 9600 bps로 설정합니다:
  Serial.begin(9600); 
}

void loop() {
  // 아날로그 입력 값을 읽습니다:
  sensorValue = analogRead(analogInPin);            
  // map 함수를 이용하여 아날로그 출력 값으로 변환합니다:
  outputValue = map(sensorValue, 0, 1023, 0, 255);  
  // 출력 핀에 아날로그 출력 값을 씁니다:
  analogWrite(analogOutPin, outputValue);           

  // 시리얼 모니터에 아날로그 입력 값과 출력 값을 출력합니다:
  Serial.print("센서 = " );
  Serial.print(sensorValue);      
  Serial.print("\t 출력 = ");      
  Serial.println(outputValue);   

  // 마지막으로 아날로그 입력 값을 읽은 후 아날로그-디지털 변환기(ADC:
  // Analog-Digital Converter)가 안정될 수 있게 2ms 동안 지연 시간을
  // 갖습니다:
  delay(2);                     
}
