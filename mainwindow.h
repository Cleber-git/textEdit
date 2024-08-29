#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVector>
#include <QMouseEvent>
#include <QTimer>
#include <QMovie>

#include "dbmanager.h"
#include "newpage.h"
#include "showbody.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    /**
   * @brief The pos class
   * Struct destinada a pegar a posição(x e y), altura e comprimento de uma
   * ferramenta
   */
    struct pos {
        int x;
        int y;
        int w;
        int h;
    };
    typedef pos POS;
    ~MainWindow();
    QPushButton *m_navigator;

    /**
   * @brief makeInit
   * Método responsável por obter todos os títulos passados para o\n
   * vetor @ref listTitle através do método @ref m_db.getTitle()
   */
    void makeInit();

    /**
   * @brief createWidgets
   * Método responsável por criar os botões dinamicamente de acordo com a
   * quantidade de títulos retornados pelo método @ref m_db.getTitle.\n Ele
   * verifica se o botão é o primeiro, se sim, Define a posição de x e y da
   * ferramenta e grava na struct @ref lastPositionButton\n para o próximo botão
   * saber onde vai ser posicionado.\n Conta com a lógica do método @ref verify
   * que guarda parte do algoritmo de organização dos widgets\n
   *
   */
    void createWidgets();

    /**
   * @brief verify
   * Método responsável por acompanhar o posicionamento dos widgets para que não
   * passe do intervalo do tamanho da tela que estão sendo organizados. \n
   * Calcula se a posição x somado com o tamanho do widget  vai passar do
   * tamanho da tela, se sim, ele vai direcionar o widget para a próxima linha,
   * usando a struct que obtém as posições.
   *
   * @param currentWidth
   * @return *True:* Se a função puder armazenar os widgets na mesma linha.\n
   * *False:* se os widgets já estiverem no fim da linha. Dessa forma o
   * algoritmo muda a próxima posição x e y para a próxima linha.
   */
    bool verify(int _currentWidth);

    /**
   * @brief connectButtons
   *
   * Método responsável por conectar todos os widgets da lista de ferramentas ao
   * slot @ref on_current_button_clicked
   */
    void connectButtons();
protected:
    void mousePressEvent(QMouseEvent*) override;
public slots:
    /**
   * @brief on_m_navigator
   * Slot responspável por chamar a interface da classe @ref NewPage
   *
   * @param _verify
   */
    void on_m_navigator(bool _verify);

    /**
   * @brief on_current_button_clicked
   *
   * Slot responsável por verificar qual botão foi pressionado através do método
   * *isChecked* e executar alguma função à partir disso
   */
    void on_current_button_clicked();

    /**
   * @brief showBodyByTitle
   * Slot responsável por chamar a instância @ref showBody e exibir a interface
   * dela.
   *
   * @param _title
   */
    void showBodyByTitle(QString _title);
    void showLabelDescanse();

signals:
    void sendTitle(QString);



private:
    Ui::MainWindow *ui;
    NewPage page;
    QVector<QPushButton *> listScreens;
    DbManager &m_db = DbManager::getInstance();
    QVector<QString> listTitle;
    POS lastPositionButton;
    ShowBody *showBody = new ShowBody;
    QString m_title;
    QTimer *m_timer;
    QMovie *movie;
};
#endif // MAINWINDOW_H
