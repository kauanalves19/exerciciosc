
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

// Função que verifica se um número é primo
bool ehPrimo(int n){
    if (n < 2){
        return false;
    }
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    int inicio, fim;

    // Entrada dos limites
    printf("Digite o primeiro número: ");
    scanf("%d", &inicio);
    printf("Digite o segundo número: ");
    scanf("%d", &fim);

    // Garante que inicio seja menor ou igual a fim
    if (inicio > fim){
        int temp = inicio;
        inicio = fim;
        fim = temp;
        
    }

    printf("Números primos entre %d e %d são: ", inicio, fim);
    for (int i = inicio; i <= fim; i++) {
        if (ehPrimo(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}