#define  c2    15384
#define  d2    13698
#define  e2    12195
#define  g2    10204
#define  a2    9090
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
}

void playTone() {
  
  long elapsed_time = 0;
  
  if (toneM > 0) {
    while (elapsed_time < duration) {
      digitalWrite(speakerOut, HIGH);
      delayMicroseconds(toneM / 2);
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
  } else if (buttonState2 == LOW) {
    toneM = d2;
    beat = 256;
    duration = beat * tempo;
    playTone();
  } else if (buttonState3 == LOW) {
    toneM = e2;
    beat = 256;
    duration = beat * tempo;
    playTone();
  } else if (buttonState4 == LOW) {
    toneM = g2;
    beat = 256;
    duration = beat * tempo;
    playTone();
  } else if (buttonState5 == LOW) {
    toneM = a2;
    beat = 256;
    duration = beat * tempo;
    playTone();
  } else {
    digitalWrite(speakerOut, HIGH);
  }
}
