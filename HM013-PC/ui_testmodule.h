/********************************************************************************
** Form generated from reading UI file 'testmodule.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTMODULE_H
#define UI_TESTMODULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_TestModule
{
public:

    void setupUi(QDialog *TestModule)
    {
        if (TestModule->objectName().isEmpty())
            TestModule->setObjectName(QStringLiteral("TestModule"));
        TestModule->resize(326, 577);
        TestModule->setStyleSheet(QStringLiteral(""));

        retranslateUi(TestModule);

        QMetaObject::connectSlotsByName(TestModule);
    } // setupUi

    void retranslateUi(QDialog *TestModule)
    {
        TestModule->setWindowTitle(QApplication::translate("TestModule", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestModule: public Ui_TestModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMODULE_H
