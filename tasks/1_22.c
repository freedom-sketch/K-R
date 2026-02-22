#include <stdio.h>

#define N 20

void collaps(void)
{
    int c, pos = 0; /* Текущая позиция*/
    int last_nonblank = 0; /* Позиция последнего непустого символа */
    char buffer[N + 1]; /* Буфер для хранения текущей строки */

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            /* Достигнут конец строки, выводим все что есть в буфере */
            for (int i = 0; i < pos; i++)
                putchar(buffer[i]);
            putchar('\n');

            pos = 0;
            last_nonblank = 0;
        } else {
            /* Сохраняем символ в буфер */
            if (pos < N) {
                buffer[pos] = c;
                
                /* Запоминаем позицию последнего непустого символа */
                if (c != ' ' && c != '\t')
                    last_nonblank = pos;
                
                pos++;

                /* Если достигли предела и есть место для переноса */
                if (pos >= N && last_nonblank > 0) {
                    /* Делаем вывод до последнего непустого символа */
                    for (int i = 0; i < last_nonblank; ++i)
                        putchar(buffer[i]);
                    putchar('\n');

                    /* Переносим остаток в начало буфера.
                    Из позиции последнего элемента вычитаем позицию
                    последнего непустого элемента и еще 1 (чтобы
                    не включать сам непустой элемент). Так мы получаем
                    количество оставшихся символов */
                    int remaining = pos - last_nonblank - 1;
                    for (int i = 0; i < remaining; ++i)
                        buffer[i] = buffer[last_nonblank + 1 + i];
                    
                    pos = remaining;
                    last_nonblank = 0;

                    /* Пересчитываем last_nonblank для нового буфера */
                    for (int i = 0; i < pos; ++i) {
                        if (buffer[i] != ' ' && buffer[i] != '\t')
                            last_nonblank = i;
                    }
                }
            }
        }
    }

    /* Выводим все что осталось в буфере */
    if (pos > 0) {
        for (int i = 0; i < pos; ++i)
            putchar(buffer[i]);
        putchar('\n');
    }
}

int main(void)
{
    collaps();

    return 0;
}