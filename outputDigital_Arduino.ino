
#define ledPin2 2

void setup() {
  pinMode(ledPin2, OUTPUT);

}

void loop() {

  digitalWrite(ledPin2, HIGH);
  delay(1000);
  digitalWrite(ledPin2, LOW);
}
