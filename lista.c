#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{
    int info;
    struct no *prox;
};

Lista inicializar_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst==NULL)
        return 1; //lista vazia
    else
        return 0; //lista N�O vazia
}

int insere_elem(Lista *lst, int elem){
    //aloca um novo n�
    Lista N=(Lista) malloc(sizeof(struct no));
    if(N==NULL)
        return 0; //falha, n� n�o alocado
    N->info=elem; //insere o conte�do(valor do elem)
    N->prox = *lst; //aponta para o 1� atual da lista
    *lst=N; //faz a lista apontar para o novo n�
    return 1; //sucesso na aloca��o
}

int remove_elem(Lista *lst, int elem){
    if(lista_vazia(*lst)==1) //verifica se a lista � vazia
        return 0; //falha
    Lista aux=*lst; //ponteiro auxiliar para o 1� n�
    //trata elemento = 1� n� da lista
    if(elem==(*lst)->info){
        *lst=aux->prox; //Lista aponta para o 2� n�
        free(aux); //libera mem�ri alocada pelo elem que foi removido
        return 1; //sucesso na remo��o
    }
    //percorrimento at� achar o elem ou final da lista
    while(aux->prox != NULL && aux->prox->info!=elem)
        aux=aux->prox;
    if(aux->prox==NULL)//caso chegue no final da lista
        return 0; //falha
    //remove o elemento != 1� n� da lista
    Lista aux2=aux->prox; //aponta n� a ser removido
    aux->prox=aux2->prox; //retira n� apontado p/ aux2 da lista
    free(aux2); //libera mem�ria do n� a ser removido
    return 1;
}

Lista imprime_lista(Lista lst){
    Lista aux=lst;
    if(lista_vazia(lst) || aux==NULL)
        return printf("Lista vazia!\n\n");
    printf("Lista: ");
    while(aux!=NULL){
        printf("%d ", aux->info);
        aux=aux->prox;
    }
    printf("\n\n");
}

int menor_elem(Lista *lst){
    if(lista_vazia(*lst)==1) //verifica se a lista � vazia
        return 0;
    Lista aux=*lst;
    int menor;
    menor=aux->info;
    while(aux!=NULL){
        if(aux->info<menor)
            menor=aux->info;
        aux=aux->prox;
    }
    remove_elem(lst,menor);
    return 1; //sucesso na remo��o
}

int tamanho(Lista lst){
    int i=0;
    Lista aux=lst;
    while(aux!=NULL){
        i++;
        aux=aux->prox;
    }
    return printf("A lista tem %d elementos!\n",i);
}

int insere_final(Lista *lst, int elem){
    Lista N=(Lista) malloc(sizeof(struct no));
    N->prox=NULL;
    if(N==NULL)
        return 0;

    N->info=elem;

    if(*lst==NULL){
        *lst=N;
    }

    else{
        Lista aux=*lst;
        while(aux->prox!=NULL)
            aux=aux->prox;
        aux->prox=N;
    }
    return 1;
}

int remove_todos(Lista *lst, int elem){
    if(lista_vazia(*lst)==1)
        return 0;

    Lista aux=*lst;

    if((*lst)->info==elem){
        *lst=aux->prox;
        free(aux);
        aux=*lst;
    }

    while(aux->prox!=NULL){
        if(aux->prox->info==elem){
            Lista aux2=aux->prox;
            aux->prox=aux2->prox;
            free(aux2);
        }else{
            aux=aux->prox;
        }
    }
    return 1;
}

Lista concatenar(Lista *lst1, Lista *lst2){
    Lista lst=inicializar_lista();
    Lista aux=*lst1;
    Lista aux2=*lst2;
    Lista aux3=lst;

    while(aux!=NULL){
        Lista N=(Lista) malloc(sizeof(struct no));
        N->info=aux->info;
        aux=aux->prox;
        if(lst==NULL)
            lst=N;
        else
            aux3->prox=N;
        aux3=N;
    }

    while(aux2!=NULL){
        Lista N=(Lista) malloc(sizeof(struct no));
        N->info=aux2->info;
        aux2=aux2->prox;
        if(lst==NULL)
            lst=N;
        else
            aux3->prox=N;
        aux3=N;
    }

    if(aux3!=NULL)
        aux3->prox=NULL;

    return lst;
}
