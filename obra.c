// obra.c
#include <stdio.h>
#include <string.h>
#include "obra.h"
#include "tema.h"

void incluirObra(Obra obras[], int* totalObras, const char* nome, const char* autor, const char* tema, Tema temas[], int totalTemas) {
    int capacidadeMaxima = MAX_OBRAS;
    int temaExistente = 0;
    int i;

    // Verifica se o tema já foi declarado
    for (i = 0; i < totalTemas; i++) {
        if (strcmp(temas[i].nome, tema) == 0) {
            temaExistente = 1;
            break;
        }
    }

    if (*totalObras < capacidadeMaxima && temaExistente) {
        // Adiciona a obra
        strcpy(obras[*totalObras].nome, nome);
        strcpy(obras[*totalObras].autor, autor);
        strcpy(obras[*totalObras].tema, tema);
        (*totalObras)++;
        printf("Obra '%s' incluída com sucesso.\n", nome);
    } else if (!temaExistente) {
        // Exibe erro se o tema não existir
        printf("Erro: O tema '%s' ainda não foi declarado.\n", tema);
    } else {
        // Exibe erro se a capacidade máxima de obras foi atingida
        printf("A capacidade máxima de obras foi atingida. Não é possível adicionar mais obras.\n");
    }
}

void consultarObra(const Obra obras[], int totalObras) {
    int i;

    if (totalObras == 0) {
        printf("Nenhuma obra cadastrada.\n");
        return;
    }

    printf("Obras cadastradas:\n");
    for (i = 0; i < totalObras; i++) {
        printf("%d - %s (Autor: %s, Tema: %s)\n", i + 1, obras[i].nome, obras[i].autor, obras[i].tema);
    }
}

void alterarObra(Obra obras[], int totalObras, const char* nome, const char* novoNome, const char* novoAutor, const char* novoTema) {
    int encontrado = 0;
    int i;

    for (i = 0; i < totalObras; i++) {
        if (strcmp(obras[i].nome, nome) == 0) {
            // Altera a obra
            strcpy(obras[i].nome, novoNome);
            strcpy(obras[i].autor, novoAutor);
            strcpy(obras[i].tema, novoTema);
            encontrado = 1;
            printf("Obra alterada com sucesso.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Obra não encontrada.\n");
    }
}

void excluirObra(Obra obras[], int* totalObras, const char* nome) {
    int encontrado = 0;
    int i;

    for (i = 0; i < *totalObras; i++) {
        if (strcmp(obras[i].nome, nome) == 0) {
            // Exclui a obra movendo a última obra para a posição a ser excluída
            strcpy(obras[i].nome, obras[(*totalObras) - 1].nome);
            strcpy(obras[i].autor, obras[(*totalObras) - 1].autor);
            strcpy(obras[i].tema, obras[(*totalObras) - 1].tema);
            (*totalObras)--;
            encontrado = 1;
            printf("Obra excluída com sucesso.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Obra não encontrada.\n");
    }
}
