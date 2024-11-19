// main.c
#include <stdio.h>
#include "lista.h"

// Função de comparação para buscar um inteiro na lista
bool compararInt(void *a, void *b) {
    int *valA = (int *)a;
    int *valB = (int *)b;
    return *valA == *valB;
}

// Função de impressão de um inteiro
void imprimirInt(void *dado) {
    int *valor = (int *)dado;
    printf("%d -> ", *valor);
}

// Função para liberar a memória de um inteiro (se necessário)
void liberarInt(void *dado) {
    free(dado); // Somente necessário se os dados forem alocados dinamicamente
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
        printf("Elemento %d não encontrado.\n", chave);
    }

    // Removendo o primeiro elemento
    int *removido = (int *)removerNoInicio(lista);
    if (removido != NULL) {
        printf("Elemento %d removido.\n", *removido);
    }

    printf("Elementos na lista após remoção: ");
    listarElementos(lista, imprimirInt);
    printf("NULL\n");

    // Liberando a lista
    destruirLista(lista, liberarInt);

    return 0;
}
