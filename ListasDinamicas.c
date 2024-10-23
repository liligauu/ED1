#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>  

typedef struct obj{
    int CPF;
    int idade;
    char nome[30];
    struct obj* prox;
} OBJETO;

typedef struct{
    OBJETO *inicio;
    int tamanho;
}LISTA_DINAMICA;

void incializaPilha(LISTA_DINAMICA *lista){
    lista->inicio = NULL;
    lista->tamanho = 0;
}

bool estaVazio(LISTA_DINAMICA *lista){
    return lista->tamanho == 0;
}

int tamanhodaLista(LISTA_DINAMICA *lista){
    return lista->tamanho;
}

void insereElementoLista(LISTA_DINAMICA* lista, int CPF, char nome[], int idade){
    OBJETO* novo = (OBJETO*) malloc (sizeof(OBJETO));
    if(novo == NULL){
        perror("Erro ao alocar memória!\n");
        exit(1);
    }

    novo->CPF = CPF;
    novo->idade = idade;
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if(estaVazio(lista) == true){
        lista->inicio = novo;
    }else{
        if(lista->inicio->idade >= idade){
            novo->prox = lista->inicio;
            lista->inicio = novo;
        }else{
            OBJETO *aux = lista->inicio;
            while(aux->prox->idade < idade){
                aux = aux->prox;
            }
        }
    }

    lista->tamanho++;

}

int main(){

    LISTA_DINAMICA lista;

    incializaPilha(&lista);
    if(estaVazio(&lista) == true){
        printf("A lista está vazia!\n");
    }
    tamanhodaLista(&lista);

    insereElementoLista(&lista, 12345, "Maria do Carmo", 50);

    return EXIT_SUCCESS;
}