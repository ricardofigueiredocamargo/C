#include <stdio.h>

int main()
{
    float mat[70][5], mediaAluno[70], mediaProvas[5], pesos[5], mediaGeral = 0;
    int matriculas[70], qntA, qntP;

    printf("Digite a quantidade de alunos: "); scanf("%d", &qntA);
    printf("Digite a quantidade de provas aplicadas: "); scanf("%d", &qntP);

    for (int i = 0; i < qntP; i++) {
        printf("   Digite o peso da Prova %d: ", i + 1); 
        scanf("%f", &pesos[i]);
    }

    printf("Agora você irá digitar a matrícula e as %d notas dos alunos da disciplina.\n", qntP);
    for (int i = 0; i < qntA; i++) {
        printf("   Digite os dados do Aluno %d: ", i + 1); 
        scanf("%d", &matriculas[i]);
        for (int j = 0; j < qntP; j++)
            scanf("%f", &mat[i][j]);
    }

    for (int i = 0; i < qntA; i++) {
        mediaAluno[i] = 0;
        for (int j = 0; j < qntP; j++) 
            mediaAluno[i] += mat[i][j] * pesos[j];

        mediaGeral += mediaAluno[i];
    }

    printf("\nSituação dos alunos\n");
    printf("   Mátricula   Média   Situação\n");
    for (int i = 0; i < qntA; i++) {
        if (mediaAluno[i] >= 6)
            printf("   %d         %.1f     Aprovado\n", matriculas[i], mediaAluno[i]);
        else    
            printf("   %d         %.1f     Reprovado\n", matriculas[i], mediaAluno[i]);
    }

    for (int i = 0; i < qntP; i++) {
        mediaProvas[i] = 0;
        for (int j = 0; j < qntA; j++) 
            mediaProvas[i] += mat[j][i];
        
        mediaProvas[i] = mediaProvas[i] / qntA;
    }

    mediaGeral = mediaGeral / qntA;
 
    printf("\nEstatísticas\n");
    for (int i = 0; i < qntP; i++){ 
        printf("   Média da Prova %d: %.1f\n", i + 1, mediaProvas[i]);
    }
    printf("   Média geral dos aluos: %.1f\n", mediaGeral);
    return 0;
}