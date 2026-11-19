# Sistema de Organização de Encomendas — Merge Sort

## Arquivos
- `Main.c`: menu e fluxo principal.
- `Encomenda.h`: estrutura `Encomenda`, constantes e protótipos.
- `Encomenda.c`: cadastro, listagem, busca, atualização, exclusão e Merge Sort.

## Compilar
Com GCC:

```bash
gcc -std=c11 -Wall -Wextra -pedantic Main.c Encomenda.c -o encomendas
```

Executar no Linux/macOS:

```bash
./encomendas
```

No Windows (MinGW):

```bash
gcc -std=c11 -Wall -Wextra -pedantic Main.c Encomenda.c -o encomendas.exe
encomendas.exe
```

## Critérios de ordenação
1. Código crescente.
2. Peso crescente.
3. Prazo crescente.

## Decisões de implementação
- Os registros são armazenados em vetor estático com capacidade de 50 encomendas.
- A busca é linear e retorna o índice do registro ou `-1` quando não encontrado.
- A exclusão desloca os registros seguintes uma posição para a esquerda.
- O Merge Sort ordena a estrutura `Encomenda` completa, comparando somente o campo selecionado.
- A intercalação usa memória auxiliar alocada com `malloc` e liberada com `free`.
- Em caso de empate, o elemento da metade esquerda é escolhido primeiro (`<=`), preservando a estabilidade.

## Complexidades
- Cadastro no fim do vetor: O(1), sem contar validações.
- Listagem: O(n).
- Busca: O(n).
- Atualização: O(n) pela busca, depois alteração O(1).
- Exclusão: O(n) pela busca e deslocamento.
- Merge Sort: O(n log n) em melhor, médio e pior caso.
- Memória auxiliar máxima de uma intercalação: O(n); pilha recursiva: O(log n).

## Observação
O programa mantém os dados apenas na memória durante a execução. Ao encerrar, os registros não são persistidos em arquivo.
