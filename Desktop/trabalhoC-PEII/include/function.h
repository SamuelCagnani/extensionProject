#ifndef _FUNCTION_H
#define _FUNCTION_H

typedef struct {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int tamanho; 
} Lista;

void inserirInicio(Lista, int);
void imprimirLista(Lista);

#endif