#ifndef _MAIN_C_
#define _MAIN_C_
#include "cofo.h"


int main(void){
    Cofo *c = NULL;
    Carro *c1;
    Carro *res6;
    long int placa;
    int stat,stat2,stat3;
    int res,res3,verif;
    char *marca;
    marca = (char*)malloc(sizeof(char*)*100);
    int opc=1,n,i;
    //c1 = (Carro*)malloc(sizeof(Carro));
        do{
            printf("###################### MENU ####################\n");
            printf("[1] - criar uma colecao\n");
            printf("[2] - destruir a colecao\n");
            printf("[3] - inserir dados de uma estrutura do tipo T em uma colecao\n");
            printf("[4] - consultar uma estrutura do tipo T identificada pelo campo F que esta na colecao\n");
            printf("[5] - remover uma estrutura do tipo T identifcada pelo campo F que esta na colecao\n");
            printf("[6] - listar todas as estruturas armazenadas na colecao\n");
            printf("[0] - sair do programa\n");
            printf("#################### MENU ####################\n");
            scanf("%d",&opc);
            switch(opc){
                case 1:
                    if(c==NULL){
                        printf("Digite o tamanho da colecao:\n");
                        scanf("%d",&n);
                        if(n>0){
                            c = cofCreate(n);
                            if(c!=NULL){
                            printf("A colecao foi criada com sucesso.\n");
                            }else{
                            printf("Sinto Muito!Não foi possível criar a sua colecao.\n");
                            }
                        }else{
                            printf("por favor, insira um tamanho maior que zero.\n");
                        }
                    }else{
                        printf("Para criar colecao primeiro voce deve excluir a anterior.\n");
                    }
                        fflush(stdin);
                    break;
                case 2:
                    if(c!=NULL){
                        stat3 = RemoveAll(c);
                        if(stat3==TRUE){
                            stat2 = cofDestroy(c);
                            if(stat2 == TRUE){
                                c = NULL;
                                printf("A sua colecao foi destruida com sucesso.\n");
                            }else{
                                printf("Desculpe.A sua colecao nao foi possivel de ser excluida.\n");
                            }
                        }
                    }else{
                        printf("Nao existe colecao para destruir.\n");
                    }
                    fflush(stdin);
                    break;
                case 3:
                    c1 = (Carro*)malloc(sizeof(Carro));
                    c1->marca = (char*)malloc(sizeof(char)*100);
                    if(c!=NULL){
                        if(c1!=NULL){
                            if(c->nElms<c->max){
                                printf("Digite a marca do carro:\n");
                                scanf("%s",(c1->marca));
                                fflush(stdin);
                                printf("Digite a potencia do carro:\n");
                                scanf("%d",&(c1->pot));
                                fflush(stdin);
                                printf("Digite o numero de portas do carro:\n");
                                scanf("%d",&(c1->nPortas));
                                fflush(stdin);
                                printf("Digite o preco do carro:\n");
                                scanf("%f",&(c1->preco));
                                fflush(stdin);
                                printf("Digite a placa do carro:\n");
                                scanf("%ld",&(c1->placa));
                                fflush(stdin);
                                stat = cofInsert(c,(void*)c1);
                                if(stat == TRUE){
                                    printf("Os elementos do Carro foram inseridos na colecao.\n");
                                    imprimirCarro(c1);
                                }else{
                                    printf("Os elementos do Carro nao conseguiram ser inseridos.\n");
                                }
                            }else{
                                printf("A sua colecao ja foi totalmente preenchida.\n");
                            }
                        }
                    }else{
                        printf("A colecao que voce quer inserir esta vazia.\n");
                    }

                    fflush(stdin);
                    break;
                case 4:
                    if(c!=NULL){
                        printf("Digite a placa do carro a ser consultado:\n");
                        scanf("%ld",&placa);
                        printf("Digite a marca do carro a ser consultado:\n");
                        scanf("%s",marca);
                        res6 = cofQuery(c,(void*)placa,(void*)marca);
                        if(res6 != NULL){
                            printf("O elemento foi encontrado.\n");
                            imprimirCarro(res6);
                        }else{
                            printf("O elemento informado nao esta dentro da colecao.\n");
                        }
                    }else{
                        printf("Nao existe colecao para consultar elemento.\n");
                    }
                    fflush(stdin);
                    break;
                case 5:
                    if(c!=NULL){
                        printf("Digite a placa do carro a ser removido:\n");
                        scanf("%ld",&placa);
                        printf("Digite a marca do carro a ser removido:\n");
                        scanf("%s",marca);
                        res3 = cofRemove(c,(void*)placa,(void*)marca);
                        if(res3 == TRUE){
                            printf("o elemento foi removido.\n");
                        }else{
                                printf("o elemento nao foi removido, pois não foi encontrado.\n");
                        }
                    }else{
                        printf("Nao existe colecao para remover elementos.\n");
                    }
                    fflush(stdin);
                    break;
                case 6:
                    if(c!=NULL){
                        if(c->nElms>0){
                            imprimirCofo(c);
                        }else{
                            printf("Nao tem elementos na colecao.\n");
                        }
                    }else{
                        printf("Nao existe colecao para imprimir.\n");
                    }
                    fflush(stdin);
                    break;
                default:
                    i=0;
                    if(opc!=0){
                      printf("Opcao invalida\n");
                    }
                    fflush(stdin);
                    break;
            }
        }while(opc!=0);
        printf("Obrigada por usar Alana's Program.\n");
}


#endif // _main_c_
