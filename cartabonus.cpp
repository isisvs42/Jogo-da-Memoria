#include "cartabonus.h"
#include "jogo.h"
#include "pontuacao.h"

CartaBonus::CartaBonus(int valor, float volumeEfeitos, bool mutar)
    : Carta(valor, volumeEfeitos, mutar){

    verso = ":/img/cards/verso_bonus_estrela.png";

    clickSound->setAudioOutput(audioOutputClick);
    clickSound->setSource(QUrl("qrc:/sounds/sounds/powerup.mp3"));
}

void CartaBonus::AoCombinar(Jogo *jogo){
    Pontuacao &jogador = jogo->GetJogadorAtual();
    jogador.SomaPontos(PONTOS_EXTRAS);
}
