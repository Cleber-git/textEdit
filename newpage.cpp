#include "newpage.h"
#include "ui_newpage.h"
#include "dbmanager.h"
#include "mainwindow.h"

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

}

NewPage::~NewPage()
{
    delete ui;
}

// Slot responsável por limpar o texto da plainEditText que está em foco.
void NewPage::clearCurrentTab(bool any){
    plainList[m_currentPlainTextEdit]->clear();
}

// Slot responsável por deletar a tab que está em foco e deletar a plainTextEdit
// na lista de ferramentas plainText.
void NewPage::deleteTable(bool any){
    if(ui->tabWidget->count() == 1) return;
    plainList.remove(m_currentPlainTextEdit);
    ui->tabWidget->removeTab(m_currentPlainTextEdit);
}

// Slot responsável por adicionar uma tab a mais ao widget principal
// ui->tabWidget e adiciona um plainTextEdit à lista de ferramentas plainList.
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

// slot responsável por receber o sinal de mudança das abas e passar o indice
// atual para a variável membro m_currentPlainTextEdit

void NewPage::setCurrentWidget(int index){
    m_currentPlainTextEdit = index;
}

// Slot responsável por receber o sinal que contém o título do arquivo fornecido
// pelo usuário e passar ele para a variável membro m_title e salvar as
// informações no banco de dados.
void NewPage::getTitle(QString _title){
    DbManager &db = DbManager::getInstance();
    m_title = _title;
    QSqlDatabase database;
    db.openDB(database);
    db.SaveInfo(m_title, plainList[m_currentPlainTextEdit]->toPlainText());
    ui->tabWidget->setTabText(m_currentPlainTextEdit, m_title);
}



void NewPage::on_pushButton_clicked()
{
    hide();
    MainWindow *w = new MainWindow();
    w->show();
}

