#include "newpage.h"
#include "ui_newpage.h"
#include "dbmanager.h"
#include "mainwindow.h"
#include "log.h"

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

    Log &log = Log::getInstance();
    log.log(this->objectName() + " Refresh");

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

void NewPage::clearCurrentTab(bool _any){
    plainList[m_currentPlainTextEdit]->clear();
}

void NewPage::deleteTable(bool _any){
    if(ui->tabWidget->count() == 1) return;
    plainList.remove(m_currentPlainTextEdit);
    ui->tabWidget->removeTab(m_currentPlainTextEdit);
}

void NewPage::addTable(bool _any) {
    QTabBar* tabBar = new QTabBar;
    QPlainTextEdit *plainTextEdit = new QPlainTextEdit(tabBar);

    plainList.push_back(plainTextEdit);
    plainTextEdit->setGeometry(0, 5, 1361, 721);
    ui->tabWidget->addTab(tabBar, "Tab " + QString::number(ui->tabWidget->count()+1));
}

void NewPage::saveTable(bool _any) {
    box->show();
}

void NewPage::setCurrentWidget(int index){
    m_currentPlainTextEdit = index;
}

void NewPage::getTitle(QString _title){
    if(this->isHidden()) return;
    qDebug() << "Está em foco";
    DbManager &db = DbManager::getInstance();
    m_title = _title;
//    db.openDB();
    db.SaveInfo(m_title, plainList[m_currentPlainTextEdit]->toPlainText());
    ui->tabWidget->setTabText(m_currentPlainTextEdit, m_title);
}

void NewPage::on_pushButton_clicked()
{
    hide();
    MainWindow *w = new MainWindow();
    w->show();
}

QLabel* NewPage::getLabelBackground(){
    return ui->backgorund_plain;
}
