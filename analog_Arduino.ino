// Entrada analogica conectada no GPIO 33 (Analog ADC1_CH5) 
#define analogIn 33

//Variavel para guardar a somatoria das medições da entrada analogica
uint32_t analogValue = 0;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  analogSetPinAttenuation(analogIn,ADC_0db);
}

void loop() {
    
    for (int i = 0; i < 100; i++)
    {
        analogValue += analogRead(analogIn);
        ets_delay_us(30);
    }
    analogValue /= 100;
        
  Serial.println(analogValue);
  delay(500);
}
