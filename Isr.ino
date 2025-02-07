unsigned long FirstPulseTime = 0;               // Время первого импульса

unsigned long lastPulseTime = 0;                // Время последнего импульса
unsigned long timeDifference = 0;               // Разница времени между импульсами

uint32_t flagNullCount = false;                        // Счётчик импульсов

void btnIsr() {
    unsigned long currentMillis = millis();

    // Проверяем разницу времени между текущим импульсом и предыдущим
    timeDifference = currentMillis - lastPulseTime;
    if (timeDifference > 10) { 
        if (flagNullCount == false) {
            FirstPulseTime = currentMillis;              // Зафиксировать время первого импульса
            flagNullCount = true;
        }

        counter++;
        event = HIGH;

        lastPulseTime = currentMillis;                   // cброс
    }
}