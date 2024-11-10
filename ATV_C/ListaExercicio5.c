#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Aluno{
    char nome[30], curso[30];
    int matricula;

};
int main(){

    struct Aluno aluno[3];
    int i;

    for(i=0; i<3; i++){
        printf("Insira o nome:\n");
        fgets(aluno[i].nome, 30, stdin);
        fflush(stdin);
        printf("Insira o curso:\n");
        fgets(aluno[i].curso, 30, stdin);
        fflush(stdin);
        printf("Insira a matricula:\n");
        scanf("%d", &aluno[i].matricula);
        fflush(stdin);
    }

    for(i=0; i<3; i++){
        printf("==========\n");
        printf("Nome: %s\n", aluno[i].nome);
        printf("Curso: %s\n", aluno[i].curso);
        printf("Matricula: %d\n", aluno[i].matricula);

    }
}
