#ifndef SHOWBODY_H
#define SHOWBODY_H

#include "dbmanager.h"

#include <QWidget>
#include <QPlainTextEdit>
#include <QPushButton>

namespace Ui {
class ShowBody;
}

class ShowBody : public QWidget
{
    Q_OBJECT

public:
    explicit ShowBody(QWidget *parent = nullptr);
    ~ShowBody();

    /**
     * @brief setPlainEditText
     *
     * Método responsável por atualizar a variável membro @ref m_body com o texto alterado pelo usuário
     */
    void setPlainEditText(QString);

public slots:
    /**
     * @brief on_change_Plain_Text
     *
     * Slot responsável por manipular a mensagem de *modificado* e o botão de update para mostrar, esconder ou mudar de cor, de acordo com as alterações que forem feitas
     */
    void on_change_Plain_Text();

    /**
     * @brief on_pushButton_clicked
     *
     * Slot responsável por chamar o método que faz o update dos dados na base com o texto que o usuário alterou
     */
    void on_pushButton_clicked();

    /**
     * @brief receiveTitle
     *
     * Slot responsável por receber o sinal da classe principal e atualizar a variável membro @ref m_title
     */
    void receiveTitle(QString);

private:
    QString m_body;
    QString m_title;
    QPushButton * m_btnUpdate;
    DbManager& m_db = DbManager::getInstance();
    int m_count=0;
    Ui::ShowBody *ui;
};

#endif // SHOWBODY_H
