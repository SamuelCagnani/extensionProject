#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include "struct.h"

int main() {

    Lista agenda; //criação da lista agenda
    agenda.inicio = NULL; //ponteiro inicio de agenda aponta para NULL
    agenda.tamanho = 0; //atribuindo 0 para o int tamanho da lista agenda

    int opcao, valor;

    do {
        printf("1 - Inserir no inicio\n");
        printf("2 - Imprimir\n");
        printf("3 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            scanf("%d", &valor);
            inserirInicio(&agenda, valor);
            break;
        case 2:
            imprimirLista(&agenda);
            break;
        case 3:
        printf("Saindo...");
            break;
        default:
            break;
        }  
    } while (opcao != 3);
    
    return 0;
}