#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSizePolicy>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_navigator = new QPushButton(this);

    m_db = DbManager::getInstance();
    QSqlDatabase database;
    m_db.openDB(database);

    // m_navigator->move(1400,350);
    m_navigator->setGeometry(1445, 10, 40, 30);
    m_navigator->setFont(QFont("Arial", 18, 800));
    m_navigator->setStyleSheet("Background: grey ;color: white ; ");

    m_navigator->show();
    m_navigator->setText("+");
    connect(m_navigator, SIGNAL(clicked(bool)), this, SLOT(on_m_navigator(bool)));
    makeInit();
    this->setStyleSheet("background: #363636 ;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_m_navigator(bool){
    hide();
    DbManager &db = DbManager::getInstance();
    db.countRows();

    page.show();
}


void MainWindow::makeInit(){
    for(QString titulo: m_db.getTitle()){
        listTitle.push_back(titulo);
        qDebug() << titulo;
    }
    createWidgets();
}

void MainWindow::createWidgets(){
    for ( QString titulo : listTitle ) {
        QPushButton *pushButton = new QPushButton(titulo, this);
        pushButton->setStyleSheet("background: white ;border-image: url(:/ferramentas/build/Desktop_Qt_6_7_2_MSVC2019_64bit-Debug/bin/button.png);");
        listScreens.push_back(pushButton);
        if(titulo == listTitle[0]){
            pushButton->setGeometry(10, 10, 150, 100);
            lastPositionButton.x = 10;
            lastPositionButton.y = 10;
            lastPositionButton.w = 150;
            lastPositionButton.h = 100;
            pushButton->show();
            continue;
        }
        lastPositionButton.x = lastPositionButton.x + (lastPositionButton.w+10);
        if(!verify(lastPositionButton.x, lastPositionButton.w)){
            qDebug() << "to no fim da tela: " << titulo;

            lastPositionButton.x = 10;
            lastPositionButton.y = (lastPositionButton.h + lastPositionButton.y + 10);
            pushButton->setGeometry(lastPositionButton.x, lastPositionButton.y, lastPositionButton.w, lastPositionButton.h);
            pushButton->show();
            continue;
        }

        pushButton->setGeometry(lastPositionButton.x, lastPositionButton.y, lastPositionButton.w, lastPositionButton.h);
        pushButton->show();

    }

}


bool MainWindow::verify(int x, int currentWidth){
    qDebug() << currentWidth + lastPositionButton.x;
    if((lastPositionButton.x + currentWidth ) > this->geometry().width()){
        return false;
    }
    return true;
}
