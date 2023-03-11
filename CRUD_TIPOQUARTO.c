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
    printf("OPERAÇÕES CRUD: HOTEL\n");
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
            repeat_list: // Marcador para o goto
            listar();
            printf("\nSelecione uma operação. Deverá inserir o numero correspondente à opção pretendida:\n");
            printf("1- Voltar\n\n");
            printf("Opção selecionada?   ");
            scanf("%d",&submenu);
            switch(submenu)
            {
                case 1:
                    goto boot; // Retorna ao início do programa
                    break;
                default:
                    goto repeat_list; // Retorna ao marcador repeat_list
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
    // Declaração de variáveis
    FILE *file;
    char data[500];
    int i=0, count=0;

    // Limpa a tela e imprime cabeçalho da tabela
    printf("\e[2J\e[H");
    printf("---|--------|------------\n");
    printf("ID | Preço  | Descrição\n");
    printf("---|--------|------------\n");

    // Abre o arquivo de armazenamento dos registros de quartos para leitura
    file = fopen("./storage/TIPOQUARTO.txt", "r");

    // Verifica se o arquivo foi aberto corretamente
    if(file == NULL)
    {
        printf("Repositório de HOTELs inacessivel!\n\n\n\n\n");
    }
    else
    {
        // Obtem o total de registros do arquivo
        fscanf(file, "%d", &count);

        // Loop para imprimir todos os registros
        do
        {
            fgets(data,500,file); // Lê uma linha do arquivo
            printf("%s\n", data); // Imprime a linha na tela
            i++; // Incrementa o contador de registros
        }while( i <= count );

        // Fecha o arquivo
        fclose(file);
    }
}

void adicionar()
{
    int num; // contador
    bool isDeleted = false; // variável booleana para indicar se o registro foi excluído
    FILE *file_old, *file_new; // ponteiros de arquivo
    char data[500], data2[500], *id, *compare, count[10], IDgrupohot[5], Name[100], dump; // variáveis para manipular dados
    const char s[2] = " "; // separador de campos

    // abrir arquivo existente em modo leitura
    file_old = fopen("./storage/TIPOQUARTO.txt", "r");

    // abrir novo arquivo em modo anexar
    file_new = fopen("./storage/TIPOQUARTO_new.txt", "a");
    
    // verificar se o arquivo existe
    if(file_old == NULL)
    {
        printf("Repositório de HOTEL inacessivel!\n\n\n\n\n");
    }
    else
    {
        /* */
        // ler o primeiro campo do arquivo existente (que é um contador)
        fgets(count,500,file_old);
        // converter para inteiro e incrementar
        num=atoi(count)+1;
        // converter novamente para string e armazenar no contador
        sprintf(count, "%d\n", num);
        // escrever o novo contador no novo arquivo
        fputs(count,file_new);
        /* */

        // percorrer o restante do arquivo existente
        while( !feof(file_old) )
        {
            // ler uma linha do arquivo existente
            fgets(data,500,file_old);
            // copiar para outra variável para não alterar a original
            strncpy(data2, data, sizeof(data));
            // escrever a linha no novo arquivo
            fputs(data2, file_new);
        }

        // fechar o arquivo existente
        fclose(file_old);

        // limpar a tela
        printf("\e[2J\e[H");
        // solicitar o novo ID do TipoQuarto
        printf("\n\nInsira o novo ID do Tipo de Quarto: ");
        scanf("%s",IDgrupohot);
        // solicitar a nova descrição do TipoQuarto
        printf("Insira a nova descrição para o Tipo de Quato: ");
        scanf("%c", &dump);
        scanf("%[^\n]",Name);
        // escrever os dados do novo registro no novo arquivo
        fputs("\n",file_new);
        fputs(IDgrupohot ,file_new);
        fputs(" " ,file_new);
        fputs(Name,file_new);      

        // fechar o novo arquivo
        fclose(file_new);

        /*apagar file_old*/
        // excluir o arquivo existente
        remove("./storage/TIPOQUARTO.txt");
        /*renomear file_new para TIPOQUARTO.txt*/
        // renomear o novo arquivo para o nome do arquivo existente
        rename("./storage/TIPOQUARTO_new.txt", "./storage/TIPOQUARTO.txt"); 
    }
}

void eliminar()
{
    int num;
    bool isDeleted = false; // Variável booleana para verificar se o TipoQuarto foi eliminado com sucesso
    FILE *file_old, *file_new; // Ponteiros para os ficheiros a serem utilizados
    char data[500], data2[500], *id, *compare, count[10]; // Variáveis para guardar dados lidos dos ficheiros e contadores
    const char s[2] = " "; // Delimitador para separar os campos dos dados lidos

    printf("\e[2J\e[H"); /*CLEAR*/ // Limpa a tela do terminal
    listar(); // Lista todos os hotéis registados
    /* */
    file_old = fopen("./storage/TIPOQUARTO.txt", "r"); // Abre o ficheiro de hotéis registados
    file_new = fopen("./storage/TIPOQUARTO_new.txt", "a"); // Cria um novo ficheiro temporário para escrever os hotéis

    if(file_old == NULL) // Verifica se o ficheiro de hotéis existe
    {
        printf("Repositório de Hoteis inacessiveis!\n\n\n\n\n");
    }
    else
    {
        printf("\n\nInserir ID do TipoQuarto a eliminar: "); // Pede o ID do TipoQuarto a eliminar
        scanf("%s",id); // Lê o ID do TipoQuarto

        /* */
        fgets(count,500,file_old); // Lê a primeira linha do ficheiro que contém o número de hotéis registados
        num=atoi(count)-1; // Converte o número de hotéis para um inteiro e subtrai 1
        sprintf(count, "%d\n", num); // Converte o novo número de hotéis para uma string
        fputs(count,file_new); // Escreve o novo número de hotéis no ficheiro temporário
        /* */

        while( !feof(file_old) ) // Enquanto não chegar ao fim do ficheiro
        {
            fgets(data,500,file_old); // Lê uma linha do ficheiro de hotéis
            strncpy(data2, data, sizeof(data)); // Copia a linha para outra variável para escrever no ficheiro temporário

            compare = strtok(data, s); // Separa o ID do TipoQuarto da linha lida
            printf("%s - compare\n %s - id", compare, id); // Imprime o ID do TipoQuarto a eliminar e o ID lido do ficheiro
            if(strcmp(id, compare)!=0) // Verifica se os IDs são diferentes
            {
                printf("\n%s - ignored\n", compare); // Imprime que o TipoQuarto não é o que se pretende eliminar
                fputs(data2, file_new); // Escreve a linha no ficheiro temporário
            }
            else
            {
                printf("\n%s - found!\n", compare); // Imprime que o TipoQuarto foi encontrado
                isDeleted = true; // Sinaliza que o TipoQuarto foi eliminado com sucesso
            }
        }

        fclose(file_old); // Fecha o ficheiro de hotéis
        fclose(file_new); // Fecha o ficheiro temporário

        if(isDeleted = true) // Verifica se o TipoQuarto foi eliminado com sucesso
        {
            /*apagar file_old*/
            remove("./storage/TIPOQUARTO.txt"); // Apaga o ficheiro de hotéis
            /*renomear file_new para TIPOQUARTO.txt*/
            rename("./storage/TIPOQUARTO_new.txt", "./storage/TIPOQUARTO.txt");
        }
        else
        {
            /* apagar file_new*/
            remove("./storage/TIPOQUARTO_new.txt");
        }
    }
}

void editar()
{
    int num;
    bool isEdited = false; // variável booleana que indica se algum registro foi editado
    FILE *file_old, *file_new; // ponteiros de arquivo para o arquivo original e o novo arquivo
    char data[500], data2[500], *id, *compare, count[10], IDgrupohot[5], Name[100], dump;
    // variáveis de caractere para armazenar dados, um ponteiro de caractere para armazenar o ID do TipoQuarto a ser editado,
    // uma variável de caractere para armazenar os valores antigos e novos, e uma variável de caractere de descarte para limpar o buffer
    const char s[2] = " "; // caractere de espaço usado para separar os campos no arquivo

    printf("\e[2J\e[H"); // limpa a tela
    listar(); // chama a função listar() para mostrar os registros atuais
    file_old = fopen("./bin/TIPOQUARTO.txt", "r"); // abre o arquivo original no modo leitura
    file_new = fopen("./storage/TIPOQUARTO_new.txt", "a"); // cria o novo arquivo no modo adição

    if(file_old == NULL) // verifica se o arquivo original pode ser aberto
    {
        printf("Repositório de Hotel inacessivel!\n\n\n\n\n"); // mensagem de erro se o arquivo não pode ser aberto
    }
    else
    {
        printf("\n\nInserir ID do TipoQuarto a editar: ");
        scanf("%s",id); // lê o ID do TipoQuarto a ser editado

        /* salta a primeira linha do documento - contagem - e escreve-a no novo registo*/
        fgets(count,500,file_old); // lê a primeira linha do arquivo original que contém o número de registros
        fputs(count,file_new); // escreve a mesma linha no novo arquivo

        while( !feof(file_old) ) // loop para ler todos os registros do arquivo original
        {
            fgets(data,500,file_old); // lê uma linha do arquivo original
            strncpy(data2, data, sizeof(data)); // copia a linha lida para a variável de valores antigos

            compare = strtok(data, s); // separa a linha lida em campos usando o caractere de espaço e armazena o primeiro campo (ID do TipoQuarto)
            printf("%s - compare\n%s - id", compare, id);
            if(strcmp(id, compare)!=0) // compara o ID do TipoQuarto lido com o ID do TipoQuarto a ser editado
            {
                printf("\n%s - not a match, ignoring\n", compare);
                fputs(data2, file_new); // se não for o ID do TipoQuarto a ser editado, escreve a linha inteira no novo arquivo
            }
            else
            {
                printf("\n%s - MATCH FOUND!\n", compare); // se for o ID do TipoQuarto a ser editado, exibe uma mensagem
                printf("\e[2J\e[H"); // limpa a tela
                printf("Valores anteriores: \n");
                printf("%s",data2); // exibe os valores antigos
                printf("\n\nInsira o novo ID do TipoQuarto: ");
                scanf("%s",IDgrupohot); // lê o novo ID do TipoQuarto
                printf("Insira a nova descrição para o TipoQuarto: ");
                scanf("%c", &dump);
                scanf("%[^\n]",Name);
                fputs(IDgrupohot ,file_new);
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
            remove("./storage/TIPOQUARTO.txt");
            /*renomear file_new para TIPOQUARTO.txt*/
            rename("./storage/TIPOQUARTO_new.txt", "./storage/TIPOQUARTO.txt");
        }
        else
        {
            /* apagar file_new*/
            remove("./storage/TIPOQUARTO_new.txt");
        }
    }
}