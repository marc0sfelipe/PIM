// tema.h
#ifndef TEMA_H
#define TEMA_H

#define MAX_TEMAS 4 // Defina o número máximo de temas permitidos

typedef struct {
    char nome[50];
} Tema;

void incluirTema(Tema temas[], int* totalTemas, const char* nome);
void consultarTema(const Tema temas[], int totalTemas);
void alterarTema(Tema temas[], int totalTemas, const char* nome, const char* novoNome);
void excluirTema(Tema temas[], int* totalTemas, const char* nome);

#endif