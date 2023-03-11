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

// Define uma função chamada listar
void listar()
{
    // Limpa a tela do terminal
    printf("\e[2J\e[H");
    // Declara uma variável de arquivo
    FILE *file;
    // Declara uma variável de string com tamanho de 500 caracteres
    char data[500];
    // Imprime um cabeçalho para a tabela de dados
    printf("-------|------------------------|----------\n");
    printf("Numero | codigoHotel | ocupação | codigoTipoQuarto \n");
    printf("-------|-------------|----------|----------\n");
    // Abre o arquivo "QUARTO.txt" em modo leitura
    file = fopen("./storage/QUARTO.txt", "r");
    // Se o arquivo não puder ser aberto, imprime uma mensagem de erro
    if(file == NULL)
    {
        printf("Repositório de quarto inacessivel!\n\n\n\n\n");
    }
    // Caso contrário, lê os dados do arquivo e os imprime na tela
    else
    {
        // Lê a primeira linha do arquivo, que contém o número total de registros
        fgets(data,500,file);
        printf("Número de registos: %s\n", data);
        // Lê o restante do arquivo e imprime cada linha na tela
        do
        {
            fgets(data,500,file);
            printf("%s\n", data);
        }while( !feof(file) ); // Continua lendo até atingir o final do arquivo
        // Fecha o arquivo
        fclose(file);
    }
}

void adicionar()
{
    int num;
    bool isDeleted = false; // Variável para indicar se o registro já foi excluído
    FILE *file_old, *file_new; // Ponteiros para os arquivos antigo e novo
    char data[500], data2[500], *id, *compare, count[10], IDaluno[10], IDuc[10], nota[10], dump;
    const char s[2] = " "; // Delimitador de string

    file_old = fopen("./storage/QUARTO.txt", "r"); // Abre o arquivo antigo para leitura
    file_new = fopen("./storage/quarto_new.txt", "a"); // Cria um novo arquivo para escrita

    if(file_old == NULL) // Verifica se o arquivo antigo foi aberto corretamente
    {
        printf("Repositório de quarto inacessivel!\n\n\n\n\n"); // Imprime uma mensagem de erro
    }
    else
    {
        /* Incrementa o número de registros */
        fgets(count,500,file_old); // Lê a primeira linha do arquivo antigo (que contém o número de registros)
        num=atoi(count)+1; // Converte o número de registros para inteiro e adiciona 1
        sprintf(count, "%d\n", num); // Converte o novo número de registros de volta para string
        fputs(count,file_new); // Escreve o novo número de registros no arquivo novo

        /* Copia os registros do arquivo antigo para o novo */
        while( !feof(file_old) ) // Enquanto não atingir o final do arquivo antigo
        {
            fgets(data,500,file_old); // Lê uma linha do arquivo antigo
            strncpy(data2, data, sizeof(data)); // Copia a linha para uma nova variável de string
            fputs(data2, file_new); // Escreve a linha no arquivo novo
        }

        fclose(file_old); // Fecha o arquivo antigo

        /* Lê as informações do novo registro e escreve no arquivo novo */
        printf("\e[2J\e[H"); // Limpa a tela do console
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

        fclose(file_new); // Fecha o arquivo novo

        /*apagar file_old*/
        remove("./storage/quarto.txt"); // Exclui o arquivo antigo
        /*renomear file_new para curso.txt*/
        rename("./storage/quarto_new.txt", "./storage/quarto.txt");  // Renomeia o arquivo novo para o nome do arquivo antigo 
    }
}

void eliminar()
{
    int num, i=0;
    bool isDeleted = false; // Variável booleana que será usada para saber se o registro foi excluído com sucesso
    FILE *file_old, *file_new; // Ponteiros para os arquivos que serão manipulados
    char data[500], data2[500], data3[500], *compare1, *compare2, count[10]; // Variáveis de caracteres que serão usadas para armazenar dados dos arquivos
    char idA[50], id[50]; // Variáveis de caracteres para armazenar os IDs do cliente e do hotel que serão excluídos
    const char s[2] = " "; // Caractere de separação de dados, que será usado para separar as informações no arquivo

    printf("\e[2J\e[H"); /*CLEAR*/
    listar(); // Exibe a lista de hotéis disponíveis

    file_old = fopen("./storage/QUARTO.txt", "r"); // Abre o arquivo de registro dos hotéis
    file_new = fopen("./storage/QUARTO_new.txt", "a"); // Abre um novo arquivo que será usado para armazenar os dados excluídos

    if(file_old == NULL) // Verifica se o arquivo de registro dos hotéis está acessível
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
        fgets(count,500,file_old); // Lê a primeira linha do arquivo, que contém o número de registros
        num=atoi(count)-1; // Converte a string para um número inteiro e subtrai 1, já que um registro será excluído
        sprintf(count, "%d\n", num); // Converte o número inteiro de volta para uma string
        fputs(count,file_new); // Escreve a nova quantidade de registros no novo arquivo
        /*Counter Updater*/

        while( !feof(file_old) ) // Loop que percorre todo o arquivo de registro dos hotéis
        {
            fgets(data,500,file_old); // Lê uma linha do arquivo de registro dos hotéis
            strncpy(data2, data, sizeof(data)); // Copia a linha lida para uma nova variável que será usada para escrever no arquivo de destino
            
            compare1 = strtok(data, s); // Separa a primeira parte da linha (ID do cliente) usando o caractere de separação definido anteriormente
            compare2 = strtok(NULL, s); // Separa a segunda parte da linha (ID do hotel) usando o caractere de separação definido anteriormente

            printf("Variável 'compare1': %s\n",compare1); // Exibe o valor da variável compare1 (ID do cliente)
            printf("Variável 'idA': %s\n",idA); // Exibe o valor da variável idA (ID do cliente que será excluído)
            printf("Variável 'compare2': %s\n",compare2); // Exibe o valor da variável compare2 (ID do hotel)
            printf("Variável 'id': %s\n",id); // Exibe o valor da variável id (ID do hotel que será excluído)

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
    int num; // variável para armazenar números
    bool isEdited = false; // flag para indicar se o registro foi editado
    FILE *file_old, *file_new; // ponteiros de arquivo para o arquivo antigo e novo
    char data[500], data2[500], *id, *compare, count[10], IDquarto[5], Name[100], dump; // arrays de caracteres para armazenar informações lidas do arquivo e do usuário, ponteiros para comparar IDs e um caractere dummy
    const char s[2] = " "; // delimitador para a função strtok()

    printf("\e[2J\e[H"); // limpa a tela
    listar(); // exibe a lista de registros
    file_old = fopen("./storage/HOTEL.txt", "r"); // abre o arquivo antigo no modo leitura
    file_new = fopen("./storage/HOTEL_new.txt", "a"); // abre o arquivo novo no modo acrescentar
    if(file_old == NULL) // verifica se o arquivo antigo não pode ser aberto
    {
        printf("Repositório de hoteis inacessivel!\n\n\n\n\n"); // exibe uma mensagem de erro
    }
    else
    {
        printf("\n\nInserir ID do hoteis a editar: "); // solicita ao usuário o ID do registro a ser editado
        scanf("%s",id); // lê o ID do usuário
        
        /* salta a primeira linha do documento - contagem - e escreve-a no novo registo*/
        fgets(count,500,file_old); // lê a primeira linha do arquivo antigo
        fputs(count,file_new); // escreve a contagem no arquivo novo

        while( !feof(file_old) ) // enquanto não for o final do arquivo antigo
        {
            fgets(data,500,file_old); // lê uma linha do arquivo antigo
            strncpy(data2, data, sizeof(data)); // faz uma cópia da linha lida

            compare = strtok(data, s); // divide a linha em substrings usando o delimitador
            printf("%s - compare\n%s - id", compare, id); // exibe as substrings comparadas
            if(strcmp(id, compare)!=0) // compara o ID do usuário com o ID do registro atual
            {
                printf("\n%s - not a match, ignoring\n", compare); // se não houver correspondência, exibe uma mensagem de ignorado
                fputs(data2, file_new); // escreve a linha no arquivo novo
            }
            else // se houver correspondência
            {
                printf("\n%s - MATCH FOUND!\n", compare); // exibe uma mensagem de correspondência
                printf("\e[2J\e[H"); // limpa a tela
                printf("Valores anteriores: \n");
                printf("%s",data2); // exibe os valores atuais do registro
                printf("\n\nInsira o novo ID do hoteis: ");
                scanf("%s",IDquarto); // lê o novo ID do usuário
                printf("Insira a nova descrição para o hotel: ");
                scanf("%c", &dump); // lê o caractere dummy para limpar o buffer do teclado
                scanf("%[^\n]",Name); // lê a nova descrição do usuário
                fputs(IDquarto ,file_new); // escreve o novo ID no arquivo novo
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