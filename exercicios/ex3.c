#include <stdio.h>
#include <locale.h>

// Função para inverter os dígitos de um número
int inverternumero(int numero) {
    int invertido = 0;

    while (numero != 0) {
        int digito = numero % 10;
        invertido = invertido * 10 + digito;
        numero /= 10;
    }

    return invertido;
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    int resultado = inverternumero(numero);

    printf("Número invertido: %d\n", resultado);

    return 0;
}
