#ifndef PILHA
#define PILHA

// declara��o de um n� que a base da minha pilha alocada dinamicamente.
typedef struct no{
    int dado;
    struct NO *next;
}no;

// declara��o do topo.
typedef struct stack{
    no *topo;
}stack;

// Inicializa minha pilha.
void startStack(stack *entrada);

// respondavel pelo empilhamento.
void push(int dado, stack *entrada);

// Desempilha os valores alocados na pilha.
int pop(stack *entrada);

// Tem o intuito de apenas printar a pilha.
void show(stack *entrada);

// Realiza a chamada do push quantas vezes o usu�rio desejar.
void chamadaPush(times, numero, ponteiro);

// Realiza a chamada do pop quantas vezes o usu�rio desejar.
void chamadaPop(times, numero, ponteiro);

// Verifica se a pilha est� vazia.
int pilhaVazia(stack* pilha);

// Faz a verifica��o de quem est� no topo da pilha.
void chamadaTopo(stack *entrada);

//Se o usuario desejar finalizar a execu��o o break � chamado por essa fun��o.
void chamadaDeBreak(stack* ponteiro);

// Fun��o que cont�m instru��es para a utiliza��o do progama.
void chamadaMenu();

// comt�m um switch para que o usuario possa navegar pelas op��es.
void pilha(times, numero, ponteiro);



#endif