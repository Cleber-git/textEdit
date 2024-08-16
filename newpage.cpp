#include "newpage.h"
#include "ui_newpage.h"
#include "db.h"

#include <QProcess>
#include <QLabel>
#include <QApplication>
#include <QPlainTextEdit>
#include <QDebug>
#include <QTabWidget>
#include <QTabBar>
#include <QUuid>

NewPage::NewPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewPage)
{
    ui->setupUi(this);

    box = new BoxTitle();
    connect(ui->Clear_tab, SIGNAL(clicked(bool)), this, SLOT(clearCurrentTab(bool)));
    connect(ui->Delet_tab, SIGNAL(clicked(bool)), this, SLOT(deleteTable(bool)));
    connect(ui->Add_tab, SIGNAL(clicked(bool)), this, SLOT(addTable(bool)));
    connect(ui->Save, SIGNAL(clicked(bool)), this, SLOT(saveTable(bool)));

    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(setCurrentWidget(int)));

    connect(box, SIGNAL(sendTitle(QString)), this, SLOT(getTitle(QString)));

    //adicionando os primeiros widgets( os fixos ) da tela. São gerados quando o programa roda.

}

NewPage::~NewPage()
{
    delete ui;
}

void NewPage::clearCurrentTab(bool any){
    plainList[m_currentPlainTextEdit]->clear();
}

void NewPage::deleteTable(bool any){
    if(ui->tabWidget->count() == 1) return;
    plainList.remove(m_currentPlainTextEdit);
    ui->tabWidget->removeTab(m_currentPlainTextEdit);
}

void NewPage::addTable(bool any) {
    QTabBar* tabBar = new QTabBar;
    QPlainTextEdit *plainTextEdit = new QPlainTextEdit(tabBar);

    plainList.push_back(plainTextEdit);
    plainTextEdit->setGeometry(0, 5, 1361, 721);
    ui->tabWidget->addTab(tabBar, "Tab " + QString::number(ui->tabWidget->count()+1));

}

void NewPage::saveTable(bool any) {
    box->show();
}



void NewPage::setCurrentWidget(int index){
    qDebug() << "called me" << QString::number(index);
    m_currentPlainTextEdit = index;
    // currentPlainTextEdit = listPlains[index];
    qDebug() << m_currentPlainTextEdit;
}

void NewPage::getTitle(QString _title){
    Db *db = new Db();
    m_title = _title;
    qDebug() << m_title;
    qDebug() << plainList[m_currentPlainTextEdit]->toPlainText();
    QSqlDatabase database;
    db->openDB(database);
    db->SaveInfo(m_title, plainList[m_currentPlainTextEdit]->toPlainText());
}
