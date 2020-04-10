#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"

int main(){

setlocale(LC_ALL, "Portuguese_Brazil");

    Lista lista1;
    lista1=inicializar_lista();

    menor_elem(&lista1);
    tamanho(lista1);

    imprime_lista(lista1);

    insere_elem(&lista1,4);
    insere_elem(&lista1,8);
    insere_elem(&lista1,0);
    insere_elem(&lista1,19);
    insere_elem(&lista1,2);
    insere_elem(&lista1,7);
    insere_elem(&lista1,9);
    insere_elem(&lista1,22);
    insere_elem(&lista1,8);

    tamanho(lista1);
    imprime_lista(lista1);

    menor_elem(&lista1);
    tamanho(lista1);

    imprime_lista(lista1);

    remove_elem(&lista1,8);

    menor_elem(&lista1);
    tamanho(lista1);

    imprime_lista(lista1);

    insere_final(&lista1,100);

    menor_elem(&lista1);

    insere_final(&lista1,5000);

    tamanho(lista1);
    imprime_lista(lista1);

    Lista lista2=inicializar_lista();

    insere_elem(&lista2,1);
    insere_elem(&lista2,4);
    insere_elem(&lista2,2);
    insere_elem(&lista2,1);
    insere_elem(&lista2,5);
    insere_elem(&lista2,1);

    printf("\n");
    tamanho(lista2);
    imprime_lista(lista2);
    remove_todos(&lista2,1);
    tamanho(lista2);
    imprime_lista(lista2);

    Lista lista3=inicializar_lista();

    insere_elem(&lista3,12);
    insere_elem(&lista3,0);
    insere_elem(&lista3,5);
    insere_elem(&lista3,52);
    insere_elem(&lista3,41);

    insere_elem(&lista2,478);
    insere_elem(&lista2,47);
    insere_elem(&lista2,4);
    insere_elem(&lista2,47896);

    Lista l=concatenar(&lista2,&lista3);

    imprime_lista(l);
    insere_final(&l,4);
    insere_elem(&l,4);
    imprime_lista(l);
    remove_todos(&l,4);
    imprime_lista(l);

    free(lista1);
    free(lista2);
    free(lista3);

    return 0;
}
