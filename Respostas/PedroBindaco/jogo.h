#ifndef _JOGO_H_
#define _JOGO_H_

typedef struct Jogo Jogo;

void criaJogo(Mapa * m, Vector * jogadores);

void desalocaJogo(Jogo * jogo);

#endif //_JOGO_H_