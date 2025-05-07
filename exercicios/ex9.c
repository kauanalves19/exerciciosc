#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_CONTATOS 100
#define TAM_NOME 100
#define TAM_TELEFONE 20

// Define a estrutura de contato
struct Contato {
    char nome[TAM_NOME];
    char telefone[TAM_TELEFONE];
};

// Declaração de funções
void adicionarContato(struct Contato contatos[], int *total);
void buscarContato(struct Contato contatos[], int total);
void exibirContatos(struct Contato contatos[], int total);

int main() {
    setlocale(LC_ALL, ""); // Suporte a caracteres acentuados

    struct Contato contatos[MAX_CONTATOS];
    int total = 0;
    int opcao;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Adicionar Contato\n");
        printf("2. Buscar Contato por Nome\n");
        printf("3. Exibir Todos os Contatos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                adicionarContato(contatos, &total);
                break;
            case 2:
                buscarContato(contatos, total);
                break;
            case 3:
                exibirContatos(contatos, total);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

void adicionarContato(struct Contato contatos[], int *total) {
    if (*total >= MAX_CONTATOS) {
        printf("Limite de contatos atingido.\n");
        return;
    }

    printf("Nome: ");
    fgets(contatos[*total].nome, TAM_NOME, stdin);
    contatos[*total].nome[strcspn(contatos[*total].nome, "\n")] = '\0'; // Remove newline

    printf("Telefone: ");
    fgets(contatos[*total].telefone, TAM_TELEFONE, stdin);
    contatos[*total].telefone[strcspn(contatos[*total].telefone, "\n")] = '\0';

    (*total)++;
    printf("Contato adicionado com sucesso!\n");
}

void buscarContato(struct Contato contatos[], int total) {
    char nomeBusca[TAM_NOME];
    int encontrado = 0;

    printf("Digite o nome para busca: ");
    fgets(nomeBusca, TAM_NOME, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < total; i++) {
        if (strcmp(contatos[i].nome, nomeBusca) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s | Telefone: %s\n", contatos[i].nome, contatos[i].telefone);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
}

void exibirContatos(struct Contato contatos[], int total) {
    if (total == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    printf("\nLista de Contatos:\n");
    for (int i = 0; i < total; i++) {
        printf("%d. Nome: %s | Telefone: %s\n", i + 1, contatos[i].nome, contatos[i].telefone);
    }
}
