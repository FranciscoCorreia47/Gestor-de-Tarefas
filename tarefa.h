#ifndef TAREFA_H
#define TAREFA_H


#define MAX_TAREFAS 100
#define TAM_NOME 50
#define TAM_DESC 256
#define ALTURA 9
#define LARGURA 55


typedef struct {
  char nome[TAM_NOME];
  char descricao[TAM_DESC];
  int concluida;
} Tarefa;


void adicionar_tarefa(Tarefa *tarefas, int *qtd);
void remover_tarefa(Tarefa *tarefas, int *qtd);
void alterar_tarefas(Tarefa *tarefas, int qtd);
void concluir_tarefa(Tarefa *tarefas, int qtd);


#endif

