#define pinoBotao GPIO_NUM_5
#define ledPin2 GPIO_NUM_2   


int statusBotao = 0;

void setup() {
  
  gpio_pad_select_gpio(ledPin2);
  gpio_pad_select_gpio(pinoBotao);
  
  gpio_set_direction(ledPin2, GPIO_MODE_OUTPUT);
  gpio_set_direction(pinoBotao, GPIO_MODE_INPUT);  
  
}

void loop() {
  
  statusBotao = gpio_get_level(pinoBotao);

  if (statusBotao == 1) {

    gpio_set_level(ledPin2, 1);
  } else {

    gpio_set_level(ledPin2, 0);
  }
}
