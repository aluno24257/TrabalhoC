#include <stdio.h>
#include <stdlib.h>
 
 int main()
 {
    int mainmenu, choice;
    char *args[3][2]={
        {"./bin/tabelas",NULL},
        {"./bin/consultas",NULL},
        {"./bin/acerca",NULL}
    };
    
    boot:
    printf("\e[2J\e[H");
    printf("--------------------------------------------------\n");
    printf("Sistema de Registos Hoteleiros\n");
    printf("--------------------------------------------------\n\n");
    printf("Selecione uma operação. Deverá inserir o numero correspondente à opção pretendida:\n");
    printf("1- Tabelas\n");
    printf("2- Consultas\n");
    printf("3- Acerca\n");
    printf("4- Sair\n\n");
    printf("Opção selecionada?   ");
    scanf("%d", &mainmenu);
    
    switch(mainmenu)
    {
        case 1:
            execv(args[0][0],args);
            break;
        
        case 2:
            execv(args[1][0],args);
            break;
        
        case 3:
            printf("\e[2J\e[H");
            printf("Trabalho feito por Bruno Carreira e Rafael Santos\n");
            printf("Carregue no Y para continuar\t");
            while(1)
                    {
                        if ('y' == getchar())
                        break;
                    }
            goto boot;
            break;
        
        case 4:
            printf("\e[2J\e[H");
            warning();
            printf("\nSair do programa?\n1-Sim     2-Não\n\nOpção selecionada?   ");
            scanf("%d", &choice);
            if(choice==1)
            {
                break;
            }
            else
            {
                goto boot;
            }
            break;

        default:
            goto boot;
            break;
    }
}

 void warning()
    {
        printf("Warning\n");                                          
    }