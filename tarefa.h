#ifndef TAREFA_H
#define TAREFA_H

#define MAX_TAREFAS 100
#define MAX_DESC 100

typedef struct {
    int id;
    char descricao[MAX_DESC];
    int concluida; // 0 = não, 1 = sim
} Tarefa;

int adicionar_tarefa(Tarefa *tarefas, int *qtd, const char *descricao);
int concluir_tarefa(Tarefa *tarefas, int qtd, int id);
int remover_tarefa(Tarefa *tarefas, int *qtd, int id);

#endif // TAREFA_H
