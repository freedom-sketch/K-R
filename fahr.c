// печать таблицы температур по Фаренгейту
// и Цельсию для fahr = 0, 20, ..., 300

#include <stdio.h>

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; // нижняя граница таблицы температур
    upper = 300; // верхняя граница
    step = 20; // шаг

    // печать таблицы температур по Фаренгейту и Цельсию
    printf("%3s\t%6s\n", " ℉", "°C ");
    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr-32.0);
        printf("%3.0f\t%6.2f \n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}