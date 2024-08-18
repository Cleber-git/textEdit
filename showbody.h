#ifndef SHOWBODY_H
#define SHOWBODY_H

#include <QWidget>
#include <QPlainTextEdit>

namespace Ui {
class ShowBody;
}

class ShowBody : public QWidget
{
    Q_OBJECT

public:
    explicit ShowBody(QWidget *parent = nullptr);
    ~ShowBody();
    void setPlainEditText(QString);

private:
    Ui::ShowBody *ui;
};

#endif // SHOWBODY_H
