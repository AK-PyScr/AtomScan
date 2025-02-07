void btnIsr() {
    unsigned long currentMillis = millis();

    // Проверяем разницу времени между текущим импульсом и предыдущим
    timeDifference = currentMillis - lastPulseTime;
    if (timeDifference > 10) { 
        if (pulseCount == 0) {
            FirstPulseTime = currentMillis;              // Зафиксировать время первого импульса

        }

        pulseCount++;
        counter++;
        event = HIGH;

        lastPulseTime = currentMillis;                   // cброс
    }
}