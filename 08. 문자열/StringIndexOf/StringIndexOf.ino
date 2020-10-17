/*
  String 클래스의 indexOf()와 lastIndexOf() 멤버 함수들

 String 객체 문자열에 들어 있는 임의의 문자(char) 혹은 문자열을
 String 클래스의 indexOf()와 lastIndexOf() 멤버 함수를 사용하여
 어떻게 찾는지를 보여주는 예제들입니다.
 
 2010년 07월 27일 창작되었으며
 2012년 04월 02일 Tom Igoe에 의하여 수정되었습니다
 2016년 06월 13일에 수정되었습니다
 
 http://www.arduino.cc/en/Tutorial/StringIndexOf

 이 예제 코드는 공유 저작물입니다.
 */

void setup() {
  // 시리얼 통신 포트를 열고 연결되기를 기다립니다:
  Serial.begin(9600);
  while (!Serial) {
    ; // 시리얼 포트가 연결되길 기다립니다. 실제 USB 포트에서만 필요
  }

  // 시작을 알리는 글을 화면에 출력합니다:
  Serial.println("\n\nString 클래스의 indexOf()와"
                  "lastIndexOf() 멤버 함수들:");
  Serial.println();
}

void loop() {
  // indexOf()는 문자열에 들어있는 특정 문자의 위치(즉 인덱스) 값을 돌려
  // 줍니다. 예로, HTML 태그들을 분석할 때, 이 함수를 사용할 수 있습니다:
  String stringOne = "<HTML><HEAD><BODY>";
  int firstClosingBracket = stringOne.indexOf('>');
  Serial.println("문자열 \"" + stringOne +\
                  "\"에 들어있는 \">\"의 첫 번째 위치는 " +\
                  firstClosingBracket + " 입니다");

  int secondOpeningBracket = firstClosingBracket + 1;
  int secondClosingBracket = stringOne.indexOf('>', secondOpeningBracket);
  Serial.println("문자열 \"" + stringOne +\
                  "\"에 들어있는 \">\"의 두 번째 위치는 " +\
                  secondClosingBracket + " 입니다");

  // indexOf() 함수로 문자열도 찾을 수 있습니다:
  stringOne = "<HTML><HEAD><BODY>";
  int bodyTag = stringOne.indexOf("<BODY>");
  Serial.println("문자열 \"" + stringOne +\
                  "\"에 들어있는 \"<BODY>\"태그의 위치는 " +\
                  bodyTag + " 입니다");

  stringOne = "<UL><LI>항목 1<LI>항목 2<LI>항목 3</UL>";
  int firstListItem = stringOne.indexOf("<LI>");
  int secondListItem = stringOne.indexOf("<LI>", firstListItem + 1);
  Serial.println("문자열 \"" + stringOne +\
                  "\"에 두 번째로 있는\n\t\"<LI>\"태그의 위치는 " +\
                  secondListItem + " 입니다");

  // lastIndexOf()는 문자열의 마지막 위치(인덱스) 값을 알려 줍니다:
  int lastOpeningBracket = stringOne.lastIndexOf('<');
  Serial.println("문자열 \"" + stringOne +\
                  "\" 마지막에 있는\n\t\"<\"의 위치는 " +\
                  lastOpeningBracket + " 입니다");

  // lastIndexOf() 또한 문자열을 찾을 수 있습니다:
  int lastListItem  = stringOne.lastIndexOf("<LI>");
  Serial.println("문자열 \"" + stringOne +\
                  "\" 마지막에 있는\n\t\"<LI>\"태그의 위치는 " +\
                  lastListItem + " 입니다");

  stringOne = "<p>군자는 이를 자신에게서 구하고</p>\n\t"
              "<p>소인은 이를 남에게서 구한다</p>\n\t"
              "<p><br></p>\n\t<p>군자</p>";
  int lastParagraph = stringOne.lastIndexOf("<p");
  int secondLastGraf = stringOne.lastIndexOf("<p", lastParagraph - 1);
  Serial.println("문자열 \"" + stringOne +\
                  "\"에 마지막으로 있는 \"<P>\"태그의 위치는 " +\
                  secondLastGraf + " 입니다");

  // 한번만 시리얼 모니터에 출력하고 멈추게 계속 기다립니다:
  while (true);
}

