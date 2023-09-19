#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/struct.h"
#include "../include/function.h"

#define listaEstatica 1

int main(){
    //criacao de uma agenda para iniciar a lista
    Lista lista;
    lista.inicio = NULL;
    lista.tamanho = 0;

    //Insercao manual de 10 contatos para maior eficiencia nos testes
    char nome[10][MAX_NOME] = {"Carol", "Samuel", "Ricardo", "Karen", "Ruben", "Karina", "Otavio", "Benicio", "Osmar", "Maria"};
    char email[10][MAX_EMAIL] = {"anacolfuentes@hotmail.com", "samuelcagnani@gmail.com", "ricardoramos@gmai.com", "karencristina@gmai.com", "rubenfuentes@gmai.com", "karinagarcia@gmai.com", "otaviohenrique@gmai.com", "beniciogarcia@gmai.com", "mariagarcia@gmai.com"};
    int numero_casa[10] = {11, 165, 166, 89, 12, 65, 28, 30, 98, 87};
    char bairro[10][MAX_BAIRRO] = {"Itamaraty", "JdEuropa", "JddosEstados", "PqPrimavera", "Centro", "PqPinheiros", "AvWenceslau", "Itamaraty", "CamposElisios", "SantaAngela"};
    char rua[10][MAX_RUA] = {"sebastiao", "Joao", "Joao", "Grande", "Paqueta", "AssisFigueiredo", "Pernambuco", "SantaCatarina", "SaoPaulo", "RiodeJaneiro"};
    char cidade[10][MAX_CIDADE] = {"SaoPaulo", "RiodeJaneiro", "PocosdeCaldas", "Alfenas", "Andradas", "PousoAlegre", "Inconfidentes", "Machado", "Pocosdealdas", "Machado"};
    char dddTelefone[10][MAX_DDD] = {"09", "78", "35", "98", "12", "45", "91", "87", "35", "18"};
    char telefone[10][MAX_NUMERO] = {"08765435", "12345678", "98765432","00000000", "78906543", "25346781", "45698235", "65321498", "87569235", "96857412"};
    char dddCelular[10][MAX_DDD] = {"09", "78", "35", "98", "12", "45", "91", "87", "35", "18"};
    char celular[10][MAX_NUMERO] = {"12345678", "14523688", "89456287", "96857412", "96857412", "98362715", "15038924", "74586325", "35698521", "58432695"};

    if(listaEstatica == 1){
        for(int i=0; i<10; i++){
            Contato * p = inserirContatoEstatico(nome[i], email[i], numero_casa[i], bairro[i], rua[i], cidade[i], dddTelefone[i], telefone[i], dddCelular[i], celular[i]);
            inserirInicio(&lista, p);
        }
        imprimirLista(&lista);
    }

    return 0;
}