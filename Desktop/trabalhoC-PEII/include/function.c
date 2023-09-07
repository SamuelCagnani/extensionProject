#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "function.h"

void inserirInicio(Lista *agenda, int valor) { //função que recebe um ponteiro para uma lista agenda e um valor inteiro
    No *novoNo = (No *) malloc(sizeof(No));    //ponteiro do tipo nó que recebe um endereço reservado de memoria do tamanho de um nó
    novoNo->valor = valor;  //altera o valor do nó que esta sendo apontado
    novoNo->proximo = agenda->inicio; //ponteiro proximo do novo nó recebe o endereço da agenda inicio
    agenda->inicio = novoNo;
    agenda->tamanho++;
}

void imprimirLista(Lista *agenda) {
    No *inicio = agenda->inicio;
    while (inicio != NULL) {
        printf("%d\n", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}