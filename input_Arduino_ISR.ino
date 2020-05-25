#define pinoBotao 5 
#define ledPin2 2   

bool botaoFlag = false;

void setup() {
  
  pinMode(ledPin2, OUTPUT);
  
  pinMode(pinoBotao, INPUT);
  
  /*
  Define quando a interrupção será acionada.
  Abaixo seguem as constantes predefinidas:
  LOW : aciona a interrupção sempre que o pino estiver baixo.
  CHANGE: aciona a interrupção sempre que o pino muda de estado.
  RISING: aciona a interrupção quando o pino vai de baixo para alto (LOW > HIGH).
  FALLING: para acionar a interrupção quando o pino vai de alto para baixo (HIGH > LOW)
  HIGH : aciona a interrupção sempre que o pino estiver alto.
  */
  attachInterrupt(pinoBotao, interrupcaoFunction,FALLING);
}

void interrupcaoFunction(){
  botaoFlag = true;
}

void loop() {
  
  if (botaoFlag == true){
    
    delay(1000);
    
    digitalWrite(ledPin2, HIGH);
    
    delay(1000);
    
    digitalWrite(ledPin2, LOW);
  }
}
