#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "aluno.h"

#define MAX_NOME 100
#define MAX_ALUNO 100

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
    int index;
    size_t escolha;
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
        scanf("%li", &escolha);
        getchar();
        printf("\n");
        if((escolha == 1) || (escolha == 2)){
            printf("Informe o documento do %iº aluno:\t", index+1);
            scanf("%d", &vetor_aluno[index]->documento.CPF);
            getchar();
        } else{
            printf("Opção inválida");
        }
        printf("\n");
    }
    printf("\n");
}

void gnomeSort(Alunos **vetor_aluno, int quantidade_alunos){
    clock_t inicio, fim;
    double tempoExecucao;
    inicio = clock();

    int posicao = 1; //1 vez: C1
    Alunos *temporaria = (Alunos*) malloc (MAX_NOME*sizeof(Alunos)); //1 vez: C2
    if (temporaria == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    while(posicao < quantidade_alunos){ //n vezes: C3*n
        if(strcmp(vetor_aluno[posicao - 1]->nome, vetor_aluno[posicao]->nome) <= 0){
            posicao++; //n² vezes: C4*n²
        } else{
            temporaria = vetor_aluno[posicao - 1];
            vetor_aluno[posicao - 1] = vetor_aluno[posicao];
            vetor_aluno[posicao] = temporaria;
            posicao--;
            posicao = (posicao==0) ? 1 : posicao; //n² vezes: C5*n²
            }
        }

        fim = clock();
        tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo de execução em segundos %f\n", tempoExecucao);
}

/*
C1+C2+C3*n+C4*n²+C5*n²
C4*n²+C5*n²+C3*n+C1+C2
T(n) an²+bn+c = Tempo de execução quadrática
Notação big-O
T(n) = O(n²)
*/

void limpar_arquivo() {
    FILE *arquivo;
    arquivo = fopen("arquivo_lista_ordenada.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    fclose(arquivo);
}

void arquivo(Alunos **vetor_aluno, int quantidade_alunos){
    FILE *arquivo;
    int index, total_alunos;
    Alunos **alunos_arquivo;
    arquivo = fopen("arquivo_lista_ordenada.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    total_alunos = 0;
    alunos_arquivo = (Alunos**) malloc (MAX_ALUNO*sizeof(Alunos*));
    for(index = 0; index < MAX_ALUNO; index++){
        alunos_arquivo[index] = (Alunos*) malloc (MAX_ALUNO*sizeof(Alunos));
        if(alunos_arquivo[index] == NULL){
            printf("Erro ao alocar memória!");
            exit(1);
        }
    }
    while(fscanf(arquivo, "Nome: %[^\n]\nMatricula:\t%d\nDocumento:\t%i\n", alunos_arquivo[total_alunos]->nome, &alunos_arquivo[total_alunos]->matricula, &alunos_arquivo[total_alunos]->documento.CPF) == 3){
        total_alunos++;
    }
    fclose(arquivo);

    alunos_arquivo = (Alunos**) realloc (alunos_arquivo, (total_alunos + quantidade_alunos)*sizeof(Alunos*));

    for(index = 0; index < quantidade_alunos; index++){
        strcpy(alunos_arquivo[total_alunos + index]->nome, vetor_aluno[index]->nome);
        alunos_arquivo[total_alunos + index]->matricula = vetor_aluno[index]->matricula;
        alunos_arquivo[total_alunos + index]->documento = vetor_aluno[index]->documento;
    }
    gnomeSort(alunos_arquivo, total_alunos + quantidade_alunos);

    arquivo = fopen("arquivo_lista_ordenada.txt", "w");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo.");
        exit(1);
    }
    for(index = 0; index < total_alunos + quantidade_alunos; index++){
        int documento = (alunos_arquivo[index]->documento.CPF == 0) ? alunos_arquivo[index]->documento.RG : alunos_arquivo[index]->documento.CPF;
        fprintf(arquivo, "Nome: %s\nMatricula:\t%d\nDocumento:\t%d\n\n", alunos_arquivo[index]->nome, alunos_arquivo[index]->matricula, documento);
    }
    fclose(arquivo);

    for(index = 0; index < total_alunos + quantidade_alunos; index++){
        free(alunos_arquivo[index]);
    }
    free(alunos_arquivo);
}
