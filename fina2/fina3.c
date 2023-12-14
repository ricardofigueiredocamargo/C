#include <stdio.h>
#include <string.h>

#define TAM 257

int contaLetras(char *palavra);
int contaPalavras(char *palavra);
void imprimeIniFim(char *palavra);

int main()
{
    char palavra[TAM];
    int contL, contP;

    printf("Digite uma frase: ");
    fgets(palavra, TAM, stdin);
    palavra[strlen(palavra) - 1] = '\0';

    contL = contaLetras(palavra);
    contP = contaPalavras(palavra);

    printf("Quantidade de letras: %d\n", contL);
    printf("Quantidade de palavras: %d\n", contP);
    printf("Dois primeiros e dois últimos caracteres: ");
    imprimeIniFim(palavra);

    return 0;
}

int contaLetras(char palavra[TAM])
{
    int cont = 0;

    for (int i = 0; i < strlen(palavra); i++) 
        if (palavra[i] >= 65 && palavra[i] <= 90 || palavra[i] >= 97 && palavra[i] <= 122)
            cont++;

    return cont;
}

int contaPalavras(char palavra[TAM])
{
    int espaco = 0;

    for (int i = 0; i < strlen(palavra); i++) 
        if (palavra[i] == ' ')
            espaco++;

    return espaco + 1;
}

void imprimeIniFim(char palavra[TAM])
{
    for (int i = 0; i < 2; i++) 
        printf("%c", palavra[i]);

    printf(" ");

    for (int i = strlen(palavra) - 2; i < strlen(palavra); i++)
        printf("%c", palavra[i]);
}
