// #include "GyverPWM.h"
#include <GyverOLED.h>
#include "GyverFilters.h"

GyverOLED<SSD1306_128x64, OLED_BUFFER, OLED_I2C> oled;
// параметры: разброс измерения, разброс оценки, скорость изменения значений
GKalman testFilter(7, 7, 0.6);

#define DUTY 450    
#define CPM_TO_USV 0.0065                       // Коэффициент пересчета для СБМ-20


uint32_t counter = 0;  
uint32_t sec, ch_sec;
boolean event = LOW;

unsigned long lastPulseTime = 0;                // Время последнего импульса
unsigned long timeDifference = 0;               // Разница времени между импульсами

unsigned long totalTime = 0;                    // Время, прошедшее на 10 
unsigned long FirstPulseTime = 0;               // Время последнего импульса
uint32_t pulseCount = 0;                        // Счётчик импульсов




