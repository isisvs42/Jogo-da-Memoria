#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jogo.h"
#include "aboutdialog.h"
#include "placar.h"

extern Jogo *jogo;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(800, 600);

    music = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    music->setAudioOutput(audioOutput);

    this->AtualizarConfiguracoes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playButton_clicked()
{
    jogo = new Jogo(this->settings.GetJogador1(), this->settings.GetJogador2(), this->settings.GetVolumeDosEfeitos(), this->settings.GetMutarTudo());
    jogo->show();
}

void MainWindow::on_exitButton_clicked()
{
    QApplication::quit();
}


void MainWindow::on_settingsButton_clicked()
{
    this->settings.setFixedSize(800, 600);
    this->settings.setModal(true);
    this->settings.exec();

    this->AtualizarConfiguracoes();
}

void MainWindow::AtualizarConfiguracoes(){
    QUrl novaMusica(QString::fromStdString("qrc:/songs/songs/" + this->settings.GetMusicaDeFundo().toStdString() + ".mp3"));

    if (music->source() != novaMusica) {
        this->music->setSource(novaMusica);
        this->music->setLoops(QMediaPlayer::Infinite);
        this->music->play();
    }

    this->audioOutput->setVolume(settings.GetVolumeDaMusica() / 100);
    this->audioOutput->setMuted(settings.GetMutarTudo());
}

void MainWindow::on_actionCriadora_triggered()
{
    AboutDialog dialog(this);
    dialog.exec();
}


void MainWindow::on_scoreButton_clicked()
{
    Placar placar(this);
    placar.setModal(true);
    placar.exec();
}

