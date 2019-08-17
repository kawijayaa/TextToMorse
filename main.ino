const int ledPin = 8;
const int buzzPin = 5;
const int buzzFreq = 443;
char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ',', '.', '?', ' '};
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}
void execMorse(String codetype, int ledpin, int buzzerpin, int delaytime, int freq) {
  int switchState;
  if (codetype == "dot") {
    switchState = 0;
  } else if (codetype == "stripe") {
    switchState = 1;
  }
  switch (switchState) {
    case 0:
      digitalWrite(ledpin, HIGH);
      tone(buzzerpin, freq);
      delay(delaytime);
      digitalWrite(ledpin, LOW);
      noTone(buzzerpin);
      break;
    case 1:
      digitalWrite(ledpin, HIGH);
      tone(buzzerpin, freq);
      delay(delaytime * 3);
      digitalWrite(ledpin, LOW);
      noTone(buzzerpin);
      break;
    default:
      break;
  }
}

void morseDelay(String delaytype, int delaytime) {
  int switchState;
  if (delaytype == "element") {
    switchState = 0;
  } else if (delaytype == "letter") {
    switchState = 1;
  } else if (delaytype == "word") {
    switchState = 2;
  }
  switch (switchState) {
    case 0:
      delay(delaytime);
      break;
    case 1:
      delay(delaytime * 3);
      break;
    case 2:
      delay(delaytime * 7);
      break;
    default:
      break;
  }
}

void morse(char letter, int ledpin, int buzzerpin, int delaytime, int freq) {
  int index;
  for (int i = 0; i < sizeof(alphabet); i++) {
    if (alphabet[i] == letter) {
      index = i;
    }
  }
  switch (index) {
    case 0:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 1:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 2:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 3:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 4:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 5:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 6:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 7:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 8:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 9:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 10:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 11:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 12:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 13:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 14:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 15:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 16:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 17:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 18:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 19:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 20:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 21:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 22:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 23:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 24:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 25:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 26:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 27:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 28:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 29:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 30:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 31:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 32:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 33:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 34:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 35:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 36:
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 37:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      break;
    case 38:
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("stripe", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      morseDelay("element", delaytime);
      execMorse("dot", ledpin, buzzerpin, delaytime, freq);
      break;
    case 39:
      morseDelay("word", delaytime);
      break;
    default:
      break;
  }
}
void loop() {
  String incoming;
  if (Serial.available() > 0) {
    // Read a byte from the serial buffer.
    char inchar = (char)Serial.read();
    if ((' ' <= inchar) && (inchar <= '~')) {
      incoming += inchar;
    }
    char inc_array[sizeof(incoming)];
    incoming.toLowerCase();
    incoming.toCharArray(inc_array,sizeof(incoming));
    for(int i = 0;i<sizeof(inc_array);i++){
      morse(inc_array[i], ledPin, buzzPin, 100, 443);
      if(inc_array[i] != " "){
        morseDelay("letter", 100);
      }
    }
  }
} 
