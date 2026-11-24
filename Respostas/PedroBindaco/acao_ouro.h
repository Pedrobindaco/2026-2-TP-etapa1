#ifndef _ACAO_OURO_H_
#define _ACAO_OURO_H_

#include "jogador.h"

#define MAX_TAM_NOME_OURO 21

typedef struct Ouro Ouro;

/**
 * @brief Aloca dinamicamente uma ação do tipo OURO e guarda nela a quantidade
 * @param qtd Quantidade de ouro
 * @return Ponteiro para o ouro criado
 */
Ouro *criaOuro(int qtd);

/**
 * @brief Lê da entrada padrão, na mesma linha, quantidade (a palavra OURO
 * já deve ter sido lida) e cria o ouro com criaOuro.
 * @return Ponteiro para o ouro criado
 */
Ouro *leOuro();

/**
 * @brief Converte o dado genérico para ouro e adiciona valor
 * @param dado Ponteiro genérico para o ouro
 * @param j Jogador que parou na célula
 * @return Quantidade de ouro a ser adicionada ao jogador
 */
int executaOuro(void *dado, Jogador *j);

/**
 * @brief Converte o dado genérico para ouro e imprime, sem quebra de linha:
 * "OURO <qtd>"
 * @param dado Ponteiro genérico para o ouro
 */
void imprimeOuro(void *dado);

/**
 * @brief Converte o dado genérico para ouro e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o ouro
 */
void desalocaOuro(void *dado);

#endif // _ACAO_OURO_H_
