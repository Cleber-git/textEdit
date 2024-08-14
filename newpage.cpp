#include "newpage.h"
#include "ui_newpage.h"
#include <QProcess>
#include <QLabel>
#include <QApplication>
#include <QPlainTextEdit>
#include <QDebug>
#include <QTabWidget>

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
    listPlains.push_back(ui->plainTextEdit);
    listWidget.push_back(ui->tabWidget);
    qDebug() << "Plains: " << listPlains.count() << "| TabWidgets: " << listWidget.count();
    ui->tabWidget->removeTab(1);
    currentPlainTextEdit = ui->plainTextEdit;

}

NewPage::~NewPage()
{
    delete ui;
}

void NewPage::clearCurrentTab(bool any){
    currentPlainTextEdit->clear();
}

void NewPage::deleteTable(bool any){
    if(ui->tabWidget->count() == 1) return;
    quint64 current = ui->tabWidget->currentIndex();
    listWidget.removeAt(current);
    listPlains.removeAt(current);
    ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
    qDebug() << "Plains: " << listPlains.count()
             << "| TabWigigets: " << listWidget.count()
             << " Current Index: " << QString::number(current);
}


void NewPage::addTable(bool any){
    listPlains.push_back(new QPlainTextEdit);
    listWidget.push_back(new QTabWidget);
    ui->tabWidget->addTab(listWidget[ui->tabWidget->count()],
                          "Tab " + QString::number(ui->tabWidget->count() + 1));
    callListOfWidgets();
    insertPlain(listPlains, listWidget);
}

void NewPage::saveTable(bool any){
    // QFile file(qApp->applicationDirPath() +  );
}

// Adiciona o plain ao tabWidget
void NewPage::insertPlain(QVector<QPlainTextEdit *> _plainTextEdit,
                          QVector<QTabWidget *> _tabWidget) {

    for (int i = 0; i < _plainTextEdit.count(); i++) {
        _plainTextEdit[i] = new QPlainTextEdit(_tabWidget[i]);
        _plainTextEdit[i]->setGeometry(0, 25, 1371, 720);
        _plainTextEdit[i]->show();
    }
}

// Imprimindo a lista de widgets para vizualizar o controle de inserção
void NewPage::callListOfWidgets(){
    for(auto item:listPlains){
        qDebug() << item;
    }
    for(auto item:listWidget){
        qDebug() << item;
    }
    qDebug() << "Plains: " << listPlains.count() << "| TabWigigets: " << listWidget.count();
}

void NewPage::setCurrentWidget(int index){
    qDebug() << "called me" << QString::number(index);
    currentPlainTextEdit = listPlains[index];
    qDebug() << currentPlainTextEdit;
}
