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
//Funcao para inserir um contato ao final da lista
void inserirFim (Lista *lista, Contato *novoContato){

    if(lista->inicio == NULL){

        printf("A lista está vazia! Não há possibilidades para inserir um contato no fim da lista.\n");
        return;
    }
    else{

        Contato *p;
        p = lista->inicio; 

        while ((p->proximo) != NULL){
                p = p->proximo;
        }
        p->proximo = novoContato;
        lista->tamanho++;

    }
    
} 

Contato * inserirNovoContato ( ) {
   
    Contato *novoContato = (Contato*) malloc(sizeof(Contato));
    novoContato->proximo = NULL;

    printf("Digite o nome do contato: ");
    scanf("%s", novoContato->nome);
    printf("Digite o email do contato: ");
    scanf("%s", novoContato-> email);
    printf("Digite o nome da rua: ");
    scanf("%s", novoContato->endereco.rua);
    printf("Digite o numero da casa: ");
    scanf("%d", &novoContato->endereco.numero);
    printf("Digite o nome do bairro: ");
    scanf("%s", novoContato->endereco.bairro);
    printf("Digite o nome da cidade: ");
    scanf("%s", novoContato->endereco.cidade);
    printf("Digite o ddd do seu telefone [xx]: ");
    scanf("%s", novoContato->telefone[0].ddd);
    printf("Digite o numero do seu telefone: ");
    scanf("%s", novoContato->telefone[0].numero);
    printf("Digite o ddd do seu celular [xx]: ");
    scanf("%s", novoContato->telefone[1].ddd);
    printf("Digite o numero do seu celular: ");
    scanf("%s", novoContato->telefone[1].numero);

    return novoContato;
}

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

