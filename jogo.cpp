#include "jogo.h"
#include "carta.h"
#include "cartaarmadilha.h"
#include "cartabonus.h"
#include "cartacomum.h"
#include "pontuacao.h"
#include "victory.h"
#include "conexao.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>    // mt19937, random_device

#include <QTimer>
#include <QDateTime>
#include <QMessageBox>

#define LINHAS 4
#define COLUNAS 5

Jogo::Jogo(QString jogador1, QString jogador2, float volumeEfeitos, bool mutar, QWidget *parent):QGraphicsView(parent){
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(QBrush(QImage(":/img/cards/background.png")));

    scene->setSceneRect(0, 0, 1200, 900);

    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(1200, 900);

    this->CriarTabuleiro(volumeEfeitos, mutar);

    this->pontuacaoJogador1 = new Pontuacao(jogador1.trimmed());
    this->pontuacaoJogador1->setPos(this->pontuacaoJogador1->x()+50, this->pontuacaoJogador1->y());
    scene->addItem(this->pontuacaoJogador1);

    this->jogadorAtual = this->pontuacaoJogador1;
    this->jogadorAtual->setDefaultTextColor(QColor("#FF1493")); // cor da vez do jogador 1

    this->pontuacaoJogador2 = new Pontuacao(jogador2.trimmed());
    this->pontuacaoJogador2->setPos(this->pontuacaoJogador2->x()+950, this->pontuacaoJogador2->y());
    scene->addItem(this->pontuacaoJogador2);

    show();
}

void Jogo::EmbaralharCartas(){
    random_device rd;
    mt19937 gerador(rd());
    shuffle(this->posicoes.begin(), this->posicoes.end(), gerador);

    int contador = 0;
    for(int l = 0; l < LINHAS; l++){
        for(int c = 0; c < COLUNAS; c++){

            int x = this->posicoes[contador].first;
            int y = this->posicoes[contador].second;

            this->cartas[contador]->setPos(x, y);
            //scene->addItem(this->cartas[contador]);

            contador++;
        }
    }
}

void Jogo::VerificarCombinacao(Carta *cartaClicada){

    if(cartaClicada->GetValor() == primeiraEscolha->GetValor()
        || cartaClicada->GetValor() == 0 || primeiraEscolha->GetValor() == 0
        || cartaClicada->GetValor() == 10 || primeiraEscolha->GetValor() == 10){

        cartaClicada->AoCombinar(this);
        primeiraEscolha->AoCombinar(this);
    }


    if(cartaClicada->GetValor() == primeiraEscolha->GetValor()){

        cartaClicada->MarcarCombinada();
        primeiraEscolha->MarcarCombinada();

        this->primeiraEscolha = nullptr;

        paresFormados++;

        if(paresFormados == 9){
            QString vencedor;
            if (this->pontuacaoJogador1->GetPontuacao() > this->pontuacaoJogador2->GetPontuacao())
                vencedor = pontuacaoJogador1->GetTextoExibido();
            else
                vencedor = pontuacaoJogador2->GetTextoExibido();

            Conexao con;
            if(con.abrir()){
                QSqlQuery query;
                query.prepare("insert into Partida (jogador1,jogador2,vencedor,pontuacao_jogador1,pontuacao_jogador2,data) values"
                              "('"+pontuacaoJogador1->GetTextoExibido()+"','"+pontuacaoJogador2->GetTextoExibido()+"','"+vencedor+"','"
                              +QString::number(pontuacaoJogador1->GetPontuacao())+"','"+QString::number(pontuacaoJogador2->GetPontuacao())+"','"
                              +QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm")+"')");

                if(!query.exec()){
                    QMessageBox::warning(this, "ERRO", "Erro ao salvar partida");
                }
                con.fechar();
            }

            Victory v(vencedor);
            v.setModal(true);
            v.exec();
        }

        return;
    }

    Carta *carta = this->primeiraEscolha;
    this->primeiraEscolha = nullptr;

    QTimer *timer = new QTimer();
    timer->setSingleShot(true);

    if(cartaClicada->GetValor() < 10)
        connect(timer,SIGNAL(timeout()),cartaClicada,SLOT(Esconder()));

    if(carta->GetValor() < 10)
        connect(timer,SIGNAL(timeout()),carta,SLOT(Esconder()));

    connect(timer, &QTimer::timeout, timer, &QTimer::deleteLater);

    timer->start(1000);

    TrocarTurno();
}

void Jogo::CriarTabuleiro(float volumeEfeitos, bool mutar){
    int id = 1;
    for(int l = 0; l < (LINHAS*COLUNAS - 2)/2; l++){
        this->cartas.push_back(new CartaComum(id, volumeEfeitos, mutar));
        this->cartas.push_back(new CartaComum(id, volumeEfeitos, mutar));
        id++;
    }

    this->cartas.push_back(new CartaBonus(10, volumeEfeitos, mutar));

    this->cartas.push_back(new CartaArmadilha(0, volumeEfeitos, mutar));

    const int margemEsquerda = 80;
    const int margemTopo = 60;
    const int tamanhoCarta = 200;
    const int espacamentoColunas = 10;
    const int espacamentoLinhas = 10;
    const int passoColuna = tamanhoCarta + espacamentoColunas;
    const int passoLinha = tamanhoCarta + espacamentoLinhas;

    int contador = 0;
    for(int l = 0; l < LINHAS; l++){
        for(int c = 0; c < COLUNAS; c++){

            int x = margemEsquerda + c * passoColuna;
            int y = margemTopo + l * passoLinha;

            this->posicoes.push_back(make_pair(x, y));

            this->cartas[contador]->setPos(x, y);
            scene->addItem(this->cartas[contador]);
            contador++;
        }
    }

    this->EmbaralharCartas();
}

void Jogo::TrocarTurno(){
    // restauro a cor do jogador
    this->jogadorAtual->setDefaultTextColor(QColor("#FFB6C1"));

    //troco a vez mudando a cor da fonte
    if(this->jogadorAtual == this->pontuacaoJogador1)
        this->jogadorAtual = this->pontuacaoJogador2;
    else
        this->jogadorAtual = this->pontuacaoJogador1;

    this->jogadorAtual->setDefaultTextColor(QColor("#FF1493"));

}

int Jogo::GetValorPrimeiraEscolha(){
    return (this->primeiraEscolha)->GetValor();
}

void Jogo::SetPrimeiraEscolha(Carta *carta){
    this->primeiraEscolha = carta;
}

Pontuacao& Jogo::GetJogadorAtual(){
    return *jogadorAtual;
}

bool Jogo::TemPrimeiraEscolha(){
    if(!this->primeiraEscolha) return false;
    return true;
}
