/*
  ASCII 테이블
 
 바이트 값들을 가능한 모든 형태로 출력합니다:  
 * 변환하지 않은 바이트 그 자체 값으로,
 * ASCII 코드로 변환한 십진 수 값, 16 진수 값, 8 진수, 그리고 2 진수
   형태로 출력합니다.
 
  ASCII에 대한 보다 많은 정보를 원하면, http://www.asciitable.com 와
  http://en.wikipedia.org/wiki/ASCII 를 참조하세요.
 
 회로:  다른 외부 하드웨어는 필요치 않습니다.
 
 2006년에 Nicholas Zambetti에 의하여 창작되었으며, 
 2012년 04월 09일에 Tom Igoe에 의하여 수정되었습니다.
 
 http://arduino.cc/en/Tutorial/ASCIITable

 이 예제 코드는 공유 저작물입니다.

 <http://www.zambetti.com> 
  
 */
void setup() { 
 // 시리얼 통신을 초기화하고 통신 포트가 열리기를 기다립니다:
  Serial.begin(9600); 
  while (!Serial) {
    ; // 통신 포트가 연결되기를 기다립니다. 리어나도(레오나르도)
      // 보드에서만 이렇게 해 줄 필요가 있습니다.
  }
  
  // 끝에 라인피드 되게 타이틀을 출력합니다 
  Serial.println("ASCII 테이블 ~ 문자 맵"); 
} 

// 최초로 볼 수 있는 ASCII 문자는 '!'이며 이것의 값은 33입니다:
int thisByte = 33; 
// ASCII 문자는 홑 따옴표로 쓸(표기할) 수 있습니다. 예를 들어 '!'는
// 33과 같습니다. 그래서 다음과 같이 사용할 수 있습니다:
//int thisByte = '!';  

void loop() { 
  // 값을 그대로 출력합니다. 즉, 바이트 값의 변환하지 않은 이진수 값.
  // 시리얼 모니터는 모든 바이트들을 ASCII 문자로 해설합니다. 그렇기
  // 때문에 33은, 처음의 숫자, '!'로 보일(나타날) 것입니다.
  Serial.write(thisByte);    

  Serial.print(", DEC: "); 
  // ASCII 코드로 변환된 10 진수 문자열로 값을 출력합니다.
  // 10 진수 출력은 Serial.print()와 Serial.println() 함수의 기본 
  // 형식이라 수정자를 필요로 하지 않습니다:
  Serial.print(thisByte);      
  // 그렇지만 10 진수 출력을 위한 수정자를 원하면 선언할 수 있습니다.
  // 이것 또한 주석을 없애면 동작합니다:

  // Serial.print(thisByte, DEC);  


  Serial.print(", HEX: "); 
  // 16 진수 문자열로 출력합니다:
  Serial.print(thisByte, HEX);     

  Serial.print(", OCT: "); 
  // 8 진수 문자열로 출력합니다;
  Serial.print(thisByte, OCT);     

  Serial.print(", BIN: "); 
  // 2 진수 문자열로 출력합니다.
  // 끝에 LF를 출력합니다:
  Serial.println(thisByte, BIN);   

  // 만약 마지막 볼 수 있는 문자 '~' 혹은 126 이 출력되었으면 멈춥니다:
  if(thisByte == 126) {     // 126 대신에  '~' 을 사용할 수 있습니다
    // 아무것도 하지 않으면서 계속 무한 반복합니다
    while(true) { 
      continue; 
    } 
  } 
  // 다음 문자로 진행합니다
  thisByte++;  
} 
