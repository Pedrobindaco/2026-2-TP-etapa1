#ifndef _JOGO_H_
#define _JOGO_H_

#include "vector.h"
#include "mapa.h"

typedef struct Jogo Jogo;

Jogo * criaJogo(Mapa * m, Vector * jogadores);

void desalocaJogo(Jogo * jogo);

void rodaJogo(Jogo * jogo, char proximaAcao);

Mapa *obtemMapaJogo(Jogo *jogo);

Vector *obtemJogadoresJogo(Jogo *jogo);

int obtemQtdJogadoresJogo(Jogo *jogo);

int obtemVezJogo(Jogo *jogo);

void avancaVezJogo(Jogo *jogo);

#endif //_JOGO_H_