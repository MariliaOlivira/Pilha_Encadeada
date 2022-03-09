
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilha.h"


void startStack(stack *entrada){
    // O topo sempre deve apontar para nulo como próximo elemento
    entrada -> topo = NULL;
}

void push(int dado, stack *entrada){

    // fazendo a alocação do novo nó
    no *aux = (no*)malloc(sizeof(no));

    if(aux ==  NULL){

        printf("\033[31mOps! ouve um erro\n");
        printf("\033[37m");

        return 0;

    }else{

        // Minha variavel auxiliar vai apontar para o dado a ser empilhado
        aux->dado = dado;

        // ele precisa apontar para o atual para que ele seja o novo topo
        aux->next = entrada->topo;
        // declaração do topo.
        entrada->topo = aux;

    }
}

int pop(stack *entrada){

    no* aux = entrada->topo;

    int dado;

    if(aux == NULL){

        printf("\033[31mOps! Tente adicionar um item para poder retiralo primeiro\n");
        printf("\033[37m");

    }else{
        entrada->topo = aux->next;
        // fazendo a retirada do item.
        aux->next = NULL;
        dado = aux->dado;
        free(aux);
        return dado;
    }

}

void show(stack *entrada){

    no *aux = entrada->topo;

    if(aux == NULL){

        printf("\033[31mOps!Ops! Nada pra mostrar a pilha está vazia\n");
        printf("\033[37m");

        return;

    }else{

        printf("\033[33mPrévia da sua pilha:\n");
        printf("\033[37m");

        while(aux != NULL){
            
            printf("\033[36m{%d}", aux->dado);
            
            aux = aux-> next;
            
            printf("\n");
        }
        
        printf("\033[37m");
    }
}


void chamadaPush(times, numero, ponteiro){

        printf("\033[35mQuantos empilhamentos? ");
        scanf("%d", &times);

        for (int i = 0; i < times; i++)
        {
            printf("\033[34m° Digite um numero: ");
            printf("\033[37m");

            fflush(stdin);
            scanf("%d", &numero);

            push(numero, ponteiro);
            show(ponteiro);
            chamadaTopo(ponteiro);
        }

}


void chamadaPop(times, numero, ponteiro){

    printf("\033[34mQuantos desempilhamentos? ");
    printf("\033[37m");

    scanf("%d", &times);

    for (int i = 0; i < times; i++)
    {

        printf("\033[34m° Aperte 1 para continuar:");
        printf("\033[37m");

        scanf("%d", &numero);

        pop(ponteiro);
        show(ponteiro);
    }
}

// Verificando se a lista está vazia.
int pilhaVazia(stack* pilha)
{

    return pilha->topo == NULL;

}


void chamadaTopo(stack *entrada){


    no *aux = entrada->topo->dado;

    if(aux == NULL){

        printf("\033[31mOps! Nada pra mostrar a pilha está vazia\n");
        printf("\033[37m");

        return;

    }else{

        printf("\033[33mO topo da sua pilha é --> {%d}\n", entrada->topo->dado);
        printf("\033[37m");

    }
}

void chamadaMenu(){
    printf("\n\n");
    printf("\t\033[33m                    (: <------> OLÁ <------> :)\n\n");
    printf("\t-------------------------------------------------------------------\n");
    printf("\t| Escolha uma opção adequada para a correta utilização da sua pilha|\n");
    printf("\t| --> Digite {1} para empilhar e {2} para desempilhar              |\n");
    printf("\t| --> Digite {3} para mostrar o topo                               |\n");
    printf("\t| --> Uma prévia da sua pilha é mostrada automáticamente           |\n");
    printf("\t| --> Caso deseje consultar o menu novamente digite {4}            |\n");
    printf("\t| --> Encerre a execução apertando {5}                             |\n");
    printf("\t-------------------------------------------------------------------\n\n");
    printf("\t                (; <------> Bom uso <--------> ;)\n\n");
    printf("\033[37m");

}
void chamadaDeBreak(stack* ponteiro){

    int opcion, times, numero;

    printf("\n\n");
    printf("\t\t\t\033[34m): <------> Já vai? <-------> :(\n");
    printf("\033[37m");
    printf(" --> Se não for o seu dejeso finalizar a execução digite {1} <---\n");
    printf(" --> caso contrário digite 0: ");

    scanf("%d", &opcion);

    if (opcion == 1)
    {

        printf("\n\n");
        printf(" \t\t\033[33m<------> Ok! Vou te mostrar novamente o menu! <------>");
        printf("\033[37m");

        chamadaMenu();

        pilha(times, numero, ponteiro);

    }else{

        exit(0);

    }
    
}

void pilha(times, numero, ponteiro){

    int opcion;


    do{    

        printf("\033[34m --> Escolha sua opção: ");
        printf("\033[37m");

        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:

            chamadaPush(times, numero, ponteiro);

            break;

        case 2:

            if (pilhaVazia(ponteiro))
            {

                printf("\033[31mOps! Sua pilha está vazia ;)\n");
                printf("\033[37m");

            }else{

                chamadaPop(times, numero, ponteiro);
            }

            break;
        case 3:
            if (pilhaVazia(ponteiro))
            {

                printf("\033[31mOps! Sua pilha está vazia ;)\n");
                printf("\033[37m");

            }else{

                chamadaTopo(ponteiro);

            }
            break;
        case 4:

            chamadaMenu();

            break;

        case 5:

            chamadaDeBreak(ponteiro);

            break;

        default:

            printf("\t\t\033[31m ------ Selecione uma opção válida --------\n");
            printf("\033[37m");

            break;
        }
    } while (opcion != 5);
}

void main(){

    // Para evitar erros com o UTF-8 uso a biblioteca locale.h
    setlocale(LC_ALL, "Portuguese");

    int numero, times;
    stack *ponteiro = (stack*)malloc(sizeof(stack));

    if(ponteiro == NULL){

        printf("\033[31mErro!");
        printf("\033[37m");

        exit(0);

    }else{

        startStack(ponteiro);
        chamadaMenu();
        pilha(times, numero, ponteiro);

    }
}