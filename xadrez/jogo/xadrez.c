#include <stdio.h>

void topoDoTabuleiro();
void peao(int, int);
void torre(int, int);
void cavalo(int, int);
void bispo(int, int);
void rainha(int, int);
void rei(int, int);

int main()
{
    int p, coluna, linha;
    char continuar;

    printf("\n\n[1] Peão\n");
    printf("[2] Torre\n");
    printf("[3] Cavalo\n");
    printf("[4] Bispo\n");
    printf("[5] Rainha\n");
    printf("[6] Rei\n");
    printf("Escolha alguma peça de xadrez: "); scanf("%d", &p);

    while (p <= 0 || p > 6) {
        printf("\n[1] Peão\n");
        printf("[2] Torre\n");
        printf("[3] Cavalo\n");
        printf("[4] Bispo\n");
        printf("[5] Rainha\n");
        printf("[6] Rei\n");
        printf("Resposta inválida! \nEscolha alguma peça de xadrez: "); scanf("%d", &p);
    }

    switch (p) {
        case 1:
            printf("\nDigite a linha e coluna em que o peão está: "); scanf("%d %d", &linha, &coluna);
            topoDoTabuleiro();
            peao(linha, coluna);
            break;
        case 2:
            printf("\nDigite a linha e coluna em que a torre está: "); scanf("%d %d", &linha, &coluna);
            topoDoTabuleiro();
            torre(linha, coluna);
            break;
        case 3:
            printf("\nDigite a linha e coluna em que o cavalo está: "); scanf("%d %d", &linha, &coluna);
            topoDoTabuleiro();
            cavalo(linha, coluna);
            break;
        case 4:
            printf("\nDigite a linha e coluna em que o bispo está: "); scanf("%d %d", &linha, &coluna);
            topoDoTabuleiro();
            bispo(linha, coluna);
            break;
        case 5:
            printf("\nDigite a linha e coluna em que a rainha está: "); scanf("%d %d", &linha, &coluna);
            topoDoTabuleiro();
            rainha(linha, coluna);
            break;
        case 6:
            printf("\nDigite a linha e coluna em que o rei está: "); scanf("%d %d", &linha, &coluna);
            topoDoTabuleiro();
            rei(linha, coluna);
            break;                    
    }

    printf("\n\nEssas são as posições possíveis\n");

    return 0;
}

void topoDoTabuleiro()
{
    printf("\n\n     |");
    for(int i = 1; i <= 8; i++) {
        printf("  %d  |", i);
    }

    printf("\n------");
    for(int i = 1; i <= 8; i++) {
        printf("------");
    }
}

void peao(int linha, int coluna)
{
    for(int y = 1; y <= 8; y++) {
        printf("\n  %d  |", y);
        for(int x = 1; x <= 8; x++) {
            if (coluna == x && linha == y)
                printf("  O  |");
            else if (coluna == x - 1 && linha == y + 1 || 
                    coluna == x && linha == y + 1 || 
                    coluna == x + 1 && linha == y + 1) 
                printf("  x  |");
            else
                printf("  -  |");    
        }
    }
}

void torre(int linha, int coluna)
{
    for(int y = 1; y <= 8; y++) {
        printf("\n  %d  |", y);
        for(int x = 1; x <= 8; x++) {
            if (coluna == x && linha == y)
                printf("  O  |");
            else if (coluna == x || linha == y) 
                printf("  x  |");
            else
                printf("  -  |");
        }
    }
}

void cavalo(int linha, int coluna)
{
    for (int y = 1; y <= 8; y++) {
        printf("\n  %d  |", y);
        for (int x = 1; x <= 8; x++) {
            if (coluna == x && linha == y)
                printf("  O  |");
            else if (y == linha - 2 && x == coluna - 1 ||
                    y == linha - 2 && x == coluna + 1 ||
                    y == linha - 1 && x == coluna - 2 ||
                    y == linha - 1 && x == coluna + 2 ||
                    y == linha + 1 && x == coluna - 2 ||
                    y == linha + 1 && x == coluna + 2 ||
                    y == linha + 2 && x == coluna - 1 ||
                    y == linha + 2 && x == coluna + 1)    
                printf("  x  |");
            else 
                printf("  -  |");
        }
    }
}

void bispo(int linha, int coluna)
{
    int aux1 = linha - 1;
    int aux2 = 1;

    for(int y = 1; y <= 8; y++) {
        printf("\n  %d  |", y);
        for(int x = 1; x <= 8; x++) {
            if (coluna == x && linha == y)
                printf("  O  |");
            else if (y < linha && x == coluna - aux1 || 
                    y < linha && x == coluna + aux1 || 
                    y > linha && x == coluna - aux2 || 
                    y > linha && x == coluna + aux2) 
                printf("  x  |"); 
            else
                printf("  -  |");
        }

        if (y > linha)
            aux2++;
        else
            aux1--;    
    }
}

void rainha(int linha, int coluna)
{
    int aux1 = linha - 1;
    int aux2 = 1;

    for(int y = 1; y <= 8; y++) {
        printf("\n  %d  |", y);
        for(int x = 1; x <= 8; x++) {
            if (coluna == x && linha == y)
                printf("  O  |");
            else if (y < linha && x == coluna - aux1 || 
                    y < linha && x == coluna + aux1 || 
                    y > linha && x == coluna - aux2 || 
                    y > linha && x == coluna + aux2 ||
                    coluna == x || 
                    linha == y) 
                printf("  x  |"); 
            else
                printf("  -  |");
        }

        if (y > linha)
            aux2++;
        else
            aux1--;    
    }
}

void rei(int linha, int coluna)
{
    for(int y = 1; y <= 8; y++) {
        printf("\n  %d  |", y);
        for(int x = 1; x <= 8; x++) {
            if (coluna == x && linha == y)
                printf("  O  |");
            else if (y == linha - 1 && x == coluna - 1 || 
                    y == linha - 1 && x == coluna + 1 || 
                    y == linha - 1 && coluna == x || 
                    y == linha && x == coluna - 1 ||
                    y == linha && x == coluna + 1 ||
                    y == linha + 1 && x == coluna - 1 || 
                    y == linha + 1 && x == coluna + 1 ||
                    y == linha + 1 && coluna == x) 
                printf("  x  |"); 
            else
                printf("  -  |");
        }
    }
} 