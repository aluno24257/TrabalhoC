#include <stdio.h>
#include <stdlib.h>
#include "strucs.h"


void tabela();
void consulta();
void acerca();

int main() {
    int mainmenu;

    while(1) {
        printf("\e[2J\e[H");
        printf("--------------------------------------------------\n");
        printf("Sistema de Registos Hoteleiros\n");
        printf("--------------------------------------------------\n\n");
        printf("Selecione uma operação. Deverá inserir o número correspondente à opção pretendida:\n");
        printf("1- Tabelas\n");
        printf("2- Consultas\n");
        printf("3- Acerca\n");
        printf("4- Sair\n\n");
        printf("Opção selecionada?   ");
        scanf("%d", &mainmenu);

        switch(mainmenu) {
            case 1:
                tabela();
                break;
            case 2:
                consulta();
                break;
            case 3:
                acerca();
                break;
            case 4:
                exit(0);
            default:
                printf("Opção inválida. Por favor, selecione uma opção válida.\n");
                break;
        }
    }

    return 0;
}

// Função da tabela
void tabela() {
     
     int submenu , CRUD;

    while(1) {
        printf("\e[2J\e[H");
        printf("--------------------------------------------------\n");
        printf("Tabelas\n");
        printf("--------------------------------------------------\n\n");
        printf("Selecione uma tabela. Deverá inserir o número correspondente à opção pretendida:\n");
        printf("1- Grupos Hoteleiros\n");
        printf("2- Tipos de Quartos\n");
        printf("3- Clientes\n");
        printf("4- Hotéis\n");
        printf("5- Quartos\n");
        printf("6- Reservas\n");
        printf("7- Voltar ao menu principal\n\n");
        printf("Opção selecionada?   ");
        scanf("%d", &submenu);

        switch(submenu) {
            case 1:
              clrscr();
              printf("\nSelecionar uma opção");
              printf("1 - Criar");
              printf("2 - Alterar");
              printf("3 - Apagar");
              printf("4 - Listar");
              printf("5 - Back");
              scanf("%d", &CRUD);
              switch(CRUD) {
                    case 1:
                    //codigo para criar função
                    printf("CRUD criada");
                    break;
                    case 2:
                    printf("CRUD alterada");
                    break;
                    case 3:
                    printf("CRUD apagada");
                    break;
                    case 4:
                    printf("CRUD listada");
                    break;
                    case 5:
                    printf("Voltando ao menu anterior\n");
                    break;
                    default:
                    printf("Opção inválida. Por favor, selecione uma opção válida.\n");
                    break;
    }
              
            case 2:
                printf("\e[2J\e[H");
                printf("--------------------------------------------------\n");
                printf("Tipos de Quartos\n");
                printf("--------------------------------------------------\n\n");
                // coloque aqui o código para a tabela de Tipos de Quartos
                printf("Pressione Enter para voltar ao menu de tabelas...");
                getchar();
                getchar();
                break;
            case 3:
                printf("\e[2J\e[H");
                printf("--------------------------------------------------\n");
                printf("Clientes\n");
                printf("--------------------------------------------------\n\n");
                // coloque aqui o código para a tabela de Clientes
                printf("Pressione Enter para voltar ao menu de tabelas...");
                getchar();
                getchar();
                break;
            case 4:
                printf("\e[2J\e[H");
                printf("--------------------------------------------------\n");
                printf("Hotéis\n");
                printf("--------------------------------------------------\n\n");
                // coloque aqui o código para a tabela de Hotéis
                printf("Pressione Enter para voltar ao menu de tabelas...");
                getchar();
                getchar();
                break;
            case 5:
                printf("\e[2J\e[H");
                printf("--------------------------------------------------\n");
                printf("Quartos\n");
                printf("--------------------------------------------------\n\n");
                // coloque aqui o código para a tabela de Quartos
                printf("Pressione Enter para voltar ao menu de tabelas...");
                getchar();
                getchar();
                break;
            case 6:
                printf("\e[2J\e[H");
                printf("--------------------------------------------------\n");
                printf("Reservas\n");
                printf("--------------------------------------------------\n\n");
                // coloque aqui o código para a tabela de Reservas
                printf("Pressione Enter para voltar ao menu de tabelas...");
                getchar();
                getchar();
                break;
            case 7:
                return;
            default:
                printf("Opção inválida. Por favor, selecione uma opção válida.\n");
                break;
        }
    }
}

// Função de consulta
void consulta() {
    int submenu;

    while(1) {
        printf("\e[2J\e[H");
        printf("--------------------------------------------------\n");
        printf("Consultas\n");
        printf("--------------------------------------------------\n\n");
        printf("Selecione uma consulta. Deverá inserir o número correspondente à opção pretendida:\n");
        printf("1- Listar as Reservas\n");
        printf("2- Listar quartos disponíveis entre duas datas\n");
        printf("3- Listar ocupação média por mês\n");
        printf("4- Listar custo de alojamento\n");
        printf("5- Voltar ao menu principal\n\n");
        printf("Opção selecionada?   ");
        scanf("%d", &submenu);

      switch(submenu) {
    case 1:
        printf("\e[2J\e[H");
        printf("--------------------------------------------------\n");
        printf("Reservas\n");
        printf("--------------------------------------------------\n\n");

        // submenu para CRUD
        int submenu1;
        do {
            printf("Escolha uma opção:\n");
            printf("1. Listar Reservas\n");
            printf("2. Inserir Reserva\n");
            printf("3. Ler Reserva\n");
            printf("4. Alterar Reserva\n");
            printf("5. Apagar Reserva\n");
            printf("6. Voltar\n");

            scanf("%d", &submenu1);
            switch(submenu1) {
                case 1:
                    // coloque aqui o código para listar as reservas
                    printf("Pressione Enter para voltar ao submenu de Reservas...");
                    getchar();
                    getchar();
                    break;
                case 2:
                    // coloque aqui o código para inserir uma nova reserva
                    printf("Pressione Enter para voltar ao submenu de Reservas...");
                    getchar();
                    getchar();
                    break;
                case 3:
                    // coloque aqui o código para ler uma reserva existente
                    printf("Pressione Enter para voltar ao submenu de Reservas...");
                    getchar();
                    getchar();
                    break;
                case 4:
                    // coloque aqui o código para alterar uma reserva existente
                    printf("Pressione Enter para voltar ao submenu de Reservas...");
                    getchar();
                    getchar();
                    break;
                case 5:
                    // coloque aqui o código para apagar uma reserva existente
                    printf("Pressione Enter para voltar ao submenu de Reservas...");
                    getchar();
                    getchar();
                    break;
                case 6:
                    break;
                default:
                    printf("Opção inválida. Por favor, selecione uma opção válida.\n");
                    break;
            }
        } while (submenu1 != 6);

/*
// Função Acerca
void acerca() 
{
    printf("\e[2J\e[H");
    printf("--------------------------------------------------\n");
    printf("Acerca\n");
    printf("--------------------------------------------------\n\n");
    printf("Este é um sistema de registos hoteleiros que permite ao usuário selecionar uma operação. Existem 3 opções disponíveis:\n");
    printf("1. Tabelas\n");
    printf("2. Consultas\n");
    printf("3. Acerca\n");
    printf("Para sair do sistema, selecione a opção 4 no menu principal.\n");
    printf("Codigo feito por Rafael Santos e Bruno Carreira");
    printf("Pressione Enter para voltar ao menu principal...");
    getchar();
   getchar();
}

*/

      }
    }
}