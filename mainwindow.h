#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>

#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_playButton_clicked();
    void on_exitButton_clicked();
    void on_settingsButton_clicked();
    void on_actionCriadora_triggered();
    void on_scoreButton_clicked();

private:
    Ui::MainWindow *ui;

    Settings settings;

    QMediaPlayer *music;
    QAudioOutput *audioOutput;

    QString jogador1;
    QString jogador2;

    void AtualizarConfiguracoes();
};
#endif // MAINWINDOW_H
