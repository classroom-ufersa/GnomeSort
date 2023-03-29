#include <stdio.h>
#include <stdlib.h>
#include "aluno.c"
 
int main (void){
    int quantidade_alunos, index;
    size_t limpar;
    printf("Informe a quantidade de alunos que serão inscritos: \t");
    scanf("%d", &quantidade_alunos);
    printf("\n");
    getchar();
    Alunos **vetor_aluno = (Alunos **) malloc (quantidade_alunos*sizeof(Alunos*));
    if (vetor_aluno == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    for(index = 0; index < quantidade_alunos; index++){
        vetor_aluno[index]=(Alunos*)malloc(MAX_ALUNO*sizeof(Alunos));
        if (vetor_aluno[index] == NULL) {
            printf("Erro ao alocar memoria.\n");
            exit(1);
        }
    }
    printf("Deseja criar um arquivo para inserir os dados dos alunos?\n");
    printf("1-SIM\t\t\t\t2-NÃO\n\t\t");
    scanf("%lu", &limpar);
    getchar();
    printf("\n\n");
    if(limpar == 1){
        limpar_arquivo();
        printf("\t\t\t\tInsira os dados dos alunos\n");
    } else if(limpar == 2){
        printf("\t\t\t\tInsira os dados dos alunos\n");
    } else{
        printf("Opção inválida!");
        exit(1);
    }
    printf("\n\n\n");
    ler_dados(vetor_aluno, quantidade_alunos);
    gnomeSort(vetor_aluno, quantidade_alunos);
    arquivo(vetor_aluno, quantidade_alunos);
    for(index = 0; index < quantidade_alunos; index++){
        free(vetor_aluno[index]);
    }
    free(vetor_aluno);
    return(0);
}
