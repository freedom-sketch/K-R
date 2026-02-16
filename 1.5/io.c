#include <stdio.h>

#ifdef _WIN32
    #include <windows.h>
    #define sleep(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define sleep(ms) usleep(ms * 1000)
#endif

#define DELAY 15

// копирование ввода на вывод
int main(void) {
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
        sleep(DELAY);
    }

    return 0;
}