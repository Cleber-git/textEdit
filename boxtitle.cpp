#include "boxtitle.h"
#include "ui_boxtitle.h"

BoxTitle::BoxTitle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoxTitle)
{
    ui->setupUi(this);
}

BoxTitle::~BoxTitle()
{
    delete ui;
}

void BoxTitle::on_pushButton_clicked()
{
    emit sendTitle(ui->lineEdit->text());
    ui->lineEdit->clear();
    hide();
}

