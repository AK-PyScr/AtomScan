# AtomScan


Устройство представляет собой счетчик радиации, использующий детектор, такой как СТС-5 или СБМ-20, для измерения количества частиц в окружающей среде. Он рассчитывает частоту событий (CPS — количество частиц в секунду) и выводит дозу радиации на основе этих измерений. Система работает с массивом, который хранит количество частиц за последние несколько минут, и рассчитывает средние значения по этим данным для более точного отображения текущего радиационного фона.

Описание основных параметров:
    NORMA — нормальное количество импульсов в минуту для различных типов счетчиков.
    FON_NORMA — нормальный радиационный фон в мкР/ч.
    TIME_UPDATE — время обновления значений частиц, определяющее интервал для расчетов.
    ARRAY_LEN — длина массива для хранения значений количества частиц за последние несколько обновлений.
    Описание работы:
    Каждый раз, когда устройство обновляет значения (каждые TIME_UPDATE секунд), оно удаляет старое значение из массива и добавляет новое.
    На основе этого массива рассчитывается среднее количество частиц за интервал и пересчитывается дозу радиации.
    Полученные данные (доза и количество частиц) выводятся через сериальный порт для дальнейшего анализа или отображения на графиках.
    Этот код и алгоритм позволяет точно отслеживать изменения в радиационном фоне, обеспечивая надежные данные для мониторинга радиационной обстановки.
    
    
    
    
The device is a radiation counter that uses a detector, such as the SCT-5 or SBM-20, to measure the number of particles in the surrounding environment. It calculates the event frequency (CPS - counts per second) and outputs the radiation dose based on these measurements. The system works with an array that stores the number of particles over the last few minutes and computes average values from this data for more accurate representation of the current radiation background.

Key Parameters:
  NORMA — normal number of counts per minute for different types of counters.
  FON_NORMA — normal radiation background in µR/h.
  TIME_UPDATE — time interval for updating particle values, determining the refresh rate for calculations.
  ARRAY_LEN — length of the array for storing particle counts over the last updates.
  How It Works:
  Each time the device updates values (every TIME_UPDATE seconds), it removes the oldest value from the array and adds the new one.
  Based on this array, the average particle count over the interval is calculated, and the radiation dose is recalculated.
  The resulting data (dose and particle count) is sent via the serial port for further analysis or visualization on graphs.
  This code and algorithm allow precise tracking of changes in the radiation background, providing reliable data for monitoring the radiation situation.


