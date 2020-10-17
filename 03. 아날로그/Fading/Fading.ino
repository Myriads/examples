/*

 Fading (점점 희미하게 만듬 혹은 반대로 점점 밝게 만듬)
 
 이 스케치는 analogWrite() 함수를 사용하여 LED를 점차 밝아지게
 만들다가 반대로 점점 어둡게 만드는 것을 무한 반복하여 보여주는
 예제입니다.
 
 회로:
 * 220Ω 저항 한쪽을 디지털 9번 핀에 연결하고 저항 다른 한쪽을 LED의
   아노드(다리가 긴쪽)에 연결합니다. LED의 캐소드(다리가 짧은 쪽)를
   GND에 연결합니다
 
 2008년 11월 01일 David A. Mellis에 의하여 창작되었으며,
 2011년 08월 30일 Tom Igoe에 의하여 수정되었습니다.
 
 http://arduino.cc/en/Tutorial/Fading
 
 이 예제 코드는 공유 저작물입니다.
 
 */


int ledPin = 9;    // 디지털 9번 핀에 연결된 LED

void setup()  { 
  // setup()에는 초기화할 것이 없습니다 
} 

void loop()  { 
  // 최소값에서 최대값으로 5씩 증가시켜 점점 밝게 합니다:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    // (0 ~ 255 범위의)값을 씁니다:
    analogWrite(ledPin, fadeValue);         
    // 점점 밝아지는 현상을 볼 수 있도록 30ms 동안 기다립니다     
    delay(30);                            
  }

  // 최대값에서 최소값으로 5씩 감소시켜 점점 어둡게 합니다:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    // (0 ~ 255 범위의)값을 씁니다:
    analogWrite(ledPin, fadeValue);
    // 점점 어두워지는 현상을 볼 수 있도록 30ms 동안 기다립니다
    delay(30);
  } 
}


