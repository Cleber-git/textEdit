#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVector>

#include "newpage.h"
#include "dbmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // struct destinada a pegar a posição(x e y), altura e comprimento de uma ferramenta
    MainWindow(QWidget *parent = nullptr);
    struct pos{
        int x;
        int y;
        int w;
        int h;
    };
    typedef pos POS;
    ~MainWindow();
    QPushButton* m_navigator;
    void makeInit();
    void createWidgets();
    bool verify( int x, int currentWidth);

public slots:
    void on_m_navigator(bool);
private:
    Ui::MainWindow *ui;
    NewPage page;
    QVector<QPushButton*> listScreens;
    DbManager &m_db = DbManager::getInstance();
    QVector<QString> listTitle;
    POS lastPositionButton;
    POS currentPositionButton;
};
#endif // MAINWINDOW_H
