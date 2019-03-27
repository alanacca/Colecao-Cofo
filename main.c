#include <stdio.h>
#include <stdlib.h>

//3 QUESTÃO
float *DiagPrin(int n,int m, float **Ma)//MOSTRA A DIAGONAL PRINCIPAL DA MATRIZ
{
    float *vetDiag = (float*)malloc(sizeof(float)*n);
    if(vetDiag == NULL){
        printf("vetor nulo");
    }
    int s=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==j){
                vetDiag[s]=Ma[i][j];
                s++;

            }
        }
    }
    return vetDiag;
}


//1 QUESTÃO
float **criaEleMatriz(int n,int m){//CRIA UMA MATRIZ
    float **M = (float**)malloc(sizeof(float*)*n);
    for(int i=0;i<n;i++){
        M[i]=(float*)malloc(sizeof(float)*m);
    }
    if(M!=NULL){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("digite:");
                scanf("%f",&M[i][j]);
            }
        }

    }
    return M;
}


void impMatriz(float**M,int n,int m){//IMPRIME A MATRIZ
    if(M!=NULL){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("matriz:%0.2f \t",M[i][j]);
            }
            printf("\n");
        }
    }
}

//4 QUESTÃO LETRA A
float *RetornaLinha(int n,int m,float **Mat, int k){//RETORNA A LINHA K
    float *vetor = (float*)malloc(sizeof(float)*m);
    if(Mat!=NULL && k<n && k>=0){
        for(int i=0;i<m;i++){
            vetor[i] = Mat[k][i];
        }
    }
    return vetor;
}

//4 QUESTÃO LETRA B
float *RetornaColuna(int n,int m, float **Mc, int k){//RETORNA A COLUNA K
    float *vet = (float*)malloc(sizeof(float)*n);
    if(Mc!=NULL && k<m&& k>=0){
        for(int i=0;i<n;i++){
            vet[i] = Mc[i][k];
        }
    }
    return vet;
}

//4 QUESTÃO LETRA C
float RetornaSomaEleColunaK(int n,int m,float **Ma,int k){//RETORNA A SOMA DA COLUNA K
    float somaColuna=0;
    if(Ma!=NULL){
        for(int i=0;i<n;i++){
            somaColuna+=Ma[i][k];
        }
    }
    return somaColuna;
}

//4 QUESTÃO LETRA D
float RetornaSomaElemLinhaK(int n,int m,float **Ma,int k){//RETORNA A SOMA DA LINHA K
    float somaLinha=0;
    if(Ma!=NULL){
       for(int i=0;i<m;i++){
            somaLinha+=Ma[k][i];
       }
    }
    return somaLinha;
}

//2 QUESTÃO
float **multMat(int n,int m,int p, int f,float **Ma,float **Mb){//FAZ A MULTIPLICAÇÃO DA MATRIZ
    if(m == p){
        float **matriz = (float**)malloc(sizeof(float*)*n);
            for(int i=0;i<n;i++){
                matriz[i] = (float*)malloc(sizeof(float)*f);
            }
        if(matriz!=NULL){
            for(int i=0;i<n;i++){
                for(int j=0;j<f;j++){
                    matriz[i][j] = 0;
                    for(int k=0;k<p;k++){
                        matriz[i][j] += (Ma[i][k]*Mb[k][j]);
                    }
                }
            }
            return matriz;
        }
    }
    return NULL;
}
int main()
{
    int n,m,p,f,k;
    printf("Digite a quantidade de linhas de a:\n");
    scanf("%d",&n);
    printf("Digite a quantidade de colunas de a:\n");
    scanf("%d",&m);
    //float **Matriz;
    //Matriz = criaEleMatriz(n,m);
    //impMatriz(Matriz,n,m);
    printf("Digite a quantidade de linhas de b:\n");
    scanf("%d",&p);
    printf("Digite a quantidade de colunas de b:\n");
    scanf("%d",&f);
   // printf("Digite qual a linha voce quer:\n");
    //scanf("%d",&k);
    float **MatrizResul;
    float **MatrizA;
    float **MatrizB;
    MatrizA = criaEleMatriz(n,m);
    MatrizB = criaEleMatriz(p,f);
    impMatriz(MatrizA,n,m);
    printf("\n");
    impMatriz(MatrizB,p,f);
    printf("\n");
    MatrizResul = multMat(n,m,p,f,MatrizA,MatrizB);
    impMatriz(MatrizResul,n,f);

    /*float *v;
    v = RetornaColuna(n,m,recebeMatriz,k);
    for(int i=0;i<n;i++){
        printf("Coluna:%0.2f \t",v[i]);
    }*/
    //printf("\n");
    //printf("somaColuna:%f\n",RetornaSomaEleColunaK(n,m,recebeMatriz,k));
    //printf("soma da linha:%0.2f\n",RetornaSomaElemLinhaK(n,m,recebeMatriz,k));

}
   /*srand(time(NULL));
   int n,m;
   printf("Digite a quantidade de linhas:\n");
   scanf("%d",&n);
   printf("Digite a quantidade de colunas:\n");
   scanf("%d",&m);
   float **M;
   M = (float**)malloc(sizeof(float*)*n);
   for(int i=0;i<n;i++){
        M[i] = (float*)malloc(sizeof(float)*m);
   }
   if (M == NULL){
        printf("matriz vazia");
   }
   for(int j=0;j<n;j++){
        for(int k=0;k<m;k++){
            M[j][k] = rand()%10;
        }
   }
   for(int j=0;j<n;j++){
        printf("\n");
        for(int k=0;k<m;k++){
            printf("[%d][%d]:%f ",j,k,M[j][k]);
        }
   }
    float *vetor;
    printf("\n");
    vetor = DiagPrin(n,m,M);
    if(n<m){
        for(int i=0;i<n;i++){
            printf("vetor: %f\n",vetor[i]);
        }
    }else{
        for(int i=0;i<m;i++){
            printf("vetor: %f\n",vetor[i]);
        }
    }*/


