#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da estrutura de Tópico
typedef struct {
    char nome[50];
    int dificuldade;
} Topico;

// Lista fixa de tópicos
Topico topicos[] = {
    {"Matemática", 2},
    {"Física", 3},
    {"Química", 1},
    {"Programação", 5}
};

// Função 1: Listar tópicos de estudo
void listarTopicos() {
    printf("\n*** Tópicos de Estudo ***\n");
    for (int i = 0; i < 4; i++) {
        printf("%d. %s (Dificuldade: %d)\n", i + 1, topicos[i].nome, topicos[i].dificuldade);
    }
    printf("\n");
}

// Função 2: Exibir plano de estudo (exemplo fixo)
void exibirPlanoEstudo() {
    printf("\n*** Exemplo de Plano de Estudo ***\n");
    printf("Assunto: Programação em C\n");
    printf("Dificuldade: 4/5\n");
    printf("Estimativa: 12.5 horas\n\n");
}

// Função 3: Mostrar dados do aluno (exemplo fixo)
void mostrarDadosAluno() {
    printf("\n*** Dados do Aluno ***\n");
    printf("Nome: João da Silva\n");
    printf("Curso: Ciência da Computação\n\n");
}

// Função 4: Calcular média de estudo nos últimos 5 dias
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

// Função 5: Calcular tempo de estudo personalizado
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

// Função 6: Modificar dificuldade dos tópicos com ponteiros
void ajustarDificuldadeTopicos() {
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

// Menu interativo
void menu() {
    int opcao;

    do {
        printf("======= MENU DE OPÇÕES =======\n");
        printf("1 - Listar Tópicos de Estudo\n");
        printf("2 - Ver Detalhes de Estudo\n");
        printf("3 - Mostrar Dados do Aluno\n");
        printf("4 - Calcular Média de Estudo\n");
        printf("5 - Calcular Tempo de Estudo Personalizado\n");
        printf("6 - Ajustar Dificuldade dos Tópicos\n");
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
            case 0: printf("Saindo do programa. Bons estudos!\n"); break;
            default: printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

// Função principal
int main() {
    menu();
    return 0;
}