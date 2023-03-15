#include <stdbool.h>

typedef struct 
{
    int nif;
    char nome[40];
    char apelido[40];
    char email[40];
    int n_tele;
    char genero[10];
    char cidade[40];
    char pais[40];  
} Clientes ;

typedef struct 
{
    int numero;
    int codigoHotel;
    int ocupacao;
    int codigoTipoQuarto;
} Quartos ;

typedef struct 
{
    int codigo;
    int nifGrupoHoteleiro;
    int estrelas;
    char nome[100];
    char cidade[40];
    char pais[40];
    
} Hoteis ;

typedef struct 
{
    int nif;
    char nome[40];
    
} GrupoHoteleiro ;

typedef struct 
{
    int codigo;
    int preco;
    char descricao;
    
} TipoQuartos ;

typedef struct 
{
    int id;
    int nifClientes;
    int numeroQuarto;
    int codigoHotel;
    int numeroAdultos;
    //int numeroCriancas;
    int dataEntrada;
    int dataSaida;
    
} Reservas ;
