
#define ledPin2 GPIO_NUM_2


void setup() {
  
  gpio_pad_select_gpio(ledPin2);

  gpio_set_direction(ledPin2, GPIO_MODE_OUTPUT);
  
}

void loop() {

  gpio_set_level(ledPin2, 1);
  delay(1000);
  gpio_set_level(ledPin2, 0);
  delay(1000);
  
}
