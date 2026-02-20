#include <stdio.h>
#define MAXLINE 1000 /* Максимальная длина строки в потоке */

int max; /* Текущая максимальная длина */
char line[MAXLINE]; /* Текущая введенная строка */
char longest[MAXLINE]; /* Самая длинная строкаиз из введенных */

int getline(void);
void copy(void);

/* Вывод самой длинной строки в потоке; специальная версия */
int main(void)
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = getline() > 0)) {
        if (len > max) {
            max = len;
            copy();
        }
    }

    if (max > 0) {
        printf("%s", longest);
    }

    return 0;
}

/* getline: специальная версия */
int getline(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

/* copy: специальная версия */
void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0') {
        ++i;
    }
}