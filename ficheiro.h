//Início de um include guard. Evita que o conteúdo deste arquivo seja incluído mais de uma vez no mesmo arquivo de código.
#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "tarefa.h"

//Define uma macro constante com o nome do arquivo onde as tarefas serão armazenadas.
#define ARQUIVO_TAREFAS "arquivo.txt" 


int salvar_tarefas(Tarefa *tarefas, int qtd); //Declara a função que salva tarefas no arquivo.
int carregar_tarefas(Tarefa *tarefas, int max); //Declara a função que carrega tarefas do arquivo.

#endif // ARQUIVO_H
