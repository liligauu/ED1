#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define M 10

typedef struct{
    int CPF;
    char nome[30];
    int idade;
} OBJETO;

typedef struct{
    int topo;
    OBJETO elementos[M];
    int qtde_elementos;
} PILHA_ESTATICA;

void inicalizaPilha(PILHA_ESTATICA *pilha){
    pilha->qtde_elementos = 0;
    pilha->topo = 0;
}

bool verificaVazio(PILHA_ESTATICA *pilha){
    return pilha->qtde_elementos == 0;
}

bool verificaCheia(PILHA_ESTATICA *pilha){
    return pilha->qtde_elementos == M;
}

int verificatamanho(PILHA_ESTATICA *pilha){
    return pilha->qtde_elementos;
}

void insereElemento(PILHA_ESTATICA *pilha, int cpf, char nome[], int idade){
    
    if(verificaCheia(pilha) == true){
        perror("A pilha está cheia. Inserção não concluída!\n");
        return;
    }
    
    pilha->elementos[pilha->topo].CPF = cpf;
    pilha->elementos[pilha->topo].idade = idade;
    strcpy(pilha->elementos[pilha->topo].nome, nome);

    pilha->qtde_elementos++;
    pilha->topo++;

}

OBJETO pilhaTopo(PILHA_ESTATICA *pilha){
    if(verificaVazio(pilha) == true){
        perror("A pilha está vazia. Busca não inicializada!\n");
        return pilha->elementos[pilha->topo];
    }

    return pilha->elementos[pilha->topo-1];
}

void imprimeTopo(PILHA_ESTATICA *pilha){
    OBJETO p = pilhaTopo(pilha);
    if(verificaVazio(pilha) == true){
        perror("Erro ao imprimir, não há elementos na pilha!\n");
        return;
    }

    printf("CPF: %-5i | Nome: %-20s | Idade: %i\n", p.CPF, p.nome, p.idade);
}

void desempilha(PILHA_ESTATICA *pilha){
    if(verificaVazio(pilha) == true){
        perror("A pilha já ta vázia manézão!\n");
        return;
    }

    pilha->topo--;
    pilha->qtde_elementos--;

}

int main(){

    PILHA_ESTATICA p;

    inicalizaPilha(&p);

    insereElemento(&p, 12345, "Maria do Carmo", 50);
    insereElemento(&p, 54321, "João", 22);
    insereElemento(&p, 42141, "Karol Conk", 5);

    desempilha(&p);     

    imprimeTopo(&p);

    return EXIT_SUCCESS;
}