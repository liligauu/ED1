#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y,z;
} Pontos;

int digitaPontos(){
    int num = 0;

    printf("Digite a quantidade de coordenadas: ");
    scanf("%i", &num);
    while(num < 0){
        printf("Digite o a quantidade de coordenadas novamente(maior que 0): ");
        scanf("%i", &num);
    }
    return num;

}

void preencherPontos(Pontos *p, int qtdcoordenadas){
    for (int i = 0; i < qtdcoordenadas; i++){
        p[i].x = i;
        p[i].y = i+1;
        p[i].z = i+2;    
    }
    
};

int main(){

    int qtdcoordenadas = 0;
    Pontos* p;

    qtdcoordenadas = digitaPontos();

    p = (Pontos*) malloc (qtdcoordenadas * sizeof(Pontos));
    if(p == NULL){
        perror("Erro ao alocar memória!\n");
        exit(1);
    }

    preencherPontos(p, qtdcoordenadas);

    for (int i = 0; i < qtdcoordenadas; i++){
        printf("%i, ", p[i].x);
        printf("%i, ", p[i].y);
        printf("%i", p[i].z);
        printf("\n");
    }

    free(p);

    return 0;     
}