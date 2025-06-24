#include "menu.h"
#include "tarefa.h"
#include "ficheiro.h"

int main() {
  Tarefa tarefas[MAX_TAREFAS];    // Array que armazenará as tarefas em memória
  int qtd_de_tarefas = 0;         // Número de tarefas atualmente carregadas

  carregar_tarefas(tarefas, &qtd_de_tarefas);  // Lê as tarefas previamente guardadas no ficheiro (se houver)
  menu_principal(tarefas, &qtd_de_tarefas);    // Inicia o menu interativo para o utilizador

  return 0;  // Termina o programa com sucesso
}
