#ifndef NEWPAGE_H
#define NEWPAGE_H

#include "boxtitle.h"
#include <QDialog>
#include <QPlainTextEdit>
#include <QSqlDatabase>
#include <QTabBar>
#include <QVector>
#include <QWidget>

namespace Ui {
class NewPage;
}

class NewPage : public QDialog {
    Q_OBJECT

public:
    explicit NewPage(QWidget *parent = nullptr);
    ~NewPage();

public slots:
    /**
   * @brief clearCurrentTab
   * Slot responsável por limpar o texto da plainEditText que está em foco.
   * @param _any
   */
    void clearCurrentTab(bool _any);

    /**
   * @brief saveTable
   * Slot responsável por pedir para o usuário definir o título do arquivo e
   * salvar no banco de dados o conteúdo da tela atual.
   *
   * @param _any
   */
    void saveTable(bool _any);

    /**
   * @brief deleteTable
   * Slot responsável por deletar a tab que está em foco e deletar a
   * plainTextEdit na lista de ferramentas plainText.
   *
   * @param _any
   */
    void deleteTable(bool _any);

    /**
   * @brief addTable
   * Slot responsável por adicionar uma tab a mais ao widget principal
   * ui->tabWidget e adiciona um plainTextEdit à lista de ferramentas plainList.
   *
   * @param _any
   */
    void addTable(bool _any);

    /**
   * @brief setCurrentWidget
   *  Slot responsável por receber o sinal de mudança das abas e passar o indice
   *  Atual para a variável membro m_currentPlainTextEdit
   *
   * @param index
   */
    void setCurrentWidget(int index);

    /**
   * @brief getTitle
   * Slot responsável por receber o sinal que contém o título do arquivo
   * fornecido pelo usuário e passar ele para a variável membro m_title e salvar
   * as informações no banco de dados.
   *
   * @param _title
   */
    void getTitle(QString _title);

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewPage *ui;
    int m_currentPlainTextEdit;
    QMap<QTabBar *, QPlainTextEdit *> lastConection;
    QVector<QPlainTextEdit *> plainList;
    BoxTitle *box;
    QString m_title;
};

#endif // NEWPAGE_H
