#ifndef PILHA
#define PILHA

// declaração de um nó que a base da minha pilha alocada dinamicamente.
typedef struct no{
    int dado;
    struct NO *next;
}no;

// declaração do topo.
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

// Realiza a chamada do push quantas vezes o usuário desejar.
void chamadaPush(times, numero, ponteiro);

// Realiza a chamada do pop quantas vezes o usuário desejar.
void chamadaPop(times, numero, ponteiro);

// Verifica se a pilha está vazia.
int pilhaVazia(stack* pilha);

// Faz a verificação de quem está no topo da pilha.
void chamadaTopo(stack *entrada);

//Se o usuario desejar finalizar a execução o break é chamado por essa função.
void chamadaDeBreak(stack* ponteiro);

// Função que contém instruções para a utilização do progama.
void chamadaMenu();

// comtém um switch para que o usuario possa navegar pelas opções.
void pilha(times, numero, ponteiro);



#endif