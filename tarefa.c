#include <stdio.h>        
#include <string.h>       
#include "tarefa.h"       // Inclui a definição da estrutura Tarefa e as funções declaradas no cabeçalho

// Função auxiliar para limpar o buffer de entrada, especialmente útil após uso de scanf
void limpar_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Descarta caracteres até nova linha ou fim de ficheiro
}

// Adiciona uma nova tarefa ao array, se não exceder o limite máximo
void adicionar_tarefa(Tarefa *tarefas, int *qtd) {
    if (*qtd >= MAX_TAREFAS) {
        printf("Limite máximo de tarefas atingido!\n");
        return;
    }

    printf("Nome da Tarefa: ");
    limpar_entrada();  // Garante que o buffer está limpo para usar fgets
    fgets(tarefas[*qtd].nome, TAM_NOME, stdin);
    tarefas[*qtd].nome[strcspn(tarefas[*qtd].nome, "\n")] = '\0';  // Remove o \n no final

    printf("Descrição: ");
    fgets(tarefas[*qtd].descricao, TAM_DESC, stdin);
    tarefas[*qtd].descricao[strcspn(tarefas[*qtd].descricao, "\n")] = '\0';

    printf("Responsável: ");
    fgets(tarefas[*qtd].responsavel, TAM_RES, stdin);
    tarefas[*qtd].responsavel[strcspn(tarefas[*qtd].responsavel, "\n")] = '\0';

    printf("Status: ");
    fgets(tarefas[*qtd].status, TAM_STATUS, stdin);
    tarefas[*qtd].status[strcspn(tarefas[*qtd].status, "\n")] = '\0';

    tarefas[*qtd].concluida = 0;  // Inicialmente, a tarefa ainda não está concluída
    (*qtd)++;  // Incrementa o número de tarefas
}

// Remove uma tarefa com base no ID informado pelo utilizador
void remover_tarefa(Tarefa *tarefas, int *qtd) {
    int id;
    printf("Digite o ID da tarefa a remover: ");
    scanf("%d", &id);
    if (id < 0 || id >= *qtd) {
        printf("ID inválido!\n");
        return;
    }
    for (int i = id; i < *qtd - 1; i++) {
        tarefas[i] = tarefas[i + 1]; // Desloca os elementos para preencher o vazio
    }
    (*qtd)--;  // Decrementa o número de tarefas
}

// Permite alterar os dados de uma tarefa específica
void alterar_tarefas(Tarefa *tarefas, int qtd) {
    int id;
    printf("Digite o ID da tarefa a alterar: ");
    scanf("%d", &id);
    if (id < 0 || id >= qtd) {
        printf("ID inválido!\n");
        return;
    }

    limpar_entrada();  // Limpa o \n deixado pelo scanf anterior

    printf("Novo nome: ");
    fgets(tarefas[id].nome, TAM_NOME, stdin);
    tarefas[id].nome[strcspn(tarefas[id].nome, "\n")] = '\0';

    printf("Nova descrição: ");
    fgets(tarefas[id].descricao, TAM_DESC, stdin);
    tarefas[id].descricao[strcspn(tarefas[id].descricao, "\n")] = '\0';

    printf("Novo responsável: ");
    fgets(tarefas[id].responsavel, TAM_RES, stdin);
    tarefas[id].responsavel[strcspn(tarefas[id].responsavel, "\n")] = '\0';

    printf("Novo status: ");
    fgets(tarefas[id].status, TAM_STATUS, stdin);
    tarefas[id].status[strcspn(tarefas[id].status, "\n")] = '\0';
}

// Marca uma tarefa como concluída com base no ID
void concluir_tarefa(Tarefa *tarefas, int qtd) {
    int id;
    printf("Digite o ID da tarefa a concluir: ");
    scanf("%d", &id);
    if (id < 0 || id >= qtd) {
        printf("ID inválido!\n");
        return;
    }
    tarefas[id].concluida = 1;  // Atualiza o campo para indicar que foi concluída
}
