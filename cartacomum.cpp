#include "cartacomum.h"
#include "jogo.h"
#include "pontuacao.h"

CartaComum::CartaComum(int valor, float volumeEfeitos, bool mutar)
    : Carta(valor, volumeEfeitos, mutar){
    string caminho = ":/img/cards/frente_" + to_string(valor) + ".png";
    verso = QString::fromStdString(caminho);
}

void CartaComum::AoCombinar(Jogo *jogo){
    Pontuacao &jogador = jogo->GetJogadorAtual();
    jogador.SomaPontos(PONTO);
}
