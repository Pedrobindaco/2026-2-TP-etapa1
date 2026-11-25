#ifndef _ACAO_VOLTA_H_
#define _ACAO_VOLTA_H_

#include "jogador.h"

typedef struct Volta Volta;

/**
 * @brief Aloca dinamicamente uma ação do tipo VOLTA e guarda nela a quantidade
 * @param qtd Quantidade de casas voltadas
 * @return Ponteiro para o Volta criado
 */
Volta *criaVolta(int qtd);

/**
 * @brief Lê da entrada padrão, na mesma linha, quantidade (a palavra VOLTA
 * já deve ter sido lida) e cria o Volta com criaVolta.
 * @return Ponteiro para o ouro criado
 */
Volta *leVolta();

/**
 * @brief Converte o dado genérico para Volta
 * @param dado Ponteiro genérico para o Volta
 * @param j Jogador que parou na célula
 * @return Quantidade de casas a serem voltadas 
 */
int executaVolta(void *dado, Jogador *j);

/**
 * @brief Converte o dado genérico para Volta e imprime, sem quebra de linha:
 * "VOLTA <qtd>"
 * @param dado Ponteiro genérico para o Volta
 */
void imprimeVolta(void *dado);

/**
 * @brief Converte o dado genérico para Volta e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o Volta
 */
void desalocaVolta(void *dado);

#endif // _ACAO_VOLTA_H_
