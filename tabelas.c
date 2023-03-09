#include <stdio.h>

int main()
{
    int menu;
    char *args[6][2]={
        {"./bin/CRUD_hoteis",NULL},
        {"./bin/CRUD_GRUPOHOTELEIRO",NULL},
        {"./bin/CRUD_clientes",NULL},
        {"./bin/CRUD_quarto",NULL},
        {"./bin/index",NULL}
    };

    boot:
    printf("\e[2J\e[H");
    printf("--------------------------------------------------\n");
    printf("Tabelas\n");
    printf("--------------------------------------------------\n\n");

    printf("Selecione uma operação. Deverá inserir o numero correspondente à opção pretendida:\n");
    printf("1- hoteis\n");
    printf("2- GRUPOHOTELEIRO\n");
    printf("3- clientes\n");
    printf("4- Quarto\n");
    printf("5- Tipo de quarto\n"); /*ATENÇÂO*/
    printf("6- Voltar\n\n");

    printf("Opção selecionada?   ");
    scanf("%d", &menu);

    switch(menu)
    {
        case 1:
            execv(args[0][0],args);
            break;
        
        case 2:
            execv(args[1][0],args);
            break;
        
        case 3:
            execv(args[2][0],args);
            break;
        
        case 4:
            execv(args[3][0],args);
            break;

        case 5:
            execv(args[4][0],args);
            break;

        case 6:
            execv(args[5][0],args);
            break;

        default:
            goto boot;
            break;
    }
}
