// pesquisa.c
#include <stdio.h>
#include <string.h>
#include "pesquisa.h"

#define MAX_PERGUNTAS 10

// Estrutura para armazenar estatísticas de cada pergunta
typedef struct {
    int sim;
    int nao;
} EstatisticaPergunta;

// Array para armazenar estatísticas de cada pergunta
static EstatisticaPergunta estatisticas[MAX_PERGUNTAS];

// Perguntas do questionário
const char *perguntas[] = {
    "Satisfacao Geral\n1. A exposicao apresentada gerou uma experiencia satisfatoria?",
    "2. As obras que foram exibidas despertaram seu interesse?",
    "3. Voce recomendaria a visita a exposicao a outras pessoas?",
    "Relevancia dos Temas\n1. Os temas das exposicoes apresentadas eram relevantes e atuais?",
    "2. Voce ja tinha algum conhecimento em relacao a obra exposta?",
    "3. Os temas apresentados abordaram questoes importantes e relevantes de cultura e atualidades?",
    "Interatividade e Acessibilidade\n1. Voce achou facil interagir com os terminais de informacao?",
    "2. As descricoes das obras ajudaram a despertar seu interesse e entendimento em relacao a obra exposta?",
    "3. Voce sentiu facilidade ao utilizar o sistema de venda de ingressos?",
    "4. Voce se sentiu confortavel durante a exposicao da obra?",
    "Obrigado pelas respostas! Deixe um comentário: (opcional)"
};

void inicializarEstatisticas() {
    int i;
    // Inicializa todas as estatísticas com zero
    for (i = 0; i < MAX_PERGUNTAS; i++) {
        estatisticas[i].sim = 0;
        estatisticas[i].nao = 0;
    }
}

void realizarPesquisa(int respostas[], int totalPerguntas) {
    int i;
    printf("Realizando pesquisa...\n");

    for (i = 0; i < totalPerguntas; i++) {
        printf("Pergunta %d: %s\n", i + 1, perguntas[i]);
        printf("1 - Sim\n");
        printf("2 - Nao\n");
        printf("Sua resposta: ");
        scanf("%d", &respostas[i]);

        // Atualiza estatísticas com base na resposta
        if (respostas[i] == 1) {
            estatisticas[i].sim++;
        } else if (respostas[i] == 2) {
            estatisticas[i].nao++;
        }
    }

    printf("Pesquisa concluída. Obrigado pelas respostas!\n");
}

void calcularEstatisticas() {
    int i;
    printf("Estatisticas da Pesquisa:\n");
    printf("Total de respostas por pergunta:\n");

    for (i = 0; i < MAX_PERGUNTAS; i++) {
        printf("Pergunta %d:\n", i + 1);
        printf("Respostas 'Sim': %d\n", estatisticas[i].sim);
        printf("Respostas 'Nao': %d\n", estatisticas[i].nao);
        printf("Percentual 'Sim': %.2f%%\n", (float)estatisticas[i].sim / (estatisticas[i].sim + estatisticas[i].nao) * 100);
        printf("Percentual 'Nao': %.2f%%\n", (float)estatisticas[i].nao / (estatisticas[i].sim + estatisticas[i].nao) * 100);
    }
}
