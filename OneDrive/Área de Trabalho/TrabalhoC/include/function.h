#ifndef FUNCTION_H
#define FUNCTION_H
#include "struct.h"

Contato * inserirContatoEstatico (char nome[MAX_NOME], char email[MAX_EMAIL], int numero_casa, char bairro[MAX_BAIRRO], char rua[MAX_RUA], char cidade[MAX_CIDADE], char dddTelefone[MAX_DDD], char telefone[MAX_TELEFONE], char dddCelular[MAX_DDD], char celular[MAX_TELEFONE]);
void inserirInicio (Lista *lista, Contato *novoContato);
void imprimirLista(Lista *lista);
Contato * inserirNovoContato ( );
void inserirFim (Lista *lista, Contato *novoContato);


#endif

// Retirar as diretivas dos parâmetros na assinatura das funções (ex. char nome[MAX_NOME] --> char [])

// O mesmo vale para as outras assinaturas (ex. Lista * lista --> Lista *)

// Depois de retirar as diretivas pode remover a inclusão da "struct.h"