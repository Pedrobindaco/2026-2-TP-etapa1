#ifndef _ACAO_ITEM_H_
#define _ACAO_ITEM_H_

#include "jogador.h"

#define MAX_TAM_NOME_ITEM 21

typedef struct Item Item;

/**
 * @brief Aloca dinamicamente uma ação do tipo ITEM e guarda nela o nome, o preco e o bonus
 * @param nome Nome do item
 * @param bonus forca a ser adicionada
 * @param preco preco do item a ser comprado
 * @return Ponteiro para o ouro criado
 */
Item *criaItem(char * nome, int bonus, int preco);

/**
 * @brief Lê da entrada padrão, na mesma linha, Nome, Preco e Bonus (a palavra ITEM
 * já deve ter sido lida) e cria o item com criaItem.
 * @return Ponteiro para o item criado
 */
Item *leItem();

/**
 * @brief Converte o dado genérico para Item e a célula vende um item.
 * Se o jogador possuir ouro suficiente, ele compra o item automaticamente
 * (não há opção de recusar): o preço é descontado do seu ouro e o bônus é somado à sua força.
 * Caso contrário, nada acontece.
 * @param dado Ponteiro genérico para o item
 * @param j Jogador que parou na célula
 * @return Sempre zero pois nao anda apos casa de ouro
 */
int executaItem(void *dado, Jogador *j);

/**
 * @brief Converte o dado genérico para item e imprime, sem quebra de linha:
 * ITEM <nome> <preco> <bonus>"
 * @param dado Ponteiro genérico para o item
 */
void imprimeItem(void *dado);

/**
 * @brief Converte o dado genérico para item e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o item
 */
void desalocaItem(void *dado);

#endif // _ACAO_ITEM_H_
