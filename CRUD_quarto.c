#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    int menu,submenu;
    char *args[1][2]={
        {"./tabelas",NULL}
    };

    boot:
    printf("\e[2J\e[H");
    printf("--------------------------------------------------\n");
    printf("OPERAÇÕES CRUD: quarto\n");
    printf("--------------------------------------------------\n");
    printf("\nSelecione uma operação. Deverá inserir o numero correspondente à opção pretendida:\n");
    printf("1- Listar dados\n");
    printf("2- Adicionar novo registo\n");
    printf("3- Alterar dados\n");
    printf("4- Eliminar registos\n");
    printf("5- Voltar\n\n");
    printf("Opção selecionada?   ");
    scanf("%d", &menu);

    switch(menu)
    {
        case 1:
            repeat_list:
            listar();
            printf("\nSelecione uma operação. Deverá inserir o numero correspondente à opção pretendida:\n");
            printf("1- Voltar\n\n");
            printf("Opção selecionada?   ");
            scanf("%d",&submenu);
            switch(submenu)
            {
                case 1:
                    goto boot;
                    break;
                default:
                    goto repeat_list;
                    break;
            }
            break;
        
        case 2:
            repeat_add:
            adicionar();
            printf("\nSelecione uma operação. Deverá inserir o numero correspondente à opção pretendida:\n");
            printf("1- Adicionar novo registo\n");
            printf("2- Voltar\n\n");
            printf("Opção selecionada?   ");
            scanf("%d",&submenu);
            switch(submenu)
            {
                case 1:
                    goto repeat_add;
                    break;
                default:
                    goto boot;
                    break;
            }
            break;
        
        case 3:
            repeat_edit:
            editar();
            printf("\nSelecione uma operação. Deverá inserir o numero correspondente à opção pretendida:\n");
            printf("1- Editar outro registo\n");
            printf("2- Voltar\n\n");
            printf("Opção selecionada?   ");
            scanf("%d",&submenu);
            switch(submenu)
            {
                case 1:
                    goto repeat_edit;
                    break;
                default:
                    goto boot;
                    break;
            }
            break;
        
        case 4:
            repeat_delete:
            eliminar();
            printf("\nSelecione uma operação. Deverá inserir o numero correspondente à opção pretendida:\n");
            printf("1- Eliminar outro registo\n");
            printf("2- Voltar\n\n");
            printf("Opção selecionada?   ");
            scanf("%d",&submenu);
            switch(submenu)
            {
                case 1:
                    goto repeat_delete;
                    break;
                default:
                    goto boot;
                    break;
            }
            break;

        case 5:
            execv(args[0][0],args);
            break;

        default:
            goto boot;
            break;
    }

    return 0;
}

void listar()
{
    printf("\e[2J\e[H");
    FILE *file;
    char data[500];
    printf("-------|------------------------|----------\n");
    printf("Numero | codigoHotel | ocupação | codigoTipoQuarto \n");
    printf("-------|-------------|----------|----------\n");
    file = fopen("./storage/QUARTO.txt", "r");
    if(file == NULL)
    {
        printf("Repositório de quarto inacessivel!\n\n\n\n\n");
    }
    else
    {
        fgets(data,500,file);
        printf("Número de registos: %s\n", data);
        do
        {
            fgets(data,500,file);
            printf("%s\n", data);
        }while( !feof(file) );
        fclose(file);
    }
}

void adicionar()
{
    int num;
    bool isDeleted = false;
    FILE *file_old, *file_new;
    char data[500], data2[500], *id, *compare, count[10], IDaluno[10], IDuc[10], nota[10], dump;
    const char s[2] = " ";

    file_old = fopen("./storage/QUARTO.txt", "r");
    file_new = fopen("./storage/quarto_new.txt", "a");
    
    if(file_old == NULL)
    {
        printf("Repositório de quarto inacessivel!\n\n\n\n\n");
    }
    else
    {
        /* */
        fgets(count,500,file_old);
        num=atoi(count)+1;
        sprintf(count, "%d\n", num);
        fputs(count,file_new);
        /* */

        while( !feof(file_old) )
        {
            fgets(data,500,file_old);
            strncpy(data2, data, sizeof(data));
            fputs(data2, file_new);
        }

        fclose(file_old);

        printf("\e[2J\e[H");
        printf("\n\nInsira o ID do cliente: ");
        scanf("%s",IDaluno);
        printf("Insira o ID do Grupo Hoteleiro a avaliar: ");
        scanf("%s",IDuc);
        printf("Insira a quarto correspondente: ");
        scanf("%s",nota);
        fputs("\n",file_new);
        fputs(IDaluno ,file_new);
        fputs(" " ,file_new);
        fputs(IDuc,file_new);
        fputs(" " ,file_new);
        fputs(nota,file_new);       

        fclose(file_new);

        /*apagar file_old*/
        remove("./storage/quarto.txt");
        /*renomear file_new para curso.txt*/
        rename("./storage/quarto_new.txt", "./storage/quarto.txt"); 
    }
}

void eliminar()
{
    int num, i=0;
    bool isDeleted = false;
    FILE *file_old, *file_new;
    char data[500], data2[500], data3[500], *compare1, *compare2, count[10];
    char idA[50], id[50];
    const char s[2] = " ";

    printf("\e[2J\e[H"); /*CLEAR*/
    listar();
    /* */
    file_old = fopen("./storage/QUARTO.txt", "r");
    file_new = fopen("./storage/QUARTO_new.txt", "a");
    
    if(file_old == NULL)
    {
        printf("Repositório de hoteis inacessivel!\n\n\n\n\n");
    }
    else
    {
        printf("\n\nInserir ID do cliente: ");
        scanf("%s",idA);
        printf("\nInserir ID do hotel: ");
        scanf("%s",id);
        
        /*Counter Updater*/
        fgets(count,500,file_old);
        num=atoi(count)-1;
        sprintf(count, "%d\n", num);
        fputs(count,file_new);
        /*Counter Updater*/

        while( !feof(file_old) )
        {
            fgets(data,500,file_old);
            strncpy(data2, data, sizeof(data));
            
            compare1 = strtok(data, s);
            compare2 = strtok(NULL, s);

            printf("Variável 'compare1': %s\n",compare1);
            printf("Variável 'idA': %s\n",idA);
            printf("Variável 'compare2': %s\n",compare2);
            printf("Variável 'id': %s\n",id);

            if( (strcmp(idA, compare1)==0 ) && (strcmp(id, compare2)==0 ) )
            {
                printf("%s - found!\n\n", compare1);
                isDeleted = true;
            }
            else
            {
                printf("%s - ignored\n\n", compare1);
                fputs(data2, file_new);
            }
        }

        fclose(file_old);
        fclose(file_new);

        if(isDeleted = true)
        {
            /*apagar file_old*/
            remove("./storage/QUARTO.txt");
            /*renomear file_new para curso.txt*/
            rename("./storage/QUARTO_new.txt", "./storage/quarto.txt");
        }
        else
        {
            /* apagar file_new*/
            remove("./storage/QUARTO_new.txt");
        }
    }
}

void editar()
{
    int num;
    bool isEdited = false;
    FILE *file_old, *file_new;
    char data[500], data2[500], *id, *compare, count[10], IDquarto[5], Name[100], dump;
    const char s[2] = " ";

    printf("\e[2J\e[H");
    listar();
    file_old = fopen("./storage/HOTEL.txt", "r");
    file_new = fopen("./storage/HOTEL_new.txt", "a");
    if(file_old == NULL)
    {
        printf("Repositório de hoteis inacessivel!\n\n\n\n\n");
    }
    else
    {
        printf("\n\nInserir ID do hoteis a editar: ");
        scanf("%s",id);
        
        /* salta a primeira linha do documento - contagem - e escreve-a no novo registo*/
        fgets(count,500,file_old);
        fputs(count,file_new);
        

        while( !feof(file_old) )
        {
            fgets(data,500,file_old);
            strncpy(data2, data, sizeof(data));

            compare = strtok(data, s);
            printf("%s - compare\n%s - id", compare, id);
            if(strcmp(id, compare)!=0)
            {
                printf("\n%s - not a match, ignoring\n", compare);
                fputs(data2, file_new);
            }
            else
            {
                printf("\n%s - MATCH FOUND!\n", compare);
                printf("\e[2J\e[H");
                printf("Valores anteriores: \n");
                printf("%s",data2);
                printf("\n\nInsira o novo ID do hoteis: ");
                scanf("%s",IDquarto);
                printf("Insira a nova descrição para o hotel: ");
                scanf("%c", &dump);
                scanf("%[^\n]",Name);
                fputs(IDquarto ,file_new);
                fputs(" " ,file_new);
                fputs(Name,file_new);
                fputs("\n",file_new);
                isEdited = true;
            }
        }

        fclose(file_old);
        fclose(file_new);

        if(isEdited = true)
        {
            /*apagar file_old*/
            remove("./storage/HOTEL.txt");
            /*renomear file_new para HOTEL.txt*/
            rename("./storage/HOTEL_new.txt", "./storage/HOTEL.txt");
        }
        else
        {
            /* apagar file_new*/
            remove("./storage/HOTEL_new.txt");
        }
    }
}