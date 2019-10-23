#ifndef _QUEUE_H_INCLUDED
#define _QUEUE_H_INCLUDED
#define TRUE 1
#define FALSE 0

typedef struct _queue_{
	void* elms;
	int front;
	int rear;
	int maxElms;
	int nelms;
}Queue;


//Cria uma fila 
Queue* qCreate(int n);
/*
	retorna uma fila vazia || NULL
*/

//Destroi uma fila vazia
int qDestroy(Queue* q);
/*
	retorna se fila foi destruida (TRUE||FALSE)
*/

//incrementa circularmente um vetor
int incrementC(int pos, int max);
/*
	retorna valor de pos incrementado
*/

/decrementa circularmente um vetor
int decrementC(int pos, int max);
/*
	retorna valor de pos decrementado
*/

#endif