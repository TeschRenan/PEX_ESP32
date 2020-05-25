#include "driver/ledc.h"
  
void setup() {

    ledc_timer_config_t ledc_timer;
        ledc_timer.duty_resolution    = LEDC_TIMER_8_BIT;     // resolução em Bits do PWM
        ledc_timer.freq_hz            = 5000;                 // Frequencia do sinal de PWM 
        ledc_timer.speed_mode         = LEDC_HIGH_SPEED_MODE; // Timer a ser usado, high speed ou low speed
        ledc_timer.timer_num          = LEDC_TIMER_0;       // Indexador do Timer
//      ledc_timer.clk_cfg            = LEDC_AUTO_CLK;      // Auto select the source clock
    
    // Configura o Timer 0 para high speed
    ledc_timer_config(&ledc_timer);

   ledc_channel_config_t ledc_channel;
        ledc_channel.channel    = LEDC_CHANNEL_0;
        ledc_channel.duty       = 0;
        ledc_channel.gpio_num   = 15;
        ledc_channel.speed_mode = LEDC_HIGH_SPEED_MODE;
        ledc_channel.timer_sel  = LEDC_TIMER_0;
        ledc_channel.hpoint     = 1;
    // Configura o Canal 0 para iniciar.
   ledc_channel_config(&ledc_channel);

   ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, 0);
   ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);
}

void loop(){
    //Incrementa o duty
    for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){    
    ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, dutyCycle);
    ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0);
    delay(15);
  }

  //decremente o duty
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    ledc_set_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0, dutyCycle);
    ledc_update_duty(LEDC_HIGH_SPEED_MODE, LEDC_CHANNEL_0); 
    delay(15);
  }
  
}
