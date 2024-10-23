#include <stdlib.h>
#include <stdio.h>

int fatorial(int n){
    int fat;

    if(n <= 0){
        return 1;    
    }else{
        fat = n * fatorial(n-1);
    }

    return fat;
}

int main(){
    int n;

    printf("Calculadora de Fatorial!\n");
    printf("Valor: ");
    scanf("%i", &n);
    
    printf("O fatorial de %i é %i!\n", n, fatorial(n));

    return 0;

}