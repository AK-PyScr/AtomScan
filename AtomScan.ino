#include "GyverPWM.h"
#include <GyverOLED.h>
#include "GyverFilters.h"

GyverOLED<SSD1306_128x64, OLED_BUFFER, OLED_I2C> oled;
// параметры: разброс измерения, разброс оценки, скорость изменения значений
GKalman testFilter(7, 7, 0.6);


uint32_t counter = 0;                           // Счётчик импульсов
uint32_t sec, ch_sec;
boolean event = LOW;

float doza = 0;    
float CPS = 0;                                               // чатици в секунду
float CPM = 0;                                               // чатици в минуту