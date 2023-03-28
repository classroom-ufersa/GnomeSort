#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

#define MAX_NOME 100

union docs{
    int CPF;
    int RG;
};

struct aluno{
    char nome[MAX_NOME];
    int matricula;
    Documentos documento;
};

void ler_dados(Alunos **vetor_aluno, int quantidade_alunos){
    int index, escolha;
    if(vetor_aluno == NULL){
        printf("ERRO!");
        exit(1);
    }
    for(index = 0; index < quantidade_alunos ; index++){
        printf("Informe o nome do %iº aluno:\t", index+1);
        fgets(vetor_aluno[index]->nome,MAX_NOME,stdin);
        printf("\n");
        printf("Informe o número da matricula do %iº aluno:\t", index+1);
        scanf("%d", &vetor_aluno[index]->matricula);
        getchar();
        printf("\n");
        printf("Escolha uma das opções de documento:\t");
        printf("1-RG\t\t\t\t2-CPF\n");
        printf("\t\t\t\t\t");
        scanf("%d", &escolha);
        if(escolha>2){
            printf("Opção inválida.");
            exit (1);
        }
        getchar();
        printf("\n");
        printf("Informe documento do %i aluno:\t", index+1);
        scanf("%d", &vetor_aluno[index]->documento.CPF);
        getchar();
        printf("\n");
    }
    printf("\n");
}

void gnomeSort(Alunos **vetor_aluno, int quantidade_alunos){
    int posicao = 1;
    char *temporaria = (char*) malloc (MAX_NOME*sizeof(char));
    while(posicao < quantidade_alunos){
        if(strcmp(vetor_aluno[posicao - 1]->nome, vetor_aluno[posicao]->nome) <= 0){
            posicao++;
        } else{
            strcpy(temporaria, vetor_aluno[posicao-1]->nome);
            strcpy(vetor_aluno[posicao - 1]->nome, vetor_aluno[posicao]->nome);
            strcpy(vetor_aluno[posicao]->nome, temporaria);
            posicao--;
            posicao = (posicao==0) ? 1 : posicao;
            }
        }
        free(temporaria);
    }

void arquivo(Alunos **vetor_aluno, int quantidade_alunos){
    FILE *arquivo;
    int index;
    arquivo = fopen("arquivo_lista_ordenada.txt", "w");
    if(arquivo==NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    fprintf(arquivo, "\t\t\t\t\tLista de alunos ordenada\n");
    for(index = 0; index < quantidade_alunos; index++){
        fprintf(arquivo, "%s", vetor_aluno[index]->nome);
    }
    fclose(arquivo);
}
