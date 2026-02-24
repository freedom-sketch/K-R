/* Программа, удаляющая все комментарии из программы на C */

#include <stdio.h>

#define NORMAL 0
#define IN_STRING 1
#define IN_COMMENT_BLOCK 3
#define IN_COMMENT_LINE 4

int peek() {
    int next = getchar();
    if (next != EOF) {
        ungetc(next, stdin);
    }
    return next;
}

int main(void)
{
    int c;
    int state = NORMAL;
    
    while ((c = getchar()) != EOF) {
        if (state == IN_COMMENT_BLOCK) {
            if (c == '*' && peek() == '/') {
                getchar();
                state = NORMAL;
            }
        } 
        else if (state == IN_COMMENT_LINE) {
            if (c == '\n') {
                putchar(c);
                state = NORMAL;
            }
        }
        else if (state == IN_STRING) {
            putchar(c);
            if (c == '\\') {
                putchar(getchar());
            }
            else if (c == '"') {
                state = NORMAL;
            }
        }
        else {
            if (c == '/' && peek() == '*') {
                getchar();
                state = IN_COMMENT_BLOCK;
            }
            else if (c == '"')
                state = IN_STRING;
            else if (c == '/' && peek() == '/') {
                getchar();
                state = IN_COMMENT_LINE;
            }
            else
                putchar(c);
        }
    }

    return 0;
}