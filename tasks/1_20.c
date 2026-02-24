/* Напишите программу detav, которая бы заменяла символы
табуляции во входном потоке соответствущим количеством пробелов
до следующей границы табцляции. Предположим, что табуляция имеет
фиксированную ширину n столбцов. */

#include <stdio.h>

#define N 5 /* Фиксированная ширина табуляции */

void detab(void)
{
    int c, cnt;
    for (int pos = 0; (c = getchar()) != EOF;)
        if (c == '\t') {
            cnt = N - pos % N;
            for (int i = 0; i < cnt; ++i) {
                putchar(' ');
                ++pos;
            }
        } else {
            putchar(c);
            pos++;

            if (c == '\n') pos = 0;
        }
}

int main(void)
{
    detab();
    putchar('\n');

    return 0;
}