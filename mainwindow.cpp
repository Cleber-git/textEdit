#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "showbody.h"
#include "log.h"


#include <QSizePolicy>
#include <QDebug>
#include <QMovie>
// #include <QCharts/QChart>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    // setAttribute(Qt::WA_DeleteOnClose);

    m_navigator = new QPushButton(this);

    Log &log = Log::getInstance();
    log.log("MainWindow refresh");

    m_db.openDB();
    m_timer = new QTimer();

    m_navigator->setGeometry(1450, 40, 40, 30);
    m_navigator->setFont(QFont("Arial", 18, 800));
    m_navigator->setStyleSheet("Background: #326500 ;color: #000000 ; border-radius: 15px ;");
    m_navigator->show();
    m_navigator->setText("+");

    // connect(m_timer, SIGNAL(timeout()), this, SLOT(showLabelDescanse()));
    connect(m_navigator, SIGNAL(clicked(bool)), this, SLOT(on_m_navigator(bool)));
    connect(this, SIGNAL(sendTitle(QString)), showBody, SLOT(receiveTitle(QString)));
    connect(ui->radioButton, SIGNAL(clicked(bool)), this, SLOT(on_change_radioButton()));
    connect(ui->radioButton_2, SIGNAL(clicked(bool)), this, SLOT(on_change_radioButton_1()));
    connect(ui->radioButton_3, SIGNAL(clicked(bool)), this, SLOT(on_change_radioButton_2()));

    makeInit();

    this->setStyleSheet("background: #363636 ;");

    ui->lbl_descanso->hide();

    showLabelDescanse();

    this->setGeometry(0, 0, 1500, 707);
    ui->radioButton->show();
    ui->radioButton_2->show();
    ui->radioButton_3->show();
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
    page.getLabelBackground()->setStyleSheet("border-image: url(qrc:/ferramentas/plano_de_fundo_text.jpeg) ;");
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
        pushButton->setStyleSheet("background: #326500 ; border-radius: 50px ; font-weight: bold ; color: #000000; font-family: cursive ; ");
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

        if (button->isChecked()){
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

void MainWindow::mousePressEvent(QMouseEvent* event){
    if(event->button() == Qt::LeftButton){
        qDebug() << "Cliquei no botão esquerdo";
    }
    QWidget::mousePressEvent(event);
}

void MainWindow::showLabelDescanse(){
    ui->lbl_descanso->setGeometry(this->geometry().x(), this->geometry().y(), this->geometry().width(), this->geometry().height());
    qDebug() << "chamei o slot";
    movie = new QMovie(":/ferramentas/vIHyJ.gif");
    ui->lbl_descanso->setMovie(movie);
    ui->lbl_descanso->setAlignment(Qt::AlignCenter);
    ui->lbl_descanso->setScaledContents(true);

    movie->start();

    ui->lbl_descanso->show();
}
void MainWindow::on_change_radioButton(){
    for(QPushButton *button: listScreens){
        button->setStyleSheet("background: red ; border-radius: 50px ; font-weight: bold ; color: #ffffff; font-family: cursive ;");
    }
    m_navigator->setStyleSheet("Background: red ;color: #ffffff ; border-radius: 15px ;");
}
void MainWindow::on_change_radioButton_1(){
    for(QPushButton *button: listScreens){
        button->setStyleSheet("background: yellow ; border-radius: 50px ; font-weight: bold ; color: black; font-family: cursive ;");
    }
    m_navigator->setStyleSheet("Background: yellow ;color: #black ; border-radius: 15px ;");
}
void MainWindow::on_change_radioButton_2(){
    for(QPushButton *button: listScreens){
        button->setStyleSheet("background: green ; border-radius: 50px ; font-weight: bold ; color: #ffffff; font-family: cursive ;");
    }
    m_navigator->setStyleSheet("Background: #326500 ;color: #000000 ; border-radius: 15px ;");
}

