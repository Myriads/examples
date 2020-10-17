/*

  Smoothing (평활화: 평평하고 매끄럽게 하기)

  이 스케치는 아날로그 입력 핀으로부터 센서 값을 반복하여 읽어 들이고, 
  전에 읽어 놓은 값들과 지금 읽은 값을 이용하여 평균값을 계산하여 이를
  컴퓨터로 출력합니다. 배열에 10개의 읽은 값들이 있고, 가장 오래된 값은
  버리고 새로 읽은 값을 넣은 이 10개로 평균을 만드는 예제입니다.
  
  회로:
    * 아날로그 센서(가변 저항)를 아날로그 A0 입력핀에 연결합니다

  2007년 04월 22일 David A. Mellis  <dam@mellis.org>에 의하여 창작
  되었으며,
  2012년 04월 09일에 Tom Igoe에 의하여 수정 되었습니다
  
  http://www.arduino.cc/en/Tutorial/Smoothing
  
  이 예제 코드는 공유 저작물입니다.

*/


// 평균값을 얻기 위한 표본 갯수를 정합니다. 값이 클수록 보다 완만한 
// 값을 얻을 수 있지만, 입력값의 변화에 늦게 응답하게 됩니다. 일반
// 변수가 아닌 상수를 사용함으로써, 센서값을 저장하는 배열의 크기를
// 결정할 수 있습니다.
const int numReadings = 10;

int readings[numReadings];      // 아날로그 입력핀으로부터 읽은 값들
int index = 0;                  // 현재 센서값을 넣어야 할 인덱스
int total = 0;                  // 센서값들의 총합
int average = 0;                // 센서값들의 평균

int inputPin = A0;

void setup()
{
  // 컴퓨터와 시리얼 통신을 9600bps로 초기화합니다:
  Serial.begin(9600);                   
  // 배열에 있는 10개의 센서 값들을 모두 0로 초기화합니다: 
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;          
}

void loop() {
  // 총합에서 전에 측정한 센서값을 뺍니다:
  total= total - readings[index];  
  // 새로 센서값을 읽습니다:  
  readings[index] = analogRead(inputPin); 
  // 총합에 새로 읽은 센서값을 더합니다:
  total= total + readings[index];       
  // 배열의 다음을 가리키게 인덱스 값을 하나 증가시킵니다:  
  index = index + 1;                    

  // 만약 배열의 끝에 있다면...
  if (index >= numReadings)              
    // ...배열의 처음으로 돌아가게 합니다: 
    index = 0;

  // 평균값을 계산합니다:
  average = total / numReadings;         
  // 컴퓨터로 ASCII 숫자로 출력합니다
  Serial.println(average);   
  delay(1);        // 다음 센서값을 읽기 위한 안정 시간을 갖습니다            
}

