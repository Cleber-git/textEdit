#include "newpage.h"
#include "ui_newpage.h"
#include <QProcess>
#include <QLabel>

NewPage::NewPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewPage)
{
    ui->setupUi(this);

    connect(ui->Clear_tab, SIGNAL(clicked(bool)), this, SLOT(clearCurrentTab(bool)));
    connect(ui->Delet_tab, SIGNAL(clicked(bool)), this, SLOT(deleteTable(bool)));
    connect(ui->Add_tab, SIGNAL(clicked(bool)), this, SLOT(addTable(bool)));
    connect(ui->Save, SIGNAL(clicked(bool)), this, SLOT(saveTable(bool)));

}

NewPage::~NewPage()
{
    delete ui;
}
void NewPage::clearCurrentTab(bool any){
    ui->plainTextEdit->clear();
}

void NewPage::deleteTable(bool any){
    ui->tabWidget->removeTab(0);
}

