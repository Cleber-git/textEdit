#ifndef NEWPAGE_H
#define NEWPAGE_H

#include <QDialog>
#include <QVector>
#include <QPlainTextEdit>
#include <QWidget>
#include <QTabBar>

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


private:
    Ui::NewPage *ui;
    int currentPlainTextEdit;
    QMap< QTabBar*, QPlainTextEdit*> lastConection;
    QVector<QPlainTextEdit*> plainList;


};

#endif // NEWPAGE_H
