#ifndef NEWPAGE_H
#define NEWPAGE_H

#include <QDialog>

namespace Ui {
class NewPage;
}

class NewPage : public QDialog
{
    Q_OBJECT

public:
    explicit NewPage(QWidget *parent = nullptr);
    ~NewPage();
public slots:
    void clearCurrentTab(bool);
    // void saveTable(bool);
    void deleteTable(bool);
    // void addTable(bool);

private:
    Ui::NewPage *ui;
};

#endif // NEWPAGE_H
