#include <stdio.h>
#include <ctype.h> 

// Função que aplica a Cifra de César
void cesar_criptografar(char mensagem[], int deslocamento) {
    int i = 0;

    while (mensagem[i] != '\0') {
        char c = mensagem[i];

        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            mensagem[i] = (c - base + deslocamento) % 26 + base;
        }

        i++;
    }
}

int main() {
    char mensagem[1000];
    int deslocamento;

    printf("Digite a mensagem a ser criptografada: ");
    fgets(mensagem, sizeof(mensagem), stdin); // lê a string com espaços

    printf("Digite o valor do deslocamento (ex: 3): ");
    scanf("%d", &deslocamento);

    cesar_criptografar(mensagem, deslocamento);

    printf("Mensagem criptografada: %s\n", mensagem);

    return 0;
}
