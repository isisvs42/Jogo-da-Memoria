#ifndef PLACAR_H
#define PLACAR_H

#include <QDialog>

#include "conexao.h"

namespace Ui {
class Placar;
}

class Placar : public QDialog
{
    Q_OBJECT

public:
    explicit Placar(QWidget *parent = nullptr);
    ~Placar();

private slots:
    void on_fecharButton_clicked();

private:
    Ui::Placar *ui;
    Conexao con;
    void PreencherTabela();
};

#endif // PLACAR_H
