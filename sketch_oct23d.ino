int current = 1; 
int pulseCount = 0;



void setup() {
  pinMode(5, INPUT);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  if (digitalRead(5) == HIGH) {
    pulseCount++;

    if (pulseCount >= 10) {
      pulseCount = 0;

      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);

      if (current == 1) digitalWrite(2, HIGH);
      if (current == 2) digitalWrite(3, HIGH);
      if (current == 3) digitalWrite(4, HIGH);

      current++;
      if (current > 3) {
        current = 1;
      }
    }

    while (digitalRead(5) == HIGH) {
      delay(50);
    }
  }
}