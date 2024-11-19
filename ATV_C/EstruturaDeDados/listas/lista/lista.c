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

// Função auxiliar para criar um nó
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

// Insere um elemento no início da lista
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

// Remove o último elemento da lista e retorna um ponteiro para o dado
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

// Busca um elemento na lista com base em uma função de comparação
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

// Lista todos os elementos chamando a função de impressão
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

// Destrói a lista e libera a memória de cada elemento
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
