#include <stdio.h>
#include <string.h>
#include "tarefa.h"


void adicionar_tarefa(Tarefa *tarefas, int *qtd) {
  if (*qtd >= MAX_TAREFAS) {
    printf("Limite máximo de tarefas atingido!\n");
    return;
  }
  printf("Nome da Tarefa: ");
  getchar();
  fgets(tarefas[*qtd].nome, TAM_NOME, stdin);
  tarefas[*qtd].nome[strcspn(tarefas[*qtd].nome, "\n")] = '\0';


  printf("Descrição: ");
  fgets(tarefas[*qtd].descricao, TAM_DESC, stdin);
  tarefas[*qtd].descricao[strcspn(tarefas[*qtd].descricao, "\n")] = '\0';


  tarefas[*qtd].concluida = 0;
  (*qtd)++;
}


void remover_tarefa(Tarefa *tarefas, int *qtd) {
  int id;
  printf("Digite o ID da tarefa a remover: ");
  scanf("%d", &id);
  if (id < 0 || id >= *qtd) {
    printf("ID inválido!\n");
    return;
  }
  for (int i = id; i < *qtd - 1; i++) {
    tarefas[i] = tarefas[i + 1];
  }
  (*qtd)--;
}


void alterar_tarefas(Tarefa *tarefas, int qtd) {
  int id;
  printf("Digite o ID da tarefa a alterar: ");
  scanf("%d", &id);
  if (id < 0 || id >= qtd) {
    printf("ID inválido!\n");
    return;
  }
  printf("Novo nome: ");
  getchar();
  fgets(tarefas[id].nome, TAM_NOME, stdin);
  tarefas[id].nome[strcspn(tarefas[id].nome, "\n")] = '\0';


  printf("Nova descrição: ");
  fgets(tarefas[id].descricao, TAM_DESC, stdin);
  tarefas[id].descricao[strcspn(tarefas[id].descricao, "\n")] = '\0';
}


void concluir_tarefa(Tarefa *tarefas, int qtd) {
  int id;
  printf("Digite o ID da tarefa a concluir: ");
  scanf("%d", &id);
  if (id < 0 || id >= qtd) {
    printf("ID inválido!\n");
    return;
  }
  tarefas[id].concluida = 1;
}
