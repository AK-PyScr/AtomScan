#define NORMA 30                                             // количество импульсов в минуту при нормальном фоне, для СТС-5 = 27, для СБМ-20 = 67, для других счетчиков см.паспорт
#define FON_NORMA 15                                         // нормальный радиационный фон 15мкР/ч

#define TIME_UPDATE 3                                        // время обновления значений частиц
#define ARRAY_LEN 40                                         // длинна массива для хранения количеста частиц


uint8_t index = 0;                                           // Индекс текущего интервала для замены данных
int SUMofCounts;                                             // сумма частиц в массиве
boolean indexFlag = false;

float CPS = 0;                                               // чатици в секунду
float CPM = 0;                                               // чатици в минуту
float doza = 0;    

int Counts[ARRAY_LEN];      

void CalculateCPM() {                                       
  ch_sec = millis() / 1000ul;
  if ((ch_sec - sec) >= TIME_UPDATE) {
    noInterrupts();

    SUMofCounts -= Counts[index];                           // Убираем самое старое значение
    Counts[index] = counter;                                // Записываем новое значение импульсов   
    counter = 0;                                            // Обнуляем счётчик для следующего интервала
    SUMofCounts += Counts[index];                           // Добавляем в сумму это последнее значение

    if (index < ARRAY_LEN - 1 && !indexFlag) {
      CPS = (float)SUMofCounts / ((index + 1) * TIME_UPDATE);  
    } else {  
      CPS = (float)SUMofCounts / (ARRAY_LEN * TIME_UPDATE);  
      indexFlag = true;
    }
    
    // Рассчитываем CPM, используя точное количество секунд
    float seconds_per_minute = 60.0;   
    float time_interval = (ch_sec - sec);                   // Время в секундах с последнего обновления
    CPM = CPS * seconds_per_minute * (time_interval / TIME_UPDATE);  // Пересчитываем CPM более точно
    
    doza = testFilter.filtered(CPM * FON_NORMA / NORMA);
    // float doza1 = (CPM * FON_NORMA / NORMA);

    // Отправляем значения для двух графиков, разделяя их запятыми
    Serial.print(doza);
    // Serial.print(",");  // Разделитель между графиками
    // Serial.println(doza1);  // Второй график


    // Serial.print("CPS: "); Serial.print(CPS, 2);  
    // Serial.print(" | SUMofCounts: "); Serial.print(SUMofCounts);
    // Serial.print(" | index: "); Serial.println(index);

    index = (index + 1) % ARRAY_LEN;  // Обновляем индекс циклично
    interrupts();

    sec = ch_sec;  // Обновляем значение секунд
    
  }
}