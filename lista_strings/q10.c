#include <stdio.h>
#include <string.h>

#define TAM 21

void escolhas(int *);
void lerString(char s[TAM]);
void imprimeTamanho(char s[TAM]);
void comparaString(char s1[TAM], char s2[TAM]);
void concatenar(char s1[TAM], char s2[TAM]);
void reversa(char s[TAM]);
void contaCaractere(char s[TAM]);
void substituiCaractere(char s[TAM]);
void substring(char s1[TAM], char s2[TAM]);
void retornaSubstring(char s1[TAM]);

int main()
{
    char s1[TAM], s2[TAM];
    int n;

    escolhas(&n);

    while (n >= 1 && n <= 9) {
        switch (n) {
            case 1:
                lerString(s1);
                break;
            case 2:
                imprimeTamanho(s1);   
                break;
            case 3:
                comparaString(s1, s2);  
                break;   
            case 4:
                concatenar(s1, s2);
                break;
            case 5:
                reversa(s1);
                break;
            case 6:
                contaCaractere(s1);
                break;
            case 7:
                substituiCaractere(s1);
                break;
            case 8:
                substring(s1, s2);
                break;
            case 9:
                retornaSubstring(s1);
                break;
        }

        escolhas(&n);
    }

    return 0;
}

void escolhas(int *n)
{
    do {
        printf("\n[1] Ler uma string\n");
        printf("[2] Imprimir o tamanho da string\n");
        printf("[3] Comparar strings\n");
        printf("[4] Concatenar duas strings\n");
        printf("[5] Imprimir string de forma reversa\n");
        printf("[6] Contar as aparições de um dado caractere\n");
        printf("[7] Substituir um caractere pelo outro\n");
        printf("[8] Verificar substring\n");
        printf("[9] Retornar uma substring\n");
        printf("Escolha uma das opções: ");
        scanf("%d", n);
        fflush(stdin);
    } while (*n < 0 || *n > 9);
}

void lerString(char s[TAM])
{
    printf("\nDigite uma frase: ");
    fgets(s, TAM, stdin);
    s[strlen(s) - 1] = '\0';
}

void imprimeTamanho(char s[TAM])
{
    printf("\nO tamanho da string é: %d\n", strlen(s));
}

void comparaString(char s1[TAM], char s2[TAM])
{
    lerString(s2);

    int compara = strcmp(s1, s2);

    if (compara < 0)
        printf("\nAs strings não são iguais, e S1 vem antes de S2\n");
    else if (compara == 0) 
        printf("\nAs strings são iguais\n");
    else
        printf("\nAs strings não são iguais, e S1 vem depois de S2\n");    
}

void concatenar(char s1[TAM], char s2[TAM])
{
    char s3[TAM];
    strcpy(s3, s1);

    lerString(s2);

    printf("\nStrings concatenadas: %s\n", strcat(s3, s2));
}

void reversa(char s[TAM])
{
    printf("\n");
    for (int i = strlen(s) - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
    printf("\n");
}

void contaCaractere(char s[TAM])
{
    int cont = 0;
    char letra;

    printf("\nDigite uma letra: "); scanf("%c", &letra);
    fflush(stdin);

    for (int i = 0; i < strlen(s); i++) 
        if (s[i] ==  letra)
            cont++;

    printf("\nA letra '%c' apareceu %d vezes na string '%s'\n", letra, cont, s);        
}

void substituiCaractere(char s[TAM])
{
    char L1, L2, s3[TAM];

    strcpy(s3, s);

    printf("\nDigite L1: "); scanf("%c", &L1);
    fflush(stdin);

    printf("Digite L2: "); scanf("%c", &L2);
    fflush(stdin);

    for (int i = 0; i < strlen(s3); i++)
        if (s3[i] == L1)
            s3[i] = L2;

    printf("\n%s\n", s3);
}

void substring(char s1[TAM], char s2[TAM])
{
    int x, cont, igual = 0;

    lerString(s2);

    for (int i = 0; i < strlen(s1); i++) {
        x = 0;
        cont = 0;

        for (int j = i; j < i + strlen(s2); j++) {
            if (s1[j] == s2[x])
                cont++;
            x++;
        } 
       
        if (cont == strlen(s2)) {
            igual = 1;
            break;
        }
    }

    if (igual)
        printf("\n'%s' é uma substring de '%s'\n", s2, s1);
    else
        printf("\n'%s' não é uma substring de '%s'\n", s2, s1);
}

void retornaSubstring(char s1[TAM])
{
    int pos, tam, x = 0, limite;
    char s3[TAM];

    printf("\nInforme a posição inicial da substring: "); scanf("%d", &pos);
    printf("Informe o tamanho da subtring: "); scanf("%d", &tam);

    if (tam + pos > strlen(s1))
        limite = strlen(s1);
    else
        limite = tam + pos;

    for (int i = pos; i < limite; i++) {
        s3[x] = s1[i];
        x++;
    }

    s3[x] = '\0';

    printf("\n'%s' é uma substring de '%s'\n", s3, s1);
}