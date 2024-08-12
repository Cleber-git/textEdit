/********************************************************************************
** Form generated from reading UI file 'newpage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPAGE_H
#define UI_NEWPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewPage
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Add_tab;
    QPushButton *Delet_tab;
    QPushButton *Clear_tab;
    QPushButton *Save;
    QPlainTextEdit *plainTextEdit;
    QWidget *tab_2;

    void setupUi(QDialog *NewPage)
    {
        if (NewPage->objectName().isEmpty())
            NewPage->setObjectName("NewPage");
        NewPage->resize(1500, 750);
        tabWidget = new QTabWidget(NewPage);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 1500, 750));
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(1400, 0, 111, 721));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Add_tab = new QPushButton(verticalLayoutWidget);
        Add_tab->setObjectName("Add_tab");

        verticalLayout->addWidget(Add_tab);

        Delet_tab = new QPushButton(verticalLayoutWidget);
        Delet_tab->setObjectName("Delet_tab");

        verticalLayout->addWidget(Delet_tab);

        Clear_tab = new QPushButton(verticalLayoutWidget);
        Clear_tab->setObjectName("Clear_tab");

        verticalLayout->addWidget(Clear_tab);

        Save = new QPushButton(verticalLayoutWidget);
        Save->setObjectName("Save");

        verticalLayout->addWidget(Save);

        plainTextEdit = new QPlainTextEdit(tab);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(0, 0, 1400, 720));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());

        retranslateUi(NewPage);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(NewPage);
    } // setupUi

    void retranslateUi(QDialog *NewPage)
    {
        NewPage->setWindowTitle(QCoreApplication::translate("NewPage", "Dialog", nullptr));
        Add_tab->setText(QCoreApplication::translate("NewPage", "Add Tab", nullptr));
        Delet_tab->setText(QCoreApplication::translate("NewPage", "Delete tab", nullptr));
        Clear_tab->setText(QCoreApplication::translate("NewPage", "Clear Tab", nullptr));
        Save->setText(QCoreApplication::translate("NewPage", "Save ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("NewPage", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("NewPage", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewPage: public Ui_NewPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPAGE_H
