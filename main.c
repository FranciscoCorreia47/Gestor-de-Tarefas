#include "menu.h"
#include "tarefa.h"
#include "ficheiro.h"


int main() {
  Tarefa tarefas[MAX_TAREFAS];
  int qtd_de_tarefas = 0;


  carregar_tarefas(tarefas, &qtd_de_tarefas);
  menu_principal(tarefas, &qtd_de_tarefas);


  return 0;
}
