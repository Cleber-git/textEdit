#include "newpage.h"
#include "ui_newpage.h"
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

    connect(ui->Clear_tab, SIGNAL(clicked(bool)), this, SLOT(clearCurrentTab(bool)));
    connect(ui->Delet_tab, SIGNAL(clicked(bool)), this, SLOT(deleteTable(bool)));
    connect(ui->Add_tab, SIGNAL(clicked(bool)), this, SLOT(addTable(bool)));
    connect(ui->Save, SIGNAL(clicked(bool)), this, SLOT(saveTable(bool)));

    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(setCurrentWidget(int)));

    //adicionando os primeiros widgets( os fixos ) da tela. São gerados quando o programa roda.

}

NewPage::~NewPage()
{
    delete ui;
}

void NewPage::clearCurrentTab(bool any){
    plainList[currentPlainTextEdit]->clear();
}

void NewPage::deleteTable(bool any){
    if(ui->tabWidget->count() == 1) return;
    plainList.remove(currentPlainTextEdit);
    ui->tabWidget->removeTab(currentPlainTextEdit);
}

void NewPage::addTable(bool any){
    QTabBar* tabBar = new QTabBar;
    QPlainTextEdit *plainTextEdit = new QPlainTextEdit(tabBar);

    plainList.push_back(plainTextEdit);
    plainTextEdit->setGeometry(0, 5, 1361, 721);
    ui->tabWidget->addTab(tabBar, "Tab " + QString::number(ui->tabWidget->count()+1));
}

void NewPage::saveTable(bool any) {
    // QFile file(qApp->applicationDirPath() +  );
}



void NewPage::setCurrentWidget(int index){
    qDebug() << "called me" << QString::number(index);
    currentPlainTextEdit = index;
    // currentPlainTextEdit = listPlains[index];
    qDebug() << currentPlainTextEdit;
}


