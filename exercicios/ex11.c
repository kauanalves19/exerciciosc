#include <stdio.h>

// Função de busca binária
int busca_binaria(int vetor[], int tamanho, int alvo) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == alvo) {
            return meio; // Elemento encontrado
        } else if (vetor[meio] < alvo) {
            inicio = meio + 1; // Procurar na metade direita
        } else {
            fim = meio - 1; // Procurar na metade esquerda
        }
    }

    return -1; // Elemento não encontrado
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int alvo = 7;

    int resultado = busca_binaria(vetor, tamanho, alvo);

    if (resultado != -1) {
        printf("Elemento %d encontrado na posição %d.\n", alvo, resultado);
    } else {
        printf("Elemento %d não encontrado no vetor.\n", alvo);
    }

    return 0;
}
