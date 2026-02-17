// Задание 1.8

#include <stdio.h>

void task_one(void) {
    long count;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            ++count;
        }
    }

    printf("%ld", count);
}

void task_two(void) {
    int ch, prev_ch = EOF;

    while ((ch = getchar()) != EOF) {
        if (ch != ' ') {
            putchar(ch);
        } else {
            if (prev_ch != ' ') {
                putchar(ch);
            }
        }

        prev_ch = ch;
    }
}

int main(void)
{
    task_two();

    return 0;
}