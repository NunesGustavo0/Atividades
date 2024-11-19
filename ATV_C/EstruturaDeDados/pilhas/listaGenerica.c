// lista.h
#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h> // Para tipo bool

// Estrutura de n� gen�rico da lista
typedef struct No {
    void *dado;               // Ponteiro gen�rico para armazenar dados
    struct No *proximo;
} NO;

// Estrutura de lista gen�rica
typedef struct {
    NO *inicio;
    int tamanho;
} LISTA;

// Fun��es para manipula��o da lista
LISTA *criarLista();
bool inserirNoInicio(LISTA *lista, void *dado, size_t tamanhoDado);
bool inserirNoFim(LISTA *lista, void *dado, size_t tamanhoDado);
void *removerNoInicio(LISTA *lista);
void *removerNoFim(LISTA *lista);
void *buscarElemento(LISTA *lista, bool (*comparator)(void *, void *), void *chave);
void listarElementos(LISTA *lista, void (*imprimir)(void *));
int tamanhoLista(LISTA *lista);
void destruirLista(LISTA *lista, void (*liberarDado)(void *));

#endif // LISTA_H

// lista.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

// Cria uma nova lista
LISTA *criarLista() {
    LISTA *lista = malloc(sizeof(LISTA));
    if (lista != NULL) {
        lista->inicio = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

// Fun��o auxiliar para criar um n�
static NO *criarNo(void *dado, size_t tamanhoDado) {
    NO *novoNo = malloc(sizeof(NO));
    if (novoNo != NULL) {
        novoNo->dado = malloc(tamanhoDado);
        if (novoNo->dado != NULL) {
            memcpy(novoNo->dado, dado, tamanhoDado);
            novoNo->proximo = NULL;
        } else {
            free(novoNo);
            return NULL;
        }
    }
    return novoNo;
}

// Insere um elemento no in�cio da lista
bool inserirNoInicio(LISTA *lista, void *dado, size_t tamanhoDado) {
    NO *novoNo = criarNo(dado, tamanhoDado);
    if (novoNo == NULL) return false;

    novoNo->proximo = lista->inicio;
    lista->inicio = novoNo;
    lista->tamanho++;
    return true;
}

// Insere um elemento no fim da lista
bool inserirNoFim(LISTA *lista, void *dado, size_t tamanhoDado) {
    NO *novoNo = criarNo(dado, tamanhoDado);
    if (novoNo == NULL) return false;

    if (lista->inicio == NULL) {
        lista->inicio = novoNo;
    } else {
        NO *atual = lista->inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
    lista->tamanho++;
    return true;
}

// Remove o primeiro elemento da lista e retorna um ponteiro para o dado
void *removerNoInicio(LISTA *lista) {
    if (lista->inicio == NULL) return NULL;

    NO *temp = lista->inicio;
    void *dado = temp->dado;
    lista->inicio = temp->proximo;
    free(temp);
    lista->tamanho--;
    return dado;
}

// Remove o �ltimo elemento da lista e retorna um ponteiro para o dado
void *removerNoFim(LISTA *lista) {
    if (lista->inicio == NULL) return NULL;

    NO *atual = lista->inicio;
    NO *anterior = NULL;

    while (atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }

    void *dado = atual->dado;
    if (anterior == NULL) {
        lista->inicio = NULL;
    } else {
        anterior->proximo = NULL;
    }
    free(atual);
    lista->tamanho--;
    return dado;
}

// Busca um elemento na lista com base em uma fun��o de compara��o
void *buscarElemento(LISTA *lista, bool (*comparator)(void *, void *), void *chave) {
    NO *atual = lista->inicio;
    while (atual != NULL) {
        if (comparator(atual->dado, chave)) {
            return atual->dado;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Lista todos os elementos chamando a fun��o de impress�o
void listarElementos(LISTA *lista, void (*imprimir)(void *)) {
    NO *atual = lista->inicio;
    while (atual != NULL) {
        imprimir(atual->dado);
        atual = atual->proximo;
    }
}

// Retorna o tamanho da lista
int tamanhoLista(LISTA *lista) {
    return lista->tamanho;
}

// Destr�i a lista e libera a mem�ria de cada elemento
void destruirLista(LISTA *lista, void (*liberarDado)(void *)) {
    NO *atual = lista->inicio;
    while (atual != NULL) {
        NO *temp = atual;
        atual = atual->proximo;
        liberarDado(temp->dado);
        free(temp);
    }
    free(lista);
}


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
