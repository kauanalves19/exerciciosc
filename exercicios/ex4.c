#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int numeros[10];
    int i, j;

    // Leitura dos 10 números
    printf("Digite 10 números inteiros:\n");
    for (i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

  
    printf("\nOcorrência de cada número:\n");
    for (i = 0; i < 10; i++) {
        // Verifica se o número já apareceu antes
        int ja_apareceu = 0;
        for (j = 0; j < i; j++) {
            if (numeros[i] == numeros[j]) {
                ja_apareceu = 1;
                break;
            }
        }

        if (ja_apareceu) {
            int contador = 1;
            for (j = i + 1; j < 10; j++) {
                if (numeros[i] == numeros[j]) {
                    contador++;
                }
            }

            printf("%d aparece %d vez(es)\n", numeros[i], contador);
        }
    }

    return 0;
}
