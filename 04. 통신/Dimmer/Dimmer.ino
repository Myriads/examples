/*
  Dimmer (빛의 밝기를 조정하는 장치: 제광 장치)
 
 이 스케치는 컴퓨터에서 아두이노로 데이터를 보내, 이 데이터로 LED의
 밝기를 조정하는 예제입니다. 데이터는 0 ~ 255 사이의 값인 각각의 
 바이트들이 보내지며 아두이노 보드가 이 바이트들을 읽어 들이고, 이 
 값을 LED의 밝기로 설정합니다.
 
 회로:
 디지털 9번 핀에 220Ω 저항을 연결하고 맞은 편 저항 다리를 LED 아노드에
 연결합니다. LED 캐소드는 GND에 연결합니다. Processingm, Max/MSP 혹은 
 다른 시리얼 응용 프로그램과 시리얼 통신 연결이 되어야 합니다.
 
 2006년에 David A. Mellis에 의하여 창작되었으며,
 2011년 08월 30일에 Tom Igoe과 Scott Fitzgerald에 의하여 수정되었습니다.
 
 이 예제 코드는 공유 저작물입니다.
 
 http://www.arduino.cc/en/Tutorial/Dimmer
 
 */

const int ledPin = 9;      // LED가 연결된 핀

void setup()
{
  // 시리얼 통신을 위한 초기화를 합니다:
  Serial.begin(9600);
  // LED 핀을 출력 핀으로 설정합니다:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  byte brightness;

  // 컴퓨터로부터 데이터가 보내졌는지 확인합니다:
  if (Serial.available()) {
    // 가장 최근에 보내진 바이트를 읽습니다 (0 ~ 255 사이의 값):
    brightness = Serial.read();
    // LED의 밝기로 설정합니다:
    analogWrite(ledPin, brightness);
  }
}

/* Processing code for this example
 // Dimmer - sends bytes over a serial port
 // by David A. Mellis
 //This example code is in the public domain.
 
 import processing.serial.*;
 Serial port;
 
 void setup() {
 size(256, 150);
 
 println("Available serial ports:");
 println(Serial.list());
 
 // Uses the first port in this list (number 0).  Change this to
 // select the port corresponding to your Arduino board.  The last
 // parameter (e.g. 9600) is the speed of the communication.  It
 // has to correspond to the value passed to Serial.begin() in your
 // Arduino sketch.
 port = new Serial(this, Serial.list()[0], 9600);  
 
 // If you know the name of the port used by the Arduino board, you
 // can specify it directly like this.
 //port = new Serial(this, "COM1", 9600);
 }
 
 void draw() {
 // draw a gradient from black to white
 for (int i = 0; i < 256; i++) {
 stroke(i);
 line(i, 0, i, 150);
 }
 
 // write the current X-position of the mouse to the serial port as
 // a single byte
 port.write(mouseX);
 }
 */

/* 이 예제를 위한 Max/MSP v5 패치
 
----------begin_max5_patcher----------
1008.3ocuXszaiaCD9r8uhA5rqAeHIa0aAMaAVf1S6hdoYQAsDiL6JQZHQ2M
YWr+2KeX4vjnjXKKkKhhiGQ9MeyCNz+X9rnMp63sQvuB+MLa1OlOalSjUvrC
ymEUytKuh05TKJWUWyk5nE9eSyuS6jesvHu4F4MxOuUzB6X57sPKWVzBLXiP
xZtGj6q2vafaaT0.BzJfjj.p8ZPukazsQvpfcpFs8mXR3plh8BoBxURIOWyK
rxspZ0YI.eTCEh5Vqp+wGtFXZMKe6CZc3yWZwTdCmYW.BBkdiby8v0r+ST.W
sD9SdUkn8FYspPbqvnBNFtZWiUyLmleJWo0vuKzeuj2vpJLaWA7YiE7wREui
FpDFDp1KcbAFcP5sJoVxp4NB5Jq40ougIDxJt1wo3GDZHiNocKhiIExx+owv
AdOEAksDs.RRrOoww1Arc.9RvN2J9tamwjkcqknvAE0l+8WnjHqreNet8whK
z6mukIK4d+Xknv3jstvJs8EirMMhxsZIusET25jXbX8xczIl5xPVxhPcTGFu
xNDu9rXtUCg37g9Q8Yc+EuofIYmg8QdkPCrOnXsaHwYs3rWx9PGsO+pqueG2
uNQBqWFh1X7qQG+3.VHcHrfO1nyR2TlqpTM9MDsLKNCQVz6KO.+Sfc5j1Ykj
jzkn2jwNDRP7LVb3d9LtoWBAOnvB92Le6yRmZ4UF7YpQhiFi7A5Ka8zXhKdA
4r9TRGG7V4COiSbAJKdXrWNhhF0hNUh7uBa4Mba0l7JUK+omjDMwkSn95Izr
TOwkdp7W.oPRmNRQsiKeu4j3CkfVgt.NYPEYqMGvvJ48vIlPiyzrIuZskWIS
xGJPcmPiWOfLodybH3wjPbMYwlbFIMNHPHFOtLBNaLSa9sGk1TxMzCX5KTa6
WIH2ocxSdngM0QPqFRxyPHFsprrhGc9Gy9xoBjz0NWdR2yW9DUa2F85jG2v9
FgTO4Q8qiC7fzzQNpmNpsY3BrYPVJBMJQ1uVmoItRhw9NrVGO3NMNzYZ+zS7
3WTvTOnUydG5kHMKLqAOjTe7fN2bGSxOZDkMrBrGQ9J1gONBEy0k4gVo8qHc
cxmfxVihWz6a3yqY9NazzUYkua9UnynadOtogW.JfsVGRVNEbWF8I+eHtcwJ
+wLXqZeSdWLo+FQF6731Tva0BISKTx.cLwmgJsUTTvkg1YsnXmxDge.CDR7x
D6YmX6fMznaF7kdczmJXwm.XSOOrdoHhNA7GMiZYLZZR.+4lconMaJP6JOZ8
ftCs1YWHZI3o.sIXezX5ihMSuXzZtk3ai1mXRSczoCS32hAydeyXNEu5SHyS
xqZqbd3ZLdera1iPqYxOm++v7SUSz
-----------end_max5_patcher-----------
 */
