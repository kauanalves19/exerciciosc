#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int vetor1[5], vetor2[5];
    int i, j;

    // Leitura do primeiro vetor
    printf("Digite 5 números para o primeiro vetor:\n");
    for (i = 0; i < 5; i++) {
        printf("Vetor1[%d]: ", i);
        scanf("%d", &vetor1[i]);
    }

    // Leitura do segundo vetor
    printf("\nDigite 5 números para o segundo vetor:\n");
    for (i = 0; i < 5; i++) {
        printf("Vetor2[%d]: ", i);
        scanf("%d", &vetor2[i]);
    }

    // Mostrar elementos comuns (sem repetição)
    printf("\nElementos comuns entre os dois vetores:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (vetor1[i] == vetor2[j]) {
                // Verifica se já foi mostrado antes
                int ja_mostrado = 0;
                for (int k = 0; k < i; k++) {
                    if (vetor1[i] == vetor1[k]) {
                        ja_mostrado = 1;
                        break;
                    }
                }
                if (!ja_mostrado) {
                    printf("%d\n", vetor1[i]);
                }
                break;
            }
        }
    }

    return 0;
}
