#ifndef _ROLAGEM_H_
#define _ROLAGEM_H_

#include "jogo.h"

int resultadoDisputa(Mapa * m, Jogador * j, int casaDestino);

void jogaTurno(Mapa * m, Jogador * j);

int partidaTerminou(Jogo * jogo);

void executaRolagem(Jogo * jogo, int qtdRolagens);

#endif //_ROLAGEM_H_