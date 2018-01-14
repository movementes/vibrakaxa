#define  c1    30303
#define  d1    27027
#define  e1    24390
#define  g1    20408
#define  a1    18181
#define  c2    15384
#define  d2    13698
#define  e2    12195
#define  g2    10204
#define  a2    9090
#define  c3    7634
#define  d3    6803
#define  e3    6061
#define  g3    5102
#define  a3    4545
#define  c4    3816    // 261 Hz
#define  d4    3401    // 294 Hz
#define  e4    3030    // 329 Hz
#define  g4    2551    // 392 Hz
#define  a4    2272    // 440 Hz
#define  c5    1912    // 523 Hz
#define  d5    1706
#define  e5    1517
#define  g5    1276
#define  a5    1136
#define  R     0

const int buttonPin1 = 4;
const int buttonPin2 = 5;
const int buttonPin3 = 6;
const int buttonPin4 = 7;
const int buttonPin5 = 8;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;

int speakerOut = 9;

long tempo = 10000;
long duration  = 0;

int rest_count = 50;
int toneM = 0;
int beat = 0;

void setup() {

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);

  pinMode(speakerOut, OUTPUT);

  Serial.begin(9600);
}

void playTone() {
  
  long elapsed_time = 0;
  
  if (toneM > 0) {
    
    while (elapsed_time < duration) {

      digitalWrite(speakerOut, HIGH);
      delayMicroseconds(toneM / 2);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(toneM / 2);

      elapsed_time += (toneM);
    }
  } else {
    for (int j = 0; j < rest_count; j++) {
      delayMicroseconds(duration); 
    }                               
  }                                
}

void loop() {

  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);

  if (buttonState1 == LOW) {
    toneM = c2;
    beat = 256;
    duration = beat * tempo;
    playTone();
    Serial.println("BOTAO 1");
  } else if (buttonState2 == LOW) {
    toneM = d2;
    beat = 256;
    duration = beat * tempo;
    playTone();
    Serial.println("BOTAO 2");
  } else if (buttonState3 == LOW) {
    toneM = e2;
    beat = 256;
    duration = beat * tempo;
    playTone();
    Serial.println("BOTAO 3");
  } else if (buttonState4 == LOW) {
    toneM = g2;
    beat = 256;
    duration = beat * tempo;
    playTone();
    Serial.println("BOTAO 4");
  } else if (buttonState5 == LOW) {
    toneM = a2;
    beat = 256;
    duration = beat * tempo;
    playTone();
    Serial.println("BOTAO 5");
  } else {
    digitalWrite(speakerOut, HIGH);
    Serial.println("NENHUM");
  }
}
