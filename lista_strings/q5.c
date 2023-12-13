#include <stdio.h>
#include <string.h>

int main()
{
    char s[61], letra;

    printf("Frase digitada: "); fgets(s, 61, stdin);
    s[strlen(s) - 1] = '\0';

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != ' ') {
            letra = s[i];
            letra = letra - 32 + 3;
            if (letra > 90)
                letra -= 25;
            s[i] = letra;
        }
    }

    printf("Frase codificada: %s", s);

    return 0;
}