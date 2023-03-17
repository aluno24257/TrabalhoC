#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "struct.h"

struct Quarto {
    int numero;
    int codigoHotel;
    int ocupacao;
    int codigoTipoQuarto;
};

int alterarTQuarto(TipoQuarto *tq, int tanTQuarto){
void adicionar_quarto() {
    struct Quarto;
    printf("Digite o numero do quarto: ");
    scanf("%d", &quarto.numero);
    printf("Digite o codigo do hotel: ");
    scanf("%d", &quarto.codigoHotel);
    printf("Digite a ocupacao do quarto: ");
    scanf("%d", &quarto.ocupacao);
    printf("Digite o codigo do tipo de quarto: ");
    scanf("%d", &quarto.codigoTipoQuarto);

    FILE *arquivo = fopen("./storage/QUARTO.txt", "a+");
    fprintf(arquivo, "%d|%d|%d|%d\n", quarto.numero, quarto.codigoHotel, quarto.ocupacao, quarto.codigoTipoQuarto);
    fclose(arquivo);
    printf("Quarto adicionado com sucesso!\n");
}
}
void editar_quarto() {
    int numero;
    printf("Digite o numero do quarto a ser editado: ");
    scanf("%d", &numero);

    FILE *arquivoAntigo = fopen("./storage/QUARTO.txt", "r");
    FILE *arquivoNovo = fopen("./storage/QUARTO_novo.txt", "w");

    struct Quarto quarto;
    while (fscanf(arquivoAntigo, "%d|%d|%d|%d\n", &quarto.numero, &quarto.codigoHotel, &quarto.ocupacao, &quarto.codigoTipoQuarto) != EOF) {
        if (quarto.numero == numero) {
            printf("Digite o codigo do hotel: ");
            scanf("%d", &quarto.codigoHotel);
            printf("Digite a ocupacao do quarto: ");
            scanf("%d", &quarto.ocupacao);
            printf("Digite o codigo do tipo de quarto: ");
            scanf("%d", &quarto.codigoTipoQuarto);
        }
        fprintf(arquivoNovo, "%d|%d|%d|%d\n", quarto.numero, quarto.codigoHotel, quarto.ocupacao, quarto.codigoTipoQuarto);
    }

    fclose(arquivoAntigo);
    fclose(arquivoNovo);

    remove("./storage/QUARTO.txt");
    rename("./storage/QUARTO_novo.txt", "./storage/QUARTO.txt");

    printf("Quarto editado com sucesso!\n");
}
/*
void remover_quarto() {
    int numero;
    printf("Digite o numero do quarto a ser removido: ");
    scanf("%d", &numero);

    FILE *arquivoAntigo = fopen("./storage/QUARTO.txt", "r");
    FILE *arquivoNovo = fopen("./storage/QUARTO_novo.txt", "w");

    struct Quarto quarto;
    while (fscanf(arquivoAntigo, "%d|%d|%d|%d\n", &quarto.numero, &quarto.codigoHotel, &quarto.ocupacao, &quarto.codigoTipoQuarto) != EOF) {
        if (quarto.numero != numero) {
            fprintf(arquivoNovo, "%d|%d|%d|%d\n", quarto.numero, quarto.codigoHotel, quarto.ocupacao, quarto.codigoTipoQuarto);
        }
    }

    fclose(arquivoAntigo);
    fclose(arquivoNov


void listar_quartos(Quarto quartos[], int num_quartos) {
    int i;
    printf("Lista de quartos:\n");
    printf("Numero | Codigo Hotel | Ocupacao | Codigo Tipo de Quarto\n");
    for (i = 0; i < num_quartos; i++) {
        printf("%6d | %12d | %8d | %19d\n", quartos[i].numero, quartos[i].codigoHotel, quartos[i].ocupacao, quartos[i].codigoTipoQuarto);
    }
}*/