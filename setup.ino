
void setup() {
  pinMode(9, OUTPUT);
  PWM_frequency(9, 6000, FAST_PWM);
  PWM_set(9, 239);
  oled.init();  // инициализация
  oled.clear();   // очистить дисплей (или буфер)
  oled.update();  // обновить. Только для режима с буфером! OLED_BUFFER

  // --------------------------
  oled.home();            // курсор в 0,0
  oled.print("Hello!");   // печатай что угодно: числа, строки, float, как Serial!
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), btnIsr, FALLING);

  pinMode(LED_BUILTIN, OUTPUT);                   // Настраиваем встроенный светодиод
  Serial.begin(9600);
  sec = ch_sec = millis() / 1000ul;
}