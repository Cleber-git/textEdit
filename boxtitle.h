#ifndef BOXTITLE_H
#define BOXTITLE_H

#include <QDialog>

namespace Ui {
class BoxTitle;
}

class BoxTitle : public QDialog
{
    Q_OBJECT

public:
    explicit BoxTitle(QWidget *parent = nullptr);
    ~BoxTitle();
signals:
    void sendTitle(QString);
private slots:
    void on_pushButton_clicked();

private:
    Ui::BoxTitle *ui;
};

#endif // BOXTITLE_H
