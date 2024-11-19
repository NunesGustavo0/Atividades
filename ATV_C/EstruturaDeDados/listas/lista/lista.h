// lista.h
#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h> // Para tipo bool

// Estrutura de nó genérico da lista
typedef struct No {
    void *dado;               // Ponteiro genérico para armazenar dados
    struct No *proximo;
} NO;

// Estrutura de lista genérica
typedef struct {
    NO *inicio;
    int tamanho;
} LISTA;

// Funções para manipulação da lista
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
