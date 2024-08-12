#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_navigator = new QPushButton(this);
    m_navigator->move(530,350);
    m_navigator->show();
    m_navigator->setText("Ir");
    connect(m_navigator, SIGNAL(clicked(bool)), this, SLOT(on_m_navigator(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_m_navigator(bool){
    hide();
    page.show();


}
