#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "function.h"
#include "struct.h"

//Funcao para inserir os contatos inicializados (na main) na lista
Contato * inserirContatoEstatico (char nome[], char email[], int numero_casa, char bairro[], char rua[], char cidade[], char dddTelefone[], char telefone[], char dddCelular[], char celular[]) {
   
    Contato * novoContato = (Contato*) malloc(sizeof(Contato));
    novoContato->proximo = NULL;

    strcpy(novoContato->nome, nome);
    strcpy(novoContato->email, email);
    novoContato->endereco.numero = numero_casa;
    strcpy(novoContato->endereco.bairro, bairro);
    strcpy(novoContato->endereco.rua, rua);
    strcpy(novoContato->endereco.cidade, cidade);
    strcpy(novoContato->telefone[0].ddd, dddTelefone);
    strcpy(novoContato->telefone[0].numero, telefone);
    strcpy(novoContato->telefone[1].ddd, dddCelular);
    strcpy(novoContato->telefone[1].numero, celular);

    return novoContato;
}

void inserirInicio (Lista *lista, Contato *novoContato) {
    
    Contato *p = novoContato;
    p->proximo = lista->inicio;
    lista->inicio = p;
    lista->tamanho++;

}
/*void inserirFim (Lista *lista){

    Contato *p;
    p = lista->inicio; 

    while ((p->proximo) != NULL){
            p = p->proximo;
    }
} */

void imprimirLista(Lista *lista) {
    
    int cont = 0;
    Contato *p;
    p = lista->inicio;

    //Tratar p/ quando a lista for vazia
    while(p->proximo != NULL) {
        cont++;
        printf("Contato %d\n", cont);
        printf("-----------------------\n");
        printf("Nome: %s\n", p->nome);
        printf("Email: %s\n", p->email);
        printf("Rua %s, %d - %s - %s\n", p->endereco.rua, p->endereco.numero,p->endereco.bairro, p->endereco.cidade);
        printf("Telefone fixo: [%s] %s\n", p->telefone[0].ddd, p->telefone[0].numero);
        printf("Telefone celular: [%s] %s\n", p->telefone[1].ddd, p->telefone[1].numero);
        printf("-----------------------\n");
        p = p->proximo;
    }
    if(p->proximo == NULL){
        cont++;
        printf("Contato %d\n", cont);
        printf("-----------------------\n");
        printf("Nome: %s\n", p->nome);
        printf("Email: %s\n", p->email);
        printf("Rua %s, %d - %s - %s\n", p->endereco.rua, p->endereco.numero,p->endereco.bairro, p->endereco.cidade);
        printf("Telefone fixo: [%s] %s\n", p->telefone[0].ddd, p->telefone[0].numero);
        printf("Telefone celular: [%s] %s\n", p->telefone[1].ddd, p->telefone[1].numero);
        printf("-----------------------\n");

    }


}

