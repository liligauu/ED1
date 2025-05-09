#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int prioridade;
} FilaHospital;

typedef struct No {
    FilaHospital topico;
    struct No* prox;
} No;

FilaHospital filadeprioridades[] = {
    {"Emergencia", 0},
    {"Muito Urgente", 1},
    {"Urgente", 2},
    {"Menos Grave", 3},
    {"Leve", 4}
};

No* inicio = NULL;
No* fim = NULL;

No* criarNo(char nome[], int prioridade) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    strcpy(novo->topico.nome, nome);
    novo->topico.prioridade = prioridade;
    novo->prox = NULL;
    return novo;
}

void leString(char nome[]){
    printf("Digite o nome do paciente: ");
    getchar(); // limpar buffer
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
}

int salvaPrioridade(int prioridade){

    printf("Digite o nível de prioridade (0-4): ");
    printf("0 - Caso Emergência\n1 - Caso Muito Urgente\n2- Caso Urgente\n3- Caso Menos Grave\n4- Caso Leve\n");
    do{
        scanf("%d", &prioridade);
        if(prioridade < 0 || prioridade > 4){
            int escolha;
            printf("Confirmar caso %s\n?", filadeprioridades[prioridade].nome);
            printf("1 - Sim\n 2 - Não\n");
            do{
                scanf("%i", &escolha);
            }while(escolha != 1 || escolha != 2);
            if(escolha == 2){
                salvaPrioridade(prioridade);
            }
        }
    }while(prioridade < 0 || prioridade > 4);
    
    return prioridade;

}

void enfileirar(FilaHospital paciente, char nome[], int prioridade) {

    No* novo = criarNo(nome, prioridade);
    if (fim == NULL) {
        inicio = fim = novo;
    } else {
        fim->prox = novo;
        fim = novo;
    }

    if (inicio == NULL) {
        printf("A fila está vazia.\n\n");
        return;
    }
    No* atual = inicio;

    while (atual != NULL) {
        atual = atual->prox;
        if()
    }
    printf("\n");

    printf("Paciente '%s' adicionado à fila com sucesso!\n\n", nome);
}

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

void listarFila() {
    if (inicio == NULL) {
        printf("A fila está vazia.\n\n");
        return;
    }

    printf("\n*** Pacientes na Fila ***\n");
    No* atual = inicio;
    while (atual != NULL) {
        printf("Paciente: %-20s, Prioridade: %s\n", atual->topico.nome, filadeprioridades[atual->topico.prioridade].nome);
        atual = atual->prox;
    }
    printf("\n");
}

void ajustarDificuldadeTopicos() {
    FilaHospital topicos[] = {
        {"Matemática", 2},
        {"Física", 3},
        {"Química", 1},
        {"Programação", 5}
    };

    FilaHospital *ptr = topicos;
    printf("\n*** Dificuldades Antes da Modificação ***\n");
    for (int i = 0; i < 4; i++) {
        printf("Tópico: %s, Dificuldade: %d\n", ptr[i].nome, ptr[i].prioridade);
    }

    for (int i = 0; i < 4; i++) {
        ptr[i].prioridade += 1;
    }

    printf("\n*** Dificuldades Após Aumento de 1 ***\n");
    for (int i = 0; i < 4; i++) {
        printf("Tópico: %s, Nova Dificuldade: %d\n", ptr[i].nome, ptr[i].prioridade);
    }
    printf("\n");
}

int main() {
    int opcao;
    char nome[50];
    int prioridade;

    do {
        printf("======= MENU DE OPÇÕES =======\n");
        printf("1 - Listar Fila\n");
        printf("2 - Adicionar Paciente à Fila\n");
        printf("3 - Remover Paciente da Fila\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                leString(&nome);
                salvaPrioridade(&prioridade);
                enfileirar(); 
                break;
            case 2: desenfileirar(); break;
            case 3: listarFila(); break;
            case 0: printf("Saindo do programa.!\n"); break;
            default: printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    // Liberar memória
    while (inicio != NULL) {
        desenfileirar();
    }

    return 0;
}