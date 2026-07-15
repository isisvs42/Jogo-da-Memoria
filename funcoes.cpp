#include "funcoes.h"
#include <fstream>
#include <QMessageBox>

void lerArquivo(string nomeArquivo, Settings &settings) {
    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open())
        return;

    string linha;
    float valorFloat;
    bool valorBool;

    std::getline(arquivo, linha);
    settings.SetMusicaDeFundo(QString::fromStdString(linha));

    arquivo >> valorFloat;
    settings.SetVolumeDaMusica(valorFloat);

    arquivo >> valorFloat;
    settings.SetVolumeDosEfeitos(valorFloat);

    arquivo >> valorBool;
    settings.SetMutarTudo(valorBool);

    arquivo.ignore();

    std::getline(arquivo, linha);
    settings.SetJogador1(QString::fromStdString(linha));

    std::getline(arquivo, linha);
    settings.SetJogador2(QString::fromStdString(linha));

    arquivo.close();
}

void salvarArquivo(string nomeArquivo, Settings &settings) {
    ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        QMessageBox::warning(nullptr, "ERRO", "Erro ao salvar configurações");
        return;
    }

    arquivo << settings.GetMusicaDeFundo().toStdString() << "\n";
    arquivo << settings.GetVolumeDaMusica() << "\n";
    arquivo << settings.GetVolumeDosEfeitos() << "\n";
    arquivo << settings.GetMutarTudo() << "\n";
    arquivo << settings.GetJogador1().toStdString() << "\n";
    arquivo << settings.GetJogador2().toStdString() << "\n";

    arquivo.close();
}
