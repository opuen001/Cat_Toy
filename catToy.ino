const int AIN1 = 7;
const int PWMA_LEFT = 5;
const int STBY_PIN = 8; 

void setup() {
  Serial.begin(9600);

  pinMode(AIN1, OUTPUT);
  pinMode(PWMA_LEFT, OUTPUT);
  pinMode(STBY_PIN, OUTPUT);

  // Enable motor driver
  digitalWrite(STBY_PIN, HIGH);

  // Seed randomness (floating analog pin is good entropy)
  randomSeed(analogRead(A0));

  Serial.println("Random motor behavior started");
}

void loop() {
  // Randomly decide direction
  bool forward = random(0, 2);   // 0 or 1
  digitalWrite(AIN1, forward ? HIGH : LOW);

  // Random speed
  int speed = random(0, 256);
  analogWrite(PWMA_LEFT, speed);

  // Print current state
  Serial.print("Direction: ");
  Serial.print(forward ? "FORWARD" : "REVERSE");
  Serial.print(" | Speed: ");
  Serial.println(speed);

  // Random delay
  delay(random(1000, 3000));
}
