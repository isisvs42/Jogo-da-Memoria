#include "carta.h"
#include "jogo.h"

extern Jogo *jogo;

Carta::Carta(int valor, float volumeEfeitos, bool mutar, QGraphicsItem *parent)
: QObject(nullptr), QGraphicsPixmapItem(parent){


    setPixmap(QPixmap(":/img/cards/verso_normal.png"));

    /*
    bulletsound = new QMediaPlayer();
    audioOutputBullet = new QAudioOutput();
    bulletsound->setAudioOutput(audioOutputBullet);
    bulletsound->setSource(QUrl("qrc:/sounds/sounds/Laser.mp3"));
    */

    clickSound = new QMediaPlayer();
    audioOutputClick = new QAudioOutput();
    clickSound->setAudioOutput(audioOutputClick);
    clickSound->setSource(QUrl("qrc:/sounds/sounds/pop.mp3"));

    matchSound = new QMediaPlayer();
    audioOutputMatch = new QAudioOutput();
    matchSound->setAudioOutput(audioOutputMatch);
    matchSound->setSource(QUrl("qrc:/sounds/sounds/fairy dust.mp3"));

    audioOutputClick->setVolume(volumeEfeitos / 100);
    audioOutputClick->setMuted(mutar);

    audioOutputMatch->setVolume(volumeEfeitos / 100);
    audioOutputMatch->setMuted(mutar);

    this->valor = valor;
    this->revelada = false;
    this->combinada = false;
}

Carta::~Carta(){

}

int Carta::GetValor(){
    return this->valor;
}

bool Carta::EstaRevelada(){
    return this->revelada;
}

bool Carta::EstaCombinada(){
    return this->combinada;
}

void Carta::Revelar(){
    this->revelada = true;
    this->setPixmap(this->verso);

    if (clickSound) {
        clickSound->stop(); // reinicia o som caso ele já esteja tocando
        clickSound->play();
    }
}

void Carta::Esconder(){
    this->revelada = false;
    this->setPixmap(QPixmap(":/img/cards/verso_normal.png"));
}

void Carta::MarcarCombinada(){
    this->combinada = true;

    if (matchSound) {
        matchSound->stop();
        matchSound->play();
    }
}

void Carta::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!this->EstaCombinada() && !this->EstaRevelada()) {
        this->Revelar();

        if(!(jogo->TemPrimeiraEscolha())){
            jogo->SetPrimeiraEscolha(this);
            return;
        }

        jogo->VerificarCombinacao(this);
    }
}
