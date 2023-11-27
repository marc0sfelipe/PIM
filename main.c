// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tema.h"
#include "obra.h"
#include "pesquisa.h"
#include "ingresso.h"

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

#define MAX_PERGUNTAS 10

int main() {
    Tema temas[MAX_TEMAS];
    int totalTemas = 0;

    Obra obras[MAX_OBRAS];
    int totalObras = 0;

    int respostas[MAX_PERGUNTAS];
    int totalPerguntas = MAX_PERGUNTAS;

    Cliente clientes[MAX_CLIENTES];
    int totalClientes = 0;

    Ingresso ingressos[MAX_INGRESSOS];
    int totalIngressos = 0;

    int temaEscolhido;
    int opTema;
    int escolha;
    char cpfCliente[12], nomeCliente[50], dataVisita[20];
    int i;

    // Inicializar estatísticas
    inicializarEstatisticas();

    while (1) {
        system(CLEAR_SCREEN);

        printf("Museu - Sistema de Gerenciamento\n");
        printf("1. Gerenciar Temas\n");
        printf("2. Gerenciar Obras\n");
        printf("3. Realizar Pesquisa de Satisfacao\n");
        printf("4. Venda de Ingressos\n");
        printf("5. Sair\n");
        printf("Escolha a opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                // Gerenciar Temas
                printf("\nGerenciar Temas\n");
                printf("1. Incluir Tema\n");
                printf("2. Consultar Tema\n");
                printf("3. Alterar Tema\n");
                printf("4. Excluir Tema\n");
                printf("Escolha a opcao: ");
                scanf("%d", &opTema);

                switch (opTema) {
                    case 1:
                        // Incluir Tema
                        printf("Digite o nome do tema: ");
                        char nomeTema[50];
                        scanf("%s", nomeTema);
                        incluirTema(temas, &totalTemas, nomeTema);
                        break;
                    case 2:
                        // Consultar Tema
                        consultarTema(temas, totalTemas);
                        break;
                    case 3:
                        // Alterar Tema
                        printf("Digite o nome do tema a ser alterado: ");
                        char nomeTemaAntigo[50];
                        scanf("%s", nomeTemaAntigo);
                        printf("Digite o novo nome do tema: ");
                        char novoNomeTema[50];
                        scanf("%s", novoNomeTema);
                        alterarTema(temas, totalTemas, nomeTemaAntigo, novoNomeTema);
                        break;
                    case 4:
                        // Excluir Tema
                        printf("Digite o nome do tema a ser excluido: ");
                        char temaExcluir[50];
                        scanf("%s", temaExcluir);
                        excluirTema(temas, &totalTemas, temaExcluir);
                        break;
                    default:
                        printf("Opcao invalida.\n");
                }
                break;
            case 2:
                // Gerenciar Obras
                printf("\nGerenciar Obras\n");
                printf("1. Incluir Obra\n");
                printf("2. Consultar Obra\n");
                printf("3. Alterar Obra\n");
                printf("4. Excluir Obra\n");
                printf("Escolha a opcao: ");
                int opObra;
                scanf("%d", &opObra);

                switch (opObra) {
                    case 1:
                        // Incluir Obra
                        printf("Digite o nome da obra: ");
                        char nomeObra[50];
                        scanf("%s", nomeObra);
                        printf("Digite o nome do autor: ");
                        char autor[50];
                        scanf("%s", autor);
                        printf("Digite o tema da obra: ");
                        char temaObra[50];
                        scanf("%s", temaObra);
                        incluirObra(obras, &totalObras, nomeObra, autor, temaObra, temas, totalTemas);
                        break;
                    case 2:
                        // Consultar Obra
                        consultarObra(obras, totalObras);
                        break;
                    case 3:
                        // Alterar Obra
                        printf("Digite o nome da obra a ser alterada: ");
                        char nomeObraAntigo[50];
                        scanf("%s", nomeObraAntigo);
                        printf("Digite o novo nome da obra: ");
                        char novoNomeObra[50];
                        scanf("%s", novoNomeObra);
                        printf("Digite o novo autor da obra: ");
                        char novoAutorObra[50];
                        scanf("%s", novoAutorObra);
                        printf("Digite o novo tema da obra: ");
                        char novoTemaObra[50];
                        scanf("%s", novoTemaObra);
                        alterarObra(obras, totalObras, nomeObraAntigo, novoNomeObra, novoAutorObra, novoTemaObra);
                        break;
                    case 4:
                        // Excluir Obra
                        printf("Digite o nome da obra a ser excluida: ");
                        char obraExcluir[50];
                        scanf("%s", obraExcluir);
                        excluirObra(obras, &totalObras, obraExcluir);
                        break;
                    default:
                        printf("Opcao invalida.\n");
                }
                break;
            case 3:
                // Realizar Pesquisa de Satisfação
                realizarPesquisa(respostas, MAX_PERGUNTAS);
                calcularEstatisticas();
                break;
            case 4:
                // Venda de Ingressos
                printf("Digite o CPF do cliente: ");
                scanf("%s", cpfCliente);
                printf("Digite o nome do cliente: ");
                scanf("%s", nomeCliente);
                cadastrarCliente(clientes, &totalClientes, nomeCliente, "01/01/2000", cpfCliente, "Endereco Exemplo", "123456789", "exemplo@email.com");

                printf("Escolha um tema:\n");
                for (i = 0; i < totalTemas; i++) {
                    printf("%d - %s\n", i + 1, temas[i].nome);
                }
                printf("Escolha o tema: ");
                scanf("%d", &temaEscolhido);

                // Verificar se o tema escolhido é válido
                if (temaEscolhido < 1 || temaEscolhido > totalTemas) {
                    printf("Tema escolhido inválido.\n");
                    break;
                }

                printf("Digite a data da visita: ");
                scanf("%s", dataVisita);

                // Vender Ingresso
                venderIngresso(clientes, ingressos, &totalClientes, &totalIngressos, cpfCliente, dataVisita, temaEscolhido);
                break;
            case 5:
                printf("Encerrando o programa.\n");
                return 0;
            default:
                printf("Opcao invalida.\n");
        }

        // Aguardar uma entrada do usuário antes de limpar a tela novamente
        printf("\nPressione Enter para continuar...");
        getchar();
        getchar(); // Aguardar a entrada do usuário
    }
}
