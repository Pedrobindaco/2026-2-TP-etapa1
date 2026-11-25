#include "rolagem.h"
#include "dado.h"
#include "jogo.h"
#include "celula.h"
#include "jogador.h"
#include "mapa.h"
#include "vector.h"
#include <stdlib.h>

int resultadoDisputa(Mapa * m, Jogador * j, int casaDestino){
    Jogador * ocupante = obtemOcupanteMapa(m, casaDestino);
    if (ocupante == NULL){
        moveJogadorMapa(m, j, casaDestino);
        return 1;
    }

    retiraJogadorMapa(m, j);

    if(venceDisputaJogador(j, ocupante)){
        incrementaDisputasVencidasJogador(j);
        recuaJogadorMapa(m, ocupante, casaDestino);
        moveJogadorMapa(m, j, casaDestino);
        return 1;
    }

    incrementaDisputasVencidasJogador(ocupante);
    recuaJogadorMapa(m, j, casaDestino);
    return 0;
}

void jogaTurno(Mapa * m, Jogador * j){
    int casaFim = obtemPosicaoFimMapa(m);
    incrementaJogadasJogador(j);
    int casaDestino = obtemPosicaoJogador(j) + RolaDado();
    if (casaDestino >= casaFim){
        moveJogadorMapa(m, j, casaFim);
        return;
    }

    if(resultadoDisputa(m, j, casaDestino) == 0){
        return;
    }
    Celula * celulaAtual = obtemCelulaMapa(m, casaDestino);
    if (celulaAtual == NULL){
        return;
    }
    int deslocamento = executaAcaoCelula(celulaAtual, j);

    if (deslocamento == RECUO_CELULA){
        recuaJogadorMapa(m, j, casaDestino);
        return;
    }

    if (deslocamento != 0){
        casaDestino += deslocamento;
        if (casaDestino < 0){
            casaDestino = 0;
        }
        if (casaDestino >= casaFim){
            moveJogadorMapa(m, j, casaFim);
            return;
        }
        resultadoDisputa(m, j, casaDestino);
    }
}

int partidaTerminou(Jogo * jogo){
    Vector * jogadores = obtemJogadoresJogo(jogo);
    int casaFim = obtemPosicaoFimMapa(obtemMapaJogo(jogo));
    for (int i = 0; i < obtemQtdJogadoresJogo(jogo); i++){
        if (obtemPosicaoJogador(VectorGet(jogadores, i)) >= casaFim){
            return 1;
        }
    }
    return 0;
}

void executaRolagem(Jogo * jogo, int qtdRolagens){
    for (int i = 0; i < qtdRolagens && !partidaTerminou(jogo); i++){
        Jogador * jogadorAtual = VectorGet(obtemJogadoresJogo(jogo), obtemVezJogo(jogo));
        jogaTurno(obtemMapaJogo(jogo), jogadorAtual);
        avancaVezJogo(jogo);
    }
}

