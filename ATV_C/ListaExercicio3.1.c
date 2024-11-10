#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Endereco{
    char rua[30], complemento[30], bairro[30], cidade[30], estado[30], pais[30];
    int cep, numero;

};
typedef struct Data{
    int dia, mes, ano;

};
typedef struct Telefone{
    int ddd, numero;

};
typedef struct Agenda{
    char nome[30], email[30];
    struct Endereco endereco;
    struct Data data_aniversario;
    struct Telefone telefone;

} agenda;

void imprimir(){
    printf("Primeiro nome: %s", agenda.nome);
    printf("Telefone: (%d) %d", agenda.telefone.ddd, agenda.telefone.numero);
    printf("E-mail: %s", agenda.email);
    printf("Data de aniversário: %d/%d/%d", agenda.data.dia, agenda.data.mes, agenda.data.ano);
    printf("")

}
int main(){
    int escolha;

    printf("digite a opção que escolher\n");
    printf("1 Busca por nome\n");
    printf("2 Busca por mês de aniversário\n");
    printf("3 Busca por dia e mês de aniversário\n");
    printf("4 Inserir pessoa\n");
    printf("5 Retirar pessoa\n");
    printf("6 Imprimir agenda\n");
    scanf("%d", &escolha);

    switch(escolha){
        case 1:
            busca_nome();
            break;
        case 2:
            busca_mes();
            break;
        case 3:
            busca_dia();
            break;
        case 4:
            inserir();
            break;
        case 5:
            retire();
            break;
        case 6:
            imprimir();
            break;
        default:
            printf("Opção inválida");
            break;
    }


}
