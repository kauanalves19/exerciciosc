#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100

// Definindo a estrutura Aluno
typedef struct {
    char nome[TAM_NOME];
    int matricula;
    float media;
} Aluno;

int main() {
    int n, i;

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &n);

    
    getchar();

    Aluno* alunos = (Aluno*)malloc(n * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Cadastro dos alunos
    for (i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i + 1);
        
        printf("Nome: ");
        fgets(alunos[i].nome, TAM_NOME, stdin);
        
        size_t len = strlen(alunos[i].nome);
        if (len > 0 && alunos[i].nome[len - 1] == '\n') {
            alunos[i].nome[len - 1] = '\0';
        }

        printf("Matrícula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Média: ");
        scanf("%f", &alunos[i].media);

      
        getchar();
    }

    // Exibe os alunos aprovados
    printf("\nAlunos aprovados (média >= 7.0):\n");
    int encontrouAprovado = 0;
    for (i = 0; i < n; i++) {
        if (alunos[i].media >= 7.0) {
            encontrouAprovado = 1;
            printf("\nNome: %s\n", alunos[i].nome);
            printf("Matrícula: %d\n", alunos[i].matricula);
            printf("Média: %.2f\n", alunos[i].media);
        }
    }

    if (!encontrouAprovado) {
        printf("Nenhum aluno aprovado.\n");
    }

    free(alunos);
    return 0;
}
