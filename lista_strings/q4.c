#include <stdio.h>
#include <string.h>

#define TAM 61

void letraRepetida(char string[TAM], char letras[TAM]);
void removeRepetida(char string[TAM], char letras[TAM]);
void inverso(char string[TAM]);

int main()
{
    char string[TAM], letras[TAM];

    printf("Digite a frase: "); 
    fgets(string, TAM, stdin);

    string[strlen(string) - 1] = '\0';
    
    letraRepetida(string, letras);

    printf("\nLetras repetidas: ");
    for (int i = 0; i < strlen(letras); i++) {
        printf("%c ", letras[i]);
    }

    inverso(string);

    removeRepetida(string, letras);

    printf("\n\nFrase sem letrsa repetidas: %s\n", string);

    return 0;
}

void letraRepetida(char string[TAM], char letras[TAM])
{
    char letra;
    int cont, x = 0;

    for (int i = 0; i < strlen(string); i++) {
        letra = string[i];
        cont = 0;
        for (int j = 0; j < strlen(string); j++) {
            if (string[j] == letra && string[j] != ' ')
                cont++;

            if (cont == 2) {
                for (int k = 0; k < strlen(letras); k++) 
                    if (letras[k] == letra)
                        cont++;

                if (cont == 2) {
                    letras[x] = letra;
                    x++;
                }  

                break;
            }
        }
    }
}

void removeRepetida(char string[TAM], char letras[TAM])
{
    int cont;
    char letra;

    for (int i = 0; i < strlen(letras); i++) {
        letra = letras[i];
        for (int j = 0; j < strlen(string); j++) {
            if (string[j] == letra) {
                string[j] = ' ';
                cont = j;
                while (cont < strlen(string)) {
                    string[cont] = string[cont + 1];
                    cont++;
                }
            }
        }
    }  
}

void inverso(char string[TAM])
{
    printf("\n\n");
    for (int i = strlen(string) - 1; i >= 0; i--) 
        printf("%c", string[i]);
    printf("\n");
}