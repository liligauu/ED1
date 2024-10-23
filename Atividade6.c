#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>   

#define M 5

typedef struct{
    int CPF;
    char nome[50];
    int idade;
} OBJETO;

typedef struct{
    int tamanho;
    int inicio;
    int fim;
    OBJETO elementos[M];
} FILA_ESTATICA;

void inicializaFila(FILA_ESTATICA* p){
    p->tamanho = 0;
    p->fim = p->inicio = -1;
}

bool estaVazio(FILA_ESTATICA *p){
    return p->tamanho == 0;
}

bool estaCheio(FILA_ESTATICA *p){
    return p->tamanho == M;
}

void insereElementoFila(FILA_ESTATICA *p, int cpf, char nome[], int idade){
    if(p->tamanho >= M){
        printf("A fila está cheia! Realocando elemento para o primeiro espaço!\n");
        p->tamanho--;
        p->fim = -1;
        p->inicio++;
    }

    if(estaVazio(p) == true){
        p->inicio++;
    }

    p->tamanho++;
    p->fim++;

    p->elementos[p->fim].CPF = cpf;
    p->elementos[p->fim].idade = idade;
    strcpy(p->elementos[p->fim].nome, nome);
    
    printf("Posição %i: %s adicionado(a) com sucesso!\n", p->fim+1, p->elementos[p->fim].nome);
    printf("%s Agora é o início da fila!\n", p->elementos[p->inicio].nome);
};

void removeElemento(FILA_ESTATICA *p){
    if(estaVazio(p) == true){
        perror("A fila está vazia, não há nada para deletar!\n");
        return;
    }

    p->tamanho--;

    if(estaVazio(p) == true){
        inicializaFila(p);
        return;
    }

    if(p->inicio >= M){
        p->inicio = 0;        
        p->fim = p->inicio++;
    }else{
        p->inicio++;
    }
        

}

int tamanhoFila(FILA_ESTATICA *p){
    return p->tamanho;
}

int main(){

    FILA_ESTATICA fila;

    inicializaFila(&fila);

    insereElementoFila(&fila, 12345, "Maria do Carmo", 50);
    insereElementoFila(&fila, 54321, "Joao", 50);
    insereElementoFila(&fila, 12323, "Pedro", 50);
    insereElementoFila(&fila, 29292, "Lucas", 50);
    insereElementoFila(&fila, 92942, "Joana", 50);
    insereElementoFila(&fila, 41241, "Joaquim", 50);
    printf("O tamanho da fila é: %i\n", tamanhoFila(&fila));

    for (int i = 0; i < M; i++){
        printf("%i | %s | %i | ", fila.elementos[i].CPF, fila.elementos[i].nome, fila.elementos[i].idade);
        if(fila.inicio){
            printf("Ínicio");
        }
        if(fila.fim){
            printf("Fim");
        }
        printf("\n");
    }
    

    removeElemento(&fila);

    return EXIT_SUCCESS;
}