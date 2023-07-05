#include <stdio.h>
#include <stdlib.h>

int questao1() {

    float n1 = 0;
    float n2 = 0;
    float n3 = 0;
    float n4 = 0; 
    float media = 0;

    printf("\nInforme a primeira nota:");
    scanf("%f", &n1);

    printf("\nInforme a segunda nota:");
    scanf("%f", &n2);

    printf("\nInforme a terceira nota:");
    scanf("%f", &n3);

    printf("\nInforme a quarta nota:");
    scanf("%f", &n4);

    printf("\nNota 1: %.2f \nNota 2: %.2f \nNota 3: %.2f \nNota 4: %.2f", n1, n2, n3, n4);

    media = (n1 + (n2*2) + (n3*3) + (n4*4)) / 10;

    printf("\n\nMedia: %.1f", media);

    printf("\n\n\n\n");

    return 0;

}

int questao2() {

    int n1 = 0;
    int n2 = 0;
    int i = 0;


    do
    {
        printf("Informe o menor numero:");
        scanf("%d", &n1);

        printf("Informe o maior numero:");
        scanf("%d", &n2);

    } while (n1 > n2);

    if(n1 == n2) {

        printf("Não existe intervalo entre números iguais.");

    } else {

    for(i = n1; i <= n2; i++) {

        if(i % 2 == 0) {

            printf("\n%d -------> %d", i, i * i);

        } else if(i % 2 == 1) {

            printf("\n%d -------> %d", i, i * i * i);
        }

    }
    printf("\n\n\n\n");


    }

    return 0;

}


int questao3() {

    int n = 0;
    int i = 0;
    float s = 0;
    
    printf("\nDigite um valor para N: ");
    scanf("%d", &n);
    
    for(i = n; i >= 1; i--) {
        
        s = s + (1.0 * i);
    }

    printf("\nO valor de S eh: %.2f\n", s);

    printf("\n\n\n\n");
    
    return 0;

}

int main() {

    int opcao = 0;

    do
    {
        printf("MENU\n");
        printf("1 - Exercicio 1\n");
        printf("2 - Exercicio 2\n");
        printf("3 - Exercicio 3\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao:");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
            questao1();
            break;

            case 2:
            questao2();
            break;
        
            case 3:
            questao3();
            break;
        
            case 0:
            printf("Saindo...\n");
            break;
        
            default:
            break;
        }


    } while (opcao != 0);

    return 0;
    
}