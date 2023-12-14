#include <stdio.h>

int main()
{
    int A = 5000000, B = 7000000, cont = 0;

    while (A < B) {
        A += A * 3 / 100;
        B += B * 2 / 100;
        cont++;
    }

    printf("\nSão necessários %d anos para que A ultrapasse B\n", cont);

    return 0;
}
