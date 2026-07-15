#include "placar.h"
#include "ui_placar.h"

#include <QMessageBox>
#include <QSqlQuery>

Placar::Placar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Placar)
{
    ui->setupUi(this);
    setFixedSize(800, 600);

    // abrir o banco de dados
    if(!con.aberto()){
        if(!con.abrir()){
            QMessageBox::warning(this, "ERRO", "Erro ao abrir banco de Dados");
        }
    }

    this->PreencherTabela();
}

Placar::~Placar()
{
    delete ui;
}

void Placar::PreencherTabela(){
    QSqlQuery query;
    query.exec("select jogador1,jogador2,vencedor,pontuacao_jogador1,pontuacao_jogador2,data "
               "from Partida order by data desc");

    int linha = 0;
    while(query.next()){
        ui->tabelaPlacar->insertRow(linha);
        ui->tabelaPlacar->setItem(linha, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tabelaPlacar->setItem(linha, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tabelaPlacar->setItem(linha, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tabelaPlacar->setItem(linha, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->tabelaPlacar->setItem(linha, 4, new QTableWidgetItem(query.value(4).toString()));
        ui->tabelaPlacar->setItem(linha, 5, new QTableWidgetItem(query.value(5).toString()));
        linha++;
    }

    con.fechar();
}

void Placar::on_fecharButton_clicked()
{
    close();
}
