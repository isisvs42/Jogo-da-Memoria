#ifndef JOGO_H
#define JOGO_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVector>

#include <vector>
#include <utility>

#include "carta.h"
#include "pontuacao.h"

using namespace std;

class Jogo : public QGraphicsView
{
public:
    Jogo(QString jogador1, QString jogador2, float volumeEfeitos, bool mutar, QWidget *parent = nullptr);

    QGraphicsScene *scene;
    QVector<Carta*> cartas;

    vector<pair<int, int>> posicoes;

    void SomaPontos(int quantidade);
    void SubtraiPontos(int quantidade);
    void EmbaralharCartas();

    void VerificarCombinacao(Carta *cartaClicada);

    int GetValorPrimeiraEscolha();
    void SetPrimeiraEscolha(Carta *carta);
    bool TemPrimeiraEscolha();

    Pontuacao& GetJogadorAtual();

private:
    void CriarTabuleiro(float volumeEfeitos, bool mutar);
    void TrocarTurno();

    Carta *primeiraEscolha = nullptr;

    Pontuacao *pontuacaoJogador1 = nullptr;
    Pontuacao *pontuacaoJogador2 = nullptr;
    Pontuacao *jogadorAtual = nullptr;

    int paresFormados = 0;
};

#endif // JOGO_H
