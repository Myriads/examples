/* 
 Debounce
 
 입력 핀 값이 LOW에서 HIGH로 변할 때(예를 들어 푸시 버튼의 눌렸을 때만),
 출력 핀 값을 LOW에서 HIGH로 혹은 HIGH에서 LOW로 바뀌는(토글) 스케치
 입니다. 기계식 스위치는 일반적으로 스프링과 같은 장치가 들어간 구조이기
 때문에, 누르거나 뗄때 붙었다 떨어졌다 하는 떨림(bounce) 현상이 발생
 합니다. 회로의 떨림 방지(즉 잡음을 제거하거나 무시)를 위한 스위치를
 누르거나 뗄때(toggle) 처음 스위치의 변화를 감지한 후에 최소한의 지연
 시간을 가져야 합니다.
 
 회로:
 * LED를 보호할 저항 220 Ohm을 13번 핀에 연결하고, LED의 아노드와 저항을
   연결하고 LED 캐소드를 GND에 연결합니다.
 * 푸시버튼을 +5V와 디지털 2번 핀과 연결합니다
 * 10K 저항을 디지털 2번 핀과 접지에 연결합니다

 * 노트: 거의 모든 아두이노 보드들은 디지털 13번 핀에 LED가 이미
         연결되어 있습니다. 그렇기 때문에 이 예제 스케치를 위하여
         별도의 부품들이 필요치 않습니다.

 2006년 11월 21일에 David A. Mellis에 의하여 창작되었습니다.
 2011년 08월 30일에 Limor Fried에 의하여 수정되었습니다.
 2012년 12월 28일에 Mike Walters에 의하여 수정되었습니다.
 2014년 08월 25일에 Wayfarer에 의하여 수정되었습니다.
 
 이 예제 코드는 공유 저작물입니다.
 
 http://www.arduino.cc/en/Tutorial/Debounce
 */

#define USE_DEBOUNCE true

// constants로 선언된 값들은 변경되지 않습니다. 핀 번호들을 설정하기 위하여
// 여기에서 사용되었습니다: 

const int buttonPin = 2;    // 푸시 버튼 핀 번호
const int ledPin = 13;      // LED 핀 번호

// 값이 변화되는 변수들:
int ledState = HIGH;         // 푸시 버튼 핀의 현 상태
int buttonState;             // 입력 핀의 현재 읽은 값

#if USE_DEBOUNCE
int lastButtonState = LOW;   // 입력 핀의 전 상태(전에 읽은 값)

// 다음 변수들은 long 타입이며, ms(milliseconds)으로 측정된 시간 값이라
// int로 저장할 수 있는 숫자보다 빨리 커기지 때문입니다. 

long lastDebounceTime = 0;  // buttonPin의 입력 값이 바뀐 최근 시간
long debounceDelay = 50;    // 떨림을 없애기 위한 지연 시간; LED가 다르게 
                            // 동작하면 지연 시간을 키우세요.
#endif

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // LED를 초기 상태 ON로 만듭니다
  digitalWrite(ledPin, ledState);
}

void loop() {
  // 스위치의 상태를 지역 변수 reading으로 읽어 들입니다:
  int reading = digitalRead(buttonPin);

  // 버튼이 눌렸는지 검사합니다(즉, 입력 값이 LOW에서 HIGH로 갔는지),
  // 잡음 제거를 위하여 마지막 눌림을 감지한 때부터 충분히 기다립니다.

  #if USE_DEBOUNCE
  // 스위치 상태가 변하였다면, 눌렸거나(떼어졌거나) 잡음 때문일 것입니다:
  if (reading != lastButtonState) {

    // 잡음 제거를 위한 타이머 값을 현재 시간으로 다시 설정합니다.
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay)
  #endif
  {
    // 떨림(bounce)을 제거하기 위한 지연 시간보다 많이 지났다면
    // 읽어 들인 스위치 상태를 실제 현재의 스위치 상태로 간주합니다.
    
    // 만약 버튼 상태가 바뀌었다면:
    if (reading != buttonState) {
      buttonState = reading;

      // 버튼 상태가 HIGH일때만 LED의 상태를 바꿉니다:
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }
 
  // LED를 LED 상태와 같게 만듭니다
  digitalWrite(ledPin, ledState);

#if USE_DEBOUNCE
  // reading 값을 저장하며, 이 값이 다음 번 loop을 실행할 때,
  // lastButtonState 변수에 있게 됩니다: 
  lastButtonState = reading;
#endif

}

