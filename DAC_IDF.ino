#include <driver/dac.h>
// DAC_CHANNEL_1 == GPIO_25
int32_t data[360] = {0};
int32_t data2[255] = {0};
int32_t inicio = 0;
int32_t fim = 0;

//16.67uS / n bits da senoide

void setup() {
  
  Serial.begin(115200);
  //Ativa o DAC
 dac_output_enable(DAC_CHANNEL_1);
    
    
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
  dac_output_voltage(DAC_CHANNEL_1,255);
  fim = micros();
  Serial.print(value); //4uS
}

void loop() { 
//-------------------------------------------------------------//
  //Senoide de baixa resolução, frequencia maxima 5.4kHz 
  // a cada 8º um incremento
  /*
  for (int16_t deg = 0; deg < 360; deg = deg + 8){
    dac_output_voltage(DAC_CHANNEL_1, data[deg]);
  }
  */
//-------------------------------------------------------------//  
  //Senoide de alta resolução Frequencia maxima 670Hz
  // a cada 1º um incremento
  /*
  for (int16_t deg = 0; deg < 360; deg = deg + 1){
    dac_output_voltage(DAC_CHANNEL_1, data[deg]);
    ets_delay_us(42); //delay para 60HZ
  }
  */
//-------------------------------------------------------------//
  //Onda triangular de baixa resolução, Frequencia Maxima de 7.7KHz
  // a cada 8 bits de incremento
  /*
     for (int16_t i = 0; i < 255; i = i + 8){
     dac_output_voltage(DAC_CHANNEL_1, data2[i]);               
  }
  */
//-------------------------------------------------------------//
  //Onda triangular de alta resolução, Frequencia Maxima de 950Hz
  // a cada 1 bits de incremento
  /*
     for (int16_t i = 0; i < 255; i++){
     dac_output_voltage(DAC_CHANNEL_1, data2[i]);               
  }
  */

  //-------------------------------------------------------------//
  //Dente de Serra de baixa resolução, Frequencia Maxima de 15KHz
  // a cada 8 bits de incremento
  /*
     for (int16_t i = 0; i < 128; i = i+8){
     dac_output_voltage(DAC_CHANNEL_1, data2[i]);               
  }
  */
  //-------------------------------------------------------------//
  //Dente de Serra de alta resolução, Frequencia Maxima de 1.9KHz
  // a cada 1 bits de incremento
  /*
     for (int16_t i = 0; i < 128; i++){
     dac_output_voltage(DAC_CHANNEL_1, data2[i]);               
  }
  */
}
