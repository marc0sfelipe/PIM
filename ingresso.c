// ingresso.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para a função rand()
#include "ingresso.h"

#define MAX_INGRESSOS_DIA_TEMA 200
#define MAX_PESSOAS_POR_DIA 200
#define MAX_PESSOAS_POR_SALA 50

void cadastrarCliente(Cliente clientes[], int* totalClientes, const char* nome, const char* dataNascimento, const char* documento, const char* endereco, const char* telefone, const char* email) {
    if (*totalClientes < MAX_CLIENTES) {
        strcpy(clientes[*totalClientes].nome, nome);
        strcpy(clientes[*totalClientes].dataNascimento, dataNascimento);
        strcpy(clientes[*totalClientes].documento, documento);
        strcpy(clientes[*totalClientes].endereco, endereco);
        strcpy(clientes[*totalClientes].telefone, telefone);
        strcpy(clientes[*totalClientes].email, email);
        (*totalClientes)++;
        printf("Cliente cadastrado com sucesso.\n");
    } else {
        printf("A capacidade máxima de clientes foi atingida. Não é possível cadastrar mais clientes.\n");
    }
}

void venderIngresso(Cliente clientes[], Ingresso ingressos[], int* totalClientes, int* totalIngressos, const char* cpf, const char* dataVisita, int temaEscolhido) {
    int tipoIngresso = 0;
    int valorIngresso = 0;

    if (*totalClientes >= MAX_PESSOAS_POR_DIA) {
        printf("Limite de pessoas por dia/tema atingido. Não é possível vender mais ingressos para este tema nesta data.\n");
        return;
    }

    if (*totalIngressos >= MAX_INGRESSOS_DIA_TEMA) {
        printf("Limite de ingressos por dia/tema atingido. Não é possível vender mais ingressos para este tema nesta data.\n");
        return;
    }

    int escolhaTipoIngresso;
    printf("Escolha o tipo de ingresso:\n");
    printf("1 - Inteira\n");
    printf("2 - Meia\n");
    printf("Digite a opção (1/2): ");
    scanf("%d", &escolhaTipoIngresso);

    if (escolhaTipoIngresso == 1) {
        tipoIngresso = 0; // Inteira
    } else if (escolhaTipoIngresso == 2) {
        int escolhaTipoMeia;
        printf("Escolha o tipo de meia:\n");
        printf("1 - Estudante\n");
        printf("2 - Idoso\n");
        printf("3 - Deficiente\n");
        printf("Digite a opção (1/2/3): ");
        scanf("%d", &escolhaTipoMeia);

        if (escolhaTipoMeia == 1) {
            tipoIngresso = 2; // Meia para Estudante
        } else if (escolhaTipoMeia == 2) {
            tipoIngresso = 3; // Meia para Idoso
        } else if (escolhaTipoMeia == 3) {
            tipoIngresso = 4; // Meia para Deficiente
        } else {
            printf("Opção de meia inválida. Venda de ingresso cancelada.\n");
            return;
        }
    } else {
        printf("Opção de ingresso inválida. Venda de ingresso cancelada.\n");
        return;
    }

    // Restante do código permanece inalterado
    valorIngresso = calcularValorIngresso(tipoIngresso, temaEscolhido);

    if (valorIngresso == 0) {
        printf("Limite de ingressos para este tipo (inteira/meia-entrada) atingido. Não é possível vender mais ingressos para este tema nesta data.\n");
        return;
    }

    ingressos[*totalIngressos].numero = gerarNumeroIngresso();
    ingressos[*totalIngressos].tipo = tipoIngresso;
    strcpy(ingressos[*totalIngressos].cpfCliente, cpf);
    strcpy(ingressos[*totalIngressos].dataVisita, dataVisita);
    ingressos[*totalIngressos].temaEscolhido = temaEscolhido;

    printf("Ingresso vendido para %s na data %s, tema %d. Valor: R$ %d,00", clientes[*totalClientes - 1].nome, dataVisita, temaEscolhido, valorIngresso);

    gerarQRCode(ingressos[*totalIngressos]);

    (*totalIngressos)++;
}

int calcularValorIngresso(int tipoIngresso, int temaEscolhido) {
    // Preços base
    int precoInteiraDiaDeSemana = 50;
    int precoMeiaDiaDeSemana = 25;
    int precoInteiraFeriadoFimDeSemana = 60;
    int precoMeiaFeriadoFimDeSemana = 30;

    // Limites de compra
    int limiteInteiraDiaDeSemana = 4;
    int limiteMeiaDiaDeSemana = 4;
    int limiteInteiraFeriadoFimDeSemana = 6;
    int limiteMeiaFeriadoFimDeSemana = 6;

    // Verifica o tipo de ingresso e limites de compra
    if (tipoIngresso == 2) { // Meia-entrada
        if (temaEscolhido == 0) { // Dia de semana
            return (limiteMeiaDiaDeSemana > 0) ? precoMeiaDiaDeSemana : 0;
        } else { // Feriado/fim de semana
            return (limiteMeiaFeriadoFimDeSemana > 0) ? precoMeiaFeriadoFimDeSemana : 0;
        }
    } else { // Inteira
        if (temaEscolhido == 0) { // Dia de semana
            return (limiteInteiraDiaDeSemana > 0) ? precoInteiraDiaDeSemana : 0;
        } else { // Feriado/fim de semana
            return (limiteInteiraFeriadoFimDeSemana > 0) ? precoInteiraFeriadoFimDeSemana : 0;
        }
    }
}

int gerarNumeroIngresso() {
    return rand() % 1000 + 1; // Gera um número aleatório entre 1 e 1000
}

void gerarQRCode(Ingresso ingresso) {
    // Lógica para gerar QR Code
    printf("QR Code gerado para o ingresso %d.\n", ingresso.numero);
}
