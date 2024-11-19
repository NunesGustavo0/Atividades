// paciente.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"

// Inicializa a lista
void inicializarLista(PACIENTEPTR *inicio) {
    *inicio = NULL;
}

// Cadastra um novo paciente
void cadastrarPaciente(PACIENTEPTR *inicio, int id, const char nome[], const char dataNascimento[]) {
    PACIENTEPTR novoPaciente = malloc(sizeof(PACIENTE));
    if (novoPaciente != NULL) {
        novoPaciente->id = id;
        strcpy(novoPaciente->nome, nome);
        strcpy(novoPaciente->dataNascimento, dataNascimento);
        novoPaciente->proximo = NULL;

        if (*inicio == NULL) {
            *inicio = novoPaciente;
        } else {
            PACIENTEPTR atual = *inicio;
            while (atual->proximo != NULL) {
                atual = atual->proximo;
            }
            atual->proximo = novoPaciente;
        }
        printf("Paciente cadastrado com sucesso.\n");
    } else {
        printf("Erro ao alocar memória para novo paciente.\n");
    }
}

// Busca um paciente pelo ID
PACIENTEPTR buscarPaciente(PACIENTEPTR inicio, int id) {
    PACIENTEPTR atual = inicio;
    while (atual != NULL && atual->id != id) {
        atual = atual->proximo;
    }
    return atual;
}

// Remove um paciente pelo ID
void removerPaciente(PACIENTEPTR *inicio, int id) {
    if (*inicio == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    PACIENTEPTR atual = *inicio;
    PACIENTEPTR anterior = NULL;

    if (atual->id == id) {
        *inicio = atual->proximo;
        free(atual);
        printf("Paciente removido com sucesso.\n");
    } else {
        while (atual != NULL && atual->id != id) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual == NULL) {
            printf("Paciente não encontrado.\n");
        } else {
            anterior->proximo = atual->proximo;
            free(atual);
            printf("Paciente removido com sucesso.\n");
        }
    }
}

// Lista todos os pacientes
void listarPacientes(PACIENTEPTR inicio) {
    if (inicio == NULL) {
        printf("Nenhum paciente cadastrado.\n");
    } else {
        printf("\nLista de Pacientes:\n");
        PACIENTEPTR atual = inicio;
        while (atual != NULL) {
            printf("ID: %d | Nome: %s | Data de Nascimento: %s\n", atual->id, atual->nome, atual->dataNascimento);
            atual = atual->proximo;
        }
    }
}

// Exibe o primeiro paciente
void exibirPrimeiro(PACIENTEPTR inicio) {
    if (inicio != NULL) {
        printf("Primeiro Paciente - ID: %d, Nome: %s, Data de Nascimento: %s\n", inicio->id, inicio->nome, inicio->dataNascimento);
    } else {
        printf("A lista está vazia.\n");
    }
}

// Exibe o último paciente
void exibirUltimo(PACIENTEPTR inicio) {
    if (inicio != NULL) {
        PACIENTEPTR atual = inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        printf("Último Paciente - ID: %d, Nome: %s, Data de Nascimento: %s\n", atual->id, atual->nome, atual->dataNascimento);
    } else {
        printf("A lista está vazia.\n");
    }
}

// Retorna o tamanho da lista
int tamanhoLista(PACIENTEPTR inicio) {
    int tamanho = 0;
    while (inicio != NULL) {
        tamanho++;
        inicio = inicio->proximo;
    }
    return tamanho;
}
