#ifndef PONTUACAO_H
#define PONTUACAO_H

#include <QGraphicsTextItem>
#include <QString>
#include <QPainter>

class Pontuacao: public QGraphicsTextItem
{
public:
    Pontuacao(QString texto, QGraphicsItem *parent = 0);
    void SomaPontos(float quantidade);
    void SubtraiPontos(float quantidade);
    QString GetTextoExibido();
    float GetPontuacao();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    float pontuacao;
    QString textoExibido;
};

#endif // PONTUACAO_H
