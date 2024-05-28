// Motor Connections (Both must use PWM pins)
#define RPWM 5
#define LPWM 6
#define ENCA 2         //AGREGADO 2 Y 3    COLOR AZUL
#define ENCB 3        //COLOR ROJO 

void setup() {
  Serial.begin(9600);       //AGREGADO
  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  // Stop motors
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
}

void readAndPrintEncoder() {
  int a = digitalRead(ENCA);
  int b = digitalRead(ENCB);
  Serial.print(a * 5);
  Serial.print(" ");
  Serial.print(b * 5);
  Serial.println();
}

void loop() {
  // Accelerate forward
  digitalWrite(RPWM, LOW);
  for (int i = 0; i < 255; i++) {
    analogWrite(LPWM, i);
    readAndPrintEncoder();
    delay(20);
  }

  delay(1000);

  // Decelerate forward
  for (int i = 255; i >= 0; i--) {
    analogWrite(LPWM, i);
    readAndPrintEncoder();
    delay(20);
  }

  delay(500);

  // Accelerate reverse
  digitalWrite(LPWM, LOW);
  for (int i = 0; i < 255; i++) {
    analogWrite(RPWM, i);
    readAndPrintEncoder();
    delay(50);
  }

  delay(1000);

  // Decelerate reverse
  for (int i = 255; i >= 0; i--) {
    analogWrite(RPWM, i);
    readAndPrintEncoder();
    delay(20);
  }

  delay(500);
}
  
    
