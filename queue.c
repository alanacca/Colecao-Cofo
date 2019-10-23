#ifndef _QUEUE_C_INCLUDED
#define _QUEUE_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

Queue* qCreate(int n){
	if(n>0){
		Queue* q;
		q = (Queue*)malloc(sizeof(Queue));
		if(q != NULL){
			q->maxElms = n;
			q->nelms = 0;
			q->front = 0;
			q->rear = -1;
			return q;
		}
	}
	return NULL;
}            

int qEnQueue(Queue* q, void* elm){
	if(q != NULL){
		if(q->nelms < q->maxElms){
			q->rear = incrementC(q->rear, q->maxElms);
			q->elms[q->rear] = elm;
			return TRUE;
		}
	}
	return FALSE;                
}

void* qDeQueue(Queue* q){
	if(q != NULL){
		if(q->nelms > 0){
			void* aux;
			aux = q->elms[q->front];
			q->front = incrementC(q->front, q->maxElms);
			return aux;
		}
	}
	return NULL;
}

int qDestroy(Queue* q){
	if(q != NULL){
		if(q->nelms <= 0){
			free(q->elms);
			free(q);
			return TRUE;
		}
	}
	return FALSE;
}
int incrementC(int pos, int max){
	if(pos == max){
		return 0;
	}
	pos++;
	return pos;
}

int decrementC(int pos, int max){
	if(pos == 0){
		return max -1;
	}
	pos--;
	return pos;
}

#endif