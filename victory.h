#ifndef VICTORY_H
#define VICTORY_H

#include <QDialog>

namespace Ui {
class Victory;
}

class Victory : public QDialog
{
    Q_OBJECT

public:
    explicit Victory(QString vencedor, QWidget *parent = nullptr);
    ~Victory();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Victory *ui;
};

#endif // VICTORY_H
