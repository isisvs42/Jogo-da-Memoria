#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

    QString GetMusicaDeFundo();
    float GetVolumeDaMusica();
    float GetVolumeDosEfeitos();
    bool GetMutarTudo();

    QString GetJogador1();
    QString GetJogador2();

    void SetMusicaDeFundo(QString musicaDeFundo);
    void SetVolumeDaMusica(float volumeDaMusica);
    void SetVolumeDosEfeitos(float volumeDosEfeitos);
    void SetMutarTudo(bool mutarTudo);

    void SetJogador1(QString jogador1);
    void SetJogador2(QString jogador2);

private slots:
    void on_btnSalvar_clicked();
    void on_btnCancelar_clicked();
    void on_muteButton_clicked();

private:
    Ui::Settings *ui;

    QString musicaDeFundo = "Hoogway - A Place I Love";
    float volumeDaMusica = 50;
    float volumeDosEfeitos = 50;
    bool mutarTudo = false;

    QString jogador1 = "Jogador 1";
    QString jogador2 = "Jogador 2";
};

#endif // SETTINGS_H
