#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "acao_item.h"
#include "jogador.h"

#define MAX_TAM_NOME_ITEM 21

struct Item{
    char nome[MAX_TAM_NOME_ITEM];
    int bonus;
    int preco;
};

/**
 * @brief Aloca dinamicamente uma ação do tipo ITEM e guarda nela o nome, o preco e o bonus
 * @param nome Nome do item
 * @param bonus forca a ser adicionada
 * @param preco preco do item a ser comprado
 * @return Ponteiro para o ouro criado
 */
Item *criaItem(char * nome, int bonus, int preco){
    Item * i = (Item*)calloc(1, sizeof(Item));
    strcpy(i->nome, nome);
    i->bonus = bonus;
    i->preco = preco;
    return i;
}

/**
 * @brief Lê da entrada padrão, na mesma linha, Nome, Preco e Bonus (a palavra ITEM
 * já deve ter sido lida) e cria o item com criaItem.
 * @return Ponteiro para o item criado
 */
Item *leItem(){
    char nome[MAX_TAM_NOME_ITEM];
    int bonus, preco;
    scanf("%s %d %d\n", nome, &preco, &bonus);
    Item * i = criaItem(nome, bonus, preco);
    return i;
}

/**
 * @brief Converte o dado genérico para Item e a célula vende um item.
 * Se o jogador possuir ouro suficiente, ele compra o item automaticamente
 * (não há opção de recusar): o preço é descontado do seu ouro e o bônus é somado à sua força.
 * Caso contrário, nada acontece.
 * @param dado Ponteiro genérico para o item
 * @param j Jogador que parou na célula
 * @return Sempre zero pois nao anda apos casa de item
 */
int executaItem(void *dado, Jogador *j){
    Item * i = (Item*)dado;
    if(i->preco <= obtemOuroJogador(j)){
        adicionaOuroJogador(j, -i->preco);
        adicionaForcaJogador(j, i->bonus);
    }
    return 0;
}

/**
 * @brief Converte o dado genérico para item e imprime, sem quebra de linha:
 * ITEM <nome> <preco> <bonus>"
 * @param dado Ponteiro genérico para o item
 */
void imprimeItem(void *dado){
    Item * i = (Item*)dado;
    printf("ITEM %s (P:%d F:+%d)", i->nome, i->preco, i->bonus);
}

/**
 * @brief Converte o dado genérico para item e libera a memória alocada para ele
 * @param dado Ponteiro genérico para o item
 */
void desalocaItem(void *dado){
    Item * i = (Item*)dado;
    free(i);
}



