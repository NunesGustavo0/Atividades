// estoque.h
#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <stdbool.h>

typedef struct Produto {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
    struct Produto *proximo;
} PRODUTO;

typedef PRODUTO *PRODUTOPTR;

// Funções para manipulação do estoque
PRODUTOPTR criarEstoque();
void adicionarProduto(PRODUTOPTR *estoque, int codigo, const char *nome, int quantidade, float preco);
bool removerProduto(PRODUTOPTR *estoque, int codigo);
PRODUTOPTR buscarProduto(PRODUTOPTR estoque, int codigo);
void listarProdutos(PRODUTOPTR estoque);
void salvarEstoqueEmArquivo(PRODUTOPTR estoque, const char *nomeArquivo);
PRODUTOPTR carregarEstoqueDeArquivo(const char *nomeArquivo);
void liberarEstoque(PRODUTOPTR *estoque);

#endif // ESTOQUE_H

