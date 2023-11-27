// tema.c
#include <stdio.h>
#include <string.h>
#include "tema.h"

void incluirTema(Tema temas[], int* totalTemas, const char* nome) {
    int capacidadeMaxima = MAX_TEMAS;
    if (*totalTemas < capacidadeMaxima) {
        strcpy(temas[*totalTemas].nome, nome);
        (*totalTemas)++;
        printf("Tema '%s' incluido com sucesso.\n", nome);
    } else {
        printf("A capacidade máxima de temas foi atingida. Nao e possivel adicionar mais temas.\n");
    }
}

void consultarTema(const Tema temas[], int totalTemas) {
    int i;
    
    if (totalTemas == 0) {
        printf("Nenhum tema cadastrado.\n");
        return;
    }

    printf("Temas cadastrados:\n");
    for (i = 0; i < totalTemas; i++) {
        printf("%d - %s\n", i + 1, temas[i].nome);
    }
}

void alterarTema(Tema temas[], int totalTemas, const char* nome, const char* novoNome) {
    int encontrado = 0;
    int i;

    for (i = 0; i < totalTemas; i++) {
        if (strcmp(temas[i].nome, nome) == 0) {
            strcpy(temas[i].nome, novoNome);
            encontrado = 1;
            printf("Tema alterado com sucesso.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Tema nao encontrado.\n");
    }
}

void excluirTema(Tema temas[], int* totalTemas, const char* nome) {
    int encontrado = 0;
    int i;

    for (i = 0; i < *totalTemas; i++) {
        if (strcmp(temas[i].nome, nome) == 0) {
            // Para excluir um tema, podemos simplesmente mover o último tema para a posição a ser excluída.
            strcpy(temas[i].nome, temas[(*totalTemas) - 1].nome);
            (*totalTemas)--;
            encontrado = 1;
            printf("Tema excluido com sucesso.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Tema nao encontrado.\n");
    }
}