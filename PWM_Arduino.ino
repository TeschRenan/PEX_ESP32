#define ledPin 15  // 15 == GPIO15

//Propriedades do PWM
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
 
void setup(){
  //Configura o canal, frequencia e resolução do PWM.
  ledcSetup(ledChannel, freq, resolution);
  
  // Configura o pino para o Canal 0.
  ledcAttachPin(ledPin, ledChannel);
}
 
void loop(){
  //Incrementa o duty
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

  //decremente o duty
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledcWrite(ledChannel, dutyCycle);   
    delay(15);
  }
}
