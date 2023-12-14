#include <stdio.h>
#include<math.h>

double logNatural2(int n);

int main()
{
    int n;
    double log;

    printf("Informe n: ");
    scanf("%d", &n);

    log = logNatural2(n);

    printf("\n%.2lf\n", log);

    return 0;
}

double logNatural2(int n)
{
    double log = 0;

    for (int i = 1; i <= n; i ++) {
        log += pow(-1, i + 1) / i;
    }

    return log;
}
