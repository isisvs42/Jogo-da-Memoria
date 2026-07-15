#include "settings.h"
#include "ui_settings.h"
#include "funcoes.h"

Settings::Settings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings)
{
    ui->setupUi(this);
    setFixedSize(800, 600);

    lerArquivo("configuracoes.txt", *this);

    ui->musicaDeFundoComboBox->setCurrentText(this->musicaDeFundo);
    ui->horizontalSliderSong->setSliderPosition(this->volumeDaMusica);
    ui->horizontalSliderEffects->setSliderPosition(this->volumeDosEfeitos);
    ui->muteButton->setChecked(this->mutarTudo);
    ui->lineEditJogador1->setText(this->jogador1);
    ui->lineEditJogador2->setText(this->jogador2);
}

Settings::~Settings()
{
    delete ui;
}

QString Settings::GetMusicaDeFundo(){
    return this->musicaDeFundo;
}

float Settings::GetVolumeDaMusica(){
    return this->volumeDaMusica;
}

float Settings::GetVolumeDosEfeitos(){
    return this->volumeDosEfeitos;
}

bool Settings::GetMutarTudo(){
    return this->mutarTudo;
}

QString Settings::GetJogador1(){
    return this->jogador1;
}

QString Settings::GetJogador2(){
    return this->jogador2;
}

void Settings::SetMusicaDeFundo(QString musicaDeFundo){
    this->musicaDeFundo = musicaDeFundo;
}

void Settings::SetVolumeDaMusica(float volumeDaMusica){
    this->volumeDaMusica = volumeDaMusica;
}

void Settings::SetVolumeDosEfeitos(float volumeDosEfeitos){
    this->volumeDosEfeitos = volumeDosEfeitos;
}

void Settings::SetMutarTudo(bool mutarTudo){
    this->mutarTudo = mutarTudo;
}

void Settings::SetJogador1(QString jogador1){
    this->jogador1 = jogador1;
}

void Settings::SetJogador2(QString jogador2){
    this->jogador2 = jogador2;
}

void Settings::on_btnSalvar_clicked()
{
    this->musicaDeFundo = ui->musicaDeFundoComboBox->currentText();
    this->volumeDaMusica = ui->horizontalSliderSong->sliderPosition();
    this->volumeDosEfeitos = ui->horizontalSliderEffects->sliderPosition();
    this->mutarTudo = ui->muteButton->isChecked();
    this->jogador1 = ui->lineEditJogador1->text();
    this->jogador2 = ui->lineEditJogador2->text();

    salvarArquivo("configuracoes.txt", *this);

    this->hide();
}

void Settings::on_btnCancelar_clicked()
{
    musicaDeFundo = "Hoogway - A Place I Love";
    volumeDaMusica = 50;
    volumeDosEfeitos = 50;
    mutarTudo = false;
    jogador1 = "Jogador 1";
    jogador2 = "Jogador 2";

    ui->musicaDeFundoComboBox->setCurrentText(this->musicaDeFundo);
    ui->horizontalSliderSong->setSliderPosition(this->volumeDaMusica);
    ui->horizontalSliderEffects->setSliderPosition(this->volumeDosEfeitos);
    ui->muteButton->setChecked(this->mutarTudo);
    ui->lineEditJogador1->setText(this->jogador1);
    ui->lineEditJogador2->setText(this->jogador2);

    this->hide();
}


void Settings::on_muteButton_clicked()
{
    if(ui->muteButton->isChecked()){
        ui->muteButton->setText("ON");
        return;
    }

    ui->muteButton->setText("OFF");
}

