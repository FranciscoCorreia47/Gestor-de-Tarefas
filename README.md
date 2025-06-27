# Gestor-de-Tarefas
Projeto final do módulo de programação do curso de ASIBD, na EICM, no ano letivo 2024/2025

## Visão geral
Este trabalho pretende a criação de um gestor de tarefas, utilizando a Linguagem C, com o principal objetivo de conseguir a persistência dos dados, por meio de um ficheiro externo onde os mesmos são guardados.

### Estrutura
O código é todo escrito em C, compilado utilizando o GCC, e encontra-se dividido em 7 ficheiros de código:
- `main.c` -> O ponto de entrada do programa, chama as funções dos outros ficheiros;
- `menu.c/.h` -> Contêm as funções relativas à interface e apresentação dos dados;
- `tarefa.c/.h` -> Contêm as funções relativas à manipulação dos dados (inserção, alteração e eliminação);
- `ficheiro.c/.h` -> Contêm as funções relativas à escrita/leitura das tarefas no `ficheiro.dat`;

É importante notar que os dados são armazenados no `ficheiro.dat` em formato binário, facilitando a escrita/leitura de e para o array de structs no programa.

O struct das tarefas apresenta a seguinte estrutura:
```C
typedef struct {
  char nome[TAM_NOME];            // Nome da tarefa
  char descricao[TAM_DESC];      // Descrição detalhada da tarefa
  int concluida;              // Indica se a tarefa foi concluída (1 = sim, 0 = não)
} Tarefa;
Tarefa tarefas[MAX_TAREFAS];
```

Sendo que `TAM_NOME = 50`, `TAM_DESC = 128` e `MAX_TAREFAS = 100`

### Instalação e Execução
Para instalar o programa é necessário clonar o repositório:
```bash
git clone https://github.com/FranciscoCorreia47/Gestor-de-Tarefas.git
cd Gestor-de-Tarefas
```
Depois, é só compilar e executar o programa, usando **gcc**:
```bash
gcc main.c menu.c tarefa.c ficheiro.c -o gestor_de_tarefas
./gestor_de_tarefas
```

### Contribuições
Caso queira contribuir para o projeto, pode criar um fork do repositório, criar um novo branch, e após fazer as suas alterações, dar commit e iniciar um pull request.
Será apreciado que se mantenha o estilo de formatação corrente, assim como a boa documentação do código por meio de comentários claros.
