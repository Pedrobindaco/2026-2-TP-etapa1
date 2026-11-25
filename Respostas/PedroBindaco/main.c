#include "acao_monstro.h"
#include "acao_ouro.h"
#include "mapa.h"
#include "jogador.h"
#include "celula.h"
#include "cadastro.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    Mapa * m = criaMapa();
    cadastraMapa(m);
    Vector * jogadores = VectorConstruct();
    cadastraJogadores(jogadores);




    return 0;
}