#define pinoBotao 5
#define ledPin2 2   


int statusBotao = 0;

void setup() {
  
  pinMode(ledPin2, OUTPUT);

  pinMode(pinoBotao, INPUT);
}

void loop() {
  
  statusBotao = digitalRead(pinoBotao);

  if (statusBotao == 1) {

    digitalWrite(ledPin2, HIGH);
  } else {

    digitalWrite(ledPin2, LOW);
  }
}
