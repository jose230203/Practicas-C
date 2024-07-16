#include <stdio.h>

int main() {
    int mult = 5;
    int result,i;

    for (i = 1; i <= 10; i++) {
        result = i * mult;
        printf("%d x %d = %d\n", mult, i, result);
    }

    return 0;
}

