#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese"); 

    int matriz[4][4];
    int i, j, soma = 0;

    // Entrada de dados
    printf("Digite os elementos da matriz 4x4:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz 4x4:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%3d ", matriz[i][j]);
            if (i == j) {
                soma += matriz[i][j];
            }
        }
        printf("\n");
    }

    // Resultado
    printf("\nSoma da diagonal principal = %d\n", soma);

    return 0;
}
