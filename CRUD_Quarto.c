#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

struct Quarto {
    int numero;
    int codigoHotel;
    int ocupacao;
    int codigoQuarto;
};

int alterarTQuarto(Quarto *tq, int tanTQuarto){

    Quarto UpdateQuarto;
    printf("Digite o numero do quarto: ");
    scanf("%d", &UpdateQuarto.numero);
    printf("Digite o codigo do hotel: ");
    scanf("%d", &UpdateQuarto.codigoHotel);
    printf("Digite a ocupacao do quarto: ");
    scanf("%d", &UpdateQuarto.ocupacao);
    printf("Digite o codigo do tipo de quarto: ");
    scanf("%d", &UpdateQuarto.codigoQuarto);

    FILE *arquivo = fopen("./storage/QUARTO.txt", "a+");
    fprintf(arquivo, "%d|%d|%d|%d\n", UpdateQuarto.numero, UpdateQuarto.codigoHotel, UpdateQuarto.ocupacao, quarto.codigoQuarto);
    fclose(arquivo);
    printf("Quarto adicionado com sucesso!\n");

}
void editar_quarto() {
    int numero;
    printf("Digite o numero do quarto a ser editado: ");
    scanf("%d", &numero);

    FILE *arquivoAntigo = fopen("./storage/QUARTO.txt", "r");
    FILE *arquivoNovo = fopen("./storage/QUARTO_novo.txt", "w");

    Quarto quarto;
    while (fscanf(arquivoAntigo, "%d|%d|%d|%d\n", &quarto.numero, &quarto.codigoHotel, &quarto.ocupacao, &quarto.codigoQuarto) != EOF) {
        if (quarto.numero == numero) {
            printf("Digite o codigo do hotel: ");
            scanf("%d", &quarto.codigoHotel);
            printf("Digite a ocupacao do quarto: ");
            scanf("%d", &quarto.ocupacao);
            printf("Digite o codigo do tipo de quarto: ");
            scanf("%d", &quarto.codigoQuarto);
        }
        fprintf(arquivoNovo, "%d|%d|%d|%d\n", quarto.numero, quarto.codigoHotel, quarto.ocupacao, quarto.codigoQuarto);
    }

    fclose(arquivoAntigo);
    fclose(arquivoNovo);

    remove("./storage/QUARTO.txt");
    rename("./storage/QUARTO_novo.txt", "./storage/QUARTO.txt");

    printf("Quarto editado com sucesso!\n");
}

 
    int numero;
    printf("Digite o numero do quarto a ser removido: ");
    scanf("%d", &numero);

    FILE *arquivoAntigo = fopen("./storage/QUARTO.txt", "r");
    FILE *arquivoNovo = fopen("./storage/QUARTO_novo.txt", "w");

    Quarto quarto;
    while (fscanf(arquivoAntigo, "%d|%d|%d|%d\n", &quarto.numero, &quarto.codigoHotel, &quarto.ocupacao, &quarto.codigoQuarto) != EOF) {
        if (quarto.numero != numero) {
            fprintf(arquivoNovo, "%d|%d|%d|%d\n", quarto.numero, quarto.codigoHotel, quarto.ocupacao, quarto.codigoQuarto);
        }
    }

    fclose(arquivoAntigo);
    fclose(arquivoNovo);


void listarQuartos() {
    FILE *arquivo = fopen("./storage/QUARTO.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Quarto quarto;
    printf("\nListagem de Quartos:\n");
    while (fscanf(arquivo, "%d %d %d %d\n", &quarto.numero, &quarto.codigoHotel,
                  &quarto.ocupacao, &quarto.codigoQuarto) != EOF) {
        printf("Numero: %d\n", quarto.numero);
        printf("Codigo do Hotel: %d\n", quarto.codigoHotel);
        printf("Ocupacao: %d\n", quarto.ocupacao);
        printf("Codigo do Tipo de Quarto: %d\n", quarto.codigoQuarto);
        printf("\n");
    }

    fclose(arquivo);
}