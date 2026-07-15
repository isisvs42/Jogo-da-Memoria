#include "pontuacao.h"

#include <QFont>

Pontuacao::Pontuacao(QString texto, QGraphicsItem *parent):QGraphicsTextItem(parent){
    this->textoExibido = texto;
    this->pontuacao = 0;
    setPlainText(this->textoExibido + ": " + QString::number(this->pontuacao));
    setDefaultTextColor(QColor("#FFB6C1"));
    setFont(QFont("Comic Sans MS",30));
}

void Pontuacao::SomaPontos(float quantidade){
    this->pontuacao += quantidade;
    setPlainText(this->textoExibido + ": " + QString::number(this->pontuacao));
    setDefaultTextColor(QColor("#FF1493"));
    setFont(QFont("Comic Sans MS",30));
}

void Pontuacao::SubtraiPontos(float quantidade){
    this->pontuacao -= quantidade;
    setPlainText(this->textoExibido + ": " + QString::number(this->pontuacao));
    setDefaultTextColor(QColor("#FF1493"));
    setFont(QFont("Comic Sans MS",30));
}

void Pontuacao::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    // fundo preto translúcido
    painter->setBrush(QColor(0, 0, 0, 150));
    painter->setPen(Qt::NoPen);
    painter->drawRoundedRect(boundingRect(), 6, 6);

    // chama o paint original para desenhar o texto por cima
    QGraphicsTextItem::paint(painter, option, widget);
}

QString Pontuacao::GetTextoExibido(){
    return this->textoExibido;
}

float Pontuacao::GetPontuacao(){
    return this->pontuacao;
}
