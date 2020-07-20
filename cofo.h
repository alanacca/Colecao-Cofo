#ifndef _COFO_H_
#define _COFO_H_
#define TRUE 1
#define FALSE 0
#define ERRO 8555523
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _cofo_{
    int max;
    int nElms;
    int cur;
    void **elms;
}Cofo;

typedef struct _carro_{
    char *marca;
    int pot;
    int nPortas;
    float preco;
    long int placa;
}Carro;

#ifdef _cofo_c_
    Cofo *cofCreate(int n);
    int cofInsert(Cofo *c,void* elem);
    void *cofRemoveLast(Cofo *c);
    void *cofRemoveFirst(Cofo *c);
    int cofDestroy(Cofo *c);
    void* cofQuery(Cofo *c,void *key,void *key2);
    int cmpPlaca(void *key,void *elem);
    int cmpMarca(void *key,void *elem);
    void imprimirCarro(Carro *c1);
    void imprimirCofo(Cofo *c);
    int cofRemove(Cofo *c,void *key,void *key2);
    int RemoveAll(Cofo *c);
#else
    extern Cofo *cofCreate(int n);
    extern int cofInsert(Cofo *c,void* elem);
    extern void *cofRemoveLast(Cofo *c);
    extern void *cofRemoveFirst(Cofo *c);
    extern int cofDestroy(Cofo *c);
    extern void* cofQuery(Cofo *c,void *key,void *key2);
    extern int cmpPlaca(void *key,void *elem);
    extern int cmpMarca(void *Key,void *elem);
    extern void imprimirCarro(Carro *c1);
    extern void imprimirCofo(Cofo *c);
    extern int cofRemove(Cofo *c,void *key,void *key2);
    extern int RemoveAll(Cofo *c);
#endif
#endif // _cofo_h_


