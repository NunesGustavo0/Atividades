#include <stdio.h>
#include <stdlib.h>

struct lista{
    char data;
    struct lista *nextPtr;
};

typedef struct lista LISTA;
typedef LISTA *LISTAPTR;

int main(){
    LISTAPTR startPtr = NULL;
    int escolha=1;

    while(escolha != 0){
        printf("Escolha uma opção:\n"
               "1 - Criar lista vazia\n"
               "2 - Inserir no início\n"
               "3 - Inserir no fim\n"
               "4 - Inserir no meio (posição)\n"
               "5 - Exibir primeiro elemento\n"
               "6 - Exibir último elemento\n"
               "7 - Exibir todos os elementos\n"
               "8 - Exibir tamanho da lista\n"
               "9 - Excluir primeiro elemento\n"
               "10 - Excluir último elemento\n"
               "11 - Excluir elemento específico\n"
               "12 - Buscar elemento\n"
               "0 - Sair\n");
        scanf("%d", &escolha);

        switch(escolha){
            case 0:
                printf("Programa encerrado!\n");
                break;
            case 1:
                criarLista(&startPtr);
                break;
            case 2:
                printf("Qual caracter deseja inserir?\n")
                scanf("%c", &caracter);

                inserirInicio(&startPtr, caracter);
                break;
            case 3:
                printf("Qual caracter deseja inserir?\n");
                scanf("%c", &caracter);

                inserirFinal(&startPtr, carcater);
            default:
                printf("Opção incorreta!\n");
                break;
        }
    }
}

void criarLista(LISTAPTR *start){
    *start = NULL;
    printf("Lista criada!\n");
}

void inserirInicio(LISTAPTR *start, char caracter){
    LISTAPTR newPtr = malloc(sizeof(LISTA));

    if(newPtr != NULL){
        newPtr->data = caracter;
        newPtr->nextPtr = *start;
        *start = newPtr;
    }else{
        printf("Erro ao inserir no começo\n");
    }
}

void inserirFinal(LISTAPTR ){
    LISTAPTR newPtr = malloc(sizeof(LISTA))

    while()
}
