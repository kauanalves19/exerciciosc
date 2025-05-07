
// Questão 08
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_PRODUTOS 100

typedef struct {
    char nome[50];
    int codigo;
    int quantidade;
    float preco;
} Produto;

Produto produtos[MAX_PRODUTOS];
int total_produtos = 0;

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarProduto() {
    if (total_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    Produto novo;

    printf("Nome do produto: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0; // Remove o '\n' do final

    printf("Código do produto: ");
    scanf("%d", &novo.codigo);
    limparBuffer();

    printf("Quantidade em estoque: ");
    scanf("%d", &novo.quantidade);
    limparBuffer();

    printf("Preço: ");
    scanf("%f", &novo.preco);
    limparBuffer();

    produtos[total_produtos++] = novo;

    printf("Produto cadastrado com sucesso!\n");
}

void buscarProduto() {
    int codigo;
    printf("Digite o código do produto: ");
    scanf("%d", &codigo);
    limparBuffer();

    for (int i = 0; i < total_produtos; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Produto encontrado:\n");
            printf("Nome: %s\n", produtos[i].nome);
            printf("Código: %d\n", produtos[i].codigo);
            printf("Quantidade: %d\n", produtos[i].quantidade);
            printf("Preço: R$ %.2f\n", produtos[i].preco);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void listarProdutos() {
    if (total_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Lista de produtos:\n");
    for (int i = 0; i < total_produtos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("  Nome: %s\n", produtos[i].nome);
        printf("  Código: %d\n", produtos[i].codigo);
        printf("  Quantidade: %d\n", produtos[i].quantidade);
        printf("  Preço: R$ %.2f\n", produtos[i].preco);
    }
}

int main() {
	setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Buscar Produto\n");
        printf("3. Listar Produtos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                buscarProduto();
                break;
            case 3:
                listarProdutos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
