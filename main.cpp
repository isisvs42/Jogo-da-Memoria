#include <QApplication>
#include "mainwindow.h"
#include "jogo.h"

Jogo *jogo; // variavel global, que pode ser acessada
//por todos os arquivos do projeto

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*
    jogo = new Jogo();
    jogo->show();
    */

    return a.exec();

}
