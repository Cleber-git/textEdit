#ifndef DB_H
#define DB_H

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>

/**
 * @brief The Db class
 * Classe destinada à fazer a conexão e gerenciamento de ações na base de
 * dados\n da aplicação
 */
class Db {
public:
    Db();

    /**
   * @brief openDB
   * Método responsável por fazer a abertura da conexão com a base de dados
   * @return *True*: se a conexão for bem sucedida \n *False*: Se houver algum
   * erro no processo
   */
    bool openDB();

    /**
   * @brief getTitle
   * Método responsável por obter todos os títulos no banco de dados e agrupar\n
   * em um vector.
   *
   * @return *QVector* com todos os títulos
   */
    QVector<QString> getTitle();

    /**
   * @brief getBody
   * Método responsável por obter do banco de dados o texto do arquivo de\n
   * acordo com o título que o usuário fornecer
   *
   * @param _title
   * @return
   */
    QString getBody(QString _title);

    /**
   * @brief countRows
   * Método responsável por contar o número de linhas que existem na base de
   * dados\n
   *
   * @return *Inteiro que representa o número de linhas*
   */
    int countRows();

    /**
   * @brief SaveInfo
   * Método responsável por registrar na base de dados as informações que o\n
   * usuário inseriu no arquivo de texto que ele criou, juntamente com o título.
   *
   * @param _title
   * @param _body
   */
    void SaveInfo(QString _title, QString _body);

    /**
   * @brief deleteInfo
   * Método responsável por deletar um arquivo da base de dados de acordo com\n
   * o título fornecido no parâmetro
   *
   * @param _title
   */
    void deleteInfo(QString _title);

    /**
   * @brief update
   * Método responsável por fazer o update de um arquivo na base de dados,\n
   * salvando as informações que estão no arquivo atualmente
   *
   * @param _title
   * @param _body
   */
    void update(QString _title, QString _body);

private:
    QSqlDatabase m_db;
    QVector<QString> m_titleList;
};

#endif // DB_H
