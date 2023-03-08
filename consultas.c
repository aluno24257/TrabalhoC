#include <stdio.h>

int main()
{
    int menu;
    char *args[4][2]={
        {"./l_clientes",NULL},
        {"./l_uc",NULL},
        {"./l_uc_quartos",NULL},
        {"./index",NULL}
    };

    boot:
    printf("\e[2J\e[H");
    printf("--------------------------------------------------\n");
    printf("Consultas\n");
    printf("--------------------------------------------------\n\n");

    printf("Selecione uma operação. Deverá inserir o numero correspondente à opção pretendida:\n");
    printf("1- Listar Clientes\n");
    printf("2- Listar Grupo Hoteleiro\n");
    printf("3- Listar quartos\n");
    printf("4- Voltar\n\n");

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

        default:
            goto boot;
            break;
    }
}
