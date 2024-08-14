#ifndef NEWPAGE_H
#define NEWPAGE_H

#include <QDialog>
#include <QVector>
#include <QPlainTextEdit>
#include <QTabWidget>

namespace Ui {
class NewPage;
}

class NewPage : public QDialog
{
    Q_OBJECT

public:
    explicit NewPage(QWidget *parent = nullptr);
    ~NewPage();

    void callListOfWidgets();
    void insertPlain(QVector<QPlainTextEdit*> _plainTextEdit, QVector<QTabWidget*> _tabWidget);

public slots:
    void clearCurrentTab(bool);
    void saveTable(bool);
    void deleteTable(bool);
    void addTable(bool);
    void setCurrentWidget( int index );


private:
    Ui::NewPage *ui;
    QVector<QPlainTextEdit*> listPlains;
    QVector<QTabWidget*> listWidget;
    QPlainTextEdit *currentPlainTextEdit;

};

#endif // NEWPAGE_H
