
#include <stdio.h>
#include <stdlib.h>

typedef struct No{

    int valor;
    struct No*prox;
    struct No* ant;
    
}No;
No * inicio = NULL;
No * fim = NULL;
int tam = 0;

void adicionar(int valor, int pos){

    if(pos>=0 && pos <= tam){
        No*novo=(No*)malloc(sizeof(No));
        novo->valor=valor;
        novo->prox=NULL;
        novo->ant=NULL;
       if(inicio == NULL){ //lista vazia!
            inicio = novo;
            fim = novo;}
            else if(pos==0){ //adionar no inicio
            novo->prox=inicio;
            inicio->ant=novo;
            inicio=novo;
        }else if(pos==tam){//adicionar no fim
            fim->prox=novo;
            novo->ant=fim;
            fim=novo;
        }else{ //adicionar no meio
            No*aux=inicio;
            int i;
            for(i=0; i<pos; i++){
                aux=aux->prox;
            }
            novo->prox=aux;
            novo->ant=aux->ant;
            aux->ant->prox=novo;
            aux->ant=novo;

        }
    }
}

int remover (int pos){
    int retorno = 1;
    if(pos>=0 && pos<tam){
        if(pos==0){ //remover no inicio da estrutura
            No*lixo=inicio;
            retorno=inicio->valor;
            inicio=inicio->prox;
            inicio->ant=NULL;
            free(lixo);
        }else if(pos==tam-1){ //remover no final
            No*lixo=fim;
            retorno=lixo->valor;
            fim->ant->prox=NULL;
            fim=fim->ant;
            free(lixo);
        }else{ //remover no meio
            No*aux=inicio;
            int i;
            for(i=0; i<pos;i++){
                aux=aux->prox;
            }
            retorno=aux->valor;
            aux->ant->prox=aux->prox;
            aux->prox->ant=aux->ant;
            free(aux);
        }
        tam--;
    }
    return retorno;
}

void imprimir(){
    No * aux = inicio;
    for(int i = 0; i<tam; i++){
        printf("Valor = %d\n", aux->valor );
        aux = aux->prox;
    }
    
}

int main(){


    adicionar(32, 0);
    adicionar(1,1);
    imprimir();
    return 0;
}