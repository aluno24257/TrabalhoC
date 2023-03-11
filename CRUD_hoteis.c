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
    printf("OPERAÇÕES CRUD: Hoteis\n");
    printf("--------------------------------------------------\n");
    printf("\nSelecione uma operação. Deverá inserir o numero correspondente à opção pretendida:\n");
    printf("1- Listar Hoteis\n");
    printf("2- Adicionar novo registo\n");
    printf("3- Alterar Hoteis\n");
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
    FILE *file;
    char data[500];
    int i=0, count=0;
    printf("\e[2J\e[H");
    printf("---|-----------------------------|------|--------|----\n");
    printf("ID | NifGrupoHoteleio | estrelas | Nome | Cidade | Pais \n");
    printf("---|------------------|----------|------|--------|----\n");
    file = fopen("./storage/HOTEL.txt", "r");
    if(file == NULL)
    {
        printf("Repositório de Hoteis inacessivel!\n\n\n\n\n");
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
    char data[500], data2[500], *id, *compare, count[10], IDHOTEL[5], Name[100], dump;
    const char s[2] = " ";

    file_old = fopen("./storage/HOTEL.txt", "r");
    file_new = fopen("./storage/HOTEL_new.txt", "a");
    
    if(file_old == NULL)
    {
        printf("Repositório de HOTEL inacessivel!\n\n\n\n\n");
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
        printf("\n\nInsira o novo ID do HOTEL: ");
        scanf("%s",IDHOTEL);
        printf("Insira a nova descrição para o HOTEL: ");
        scanf("%c", &dump);
        scanf("%[^\n]",Name);
        fputs("\n",file_new);
        fputs(IDHOTEL ,file_new);
        fputs(" " ,file_new);
        fputs(Name,file_new);      

        fclose(file_new);

        /*apagar file_old*/
        remove("./storage/HOTEL.txt");
        /*renomear file_new para HOTEL.txt*/
        rename("./storage/HOTEL_new.txt", "./storage/HOTEL.txt"); 
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
    file_old = fopen("./storage/HOTEL.txt", "r");
    file_new = fopen("./storage/HOTEL_new.txt", "a");
    
    if(file_old == NULL)
    {
        printf("Repositório de Hoteis inacessiveis!\n\n\n\n\n");
    }
    else
    {
        printf("\n\nInserir ID do Hotel a eliminar: ");
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

void editar()
{
    // Declaração de variáveis e inicialização de algumas
    int num;
    bool isEdited = false; // Inicialmente, a variável que verifica se o registro foi editado é definida como falso
    FILE *file_old, *file_new; // Declara dois ponteiros para FILE - um para o arquivo original e outro para o arquivo novo
    char data[500], data2[500], *id, *compare, count[10], IDHOTEL[5], Name[100], dump;
    // Declarando variáveis ​​para armazenar os dados de entrada, como o ID do hotel, nome, etc.
    const char s[2] = " "; // Defina o delimitador de espaço para separar as informações de registro

    printf("\e[2J\e[H"); // Limpa a tela
    listar(); // Exibe todos os registros de hotel antes da edição
    file_old = fopen("./bin/HOTEL.txt", "r"); // Abre o arquivo original em modo leitura
    file_new = fopen("./storage/HOTEL_new.txt", "a"); // Abre o arquivo novo em modo append

    // Se o arquivo original não puder ser aberto, exiba uma mensagem de erro
    if(file_old == NULL)
    {
        printf("Repositório de Hotel inacessivel!\n\n\n\n\n");
    }
    else
    {
        printf("\n\nInserir ID do Hotel a editar: ");
        scanf("%s",id); // Obtém o ID do hotel que o usuário deseja editar
        
        /* salta a primeira linha do documento - contagem - e escreve-a no novo registo*/
        fgets(count,500,file_old); // Lê a primeira linha do arquivo original (o número total de registros) e armazena em count
        fputs(count,file_new); // Escreve essa primeira linha no novo arquivo também

        // Loop através de todos os registros no arquivo original
        while( !feof(file_old) )
        {
            fgets(data,500,file_old); // Lê uma linha inteira do arquivo original e armazena em data
            strncpy(data2, data, sizeof(data)); // Copia a linha lida em data para data2

            compare = strtok(data, s); // Use a função strtok para extrair o ID do hotel da linha lida em data
            printf("%s - compare\n%s - id", compare, id);
            if(strcmp(id, compare)!=0) // Se o ID do hotel lido não for igual ao ID do hotel a ser editado, escreva a linha no novo arquivo
            {
                printf("\n%s - not a match, ignoring\n", compare);
                fputs(data2, file_new);
            }
            else // Se o ID do hotel lido for igual ao ID do hotel a ser editado, permita que o usuário edite os detalhes
            {
                printf("\n%s - MATCH FOUND!\n", compare);
                printf("\e[2J\e[H"); // Limpa a tela
                printf("Valores anteriores: \n");
                printf("%s",data2); // Exibe os valores anteriores antes da edição
                printf("\n\nInsira o novo ID do HOTEL: ");
                scanf("%s",IDHOTEL);
                printf("Insira a nova descrição para o HOTEL: ");
                scanf("%c", &dump);
                scanf("%[^\n]",Name);
                fputs(IDHOTEL ,file_new);
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