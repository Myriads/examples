/*
  Physical Pixel (물리적 화소)
 
 이 스케치는 아두이노 보드를 이용하여 컴퓨터로부터 데이터를 받는
 예제입니다.  이 경우에 있어서, 'H' 글자를 받으면 LED를 켜고, 'L'
 문자를 받으면 LED를 끄는 동작을 실행합니다.
 
 데이터는 아두이노 시리얼 모니터에서 보낼 수 있으며, Processing(
 밑에 있는 코드를 보세요), Flash (serial-net proxy를 통하여), PD,
 혹은 Max/MSP와 같은 프로그램으로부터 보낼 수도 있습니다.
 
 회로:
 * 디지털 핀 13에 LED 보호 저항을 통하여 LED에 연결하고 LED 캐소드
   핀을 GND에 연결합니다
 
 2006년 David A. Mellis에 의하여 창작되었으며,
 2011년 08월 30일 Tom Igoe와 Scott Fitzgerald에 의하여 수정되었습니다
 
 이 예제 코드는 공유 저작물입니다.

 http://www.arduino.cc/en/Tutorial/PhysicalPixel
 */

const int ledPin = 13; // LED가 연결된 디지털 핀
int incomingByte;      // 시리얼 포트로부터 받은 데이터

void setup() {
  // 시리얼 통신을 위한 초기화를 합니다:
  Serial.begin(9600);
  // LED 핀을 출력핀으로 초기화합니다:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 시리얼 데이터가 있는지 확인합니다:
  if (Serial.available() > 0) {
    // 시리얼 버퍼에 있는 가장 오래된 데이터를 읽어들입니다:
    incomingByte = Serial.read();
    // 대문자 'H'(ASCII 72)이면, LED를 켭니다:
    if (incomingByte == 'H') {
      digitalWrite(ledPin, HIGH);
    } 
    // 대문자 'L'(ASCII 76)이면, LED를 끔니다:
    if (incomingByte == 'L') {
      digitalWrite(ledPin, LOW);
    }
  }
}

/* Processing code for this example
 
 // mouseover serial 
 
 // Demonstrates how to send data to the Arduino I/O board, in order to 
 // turn ON a light if the mouse is over a square and turn it off 
 // if the mouse is not. 
 
 // created 2003-4
 // based on examples by Casey Reas and Hernando Barragan
 // modified 30 Aug 2011
 // by Tom Igoe
 // This example code is in the public domain.

 
 
 import processing.serial.*; 
 
 float boxX;
 float boxY;
 int boxSize = 20;
 boolean mouseOverBox = false;
 
 Serial port; 
 
 void setup()  {
 size(200, 200);
 boxX = width/2.0;
 boxY = height/2.0;
 rectMode(RADIUS); 
 
 // List all the available serial ports in the output pane. 
 // You will need to choose the port that the Arduino board is 
 // connected to from this list. The first port in the list is 
 // port #0 and the third port in the list is port #2. 
 println(Serial.list()); 
 
 // Open the port that the Arduino board is connected to (in this case #0) 
 // Make sure to open the port at the same speed Arduino is using (9600bps) 
 port = new Serial(this, Serial.list()[0], 9600); 
 
 }
 
 void draw() 
 { 
 background(0);
 
 // Test if the cursor is over the box 
 if (mouseX > boxX-boxSize && mouseX < boxX+boxSize && 
 mouseY > boxY-boxSize && mouseY < boxY+boxSize) {
 mouseOverBox = true;  
 // draw a line around the box and change its color:
 stroke(255); 
 fill(153);
 // send an 'H' to indicate mouse is over square:
 port.write('H');       
 } 
 else {
 // return the box to it's inactive state:
 stroke(153);
 fill(153);
 // send an 'L' to turn the LED off: 
 port.write('L');      
 mouseOverBox = false;
 }
 
 // Draw the box
 rect(boxX, boxY, boxSize, boxSize);
 }
 
 
 */

/*
Max/MSP version 5 patch to run with this example:

----------begin_max5_patcher----------
1672.3oc2ZszaaiCD9ryuBBebQVCQRYao8xhf1cQCPVfBzh8RRQ.sDsM2HSZ
HQmlzh9eu7gjsjsEk7y0oWjiHoHm4aluYHGlueUmtiDuPy5B9Cv8fNc99Uc5
XZR2Pm726zcF4knDRlYXciDylQ4xtWa6SReQZZ+iSeMiEQR.ej8BM4A9C7OO
kkAlSjQSAYTdbFfvA27o2c6sfO.Doqd6NfXgDHmRUCKkolg4hT06BfbQJGH3
5Qd2e8d.QJIQSow5tzebZ7BFW.FIHow8.2JAQpVIIYByxo9KIMkSjL9D0BRT
sbGHZJIkDoZOSMuQT.8YZ5qpgGI3locF4IpQRzq2nDF+odZMIJkRjpEF44M3
A9nWAum7LKFbSOv+PSRXYOvmIhYiYpg.8A2LOUOxPyH+TjPJA+MS9sIzTRRr
QP9rXF31IBZAHpVHkHrfaPRHLuUCzoj9GSoQRqIB52y6Z.tu8o4EX+fddfuj
+MrXiwPL5+9cXwrOVvkbxLpomazHbQO7EyX7DpzXYgkFdF6algCQpkX4XUlo
hA6oa7GWck9w0Gnmy6RXQOoQeCfWwlzsdnHLTq8n9PCHLv7Cxa6PAN3RCKjh
ISRVZ+sSl704Tqt0kocE9R8J+P+RJOZ4ysp6gN0vppBbOTEN8qp0YCq5bq47
PUwfA5e766z7NbGMuncw7VgNRSyQhbnPMGrDsGaFSvKM5NcWoIVdZn44.eOi
9DTRUT.7jDQzSTiF4UzXLc7tLGh4T9pwaFQkGUGIiOOkpBSJUwGsBd40krHQ
9XEvwq2V6eLIhV6GuzP7uzzXBmzsXPSRYwBtVLp7s5lKVv6UN2VW7xRtYDbx
7s7wRgHYDI8YVFaTBshkP49R3rYpH3RlUhTQmK5jMadJyF3cYaTNQMGSyhRE
IIUlJaOOukdhoOyhnekEKmZlqU3UkLrk7bpPrpztKBVUR1uorLddk6xIOqNt
lBOroRrNVFJGLrDxudpET4kzkstNp2lzuUHVMgk5TDZx9GWumnoQTbhXsEtF
tzCcM+z0QKXsngCUtTOEIN0SX2iHTTIIz968.Kf.uhfzUCUuAd3UKd.OKt.N
HTynxTQyjpQD9jlwEXeKQxfHCBahUge6RprSa2V4m3aYOMyaP6gah2Yf1zbD
jVwZVGFZHHxINFxpjr5CiTS9JiZn6e6nTlXQZTAFj6QCppQwzL0AxVtoi6WE
QXsANkEGWMEuwNvhmKTnat7A9RqLq6pXuEwY6xM5xRraoTiurj51J1vKLzFs
CvM7HI14Mpje6YRxHOSieTsJpvJORjxT1nERK6s7YTN7sr6rylNwf5zMiHI4
meZ4rTYt2PpVettZERbjJ6PjfqN2loPSrUcusH01CegsGEE5467rnCdqT1ES
QxtCvFq.cvGz+BaAHXKzRSfP+2Jf.KCvj5ZLJRAhwi+SWHvPyN3vXiaPn6JR
3eoA.0TkFhTvpsDMIrL20nAkCI4EoYfSHAuiPBdmJRyd.IynYYjIzMvjOTKf
3DLvnvRLDLpWeEOYXMfAZqfQ0.qsnlUdmA33t8CNJ7MZEb.u7fiZHLYzDkJp
R7CqEVLGN75U+1JXxFUY.xEEBcRCqhOEkz2bENEWnh4pbh0wY25EefbD6EmW
UA6Ip8wFLyuFXx+Wrp8m6iff1B86W7bqJO9+mx8er4E3.abCLrYdA16sBuHx
vKT6BlpIGQIhL55W7oicf3ayv3ixQCm4aQuY1HZUPQWY+cASx2WZ3f1fICuz
vj5R5ZbM1y8gXYN4dIXaYGq4NhQvS5MmcDADy+S.j8CQ78vk7Q7gtPDX3kFh
3NGaAsYBUAO.8N1U4WKycxbQdrWxJdXd10gNIO+hkUMmm.CZwknu7JbNUYUq
0sOsTsI1QudDtjw0t+xZ85wWZd80tMCiiMADNX4UzrcSeK23su87IANqmA7j
tiRzoXi2YRh67ldAk79gPmTe3YKuoY0qdEDV3X8xylCJMTN45JIakB7uY8XW
uVr3PO8wWwEoTW8lsfraX7ZqzZDDXCRqNkztHsGCYpIDDAOqxDpMVUMKcOrp
942acPvx2NPocMC1wQZ8glRn3myTykVaEUNLoEeJjVaAevA4EAZnsNgkeyO+
3rEZB7f0DTazDcQTNmdt8aACGi1QOWnMmd+.6YjMHH19OB5gKsMF877x8wsJ
hN97JSnSfLUXGUoj6ujWXd6Pk1SAC+Pkogm.tZ.1lX1qL.pe6PE11DPeMMZ2
.P0K+3peBt3NskC
-----------end_max5_patcher-----------
 
 
 */
