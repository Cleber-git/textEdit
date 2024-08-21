#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "showbody.h"

#include <QSizePolicy>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_navigator = new QPushButton(this);

    m_db.openDB();

    m_navigator->setGeometry(1450, 40, 40, 30);
    m_navigator->setFont(QFont("Arial", 18, 800));
    m_navigator->setStyleSheet("Background: rgb(51, 8, 115) ;color: white ; border-radius: 15px ;");
    m_navigator->show();
    m_navigator->setText("+");

    connect(m_navigator, SIGNAL(clicked(bool)), this, SLOT(on_m_navigator(bool)));
    connect(this, SIGNAL(sendTitle(QString)), showBody, SLOT(receiveTitle(QString)));

    makeInit();
    this->setStyleSheet("background: #363636 ;");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_m_navigator(bool _verify){
    hide();
    DbManager &db = DbManager::getInstance();
    db.countRows();

    page.show();
}


void MainWindow::makeInit(){
    for(QString titulo: m_db.getTitle()){
        listTitle.push_back(titulo);
    }
    createWidgets();
}

void MainWindow::createWidgets(){
    for ( QString titulo : listTitle ) {
        QPushButton *pushButton = new QPushButton(titulo, this);
        pushButton->setCheckable(true);
        pushButton->setStyleSheet("background: white ; border-radius: 50px ; font-weight: bold ; color: rgb(51, 8, 115); font-family: cursive ; ");
        listScreens.push_back(pushButton);

        //// Como vou organizar os botões na tela?
        //    Is the first content?
        if(titulo == listTitle[0]){
            pushButton->setGeometry(10, 10, 150, 100);
            lastPositionButton.x = 10;
            lastPositionButton.y = 10;
            lastPositionButton.w = 150;
            lastPositionButton.h = 100;
            pushButton->show();
            continue;
        }

        // don't is first content?
        lastPositionButton.x = lastPositionButton.x + (lastPositionButton.w+10);
        if(!verify(lastPositionButton.w)){
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
    connectButtons();
}

bool MainWindow::verify(int _currentWidth){
    if((lastPositionButton.x + _currentWidth ) > this->geometry().width()){
        return false;
    }
    return true;
}


void MainWindow::connectButtons(){
    for(QPushButton*button:listScreens){
        connect(button, SIGNAL(clicked(bool)), this, SLOT(on_current_button_clicked()));
    }
}


void MainWindow::on_current_button_clicked(){
    for(QPushButton* button: listScreens){
        if (button->isChecked()) {
            showBodyByTitle(button->text());
            emit sendTitle(button->text());
            button->setChecked(false);
        }
    }
}

void MainWindow::showBodyByTitle(QString _title){
    QString body = m_db.getBody(_title);
    qDebug() << body;
    showBody->setCount(0);
    showBody->setPlainEditText(body);

    showBody->show();
}
