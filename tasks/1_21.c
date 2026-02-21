/* Напишите программу entab, которая бы заменяла пустые строки,
состоящие из одних пробелов, строками, содержащими минимальное количество
табуляций и дополнительных пробелов, - так, чтобы заполнять то же пространство. */

#include <stdio.h>

#define N 5

void entab(void)
{
    int c;
    int pos = 0;
    int sp_cnt = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            sp_cnt++;
            pos++;
        } else {
            if (sp_cnt > 0) {
                int tb_cnt = sp_cnt / N;
                int mk_sp = sp_cnt % N;
                
                for (int i = 0; i < tb_cnt; i++)
                    putchar('\t');
                for (int i = 0; i < mk_sp; i++)
                    putchar(' ');
                    
                sp_cnt = 0;
            }

            putchar(c);
            pos++;

            if (c == '\n')
                pos = 0;
        }
    }
}

int main(void)
{
    entab();
    putchar('\n');

    return 0;
}