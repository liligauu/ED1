#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct objeto{
    int CPF;
    char nome[30];
    int idade;
    struct objeto *prox;
} OBJETO;

typedef struct{
    OBJETO *topo;
    int qtd_elementos;
} PILHA_DINAMICA;

void inicializaPilha(PILHA_DINAMICA *pilha){
    pilha->qtd_elementos = 0;
    pilha->topo = NULL;
}

bool estaVazia(PILHA_DINAMICA *pilha){
    return pilha->qtd_elementos == 0; 
}

int tamanhoPilha(PILHA_DINAMICA *pilha){
    return pilha->qtd_elementos;
}

void insereElemento(PILHA_DINAMICA *pilha, int cpf, char nome[], int idade){
    OBJETO *aux = (OBJETO*) malloc (sizeof(OBJETO));
    if(aux == NULL){
        perror("Erro ao alocar memória!\n");
        return;
    }

    aux->CPF = cpf;
    aux->idade = idade;
    strcpy(aux->nome, nome);

    aux->prox = pilha->topo;
    pilha->topo = aux;

    pilha->qtd_elementos++;
}

OBJETO* topoPilha(PILHA_DINAMICA* pilha){
    return pilha->topo;
}

void desempilha(PILHA_DINAMICA* pilha){
    OBJETO *aux = pilha->topo;
    if(aux == NULL){
        printf("Pilha vazia!\n");
        return;
    }

    pilha->topo = aux->prox;
    pilha->qtd_elementos--;
}

void imprimeTopo(PILHA_DINAMICA* pilha){
    if(estaVazia(pilha)){
        printf("A pilha está vázia!\n");
        return;
    }

    printf("======================================================================\n");
    printf("Nome: %-20s | CPF: %i | Idade: %i\n", pilha->topo->nome, pilha->topo->CPF, pilha->topo->idade);
    printf("======================================================================\n");

}

void destruirPilha(PILHA_DINAMICA* pilha){
    while(estaVazia(pilha) == false){
        desempilha(pilha);
    }
}

int main(){

    PILHA_DINAMICA p;

    inicializaPilha(&p);

    insereElemento(&p, 123456789, "Jurandir", 99);
    insereElemento(&p, 987654321, "Jiovana", 10);
    insereElemento(&p, 777777777, "Tue", 777);
    insereElemento(&p, 424242424, "Fi do Wiu", 21);
    desempilha(&p);

    imprimeTopo(&p);
    destruirPilha(&p);
    
    imprimeTopo(&p);

    return EXIT_SUCCESS;
}