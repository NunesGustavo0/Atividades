// paciente.h
#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct Paciente {
    int id;
    char nome[50];
    char dataNascimento[11];
    struct Paciente *proximo;
} PACIENTE;

typedef PACIENTE *PACIENTEPTR;

// Funções para gerenciamento da lista de pacientes
void inicializarLista(PACIENTEPTR *inicio);
void cadastrarPaciente(PACIENTEPTR *inicio, int id, const char nome[], const char dataNascimento[]);
PACIENTEPTR buscarPaciente(PACIENTEPTR inicio, int id);
void removerPaciente(PACIENTEPTR *inicio, int id);
void listarPacientes(PACIENTEPTR inicio);
void exibirPrimeiro(PACIENTEPTR inicio);
void exibirUltimo(PACIENTEPTR inicio);
int tamanhoLista(PACIENTEPTR inicio);

#endif // PACIENTE_H
