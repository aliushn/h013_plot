/********************************************************************************
** Form generated from reading UI file 'enterwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERWINDOW_H
#define UI_ENTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnterWindow
{
public:
    QLabel *label;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *EnterWindow)
    {
        if (EnterWindow->objectName().isEmpty())
            EnterWindow->setObjectName(QStringLiteral("EnterWindow"));
        EnterWindow->resize(291, 195);
        label = new QLabel(EnterWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 61, 21));
        textEdit = new QTextEdit(EnterWindow);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(90, 40, 151, 31));
        textEdit_2 = new QTextEdit(EnterWindow);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(90, 80, 151, 31));
        label_2 = new QLabel(EnterWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 54, 12));
        pushButton = new QPushButton(EnterWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 120, 71, 31));
        pushButton_2 = new QPushButton(EnterWindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 120, 71, 31));

        retranslateUi(EnterWindow);

        QMetaObject::connectSlotsByName(EnterWindow);
    } // setupUi

    void retranslateUi(QWidget *EnterWindow)
    {
        EnterWindow->setWindowTitle(QApplication::translate("EnterWindow", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("EnterWindow", "\350\264\246\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("EnterWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        pushButton->setText(QApplication::translate("EnterWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("EnterWindow", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EnterWindow: public Ui_EnterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERWINDOW_H
