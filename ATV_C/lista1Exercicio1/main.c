#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define N 5

struct endereco{
    char  rua[30], bairro[30], complemento[30], cidade[30], uf[3];
    int cep, num;

}endereco_pessoa;

struct cadastro{
    struct endereco endereco_pessoa;
    char nome[30];
    int telefone1, telefone2, telefone3;

}cadastro [6];

int main(){
    setlocale(LC_ALL, "Portuguese");

    int i, j;
    char maior[30];

    for(i=0; i<N; i++){
        printf("Insira o seu nome: \n");
        fgets(cadastro[N].nome, 29, stdin);
        fflush(stdin);
        printf("Insira o sua rua: \n");
        fgets(cadastro[N].endereco_pessoa.rua, 29, stdin);
        fflush(stdin);
        printf("Insira o numero da sua casa: \n");
        scanf("%d", &cadastro[N].endereco_pessoa.num);
        fflush(stdin);
        printf("Insira o seu cep: \n");
        scanf("%d", &cadastro[N].endereco_pessoa.cep);
        fflush(stdin);
        printf("Insira o seu bairro: \n");
        fgets(cadastro[N].endereco_pessoa.bairro, 29, stdin);
        fflush(stdin);
        printf("Insira o complemento: \n");
        fgets(cadastro[N].endereco_pessoa.complemento, 29, stdin);
        fflush(stdin);
        printf_s("Insira a sua cidade: \n");
        fgets(cadastro[N].endereco_pessoa.cidade, 29, stdin);
        fflush(stdin);
        printf("Insira a sua UF: \n");
        fgets(cadastro[N].endereco_pessoa.rua, 2, stdin);
        fflush(stdin);
        printf("Insira o seu telefone(3 telefones possiveis): \n");
        scanf("%d %d %d", &cadastro[N].telefone1, &cadastro[N].telefone2, &cadastro[N].telefone3);

    }
    system("cls");

    for(i=0; i<N; i++){
        for(j=0; j<N; j++);
        if(strcmp(cadastro[N].nome, cadastro[j].nome) < 0){
            maior -> cadastro[N].nome;
            printf("%s", cadastro[N.nome]);
        }
    }
    return 0;
}
