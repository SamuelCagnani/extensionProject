#ifndef STRUCTS_H
#define STRUCTS_H
#include <string.h>

// Definicao global do tamanho dos arrays
#define MAX_RUA 50
#define MAX_BAIRRO 50
#define MAX_CIDADE 50
#define MAX_DDD 2
#define MAX_NUMERO 9
#define MAX_NOME 50
#define MAX_EMAIL 30
#define MAX_TELEFONE 2

// Criacao de uma struct endereco
typedef struct {
    char rua[MAX_RUA];
    char bairro[MAX_BAIRRO];
    char cidade[MAX_CIDADE];
    int numero;
} Endereco;

// Criacao de uma struct telefone
typedef struct {
    char ddd[MAX_DDD];
    char numero[MAX_NUMERO];
} Telefone;

// Criacao de uma struct contato
typedef struct contato{
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    Endereco endereco;
    Telefone telefone[MAX_TELEFONE];
    struct contato *proximo;
} Contato;

// Criacao de uma struct agenda
typedef struct{
    int tamanho; // variavel para definir o tamanho da agenda
    Contato *inicio; // campo que vai apontar para o endereco do proximo contato da agenda
} Lista;

#endif