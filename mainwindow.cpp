#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "db.h"
#include <QSizePolicy>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_navigator = new QPushButton(this);

    // m_navigator->move(1400,350);
    m_navigator->setGeometry(1310, 50, 150, 75);
    m_navigator->setFont(QFont("Arial", 18, 800));
    m_navigator->setStyleSheet("Background: grey ;color: white ; ");

    m_navigator->show();
    m_navigator->setText("New");
    connect(m_navigator, SIGNAL(clicked(bool)), this, SLOT(on_m_navigator(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_m_navigator(bool){
    hide();
    Db *db = new Db();
    QSqlDatabase database;
    db->openDB(database);
    db->countRows();

    page.show();
}


