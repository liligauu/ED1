/**
 * @file listadinamica.c
 * @author Leonardo Tanamura
 * @version 0.1
 * @date 2025-04-11
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "lista.h"

void inicializarLista(Lista* lista){
    lista->cabeca = NULL;
}

int isListaVazia(Lista* lista){
    if(lista->cabeca == NULL){
        return 1;
    }else{
        return 0;
    }
}

void inserirNaLista(Lista* lista, int valor){
    No* aux = (No*) malloc (sizeof(No));

    if(isListaVazia(lista)){
        aux->dado = valor;
        aux->prox = NULL;
        lista->cabeca = aux;
        printf("Valor %i adicionado com sucesso!\n", valor);
    }else{
        aux = lista->cabeca;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->dado = valor;
        aux->prox = NULL;
        lista->cabeca = aux;
        printf("Valor %i adicionado com sucesso!\n", valor);
    }

    return;
}

int main(){

    Lista lista;

    inicializarLista(&lista);
    isListaVazia(&lista);
    inserirNaLista(&lista, 10);
    inserirNaLista(&lista, 20);

    return EXIT_SUCCESS;
}