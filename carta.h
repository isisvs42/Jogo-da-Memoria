#ifndef CARTA_H
#define CARTA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QAudioOutput>

class Jogo;

class Carta : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Carta(int valor, float volumeEfeitos, bool mutar, QGraphicsItem *parent = nullptr);
    virtual ~Carta();

    int GetValor();
    bool EstaRevelada();
    bool EstaCombinada();
    void Revelar();
    void MarcarCombinada();

    virtual void AoCombinar(Jogo *jogo) = 0;

public slots:
    void Esconder();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override; // substitui o slot clicked()

    int valor;
    bool revelada;
    bool combinada;

    QMediaPlayer *clickSound;
    QAudioOutput *audioOutputClick;

    QMediaPlayer *matchSound;
    QAudioOutput *audioOutputMatch;

    QString verso;
};

#endif // CARTA_H
