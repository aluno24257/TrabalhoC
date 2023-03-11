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
    FILE *file; // ponteiro para o arquivo
    char data[500]; // variável para armazenar os dados de cada registro
    int i=0, count=0; // variáveis para controlar o loop e o número total de registros

    // Imprime cabeçalho da tabela
    printf("\e[2J\e[H");
    printf("---|-----------------------------|------|--------|----\n");
    printf("ID | NifGrupoHoteleio | estrelas | Nome | Cidade | Pais \n");
    printf("---|------------------|----------|------|--------|----\n");

    // Abre o arquivo
    file = fopen("./storage/HOTEL.txt", "r");
    if(file == NULL)
    {
        printf("Repositório de Hoteis inacessivel!\n\n\n\n\n");
    }
    else
    {
        // Lê o número total de registros do arquivo
        fscanf(file, "%d", &count); 

        // Loop para ler e imprimir cada registro
        do
        {
            fgets(data,500,file); // Lê uma linha do arquivo
            printf("%s\n", data); // Imprime a linha
            i++; // Incrementa o contador
        } while ( i <= count ); // Repete até imprimir todos os registros

        fclose(file); // Fecha o arquivo
    }
}

// Declaração da função "adicionar"
void adicionar()
{
    int num; // Variável para armazenar o número de registros no arquivo
    bool isDeleted = false; // Variável booleana para verificar se há registros apagados
    FILE *file_old, *file_new; // Declaração de dois ponteiros para arquivos
    char data[500], data2[500], *id, *compare, count[10], IDHOTEL[5], Name[100], dump; // Declaração de variáveis para armazenar dados
    const char s[2] = " "; // String com o separador de dados

    // Abre o arquivo "HOTEL.txt" em modo leitura
    file_old = fopen("./storage/HOTEL.txt", "r");
    // Abre o arquivo "HOTEL_new.txt" em modo escrita, para criar um novo arquivo com os dados atualizados
    file_new = fopen("./storage/HOTEL_new.txt", "a");
    
    // Verifica se o arquivo "HOTEL.txt" pode ser aberto
    if(file_old == NULL)
    {
        printf("Repositório de HOTEL inacessivel!\n\n\n\n\n");
    }
    else
    {
        /* Cria um novo registro, incrementando o número de registros em 1 */
        // Lê o primeiro registro do arquivo antigo e armazena o número de registros na variável "num"
        fgets(count,500,file_old);
        num=atoi(count)+1; // Converte a string "count" em um número inteiro e adiciona 1
        sprintf(count, "%d\n", num); // Converte o número inteiro em uma string e armazena na variável "count"
        fputs(count,file_new); // Escreve a nova quantidade de registros no arquivo novo

        /* Copia os registros do arquivo antigo para o arquivo novo */
        while( !feof(file_old) ) // Enquanto não chegar ao final do arquivo antigo
        {
            // Lê um registro do arquivo antigo e armazena na variável "data"
            fgets(data,500,file_old);
            // Copia o conteúdo da variável "data" para a variável "data2"
            strncpy(data2, data, sizeof(data));
            // Escreve o conteúdo da variável "data2" no arquivo novo
            fputs(data2, file_new);
        }

        // Fecha o arquivo antigo
        fclose(file_old);

        /* Adiciona um novo registro ao arquivo */
        // Limpa a tela do console
        printf("\e[2J\e[H");
        // Solicita o ID do novo hotel
        printf("\n\nInsira o novo ID do HOTEL: ");
        scanf("%s",IDHOTEL);
        // Solicita a descrição do novo hotel
        printf("Insira a nova descrição para o HOTEL: ");
        scanf("%c", &dump); // Consome o caractere "newline" deixado pelo scanf anterior
        scanf("%[^\n]",Name); // Lê uma linha inteira como entrada, até encontrar um caractere "newline"
        fputs("\n",file_new); // Escreve um caractere "newline" no arquivo novo
        fputs(IDHOTEL ,file_new); // Escreve o ID do novo hotel no arquivo novo
        fputs(" " ,file_new); // Escreve um espaço em branco no arquivo novo
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
    int num; /* variável para armazenar o número de hóteis no arquivo */
    bool isDeleted = false; /* variável para indicar se o hotel foi encontrado e excluído */
    FILE *file_old, *file_new; /* ponteiros de arquivo para o arquivo antigo (a ser lido) e o novo (a ser escrito) */
    char data[500], data2[500], *id, *compare, count[10]; /* variáveis para armazenar dados lidos do arquivo e para manipulação de strings */
    const char s[2] = " "; /* delimitador para a função strtok */

    /* Limpar a tela e exibir a lista de hotéis existentes */
    printf("\e[2J\e[H"); /*CLEAR*/
    listar();

    /* Abrir o arquivo antigo para leitura e o novo para escrita */
    file_old = fopen("./storage/HOTEL.txt", "r");
    file_new = fopen("./storage/HOTEL_new.txt", "a");
    
    /* Verificar se o arquivo antigo foi aberto com sucesso */
    if(file_old == NULL)
    {
        printf("Repositório de Hoteis inacessiveis!\n\n\n\n\n");
    }
    else
    {
        /* Pedir ao usuário que insira o ID do hotel a ser excluído */
        printf("\n\nInserir ID do Hotel a eliminar: ");
        scanf("%s",id);
        
        /* Ler o número de hotéis do arquivo antigo */
        fgets(count,500,file_old);
        num=atoi(count)-1;
        /* Subtrair 1 do número de hotéis e escrevê-lo no arquivo novo */
        sprintf(count, "%d\n", num);
        fputs(count,file_new);

        /* Ler os dados do arquivo antigo linha por linha */
        while( !feof(file_old) )
        {
            fgets(data,500,file_old);
            /* Copiar a linha lida para outra variável para manipulação */
            strncpy(data2, data, sizeof(data));

            /* Obter o ID do hotel na linha atual usando a função strtok */
            compare = strtok(data, s);
            /* Exibir o ID atual e o ID a ser excluído para fins de depuração */
            printf("%s - compare\n %s - id", compare, id);
            /* Se o ID atual for diferente do ID a ser excluído, escrever a linha no arquivo novo */
            if(strcmp(id, compare)!=0)
            {
                printf("\n%s - ignored\n", compare);
                fputs(data2, file_new);
            }
            /* Se o ID atual for igual ao ID a ser excluído, marcar a variável isDeleted como true */
            else
            {
                printf("\n%s - found!\n", compare);
                isDeleted = true;
            }
        }

        /* Fechar os arquivos antigo e novo */
        fclose(file_old);
        fclose(file_new);

        /* Se o hotel foi encontrado e excluído, renomear o arquivo novo como o arquivo antigo e apagar o arquivo antigo */
        if(isDeleted = true)
        {
            /*apagar file_old*/
            remove("./storage/HOTEL.txt");
            /*renomear file_new para HOTEL.txt*/
            rename("./storage/HOTEL_new.txt", "./storage/HOTEL.txt");
        }
        /* Se o hotel não foi encontrado e excluído, apagar o arquivo novo */
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