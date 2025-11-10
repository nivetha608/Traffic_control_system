// LEDs
int redLED1 = 23, greenLED1 = 27;
int redLED2 = 29, greenLED2 = 33;
int redLED3 = 35, greenLED3 = 39;
int redLED4 = 41, greenLED4 = 45;

// Ultrasonic Sensors
int trig1 = 11, echo1 = 10;
int trig2 = 7, echo2 = 6;
int trig3 = 5, echo3 = 4;
int trig4 = 3, echo4 = 2;


int threshold = 5;

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600); // Read UID from Nano

  // LEDs
  pinMode(redLED1, OUTPUT); pinMode(greenLED1, OUTPUT);
  pinMode(redLED2, OUTPUT); pinMode(greenLED2, OUTPUT);
  pinMode(redLED3, OUTPUT); pinMode(greenLED3, OUTPUT);
  pinMode(redLED4, OUTPUT); pinMode(greenLED4, OUTPUT);

  // Ultrasonic
  pinMode(trig1, OUTPUT); pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT); pinMode(echo2, INPUT);
  pinMode(trig3, OUTPUT); pinMode(echo3, INPUT);
  pinMode(trig4, OUTPUT); pinMode(echo4, INPUT);

  setSignals(0); // All red
}

void loop() {
  if (Serial1.available()) {
    String uid = Serial1.readStringUntil('\n');
    uid.trim();
    Serial.print("Received UID: "); Serial.println(uid);
  }

  int d1 = getDistance(trig1, echo1);
  int d2 = getDistance(trig2, echo2);
  int d3 = getDistance(trig3, echo3);
  int d4 = getDistance(trig4, echo4);

  Serial.print("D1: "); Serial.print(d1);
  Serial.print(" | D2: "); Serial.print(d2);
  Serial.print(" | D3: "); Serial.print(d3);
  Serial.print(" | D4: "); Serial.println(d4);

  if (d1 < threshold) activateLane(1);
  else if (d2 < threshold) activateLane(2);
  else if (d3 < threshold) activateLane(3);
  else if (d4 < threshold) activateLane(4);
  else {
    alternateSignals();
  }
}

void activateLane(int lane) {
  Serial.print("Activating Lane "); Serial.println(lane);
  setSignals(lane);
}

void setSignals(int active) {
  digitalWrite(greenLED1, active == 1);
  digitalWrite(redLED1, active != 1);
  digitalWrite(greenLED2, active == 2);
  digitalWrite(redLED2, active != 2);
  digitalWrite(greenLED3, active == 3);
  digitalWrite(redLED3, active != 3);
  digitalWrite(greenLED4, active == 4);
  digitalWrite(redLED4, active != 4);
}

void alternateSignals() {
  for (int i = 1; i <= 4; i++) {
    setSignals(i);
    Serial.print("Alternating Lane: "); Serial.println(i);
    delay(2000);
  }
}

int getDistance(int trig, int echo) {
  digitalWrite(trig, LOW); delayMicroseconds(2);
  digitalWrite(trig, HIGH); delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH, 20000);
  return (duration == 0) ? 999 : duration * 0.034 / 2;
}
