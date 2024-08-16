#ifndef NEWPAGE_H
#define NEWPAGE_H

#include <QDialog>
#include <QVector>
#include <QPlainTextEdit>
#include <QWidget>
#include <QTabBar>
#include <QSqlDatabase>
#include "boxtitle.h"


namespace Ui {
class NewPage;
}

class NewPage : public QDialog
{
    Q_OBJECT

public:
    explicit NewPage(QWidget *parent = nullptr);
    ~NewPage();
    void addPlainInWidget(QPlainTextEdit*, QTabBar*);



public slots:
    void clearCurrentTab(bool);
    void saveTable(bool);
    void deleteTable(bool);
    void addTable(bool);
    void setCurrentWidget( int index );
    void getTitle(QString);


private:
    Ui::NewPage *ui;
    int m_currentPlainTextEdit;
    QMap< QTabBar*, QPlainTextEdit*> lastConection;
    QVector<QPlainTextEdit*> plainList;
    BoxTitle *box;
    QString m_title;


};

#endif // NEWPAGE_H
