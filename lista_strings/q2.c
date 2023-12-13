#include <stdio.h>
#include <string.h>

int contaLetra(char string[61], char letra);

int main()
{
    char string[61], letra;
    int cont;

    printf("Digite a frase: ");
    fgets(string, 61, stdin);

    string[strlen(string) - 1] = '\0';

    printf("\nDigite a letra: ");
    scanf("%c", &letra);

    cont = contaLetra(string, letra);

    printf("\nA letra '%c' aparece %d vezes na frase digitada.\n", letra, cont);

    return 0;
}

int contaLetra(char string[61], char letra) 
{
    int cont = 0;

    for (int i = 0; i < strlen(string); i++) 
        if (string[i] == letra)
            cont++;

    return cont;        
}


