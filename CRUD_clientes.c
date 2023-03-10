#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Declaração das funções
void listar();
void adicionar();
void editar();
void eliminar();

int main()
{
    int menu,submenu;

    // Declaração de um array de strings para passar como argumentos para execv()
    char *args[1][2]={
        {"./tabelas",NULL}
    };

    boot:
    // Limpa o ecrã e imprime o cabeçalho do programa
    printf("\e[2J\e[H");
    printf("--------------------------------------------------\n");
    printf("OPERAÇÕES CRUD: Clientes\n");
    printf("--------------------------------------------------\n");

    // Menu principal com as opções disponíveis
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
            listar(); // Chama a função para listar os dados
            printf("\nSelecione uma operação. Deverá inserir o numero correspondente à opção pretendida:\n");
            printf("1- Voltar\n\n");
            printf("Opção selecionada?   ");
            scanf("%d",&submenu);
            switch(submenu)
            {
                case 1:
                    goto boot; // Volta ao menu principal
                    break;
                default:
                    goto repeat_list; // Volta a chamar a função para listar dados
                    break;
            }
            break;
        
        case 2:
            repeat_add:
            adicionar(); // Chama a função para adicionar novo registo
            printf("\nSelecione uma operação. Deverá inserir o numero correspondente à opção pretendida:\n");
            printf("1- Adicionar novo registo\n");
            printf("2- Voltar\n\n");
            printf("Opção selecionada?   ");
            scanf("%d",&submenu);
            switch(submenu)
            {
                case 1:
                    goto repeat_add; // Volta a chamar a função para adicionar novo registo
                    break;
                default:
                    goto boot; // Volta ao menu principal
                    break;
            }
            break;
        
        case 3:
            repeat_edit:
            editar(); // Chama a função para alterar dados
            printf("\nSelecione uma operação. Deverá inserir o numero correspondente à opção pretendida:\n");
            printf("1- Editar outro registo\n");
            printf("2- Voltar\n\n");
            printf("Opção selecionada?   ");
            scanf("%d",&submenu);
            switch(submenu)
            {
                case 1:
                    goto repeat_edit; // Volta a chamar a função para alterar dados
                    break;
                default:
                    goto boot; // Volta ao menu principal
                    break;
            }
            break;
        
        case 4:
            repeat_delete:
            eliminar(); // Chama a função para eliminar registos
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
    FILE *file;
    char data[500];
    int i=0, count=0;
    printf("\e[2J\e[H");
    printf("----|-------------|---------|-------|----------|-------|--------|-----\n");
    printf("Nif | NumeroTelem |  Genero | Nomes | Apelidos | Email | Cidade | Pais\n");
    printf("----|-------------|---------|-------|----------|-------|--------|-----\n");
    file = fopen("./storage/CLIENTE.txt", "r");
    if(file == NULL)
    {
        printf("Repositório de Clientes inacessivel!\n\n\n\n\n");
    }
    else
    {
        /*Obtem o total de registos */
        fscanf(file, "%d", &count); 
        do
        {
            fgets(data,500,file);
            printf("%s\n", data);
            i++;
        }while( i <= count );
        fclose(file);
    }
}

void adicionar()
{
    int num;
    bool isDeleted = false;
    FILE *file_old, *file_new;
    char data[500], data2[500], *id, *compare, count[10], IDcliente[5], Name[100], dump;
    const char s[2] = " ";

    file_old = fopen("./storage/CLIENTE.txt", "r");
    file_new = fopen("./storage/CLIENTE_new.txt", "a");
    
    if(file_old == NULL)
    {
        printf("Repositório de Clientes inacessivel!\n\n\n\n\n");
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
        printf("\n\nInsira o novo ID do Cliente: ");
        scanf("%s",IDcliente);
        printf("Insira a nova descrição para o Cliente: ");
        scanf("%c", &dump);
        scanf("%[^\n]",Name);
        fputs("\n",file_new);
        fputs(IDcliente ,file_new);
        fputs(" " ,file_new);
        fputs(Name,file_new);      

        fclose(file_new);

        /*apagar file_old*/
        remove("./storage/CLIENTE.txt");
        /*renomear file_new para CLIENTE.txt*/
        rename("./storage/CLIENTE_new.txt", "./storage/CLIENTE.txt"); 
    }
}

void eliminar()
{
    int num;
    bool isDeleted = false;
    FILE *file_old, *file_new;
    char data[500], data2[500], *id, *compare, count[10];
    const char s[2] = " ";

    printf("\e[2J\e[H"); /*CLEAR*/
    listar();
    /* */
    file_old = fopen("./storage/CLIENTE.txt", "r");
    file_new = fopen("./storage/CLIENTE_new.txt", "a");
    
    if(file_old == NULL)
    {
        printf("Repositório de Clientes inacessiveis!\n\n\n\n\n");
    }
    else
    {
        printf("\n\nInserir ID do Cliente a eliminar: ");
        scanf("%s",id);
        
        /* */
        fgets(count,500,file_old);
        num=atoi(count)-1;
        sprintf(count, "%d\n", num);
        fputs(count,file_new);
        /* */

        while( !feof(file_old) )
        {
            fgets(data,500,file_old);
            strncpy(data2, data, sizeof(data));

            compare = strtok(data, s);
            printf("%s - compare\n %s - id", compare, id);
            if(strcmp(id, compare)!=0)
            {
                printf("\n%s - ignored\n", compare);
                fputs(data2, file_new);
            }
            else
            {
                printf("\n%s - found!\n", compare);
                isDeleted = true;
            }
        }

        fclose(file_old);
        fclose(file_new);

        if(isDeleted = true)
        {
            /*apagar file_old*/
            remove("./storage/CLIENTE.txt");
            /*renomear file_new para CLIENTE.txt*/
            rename("./storage/CLIENTE_new.txt", "./storage/CLIENTE.txt");
        }
        else
        {
            /* apagar file_new*/
            remove("./storage/CLIENTE_new.txt");
        }
    }
}

void editar()
{
    int num;
    bool isEdited = false;
    FILE *file_old, *file_new;
    char data[500], data2[500], *id, *compare, count[10], IDcliente[5], Name[100], dump;
    const char s[2] = " ";

    printf("\e[2J\e[H");
    listar();
    file_old = fopen("./bin/CLIENTE.txt", "r");
    file_new = fopen("./storage/CLIENTE_new.txt", "a");
    if(file_old == NULL)
    {
        printf("Repositório de Clientes inacessivel!\n\n\n\n\n");
    }
    else
    {
        printf("\n\nInserir ID do Cliente a editar: ");
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
                printf("\n\nInsira o novo ID do Cliente: ");
                scanf("%s",IDcliente);
                printf("Insira a nova descrição para o Cliente: ");
                scanf("%c", &dump);
                scanf("%[^\n]",Name);
                fputs(IDcliente ,file_new);
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
            remove("./storage/CLIENTE.txt");
            /*renomear file_new para CLIENTE.txt*/
            rename("./storage/CLIENTE_new.txt", "./storage/CLIENTE.txt");
        }
        else
        {
            /* apagar file_new*/
            remove("./storage/CLIENTE_new.txt");
        }
    }
}