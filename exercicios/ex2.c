#include <stdio.h>
#include <locale.h>

// Função para calcular base^expoente usando apenas multiplicações
int potencia(int base, int expoente) {
    int resultado = 1;

    if (expoente == 0) {
        return 1;
    }

    if (expoente < 0) {
        printf("Erro: expoente negativo não suportado com inteiros.\n");
        return -1;
    }

    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }

    return resultado;
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    int base, expoente;

    // Solicita ao usuário os valores
    printf("Digite a base: ");
    scanf("%d", &base);

    printf("Digite o expoente (inteiro não negativo): ");
    scanf("%d", &expoente);

    int resultado = potencia(base, expoente);

    if (resultado != -1){
        printf("%d^%d = %d\n", base, expoente, resultado);
    }

    return 0;
}
