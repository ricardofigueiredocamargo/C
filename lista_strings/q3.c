#include <stdio.h>
#include <string.h>

#define TAM 61

void apaga(char string[TAM], char letra);

int main()
{
    char string[TAM], letra;

    printf("Digite a frase: "); 
    fgets(string, TAM, stdin);

    string[strlen(string) - 1] = '\0';

    printf("\nDigite a letra: "); scanf("%c", &letra);

    apaga(string, letra);

    printf("\n%s\n", string);

    return 0;
}

void apaga(char string[TAM], char letra)
{
    int cont;

    for (int i = 0; i < strlen(string); i++) 
        if (string[i] == letra) {
            string[i] = ' ';
            cont = i;
            while (cont < strlen(string)) {
                string[cont] = string[cont + 1];
                cont++;
            }
        }
}