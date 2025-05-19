#include "menu.h"

void menu_principal(Tarefa *tarefas, int qtd_de_tarefas){
  short int opcao;

  do{
    system("cls");
    printf("+---------------------------+\n");
    printf("|     Gestor de Tarefas     |\n");
    printf("+---------------------------+\n");
    printf("|  [1] Adicionar Tarefas    |\n");
    printf("|  [2] Eliminar Tarefas     |\n");
    printf("|  [3] Listar Tarefas       |\n");
    printf("|  [4] Alterar Tarefas      |\n");
    printf("|  [0] Sair                 |\n");
    printf("+---------------------------+\n");
    printf("|\n+-> ");
    scanf("%hd", &opcao);

    switch(opcao){
      case 1: criar_tarefas(); break;
      case 2: eliminar_tarefas(); break;
      case 3: menu_listar(tarefas, qtd_de_tarefas); break;
      case 4: alterar_tarefas(); break;
      case 0: 
        guardar_tarefas(); 
        opcao = -1;
      break;
      default:
        printf("Opção inválida.\n");
        opcao = -1;
    }
  }while(opcao != -1);
}

void menu_listar(Tarefa *tarefas, int qtd_de_tarefas) {
  int printed;  

  for (int i = 0; i < qtd_de_tarefas; i++) {
    for (int j = 0; j < ALTURA; j++) {
      // Linhas de separação (pares) 
      if (j % 2 == 0 && j != 6) {
        printf("+");
        for (int k = 1; k < LARGURA; k++)
          printf("-");
        printf("+\n");
      }
      // Linhas de conteúdo (ímpares)
      else {
        printf("|");

        if (j == 1) {
           printf(" Tarefa %d", i);
           // Para manter as bordas retas mesmo quando i tem 2 dígitos (a condição devolve 1 se verdadeira e 0 se falsa)
           printed = 9 + (i > 9);
           for (int s = printed; s < LARGURA - 1; s++)
             printf(" "); // Imprimir espaços até o fim da linha
           }
        else if (j == 3) {
             printf(" %s", tarefas[i].nome);
             printed = 1 + strlen(tarefas[i].nome);
             for (int s = printed; s < LARGURA - 1; s++)
               printf(" ");
          }
        else if (j == 5) {
          printf(" ");
          int max_len = LARGURA - 3;
                
          for (int s = 0; s < max_len && tarefas[i].descricao[s] != '\0'; s++)
            printf("%c", tarefas[i].descricao[s]);

          printed = strlen(tarefas[i].descricao);
                
          if (printed > max_len)
            printed = max_len;
                
          for (int s = printed + 1; s < LARGURA - 1; s++)
            printf(" ");
        }
        else if (j == 6) {
          printf(" ");
          int remaining_length = strlen(tarefas[i].descricao) - (LARGURA - 3); // Verifica se ainda sobra texto, e se sim: 

          // Imprime o resto da descrição
          if (remaining_length > 0) {
            for (int s = LARGURA - 3; s < LARGURA - 3 + remaining_length; s++)
              printf("%c", tarefas[i].descricao[s]);
          }
          printed = remaining_length;
          
          // Se foi imprimida mais descrição, garantir que não excede o limite da tabela
          if (printed > LARGURA - 3)
            printed = LARGURA - 3;
          // Preencher o resto da linha
          for (int s = printed + 1; s < LARGURA - 1; s++)
            printf(" ");
        }
        else if (j == 7) {
          // Se tarefas[i].concluida = 0 imprime "Status: Pendente" se for 1, "Concluída"
          printf(" Status: %s", tarefas[i].concluida ? "Concluída" : "Pendente ");
          printed = strlen(" Status: Concluída");
          // Preencher o resto da linha
          for (int s = printed; s < LARGURA - 1; s++) 
            printf(" ");
        }
        else {
          // Caso hajam linhas a mais, imprimir uma linha em branco
          for (int s = 0; s < LARGURA - 1; s++) 
            printf(" ");
        }
      printf("|\n");
      }
    printf("\n");
    }
  }
  printf("Pressione qualquer tecla para voltar ao menu principal...");
  system("pause>nul");
}
