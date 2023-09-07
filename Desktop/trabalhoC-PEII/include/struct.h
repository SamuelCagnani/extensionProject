#ifndef _STRUCT_H
#define _STRUCT_H

#define MAX_LEN_RUA 50
#define MAX_LEN_BAIRRO 50
#define MAX_LEN_CIDADE 50
#define MAX_LEN_DDD 2
#define MAX_LEN_NUMERO 9
#define MAX_LEN_NOME 50
#define MAX_LEN_EMAIL 30
#define MAX_LEN_TELEFONE 2

typedef struct {
    int numero;
    char rua[MAX_LEN_RUA];
    char bairro[MAX_LEN_BAIRRO];
    char cidade[MAX_LEN_CIDADE];
} Endereco;

typedef struct {
    char ddd[MAX_LEN_DDD];
    char numero[MAX_LEN_NUMERO];
} Telefone;

typedef struct {
    char nome[MAX_LEN_NOME];
    char email[MAX_LEN_EMAIL];
    Endereco endereco;
    Telefone telefone[MAX_LEN_TELEFONE];
} Contato;

#endif