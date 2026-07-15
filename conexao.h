#ifndef CONEXAO_H
#define CONEXAO_H

#include <QtSql>
#include <QCoreApplication>

class Conexao{
public:
    QSqlDatabase bancoDeDados;
    QString banco;

    // conexão com o banco de dados
    Conexao(){
        // endereço do arquivo banco de dados (pasta do executável)
        banco = QCoreApplication::applicationDirPath() + "/placar";

        // nome do programa para conexão
        bancoDeDados = QSqlDatabase::addDatabase("QSQLITE");
    }

    void fechar(){
        bancoDeDados.close();
    }

    bool abrir(){
        bancoDeDados.setDatabaseName(banco);

        if(!bancoDeDados.open()) return false;

        QSqlQuery query;
        query.exec("create table if not exists Partida ("
                   "jogador1 TEXT NOT NULL,"
                   "jogador2 TEXT NOT NULL,"
                   "vencedor TEXT NOT NULL,"
                   "pontuacao_jogador1 INTEGER NOT NULL,"
                   "pontuacao_jogador2 INTEGER NOT NULL,"
                   "data TEXT NOT NULL"
                   ")");

        return true;
    }

    bool aberto(){
        if(bancoDeDados.isOpen()) return true;

        else return false;
    }
};

#endif // CONEXAO_H
