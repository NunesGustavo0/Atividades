// estoque.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

// Cria um estoque vazio
PRODUTOPTR criarEstoque() {
    return NULL;
}

// Adiciona um novo produto ao estoque
void adicionarProduto(PRODUTOPTR *estoque, int codigo, const char *nome, int quantidade, float preco) {
    PRODUTOPTR novoProduto = malloc(sizeof(PRODUTO));
    if (novoProduto == NULL) {
        printf("Erro ao alocar memória para o produto.\n");
        return;
    }
    novoProduto->codigo = codigo;
    strcpy(novoProduto->nome, nome);
    novoProduto->quantidade = quantidade;
    novoProduto->preco = preco;
    novoProduto->proximo = *estoque;
    *estoque = novoProduto;
    printf("Produto adicionado com sucesso!\n");
}

// Remove um produto do estoque pelo código
bool removerProduto(PRODUTOPTR *estoque, int codigo) {
    PRODUTOPTR atual = *estoque, anterior = NULL;
    while (atual != NULL && atual->codigo != codigo) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Produto não encontrado.\n");
        return false;
    }

    if (anterior == NULL) {
        *estoque = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Produto removido com sucesso!\n");
    return true;
}

// Busca um produto pelo código
PRODUTOPTR buscarProduto(PRODUTOPTR estoque, int codigo) {
    while (estoque != NULL && estoque->codigo != codigo) {
        estoque = estoque->proximo;
    }
    return estoque;
}

// Lista todos os produtos no estoque
void listarProdutos(PRODUTOPTR estoque) {
    if (estoque == NULL) {
        printf("O estoque está vazio.\n");
        return;
    }

    printf("Produtos no estoque:\n");
    while (estoque != NULL) {
        printf("Código: %d | Nome: %s | Quantidade: %d | Preço: R$%.2f\n",
               estoque->codigo, estoque->nome, estoque->quantidade, estoque->preco);
        estoque = estoque->proximo;
    }
}

// Salva o estoque em um arquivo binário
void salvarEstoqueEmArquivo(PRODUTOPTR estoque, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    while (estoque != NULL) {
        fwrite(estoque, sizeof(PRODUTO) - sizeof(PRODUTOPTR), 1, arquivo);
        estoque = estoque->proximo;
    }

    fclose(arquivo);
    printf("Estoque salvo com sucesso em '%s'.\n", nomeArquivo);
}

// Carrega o estoque de um arquivo binário
PRODUTOPTR carregarEstoqueDeArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }

    PRODUTOPTR estoque = NULL, ultimo = NULL;
    PRODUTO temp;

    while (fread(&temp, sizeof(PRODUTO) - sizeof(PRODUTOPTR), 1, arquivo)) {
        PRODUTOPTR novoProduto = malloc(sizeof(PRODUTO));
        if (novoProduto == NULL) {
            printf("Erro ao alocar memória para o produto.\n");
            fclose(arquivo);
            liberarEstoque(&estoque);
            return NULL;
        }

        *novoProduto = temp;
        novoProduto->proximo = NULL;

        if (ultimo == NULL) {
            estoque = novoProduto;
        } else {
            ultimo->proximo = novoProduto;
        }
        ultimo = novoProduto;
    }

    fclose(arquivo);
    printf("Estoque carregado com sucesso de '%s'.\n", nomeArquivo);
    return estoque;
}

// Libera a memória do estoque
void liberarEstoque(PRODUTOPTR *estoque) {
    while (*estoque != NULL) {
        PRODUTOPTR temp = *estoque;
        *estoque = (*estoque)->proximo;
        free(temp);
    }
}
