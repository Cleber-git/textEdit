#include "showbody.h"
#include "ui_showbody.h"
#include "mainwindow.h"
#include "log.h"

#include <QPlainTextEdit>
#include <QDebug>


ShowBody::ShowBody(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowBody)
{

    m_btnUpdate = new QPushButton(this);

    ui->setupUi(this);

    connect(ui->plainTextEdit, SIGNAL(textChanged()), this, SLOT(on_change_Plain_Text()));
    connect(m_btnUpdate, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_clicked()));
    m_btnUpdate->setGeometry(1220,10,61,20);
    m_btnUpdate->setText("Update");
    m_btnUpdate->hide();
    ui->msg_info->hide();
    ui->lbl_ok->hide();
    this->setWindowTitle(m_title);
}

ShowBody::~ShowBody()
{
    delete ui;
}

void ShowBody::setPlainEditText(QString _text){
    ui->plainTextEdit->setPlainText(_text);
    m_body = _text;
}

void ShowBody::on_change_Plain_Text(){
    ui->lbl_ok->hide();
    m_count++;
    qDebug() << m_count;
    if(m_count <= 2){
        return;
    }
    ui->msg_info->setText("Modificado");
    ui->msg_info->setStyleSheet("Color: red ;");
    ui->msg_info->show();
    m_btnUpdate->show();
    m_body = ui->plainTextEdit->toPlainText();

}

void ShowBody::on_pushButton_clicked()
{
    m_db.update(m_title, m_body);
    qDebug()<< "Atualizado" << m_title << " == "<< m_body;
    ui->msg_info->setStyleSheet("color: green ;");
    m_btnUpdate->hide();
    m_count=0;
    ui->msg_info->hide();
    ui->lbl_ok->show();
}

void ShowBody::receiveTitle(QString _title){
    m_title = _title;
}

void ShowBody::setCount(int _count){
    m_count = _count;
}

