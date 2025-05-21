#include <stdio.h>
#include <string.h>
#include "tarefa.h"

void listar_tarefas(Tarefa *tarefas, int qtd) {
    printf("Lista de Tarefas:\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d. %s [%s]\n", tarefas[i].id, tarefas[i].descricao, tarefas[i].concluida ? "Concluída" : "Pendente");
    }
}

int adicionar_tarefa(Tarefa *tarefas, int *qtd, const char *descricao) {
    if (*qtd >= MAX_TAREFAS) return 0;
    tarefas[*qtd].id = *qtd + 1;
    strncpy(tarefas[*qtd].descricao, descricao, MAX_DESC-1);
    tarefas[*qtd].descricao[MAX_DESC-1] = '\0';
    tarefas[*qtd].concluida = 0;
    (*qtd)++;
    return 1;
}

int concluir_tarefa(Tarefa *tarefas, int qtd, int id) {
    for (int i = 0; i < qtd; i++) {
        if (tarefas[i].id == id) {
            tarefas[i].concluida = 1;
            return 1;
        }
    }
    return 0;
}

int remover_tarefa(Tarefa *tarefas, int *qtd, int id) {
    int found = 0;
    for (int i = 0; i < *qtd; i++) {
        if (tarefas[i].id == id) {
            found = 1;
        }
        if (found && i < *qtd - 1) {
            tarefas[i] = tarefas[i+1];
        }
    }
    if (found) {
        (*qtd)--;
    }
    return found;
}
