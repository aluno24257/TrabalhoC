#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "funcoes.h"
#include "funcoes.c"


int main()
{
    int pMenu, sMenu, CRUD, opcaoCRUD, t;
   
    do
    {
        system("clear");
        printf("Selecione uma operação:\n");
        printf("1.Tabelas\n");
        printf("2.Consultas\n");
        printf("3.Acerca\n");
        printf("4.Sair\n\n");
        printf("-->");
        scanf("%d", &pMenu);

        switch (pMenu)
        {
        case 1:
            do
            {
                system("clear");
                printf("Selecione uma operação:\n");
                printf("1.Grupos Hoteleiros\n");
                printf("2.Tipos de Quartos\n");
                printf("3.Clientes\n");
                printf("4.Hotéis\n");
                printf("5.Quartos\n");
                printf("6.Reservas\n");
                printf("7.Voltar\n\n");
                printf("-->");
                scanf("%d", &sMenu);
                switch (sMenu)
                {
                case 1:
                    do
                    {
                        system("clear");
                        printf("\n\nSelecione uma operacao (Grupo Hoteleiro):\n");
                        printf("1.Criar\n");
                        printf("2.Alterar\n");
                        printf("3.Apagar\n");
                        printf("4.Listar\n");
                        printf("5.Voltar\n\n");
                        printf("->");
                        scanf("%d", &opcaoCRUD);
                        switch (opcaoCRUD)
                        {
                        case 1:
                            system("clear");
                            /*O insert GHoteleiro retorna 1 */
                          
                            break;
                        case 2:
                            system("clear");
                         
                            break;
                        case 3:
                            system("clear");
                            
                            break;
                        case 4:
                            system("clear");
                            scanf("%d", &t);
                            break;
                        case 5:
                    
                            break;
                        }

                    } while (CRUD != 5);
                    break;
                case 2:
                    do
                    {
                        system("clear");
                        printf("\n\nSelecione uma operacao (Tipo Quarto):\n");
                        printf("1.Criar\n");
                        printf("2.Alterar\n");
                        printf("3.Apagar\n");
                        printf("4.Listar\n");
                        printf("5.Voltar\n\n");
                        printf("->");
                        scanf("%d", &CRUD);
                        switch (CRUD)
                        {
                        case 1:
                            system("clear");
                            adicionar_quarto(q);
                            break;
                        case 2:
                            system("clear");
                            editar_quarto(); // código para alterar um quarto
                        case 3:
                            system("clear");
                            // código para apagar um quarto
                            break;
                        case 4:
                            // código para listar os quartos
                            break;
                        case 5:
                     
                            break;
                        }

                    } while (opcaoCRUD != 5);
                    break;
                case 3:
                    do
                    {
                        system("clear");
                        printf("\n\nSelecione uma operacao (Clientes):\n");
                        printf("1.Criar\n");
                        printf("2.Alterar\n");
                        printf("3.Apagar\n");
                        printf("4.Listar\n");
                        printf("5.Voltar\n\n");
                        printf("->");
                        scanf("%d", &CRUD);
                        switch (CRUD)
                        {
                        case 1:
                            system("clear");
                           
                            break;
                        case 2:
                            system("clear");
                            
                            break;
                        case 3:
                            system("clear");
                          
                            break;
                        case 4:
                            system("clear");
                            
                            break;
                        case 5:
                           
                            break;
                        }

                    } while (CRUD != 5);
                    break;
                case 4:
                    do
                    {
                        system("clear");
                        printf("\n\nSelecione uma operacao (Hotéis):\n");
                        printf("1.Criar\n");
                        printf("2.Alterar\n");
                        printf("3.Apagar\n");
                        printf("4.Listar\n");
                        printf("5.Voltar\n\n");
                        printf("->");
                        scanf("%d", &CRUD);
                        switch (CRUD)
                        {
                        case 1:
                            system("clear");
                            
                            break;
                        case 2:
                            system("clear");
                         
                            break;
                        case 3:
                            system("clear");
                            
                            break;
                        case 4:
                            system("clear");
                            
                            break;
                        case 5:
                          
                            break;
                        }

                    } while (CRUD != 5);
                    break;
                case 5:
                    do
                    {
                        system("clear");
                        printf("\n\nSelecione uma operacao (Quarto):\n");
                        printf("1.Criar\n");
                        printf("2.Alterar\n");
                        printf("3.Apagar\n");
                        printf("4.Listar\n");
                        printf("5.Voltar\n\n");
                        printf("->");
                        scanf("%d", &CRUD);
                        switch (CRUD)
                        {
                        case 1:
                           
                            break;
                        case 2:
                           
                            break;
                        case 3:
                            
                            break;
                        case 4:
                            
                            break;
                        case 5:
                            
                            break;
                        }

                    } while (CRUD != 5);
                    break;
                case 6:
                    do
                    {
                        system("clear");
                        printf("\n\nSelecione uma operacao (Reservas):\n");
                        printf("1.Criar\n");
                        printf("2.Alterar\n");
                        printf("3.Apagar\n");
                        printf("4.Listar\n");
                        printf("5.Voltar\n\n");
                        printf("->");
                        scanf("%d", &CRUD);
                        switch (CRUD)
                        {
                        case 1:
                           
                        case 2:
                          
                        case 3:
                           
                        case 4:
                         
                        case 5:
                           
                        }

                    } while (CRUD != 5);
                    break;
                }
            } while (sMenu != 7);
            break;
        case 2:
            system("clear");
            printf("\n\nConsultas :\n");
            printf("1.Listar as Reservas\n");
            printf("2.Voltar\n\n");
            printf("->");
            scanf("%d", &CRUD);
            switch (CRUD)
            {
            case 1:
                system("clear");
                printf("\n\nEscolha :\n");
                printf("1.Filtrar por hotel\n");
                printf("2.Filtrar por Cliente\n\n");
                break;
            }
            break;
        }

    } while (pMenu != 4);

    return 0;
}