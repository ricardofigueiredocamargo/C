#include <stdio.h>
#include <string.h>

void maiusculo(char string[61]);
void minusculo(char string[61]);

int main()
{
    char string[61];

    printf("Digite a frase: "); 
    fgets(string, 61, stdin);

    string[strlen(string) - 1] = '\0';

    maiusculo(string);

    minusculo(string);

    return 0;
}

void maiusculo(char string[61]) 
{
    char letra;

    for (int i = 0; i < strlen(string); i++) {
        letra = string[i];
        if (letra >= 97 && letra <= 122) {
            letra -= 32;
            string[i] = letra;
        }
    }

    printf("\n%s\n", string);
}

void minusculo(char string[61]) 
{
    char letra;

    for (int i = 0; i < strlen(string); i++) {
        letra = string[i];
        if (letra >= 65 && letra <= 90) {
            letra += 32;
            string[i] = letra;
        }
    }

    printf("\n%s\n", string);
}