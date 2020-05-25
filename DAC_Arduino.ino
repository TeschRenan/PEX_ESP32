#define Dac1Pin 25

int32_t data[360] = {0};
int32_t data2[255] = {0};
int32_t inicio = 0;
int32_t fim = 0;

//16.67 / n bits da senoide

void setup() {
  
  Serial.begin(115200);

//Monta o vetor da senoide de 0 a 360 Graus
  for (int16_t deg = 0; deg < 360; deg = deg + 1){
    data[deg] = (128 + 64 * (sin(deg*PI/180)));
                //OFFSET //Amplitude de sinal //graus para radianos
}
//Monta o vetor da onda triangular de 0 a 255, de 0 a 127 é a dente de serra.
  for (int16_t i = 0; i < 128; i++){
    data2[i] = i * 2;               
}
  for (int16_t i = 128; i < 255; i++){
    data2[i] = (255 - i) * 2;               
}

  inicio = micros();
  dacWrite(Dac1Pin, data[180]);
  fim = micros();
  Serial.print(fim-inicio);
}

void loop() { 
//-------------------------------------------------------------//
  //Senoide de baixa resolução, frequencia maxima 4kHz 
  // a cada 8º um incremento
  /*
  for (int16_t deg = 0; deg < 360; deg = deg + 8){
    dacWrite(Dac1Pin, data[deg]);
  }
  */
//-------------------------------------------------------------//  
  //Senoide de alta resolução Frequencia maxima 160Hz
  // a cada 1º um incremento
  /*
  for (int16_t deg = 0; deg < 360; deg = deg + 1){
    dacWrite(Dac1Pin, data[deg]);
    ets_delay_us(40);
  }
  */
//-------------------------------------------------------------//
  //Onda triangular de baixa resolução, Frequencia Maxima de 5.8KHz
  // a cada 8 bits de incremento
  /*
     for (int16_t i = 0; i < 255; i = i + 8){
     dacWrite(Dac1Pin, data2[i]);               
  }
  */
//-------------------------------------------------------------//
  //Onda triangular de alta resolução, Frequencia Maxima de 720Hz
  // a cada 1 bits de incremento
  /*
     for (int16_t i = 0; i < 255; i++){
     dacWrite(Dac1Pin, data2[i]);               
  }
  */

  //-------------------------------------------------------------//
  //Dente de Serra de baixa resolução, Frequencia Maxima de 11.5KHz
  // a cada 8 bits de incremento
  /*
     for (int16_t i = 0; i < 128; i = i+8){
     dacWrite(Dac1Pin, data2[i]);               
  }
  */
  //-------------------------------------------------------------//
  //Dente de Serra de alta resolução, Frequencia Maxima de 1.45KHz
  // a cada 1 bits de incremento
  /*
     for (int16_t i = 0; i < 128; i++){
     dacWrite(Dac1Pin, data2[i]);               
  }
  */
}
