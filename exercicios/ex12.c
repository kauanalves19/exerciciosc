#include <stdio.h>

// Função para calcular o tamanho da string manualmente
int tamanho_string(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

// Função que verifica se é palíndromo
int eh_palindromo(char str[]) {
    int inicio = 0;
    int fim = tamanho_string(str) - 1;

    while (inicio < fim) {
        if (str[inicio] != str[fim]) {
            return 0; // Não é palíndromo
        }
        inicio++;
        fim--;
    }

    return 1; // É palíndromo
}

int main() {
    char palavra[100];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    if (eh_palindromo(palavra)) {
        printf("'%s' é um palíndromo.\n", palavra);
    } else {
        printf("'%s' não é um palíndromo.\n", palavra);
    }

    return 0;
}
