#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de Tópico
typedef struct {
    char nome[50];
    int dificuldade;
} Topico;

// Nó da Fila
typedef struct No {
    Topico topico;
    struct No* prox;
} No;

// Ponteiros para o início e fim da fila
No* inicio = NULL;
No* fim = NULL;

// Criar novo nó
No* criarNo(char nome[], int dificuldade) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    strcpy(novo->topico.nome, nome);
    novo->topico.dificuldade = dificuldade;
    novo->prox = NULL;
    return novo;
}

// Enfileirar (adicionar no fim)
void enfileirar() {
    char nome[50];
    int dificuldade;

    printf("Digite o nome da matéria: ");
    getchar(); // limpar buffer
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // remover \n

    printf("Digite o nível de dificuldade (1-5): ");
    scanf("%d", &dificuldade);

    No* novo = criarNo(nome, dificuldade);
    if (fim == NULL) {
        inicio = fim = novo;
    } else {
        fim->prox = novo;
        fim = novo;
    }

    printf("Matéria '%s' adicionada à fila com sucesso!\n\n", nome);
}

// Desenfileirar (remover do início)
void desenfileirar() {
    if (inicio == NULL) {
        printf("A fila está vazia.\n\n");
        return;
    }

    No* temp = inicio;
    printf("Matéria '%s' removida da fila.\n\n", temp->topico.nome);
    inicio = inicio->prox;
    if (inicio == NULL) fim = NULL;
    free(temp);
}

// Listar matérias da fila
void listarFila() {
    if (inicio == NULL) {
        printf("A fila está vazia.\n\n");
        return;
    }

    printf("\n*** Matérias na Fila ***\n");
    No* atual = inicio;
    while (atual != NULL) {
        printf("Matéria: %s, Dificuldade: %d\n", atual->topico.nome, atual->topico.dificuldade);
        atual = atual->prox;
    }
    printf("\n");
}

// Exibir plano de estudo baseado na fila
void exibirPlanoEstudo() {
    if (inicio == NULL) {
        printf("\nA fila está vazia. Adicione matérias primeiro.\n\n");
        return;
    }

    float totalHoras = 0.0;
    int count = 0;

    printf("\n*** Plano de Estudo Gerado ***\n");

    No* atual = inicio;
    while (atual != NULL) {
        float horas = atual->topico.dificuldade * 2.5;
        printf("Matéria: %s | Dificuldade: %d | Estimativa: %.1f horas\n",
               atual->topico.nome, atual->topico.dificuldade, horas);
        totalHoras += horas;
        count++;
        atual = atual->prox;
    }

    float media = totalHoras / count;
    printf("\nCarga horária total: %.1f horas\n", totalHoras);
    printf("Média por matéria: %.1f horas\n\n", media);
}

// Funções auxiliares
void listarTopicos() {
    Topico topicos[] = {
        {"Matemática", 2},
        {"Física", 3},
        {"Química", 1},
        {"Programação", 5}
    };

    printf("\n*** Tópicos de Estudo ***\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s (Dificuldade: %d)\n", i + 1, topicos[i].nome, topicos[i].dificuldade);
    }
    printf("\n");
}

void mostrarDadosAluno() {
    printf("\n*** Dados do Aluno ***\n");
    printf("Nome: João da Silva\n");
    printf("Curso: Ciência da Computação\n\n");
}

void calcularMediaEstudo() {
    float horas[5], soma = 0.0;
    printf("\nInforme as horas de estudo dos últimos 5 dias:\n");
    for (int i = 0; i < 5; i++) {
        printf("Dia %d: ", i + 1);
        scanf("%f", &horas[i]);
        soma += horas[i];
    }
    printf("Média diária: %.2f horas\n\n", soma / 5);
}

void calcularTempoEstudoPersonalizado() {
    int dificuldade, experiencia, tempoSemanal;
    float tempoBase, tempoFinal;

    printf("\n*** Calculadora de Tempo de Estudo ***\n");
    printf("Nível de dificuldade do conteúdo (1-5): ");
    scanf("%d", &dificuldade);
    printf("Nível de experiência (1-Iniciante, 2-Intermediário, 3-Avançado): ");
    scanf("%d", &experiencia);
    printf("Horas disponíveis por semana: ");
    scanf("%d", &tempoSemanal);

    tempoBase = dificuldade * 5.0;

    if (experiencia == 1) {
        tempoFinal = tempoBase * 1.5;
    } else if (experiencia == 2) {
        tempoFinal = tempoBase;
    } else {
        tempoFinal = tempoBase * 0.7;
    }

    printf("Você precisará de aproximadamente %.1f horas.\n", tempoFinal);
    printf("Concluirá em cerca de %.1f semanas.\n\n", tempoFinal / tempoSemanal);
}

void ajustarDificuldadeTopicos() {
    Topico topicos[] = {
        {"Matemática", 2},
        {"Física", 3},
        {"Química", 1},
        {"Programação", 5}
    };

    Topico *ptr = topicos;
    printf("\n*** Dificuldades Antes da Modificação ***\n");
    for (int i = 0; i < 4; i++) {
        printf("Tópico: %s, Dificuldade: %d\n", ptr[i].nome, ptr[i].dificuldade);
    }

    for (int i = 0; i < 4; i++) {
        ptr[i].dificuldade += 1;
    }

    printf("\n*** Dificuldades Após Aumento de 1 ***\n");
    for (int i = 0; i < 4; i++) {
        printf("Tópico: %s, Nova Dificuldade: %d\n", ptr[i].nome, ptr[i].dificuldade);
    }
    printf("\n");
}

// Menu principal
int main() {
    int opcao;

    do {
        printf("======= MENU DE OPÇÕES =======\n");
        printf("1 - Listar Tópicos de Estudo\n");
        printf("2 - Gerar Plano de Estudo\n");
        printf("3 - Mostrar Dados do Aluno\n");
        printf("4 - Calcular Média de Estudo\n");
        printf("5 - Calcular Tempo de Estudo Personalizado\n");
        printf("6 - Ajustar Dificuldade dos Tópicos\n");
        printf("7 - Adicionar Matéria à Fila\n");
        printf("8 - Remover Matéria da Fila\n");
        printf("9 - Listar Fila de Matérias\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: listarTopicos(); break;
            case 2: exibirPlanoEstudo(); break;
            case 3: mostrarDadosAluno(); break;
            case 4: calcularMediaEstudo(); break;
            case 5: calcularTempoEstudoPersonalizado(); break;
            case 6: ajustarDificuldadeTopicos(); break;
            case 7: enfileirar(); break;
            case 8: desenfileirar(); break;
            case 9: listarFila(); break;
            case 0: printf("Saindo do programa. Bons estudos!\n"); break;
            default: printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    // Liberar memória
    while (inicio != NULL) {
        desenfileirar();
    }

    return 0;
}