#ifndef SHOWBODY_H
#define SHOWBODY_H

#include "dbmanager.h"

#include <QPlainTextEdit>
#include <QPushButton>
#include <QWidget>

namespace Ui {
class ShowBody;
}

class ShowBody : public QWidget {
    Q_OBJECT

public:
    explicit ShowBody(QWidget *parent = nullptr);
    ~ShowBody();

    /**
   * @brief setCount
   * Método responsável por definir o valor da variável membro @ref m_count
   *
   * @param _count
   */
    void setCount(int _count);
    /**
   * @brief setPlainEditText
   *
   * Método responsável por atualizar a variável membro @ref m_body com o texto
   * alterado pelo usuário
   *
   * @param _text
   */
    void setPlainEditText(QString _text);

public slots:
    /**
   * @brief on_change_Plain_Text
   *
   * Slot responsável por manipular a mensagem de *modificado* e o botão de\n
   * update para mostrar, esconder ou mudar de cor, de acordo com as
   * alterações\n que forem feitas
   */
    void on_change_Plain_Text();

    /**
   * @brief on_pushButton_clicked
   *
   * Slot responsável por chamar o método que faz o update dos dados na base
   * com\n o texto que o usuário alterou
   */
    void on_pushButton_clicked();

    /**
   * @brief receiveTitle
   *
   * Slot responsável por receber o sinal da classe principal e atualizar a\n
   * variável membro @ref m_title
   *
   * @param _title
   */
    void receiveTitle(QString _title);

private:
    QString m_body;
    QString m_title;
    QPushButton *m_btnUpdate;
    DbManager &m_db = DbManager::getInstance();
    int m_count = 0;
    Ui::ShowBody *ui;
};

#endif // SHOWBODY_H
