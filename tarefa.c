#include <stdio.h>
#include <string.h>
#include "tarefa.h"

// A função para adicionar uma nova tarefa à lista existente
int adicionar_tarefa(Tarefa *tarefas, int *qtd, const char *descricao) {
    if (*qtd >= MAX_TAREFAS) return 0; // Evita adicionar mais tarefas que o máximo permitido (100)
    tarefas[*qtd].id = *qtd + 1; // ID começa em 1
    strncpy(tarefas[*qtd].descricao, descricao, MAX_DESC-1); // Copiar a descrição inserida para o struct, atentando para copiar apenas os 100 caracteres permitidos
    tarefas[*qtd].descricao[MAX_DESC-1] = '\0'; // Finalizar a string com \0 para evitar problemas de escrita/leitura
    tarefas[*qtd].concluida = 0;
    (*qtd)++; // Incrementar a quantidade de tarefas existentes
    return 1; // Devolver 1 para indicar sucesso na execução da adição
}

// A função para marcar uma tarefa da lista existente como concluída
int concluir_tarefa(Tarefa *tarefas, int qtd) {
    int id;
    printf("Insira o id da tarefa a concluir: ");
    scanf("%d", &id);
    id >= qtd ? return 0 : tarefas[id].concluida = 1; // Caso o id fornecido não corresponder a uma tarefa existente, devolver 0
    return 1;
}

// A função para remover uma tarefa da lista existente
int remover_tarefa(Tarefa *tarefas, int *qtd, int id) {
    int found = 0;
    for (int i = 0; i < *qtd; i++) {
        if (tarefas[i].id == id)
            found = 1;
        if (found && i < *qtd - 1)
            tarefas[i] = tarefas[i+1]; // Copiar a próxima tarefa para a atual
    }
    if (found)
        (*qtd)--; // Decrementar a quantidade de tarefas existentes
    return found; // 1 se executar corretamente, 0 se o ID inserido não corresponder a uma tarefa existente
}
