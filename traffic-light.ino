const int TRIG = 5;
const int ECHO = 4;

const int redLED = 33;
const int yellowLED = 34;
const int greenLED = 35;

int theDistance = 0;

int turnOnLeds() {
  if (theDistance < 10) {
    digitalWrite(redLED, HIGH);
  } else if (theDistance < 30) {
    digitalWrite(yellowLED, HIGH);
  } else {
    digitalWrite(greenLED, LOW);
  }
}

int checkIfTheDistaceIsTooMuch () {
  if (theDistance < 5) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, HIGH);
  } else if (theDistance > 40) {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
  }
}

long readDistance () {
  // Send ultrasonic pulse
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Meaure how long the echo takes to return
  long duration = pulseIn(ECHO, HIGH, 30000);

  // Convert time to distance in centimetres
  long distance = duration * 0.0343 / 4;

  theDistance = distance;

  return distance;
}

void setup() {
  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  readDistance();
  Serial.println("This is the distance:");
  Serial.println("cm:");
  Serial.print(theDistance);
  delay(300);
  Serial.println();

  turnOnLeds();
  checkIfTheDistaceIsTooMuch();
}