#ifndef MENU_H
#define MENU_H  // Evita múltiplas inclusões do cabeçalho

#include "tarefa.h"  // Necessário para manipular a estrutura Tarefa

// Exibe o menu principal da aplicação, onde o utilizador pode escolher
// opções como adicionar, remover, listar ou alterar tarefas.
void menu_principal(Tarefa *tarefas, int *qtd);

// Exibe todas as tarefas atualmente armazenadas na memória.
void menu_listar(Tarefa *tarefas, int qtd);

#endif  // Fim da proteção contra múltiplas inclusões
