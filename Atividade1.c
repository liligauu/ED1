#include <stdlib.h>
#include <stdio.h>

void converte(int milhas, float* km, float* metros){
    *km = milhas * 1.609;
    *metros = *km * 0.277778;
}

int main(){

    int milhas;
    float km;
    float metros;

    printf("Valor em milhas a ser convertidas: ");
    scanf("%i", &milhas);

    converte(milhas, &km, &metros);

    printf("O Resultado em Km/h é %.2f, e em m/s é %.2f\n", km, metros);
    
    return 0;

}