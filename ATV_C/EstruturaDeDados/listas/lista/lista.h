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
