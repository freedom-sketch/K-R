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

void task_three(void) {
    int ch;

    while ((ch = getchar()) != EOF) {
        if (ch == '\t') {
            putchar('\\');
            putchar('t');
        } else if (ch == '\b') {
            putchar('\\');
            putchar('b');
        } else if (ch == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(ch);
        }
    }
}

int main(void)
{
    task_three();

    return 0;
}