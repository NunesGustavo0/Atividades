// main.c
#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"

void exibirMenu();

int main() {
    PACIENTEPTR inicio = NULL;
    int escolha, id;
    char nome[50];
    char dataNascimento[11];

    inicializarLista(&inicio);

    do {
        exibirMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o ID do paciente: ");
                scanf("%d", &id);
                printf("Digite o nome do paciente: ");
                scanf(" %[^\n]%*c", nome);
                printf("Digite a data de nascimento (DD/MM/AAAA): ");
                scanf("%s", dataNascimento);
                cadastrarPaciente(&inicio, id, nome, dataNascimento);
                break;
            case 2:
                printf("Digite o ID do paciente para busca: ");
                scanf("%d", &id);
                PACIENTEPTR pacienteEncontrado = buscarPaciente(inicio, id);
                if (pacienteEncontrado) {
                    printf("Paciente encontrado - ID: %d, Nome: %s, Data de Nascimento: %s\n",
                           pacienteEncontrado->id, pacienteEncontrado->nome, pacienteEncontrado->dataNascimento);
                } else {
                    printf("Paciente com ID %d não encontrado.\n", id);
                }
                break;
            case 3:
                listarPacientes(inicio);
                break;
            case 4:
                printf("Digite o ID do paciente para remover: ");
                scanf("%d", &id);
                removerPaciente(&inicio, id);
                break;
            case 5:
                exibirPrimeiro(inicio);
                break;
            case 6:
                exibirUltimo(inicio);
                break;
            case 7:
                printf("Tamanho da lista: %d\n", tamanhoLista(inicio));
                break;
            case 8:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (escolha != 8);

    return 0;
}

void exibirMenu() {
    printf("\nSistema de Registro de Pacientes\n");
    printf("1. Cadastrar paciente\n");
    printf("2. Buscar paciente por ID\n");
    printf("3. Listar todos os pacientes\n");
    printf("4. Remover paciente\n");
    printf("5. Exibir primeiro paciente\n");
    printf("6. Exibir último paciente\n");
    printf("7. Exibir tamanho da lista\n");
    printf("8. Sair\n");
}
