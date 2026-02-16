#include <stdio.h>

#define LOWER  0
#define UPPER  300
#define STEP   20

static void print_temperature_table(int start, int end, int step) {
    printf("%3s\t%6s\n", "°F", "°C");

    int fahr = start;
    while (1) {
        printf("%3d%7.1f\n", fahr, (5.0/9.0)*(fahr - 32));
        if (fahr == end) break;
        fahr += step;
    }
}

int main(void) {
    print_temperature_table(UPPER, LOWER, -STEP);
    printf("\n");
    print_temperature_table(LOWER, UPPER,  STEP);

    return 0;
}