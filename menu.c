#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>    
#include "menu.h"      // Declarações dos menus
#include "tarefa.h"    // Estrutura e funções de tarefas
#include "ficheiro.h"  // Leitura/escrita de ficheiros

// Função que apresenta o menu principal ao utilizador e executa as ações conforme opção escolhida.
void menu_principal(Tarefa *tarefas, int *qtd){
  short int opcao;

  do{
    system("cls||clear");  // Limpa o terminal (compatível com Windows e Unix)
    printf("---Seja Bem Vindo ao Gestor de Tarefas!---");
    printf("\n");
    printf("      O que pretende fazer?      ");
    printf("\n");
    // Interface textual do menu
    printf("+----------------------------------+\n");
    printf("|        Gestor de Tarefas         |\n");
    printf("+----------------------------------+\n");
    printf("|       [1] Adicionar Tarefas      |\n");
    printf("|       [2] Eliminar Tarefas       |\n");
    printf("|       [3] Listar Tarefas         |\n");
    printf("|       [4] Alterar Tarefas        |\n");
    printf("|       [5] Concluir Tarefas       |\n");
    printf("|       [0] Sair                   |\n");
    printf("+----------------------------------+\n");
    printf("|\n+-> ");
    scanf("%hd", &opcao);  // Lê a opção escolhida

    // Executa a ação correspondente  
    switch(opcao){
      case 1: adicionar_tarefa(tarefas, qtd); break;
      case 2: remover_tarefa(tarefas, qtd); break;
      case 3: menu_listar(tarefas, *qtd); break;
      case 4: alterar_tarefas(tarefas, *qtd); break;
      case 5: concluir_tarefa(tarefas, *qtd); break;
      case 0:
        guardar_tarefas(tarefas, *qtd);  // Guarda os dados antes de sair
        opcao = -1;                      // Encerra o ciclo
        break;
    }
  }while(opcao != -1);
}

// Função que lista todas as tarefas de forma visualmente organizada
void menu_listar(Tarefa *tarefas, int qtd) {
  int printed;

  for (int i = 0; i < qtd; i++) {
    for (int j = 0; j < ALTURA; j++) {
      if (j % 2 == 0 && j != 6) {
        // Linha de borda horizontal
        printf("+");
        for (int k = 1; k < LARGURA; k++) printf("-");
        printf("+\n");
      } else {
        printf("|");
        if (j == 1) {
          // Linha com número da tarefa
          printf(" Tarefa %d", i);
          printed = 9 + (i > 9);
          for (int s = printed; s < LARGURA - 1; s++) printf(" ");
        } else if (j == 3) {
          // Linha com nome da tarefa
          printf(" %s", tarefas[i].nome);
          printed = 1 + strlen(tarefas[i].nome);
          for (int s = printed; s < LARGURA - 1; s++) printf(" ");
        } else if (j == 5) {
          // Primeira linha da descrição
          printf(" ");
          int max_len = LARGURA - 3;
          for (int s = 0; s < max_len && tarefas[i].descricao[s] != '\0'; s++)
            printf("%c", tarefas[i].descricao[s]);
          printed = strlen(tarefas[i].descricao);
          if (printed > max_len) printed = max_len;
          for (int s = printed + 1; s < LARGURA - 1; s++) printf(" ");
        } else if (j == 6) {
          // Segunda linha da descrição, se necessário
          printf(" ");
          int remaining = strlen(tarefas[i].descricao) - (LARGURA - 3);
          if (remaining > 0) {
            for (int s = LARGURA - 3; s < LARGURA - 3 + remaining; s++)
              printf("%c", tarefas[i].descricao[s]);
          }
          printed = remaining;
          if (printed > LARGURA - 3) printed = LARGURA - 3;
          for (int s = printed + 1; s < LARGURA - 1; s++) printf(" ");
        } else if (j == 7) {
          // Linha de status
          printf(" Status: %s", tarefas[i].concluida ? "Concluída" : "Pendente ");
          printed = strlen(" Status: Concluída");
          for (int s = printed; s < LARGURA - 1; s++) printf(" ");
        } else {
          // Linhas em branco
          for (int s = 0; s < LARGURA - 1; s++) printf(" ");
        }
        printf("|\n");
      }
    }
    printf("\n");
  }

  // Pausa antes de retornar ao menu principal
  printf("Pressione qualquer tecla para voltar ao menu principal...");
  system("pause > nul || read -n 1 -s");
}
