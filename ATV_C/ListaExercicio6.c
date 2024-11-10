#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Aluno{
    char nome[30];
    int matricula, n1, n2, n3;

};
void insira(int i){
    printf("Insira o nome do aluno:\n");
    fgets(aluno[i].nome, 30, stdin);
    printf("Insira a matricula do aluno:\n")
    scanf("%d", &aluno[i].matricula);
    printf("Inssira a primeira nota do aluno:\n");
    scanf("%d", &aluno[i].n1);
    printf("Insira a segunda nota do aluno:\n");
    scanf("%d", &aluno[i].n2);
    printf("Insira a terceira nota do aluno:\n");
    scanf("%d", &aluno[i].n3);

}
int main(){
    struct Aluno aluno[5];
    int i, maior;

    for(i=1; i<6; i++){
        insira(i);
        if(aluno[i].n1 > maior)
            maior = aluno[i].n1;
        media = ((aluno[i].n1) + (aluno[i].n2) + (aluno[i].n3)) / 3;
    }



}
