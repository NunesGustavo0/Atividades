// main.c
#include <stdio.h>
#include "estoque.h"

#define ARQUIVO_ESTOQUE "estoque.bin"

void exibirMenu();

int main() {
    PRODUTOPTR estoque = carregarEstoqueDeArquivo(ARQUIVO_ESTOQUE);

    int opcao, codigo, quantidade;
    float preco;
    char nome[50];

    do {
        exibirMenu();
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o c�digo do produto: ");
                scanf("%d", &codigo);
                printf("Digite o nome do produto: ");
                scanf(" %[^\n]%*c", nome);
                printf("Digite a quantidade: ");
                scanf("%d", &quantidade);
                printf("Digite o pre�o: ");
                scanf("%f", &preco);
                adicionarProduto(&estoque, codigo, nome, quantidade, preco);
                break;
            case 2:
                printf("Digite o c�digo do produto para remover: ");
                scanf("%d", &codigo);
                removerProduto(&estoque, codigo);
                break;
            case 3:
                listarProdutos(estoque);
                break;
            case 4:
                printf("Digite o c�digo do produto para buscar: ");
                scanf("%d", &codigo);
                PRODUTOPTR produto = buscarProduto(estoque, codigo);
                if (produto) {
                    printf("Produto encontrado - C�digo: %d | Nome: %s | Quantidade: %d | Pre�o: R$%.2f\n",
                           produto->codigo, produto->nome, produto->quantidade, produto->preco);
                } else {
                    printf("Produto com c�digo %d n�o encontrado.\n", codigo);
                }
                break;
            case 5:
                salvarEstoqueEmArquivo(estoque, ARQUIVO_ESTOQUE);
                break;
            case 6:
                printf("Saindo do programa...\n");
                salvarEstoqueEmArquivo(estoque, ARQUIVO_ESTOQUE);
                liberarEstoque(&estoque);
                break;
            default:
                printf("Op��o inv�lida! Tente novamente.\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}

void exibirMenu() {
    printf("\nControle de Estoque\n");
    printf("1. Adicionar produto\n");
    printf("2. Remover produto\n");
    printf("3. Listar produtos\n");
    printf("4. Buscar produto\n");
    printf("5. Salvar estoque\n");
    printf("6. Sair\n");
}
