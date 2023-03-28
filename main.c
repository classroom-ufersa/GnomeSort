#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.c"



int main (void){
    int qnt, i;
    printf("Informe a quantidade: ");
    scanf("%d", &qnt);
    getchar();
    Alunos **vetor = (Alunos **) malloc (qnt*sizeof(Alunos*));
    for(i=0;i<qnt;i++){
        vetor[i]=(Alunos*)malloc(MAX_ALUNO*sizeof(Alunos));
    }
    ler_dados(vetor, qnt);
    gnomeSort(vetor, qnt);
    arquivo(vetor, qnt);
    for(i = 0; i < qnt; i++){
        free(vetor[i]);
    }
    free(vetor);
    return 0;
}