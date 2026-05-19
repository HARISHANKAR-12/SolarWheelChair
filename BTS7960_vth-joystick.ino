// Motor 1
int R_PWM = 3;
int L_PWM = 6;

// Motor 2
int R_PWM2 = 9;
int L_PWM2 = 10;

// Enable pins
int R_EN = 2;
int L_EN = 5;
int R_EN2 = 8;
int L_EN2 = 7;

// Joystick pins
int joyX = A0;
int joyY = A1;

void setup() {
  pinMode(R_PWM, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(R_PWM2, OUTPUT);
  pinMode(L_PWM2, OUTPUT);

  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);
  pinMode(R_EN2, OUTPUT);
  pinMode(L_EN2, OUTPUT);

  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);
  digitalWrite(R_EN2, HIGH);
  digitalWrite(L_EN2, HIGH);

  Serial.begin(9600);
}

void loop() {
  int x = analogRead(joyX); // 0–1023
  int y = analogRead(joyY); // 0–1023

  // Convert to -255 to +255
  int forward = map(y, 0, 1023, 255, -255);
  int turn    = map(x, 0, 1023, -255, 255);

  int leftMotor  = forward + turn;
  int rightMotor = forward - turn;

  leftMotor  = constrain(leftMotor, -255, 255);
  rightMotor = constrain(rightMotor, -255, 255);

  // LEFT MOTOR
  if (leftMotor > 0) {
    analogWrite(R_PWM, leftMotor);
    analogWrite(L_PWM, 0);
  } else {
    analogWrite(R_PWM, 0);
    analogWrite(L_PWM, -leftMotor);
  }

  // RIGHT MOTOR
  if (rightMotor > 0) {
    analogWrite(R_PWM2, rightMotor);
    analogWrite(L_PWM2, 0);
  } else {
    analogWrite(R_PWM2, 0);
    analogWrite(L_PWM2, -rightMotor);
  }

  delay(50);
}