// ingresso.h
#ifndef INGRESSO_H
#define INGRESSO_H

#define MAX_CLIENTES 200
#define MAX_INGRESSOS 200

typedef struct {
    char nome[100];
    char dataNascimento[11];
    char documento[15];
    char endereco[200];
    char telefone[15];
    char email[100];
} Cliente;

typedef struct {
    int numero;
    int tipo; // 0 - Inteira, 1 - Meia, 2 - Meia Estudante, 3 - Meia Idoso, 4 - Meia Deficiente
    char cpfCliente[15];
    char dataVisita[11];
    int temaEscolhido;
} Ingresso;

void cadastrarCliente(Cliente clientes[], int* totalClientes, const char* nome, const char* dataNascimento, const char* documento, const char* endereco, const char* telefone, const char* email);
void venderIngresso(Cliente clientes[], Ingresso ingressos[], int* totalClientes, int* totalIngressos, const char* cpf, const char* dataVisita, int temaEscolhido);
int calcularValorIngresso(int tipoIngresso, int temaEscolhido);
int gerarNumeroIngresso();
int verificarMeiaEntrada(const char* dataNascimento);
void gerarQRCode(Ingresso ingresso);

#endif // INGRESSO_H
