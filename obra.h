// obra.h
#ifndef OBRA_H
#define OBRA_H

#include "tema.h" // Incluído aqui

#define MAX_OBRAS 100

typedef struct {
    char nome[50];
    char autor[50];
    char tema[50];
} Obra;

void incluirObra(Obra obras[], int* totalObras, const char* nome, const char* autor, const char* tema, Tema temas[], int totalTemas);
void consultarObra(const Obra obras[], int totalObras);
void alterarObra(Obra obras[], int totalObras, const char* nome, const char* novoNome, const char* novoAutor, const char* novoTema);
void excluirObra(Obra obras[], int* totalObras, const char* nome);

#endif // OBRA_H
