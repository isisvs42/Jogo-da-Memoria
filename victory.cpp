#include "victory.h"
#include "ui_victory.h"
#include "jogo.h"
#include "mainwindow.h"

#include <string>

using namespace std;

extern Jogo *jogo;

Victory::Victory(QString vencedor, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Victory)
{
    ui->setupUi(this);
    setFixedSize(400, 300);

    string v = vencedor.toStdString();
    string txt = ui->texto->text().toStdString();

    txt.replace(txt.find("Jogador N"), txt.find("Jogador N")+9, v);
    txt.replace(txt.find("Jogador N"), txt.find("Jogador N")+9, v); // troca a segunda ocorrência também

    ui->texto->setText(QString::fromStdString(txt));
}

Victory::~Victory()
{
    delete ui;
}

void Victory::on_pushButton_clicked()
{
    this->close();
    jogo->close();
}

