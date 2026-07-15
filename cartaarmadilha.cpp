#include "cartaarmadilha.h"
#include "jogo.h"
#include "pontuacao.h"

CartaArmadilha:: CartaArmadilha(int valor, float volumeEfeitos, bool mutar)
    : Carta(valor, volumeEfeitos, mutar){

    verso = ":/img/cards/verso_armadilha_bomba.png";

    clickSound->setAudioOutput(audioOutputClick);
    clickSound->setSource(QUrl("qrc:/sounds/sounds/small explotion.mp3"));
}

void CartaArmadilha::AoCombinar(Jogo *jogo){
    Pontuacao &jogador = jogo->GetJogadorAtual();
    jogador.SubtraiPontos(PENALIDADE);
    jogo->EmbaralharCartas();
}
