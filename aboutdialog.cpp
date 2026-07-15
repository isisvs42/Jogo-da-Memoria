#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AboutDialog)
{
    ui->setupUi(this);

    ui->fotoLabel->setPixmap(QPixmap(":/foto/IMG_1561.jpg").scaled(150, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_fecharButton_clicked()
{
    close();
}
