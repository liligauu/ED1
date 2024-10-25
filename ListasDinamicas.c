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
        return;
    }

    novo->CPF = CPF;
    novo->idade = idade;
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if(estaVazio(lista) == true){
        lista->inicio = novo;
    }else{
        if(lista->inicio->idade > idade){
            novo->prox = lista->inicio;
            lista->inicio = novo;
        }else{
            OBJETO *aux = lista->inicio;
            while(aux->prox != NULL && aux->prox->idade < idade){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }

    lista->tamanho++;

}

void imprimeElementos(LISTA_DINAMICA *lista){
    OBJETO *aux = lista->inicio;
    printf("\n======================================================\n");
    printf("Os elementos da lista são :");
    printf("\n======================================================\n");
    
    while(aux != NULL){
        printf("Idade: %d | Nome: %s | CPF: %i\n", aux->idade, aux->nome, aux->CPF);
        aux = aux->prox;
    }
}

void destroiLista(LISTA_DINAMICA *lista){
    OBJETO *aux = NULL;
    while(estaVazio(lista) == true){
        aux = lista->inicio;
        lista->inicio = aux->prox;
        free(aux);
    }
    incializaPilha(lista);
}

void removerElemento(LISTA_DINAMICA *lista){
    int contaelemento;
    if(estaVazio(lista)){
        printf("A lista está vazia!\n");
        return;
    }

    imprimeElementos(lista);
    do{
        printf("Qual elemento deve ser excluido?");
        printf("\nLinha: ");
        scanf("%i", &contaelemento);
    } while(contaelemento > lista->tamanho || contaelemento < 1);

    while(contaelemento > 0){
        -
        contaelemento--;
    }
}

// FAZER PESQUISAR, MAXIMO, MINIMO, PROXIMO E ANTERIOR.

int main(){

    LISTA_DINAMICA lista;

    incializaPilha(&lista);
    if(estaVazio(&lista) == true){
        printf("A lista está vazia!\n");
    }
    tamanhodaLista(&lista);

    insereElementoLista(&lista, 12345, "Maria do Carmo", 50);
    insereElementoLista(&lista, 54321, "Joao Jose", 38);
    insereElementoLista(&lista, 56789, "Laura Silva", 60);
    insereElementoLista(&lista, 98564, "Karina Tavares", 55);
    insereElementoLista(&lista, 25852, "Osvaldo Cruz", 70);


    imprimeElementos(&lista);
    removerElemento(&lista);

    return EXIT_SUCCESS;
}