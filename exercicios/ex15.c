#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Palavra secreta
    char palavra[] = "banana";
    int tamanho = strlen(palavra);

    // Vetor para armazenar as letras descobertas
    char letras_descobertas[tamanho];
    for (int i = 0; i < tamanho; i++) {
        letras_descobertas[i] = '_';
    }

    int tentativas = 6;
    char letra;
    int ganhou = 0;

    printf("=== JOGO DA FORCA ===\n");

    while (tentativas > 0 && !ganhou) {
        // Mostra a palavra parcialmente descoberta
        printf("\nPalavra: ");
        for (int i = 0; i < tamanho; i++) {
            printf("%c ", letras_descobertas[i]);
        }

        // Entrada do jogador
        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra);  // Normaliza a letra

        // Verifica se a letra está na palavra
        int acertou = 0;
        for (int i = 0; i < tamanho; i++) {
            if (palavra[i] == letra && letras_descobertas[i] == '_') {
                letras_descobertas[i] = letra;
                acertou = 1;
            }
        }

        // Resultado da jogada
        if (acertou) {
            printf("Boa! A letra '%c' está na palavra.\n", letra);
        } else {
            tentativas--;
            printf("Errado! Você tem %d tentativa(s) restante(s).\n", tentativas);
        }

        // Verifica se o jogador ganhou
        ganhou = 1;
        for (int i = 0; i < tamanho; i++) {
            if (letras_descobertas[i] == '_') {
                ganhou = 0;
                break;
            }
        }
    }

    // Fim do jogo
    if (ganhou) {
        printf("\nParabéns! Você acertou a palavra: %s\n", palavra);
    } else {
        printf("\nGame over! A palavra era: %s\n", palavra);
    }

    return 0;
}
