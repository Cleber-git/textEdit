#include "showbody.h"
#include "ui_showbody.h"

ShowBody::ShowBody(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowBody)
{
    ui->setupUi(this);
}

ShowBody::~ShowBody()
{
    delete ui;
}

void ShowBody::setPlainEditText(QString _text){
    ui->plainTextEdit->setPlainText(_text);
}
