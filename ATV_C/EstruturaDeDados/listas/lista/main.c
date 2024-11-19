// main.c
#include <stdio.h>
#include "lista.h"

// Fun��o de compara��o para buscar um inteiro na lista
bool compararInt(void *a, void *b) {
    int *valA = (int *)a;
    int *valB = (int *)b;
    return *valA == *valB;
}

// Fun��o de impress�o de um inteiro
void imprimirInt(void *dado) {
    int *valor = (int *)dado;
    printf("%d -> ", *valor);
}

// Fun��o para liberar a mem�ria de um inteiro (se necess�rio)
void liberarInt(void *dado) {
    free(dado); // Somente necess�rio se os dados forem alocados dinamicamente
}

int main() {
    LISTA *lista = criarLista();

    // Inserindo alguns inteiros na lista
    int a = 10, b = 20, c = 30;
    inserirNoInicio(lista, &a, sizeof(int));
    inserirNoFim(lista, &b, sizeof(int));
    inserirNoFim(lista, &c, sizeof(int));

    printf("Elementos na lista: ");
    listarElementos(lista, imprimirInt);
    printf("NULL\n");

    // Buscando um elemento
    int chave = 20;
    int *encontrado = (int *)buscarElemento(lista, compararInt, &chave);
    if (encontrado != NULL) {
        printf("Elemento %d encontrado!\n", *encontrado);
    } else {
        printf("Elemento %d n�o encontrado.\n", chave);
    }

    // Removendo o primeiro elemento
    int *removido = (int *)removerNoInicio(lista);
    if (removido != NULL) {
        printf("Elemento %d removido.\n", *removido);
    }

    printf("Elementos na lista ap�s remo��o: ");
    listarElementos(lista, imprimirInt);
    printf("NULL\n");

    // Liberando a lista
    destruirLista(lista, liberarInt);

    return 0;
}
