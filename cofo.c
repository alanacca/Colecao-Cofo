#ifndef _COFO_C_
#define _COFO_C_
#include "cofo.h"


Cofo *cofCreate(int n){//CRIANDO A COLECAO
    Cofo *c;
    c = (Cofo*)malloc(sizeof(Cofo));
    if(c!=NULL){
        c->elms = (void**)malloc(sizeof(void*)*n);
    }
    if(c->elms!=NULL){
        c->nElms = 0;
        c->max = n;
        c->cur = -1;
        return c;
    }else{
      free(c);
    }
    return NULL;
}

int cofInsert(Cofo *c,void* elem){//INSERINDO ELEMENTOS DENRO DA COLECAO
    if(c!=NULL){
        if(c->nElms<c->max){
                //printf("nelms:%d//max:%d",c->nElms,c->max);
            c->elms[c->nElms] = elem;
            c->nElms++;
            return TRUE;
        }
    }
    return FALSE;
}

int cmpPlaca(void *key,void *elem){//COMPARANDO A PLACA
   long int ik = (long int)key;
   Carro *Aelem = (Carro*)elem;
   if(ik==Aelem->placa){
        return TRUE;
    }else{
        return FALSE;
    }
}

int cmpMarca(void *key,void *elem){//COMPARANDO A MARCA
  char *ik = (char*)key;
  Carro *Aelem = (Carro*)elem;
  if(strcmp(ik,Aelem->marca)==0){
    return TRUE;
  }else{
    return FALSE;
  }
}

void* cofQuery(Cofo *c,void *key,void *key2){//PROCURANDO O ELEMENTO DENTRO DA COLECAO
    int i,stat,stat2;
    if(c!=NULL){
        if(c->nElms>0){
            i=0;
            while(i<c->nElms){
                stat = cmpPlaca(key,c->elms[i]);
                stat2 = cmpMarca(key2,c->elms[i]);
                if(stat==TRUE && stat2==TRUE){
                    return c->elms[i];
                }
                i++;
            }
        }

    }
    return NULL;
}


int cofDestroy(Cofo *c){//DESTRUIR A COLECAO
    if(c!=NULL){
        if(c->nElms == 0){
            free(c->elms);
            free(c);
            return TRUE;
        }
    }
    return FALSE;
}

void imprimirCarro(Carro *c1){//IMPRIMIR A ESTRUTURA DO CARRO
    if(c1!=NULL){
        printf("Placa:%ld\nPotencia:%d\nPreco:%.2f\nNumero de Portas:%d\nMarca:%s\n------------------------\n",c1->placa,c1->pot,c1->preco,c1->nPortas,c1->marca);
    }
}


void imprimirCofo(Cofo *c){//IMPRIMIR O QUE ESTA DENTRO DA COLECAO
    if(c!=0){
        for(int i=0;i<c->nElms;i++){
            imprimirCarro((Carro*)c->elms[i]);
        }
    }
}


int cofRemove(Cofo *c,void *key,void *key2){//REMOVER UM ELEMENTO DA COLECAO
    int i,stat,stat2;
    if(c!=NULL){
        if(c->nElms>0){
            i=0;
            while(i<c->nElms){
                stat = cmpPlaca(key,c->elms[i]);
                stat2 = cmpMarca(key2,c->elms[i]);
                if(stat==TRUE && stat2==TRUE){
                    for(int j=i;j<c->nElms-1;j++){
                        c->elms[j] = c->elms[j+1];
                    }
                    c->nElms--;
                    return TRUE;
                }
                i++;
            }
        }

    }
    return FALSE;
}

int RemoveAll(Cofo *c){//REMOVER TODOS OS ELEMENTOS DA COLECAO
    if(c!=NULL){
        c->nElms = 0;
        return TRUE;
    }
    return FALSE;
}

#endif // _cofo_c_


