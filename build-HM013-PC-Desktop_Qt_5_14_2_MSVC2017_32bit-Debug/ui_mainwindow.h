/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QDial *dial;
    QDial *dial_2;
    QLCDNumber *lcdNumber_2;
    QDial *dial_3;
    QLCDNumber *lcdNumber_3;
    QLCDNumber *lcdNumber_4;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QDial *dial_4;
    QTextBrowser *textBrowser;
    QProgressBar *progressBar;
    QSlider *verticalSlider_2;
    QSlider *verticalSlider_3;
    QSlider *verticalSlider_4;
    QSlider *verticalSlider_5;
    QPushButton *pushButton_2;
    QLabel *label_6;
    QLCDNumber *lcdNumber_5;
    QLCDNumber *lcdNumber_6;
    QLCDNumber *lcdNumber_7;
    QLCDNumber *lcdNumber_8;
    QWidget *widget;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton;
    QLabel *label_2;
    QPushButton *pushButton_6;
    QTextBrowser *textBrowser_2;
    QWidget *tab_2;
    QComboBox *comboBox;
    QLabel *label_4;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_5;
    QWidget *tab_3;
    QCustomPlot *serial_plot;
    QTextBrowser *textBrowser_3;
    QLabel *label_14;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_15;
    QComboBox *comboBox_7;
    QLabel *label_9;
    QComboBox *comboBox_2;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QComboBox *comboBox_6;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QPlainTextEdit *serialSendWindow;
    QCheckBox *checkSendHexBox;
    QCheckBox *checkRecHexBox;
    QLabel *label_16;
    QLabel *label_17;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_19;
    QLabel *label_18;
    QLabel *label_20;
    QLabel *label_21;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_25;
    QLabel *label_22;
    QLabel *label_24;
    QLabel *label_23;
    QWidget *verticalLayoutWidget_11;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_58;
    QLabel *label_59;
    QProgressBar *progressBar_3;
    QProgressBar *progressBar_4;
    QLabel *label_60;
    QLabel *label_61;
    QDial *dial_9;
    QLabel *label_62;
    QLCDNumber *lcdNumber_19;
    QWidget *tab_4;
    QCustomPlot *graph_plot;
    QDial *dial_10;
    QDial *dial_11;
    QWidget *tab_5;
    QTreeView *treeView;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLCDNumber *lcdNumber_9;
    QPushButton *pushButton_17;
    QTextEdit *textEdit_3;
    QWidget *tab_6;
    QLabel *label_3;
    QTextBrowser *textBrowser_7;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1744, 929);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 0, 1731, 781));
        tabWidget->setToolTipDuration(-3);
        tabWidget->setMovable(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        dial = new QDial(tab);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(1080, 340, 80, 80));
        dial_2 = new QDial(tab);
        dial_2->setObjectName(QString::fromUtf8("dial_2"));
        dial_2->setGeometry(QRect(1180, 340, 80, 80));
        lcdNumber_2 = new QLCDNumber(tab);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(1190, 480, 64, 23));
        dial_3 = new QDial(tab);
        dial_3->setObjectName(QString::fromUtf8("dial_3"));
        dial_3->setGeometry(QRect(1280, 340, 80, 80));
        lcdNumber_3 = new QLCDNumber(tab);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(1290, 480, 64, 23));
        lcdNumber_4 = new QLCDNumber(tab);
        lcdNumber_4->setObjectName(QString::fromUtf8("lcdNumber_4"));
        lcdNumber_4->setGeometry(QRect(1390, 480, 64, 23));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1090, 420, 371, 41));
        label->setTextFormat(Qt::PlainText);
        label->setScaledContents(true);
        label->setWordWrap(true);
        lcdNumber = new QLCDNumber(tab);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(1090, 480, 64, 23));
        dial_4 = new QDial(tab);
        dial_4->setObjectName(QString::fromUtf8("dial_4"));
        dial_4->setGeometry(QRect(1380, 340, 80, 80));
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 50, 221, 291));
        progressBar = new QProgressBar(tab);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 350, 221, 16));
        progressBar->setValue(24);
        verticalSlider_2 = new QSlider(tab);
        verticalSlider_2->setObjectName(QString::fromUtf8("verticalSlider_2"));
        verticalSlider_2->setGeometry(QRect(1110, 70, 22, 160));
        verticalSlider_2->setOrientation(Qt::Vertical);
        verticalSlider_3 = new QSlider(tab);
        verticalSlider_3->setObjectName(QString::fromUtf8("verticalSlider_3"));
        verticalSlider_3->setGeometry(QRect(1210, 70, 22, 160));
        verticalSlider_3->setOrientation(Qt::Vertical);
        verticalSlider_4 = new QSlider(tab);
        verticalSlider_4->setObjectName(QString::fromUtf8("verticalSlider_4"));
        verticalSlider_4->setGeometry(QRect(1310, 70, 22, 160));
        verticalSlider_4->setOrientation(Qt::Vertical);
        verticalSlider_5 = new QSlider(tab);
        verticalSlider_5->setObjectName(QString::fromUtf8("verticalSlider_5"));
        verticalSlider_5->setGeometry(QRect(1410, 70, 22, 160));
        verticalSlider_5->setOrientation(Qt::Vertical);
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 380, 111, 23));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1150, 10, 181, 31));
        lcdNumber_5 = new QLCDNumber(tab);
        lcdNumber_5->setObjectName(QString::fromUtf8("lcdNumber_5"));
        lcdNumber_5->setGeometry(QRect(1090, 270, 64, 23));
        lcdNumber_6 = new QLCDNumber(tab);
        lcdNumber_6->setObjectName(QString::fromUtf8("lcdNumber_6"));
        lcdNumber_6->setGeometry(QRect(1190, 270, 64, 23));
        lcdNumber_7 = new QLCDNumber(tab);
        lcdNumber_7->setObjectName(QString::fromUtf8("lcdNumber_7"));
        lcdNumber_7->setGeometry(QRect(1290, 270, 64, 23));
        lcdNumber_8 = new QLCDNumber(tab);
        lcdNumber_8->setObjectName(QString::fromUtf8("lcdNumber_8"));
        lcdNumber_8->setGeometry(QRect(1390, 270, 64, 23));
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(260, 50, 811, 671));
        widget->setStyleSheet(QString::fromUtf8(""));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(1090, 630, 101, 31));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(1090, 670, 101, 31));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1090, 530, 141, 51));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1250, 530, 141, 51));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1090, 590, 101, 31));
        radioButton_2 = new QRadioButton(tab);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(1280, 630, 131, 31));
        radioButton_3 = new QRadioButton(tab);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(1280, 670, 121, 31));
        radioButton = new QRadioButton(tab);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(1280, 590, 111, 31));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 221, 31));
        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(124, 380, 111, 23));
        textBrowser_2 = new QTextBrowser(tab);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(10, 410, 221, 101));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        comboBox = new QComboBox(tab_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 10, 191, 21));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(220, 0, 151, 41));
        textEdit = new QTextEdit(tab_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 60, 261, 301));
        textEdit_2 = new QTextEdit(tab_2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 370, 171, 31));
        pushButton_5 = new QPushButton(tab_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(190, 370, 81, 31));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        serial_plot = new QCustomPlot(tab_3);
        serial_plot->setObjectName(QString::fromUtf8("serial_plot"));
        serial_plot->setEnabled(true);
        serial_plot->setGeometry(QRect(10, 30, 1111, 461));
        textBrowser_3 = new QTextBrowser(tab_3);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setEnabled(true);
        textBrowser_3->setGeometry(QRect(10, 510, 1111, 201));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 720, 131, 21));
        formLayoutWidget = new QWidget(tab_3);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(1410, 0, 311, 171));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(formLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_15);

        comboBox_7 = new QComboBox(formLayoutWidget);
        comboBox_7->addItem(QString());
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox_7);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_9);

        comboBox_2 = new QComboBox(formLayoutWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox_2);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_10);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_11);

        label_12 = new QLabel(formLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_12);

        label_13 = new QLabel(formLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_13);

        comboBox_3 = new QComboBox(formLayoutWidget);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_3);

        comboBox_4 = new QComboBox(formLayoutWidget);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox_4);

        comboBox_5 = new QComboBox(formLayoutWidget);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox_5);

        comboBox_6 = new QComboBox(formLayoutWidget);
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));

        formLayout->setWidget(5, QFormLayout::FieldRole, comboBox_6);

        horizontalLayoutWidget = new QWidget(tab_3);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(1410, 180, 311, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_7 = new QPushButton(horizontalLayoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(horizontalLayoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(tab_3);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(1410, 390, 93, 28));
        verticalLayoutWidget = new QWidget(tab_3);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(1560, 390, 160, 65));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_11 = new QPushButton(verticalLayoutWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        verticalLayout->addWidget(pushButton_11);

        pushButton_10 = new QPushButton(verticalLayoutWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        verticalLayout->addWidget(pushButton_10);

        serialSendWindow = new QPlainTextEdit(tab_3);
        serialSendWindow->setObjectName(QString::fromUtf8("serialSendWindow"));
        serialSendWindow->setGeometry(QRect(1410, 280, 311, 101));
        checkSendHexBox = new QCheckBox(tab_3);
        checkSendHexBox->setObjectName(QString::fromUtf8("checkSendHexBox"));
        checkSendHexBox->setGeometry(QRect(1420, 230, 131, 31));
        checkRecHexBox = new QCheckBox(tab_3);
        checkRecHexBox->setObjectName(QString::fromUtf8("checkRecHexBox"));
        checkRecHexBox->setGeometry(QRect(1580, 230, 141, 31));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(1220, 20, 72, 15));
        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(1310, 20, 72, 15));
        verticalLayoutWidget_4 = new QWidget(tab_3);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(1130, 50, 91, 231));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(verticalLayoutWidget_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        verticalLayout_4->addWidget(label_19);

        label_18 = new QLabel(verticalLayoutWidget_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_4->addWidget(label_18);

        label_20 = new QLabel(verticalLayoutWidget_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        verticalLayout_4->addWidget(label_20);

        label_21 = new QLabel(verticalLayoutWidget_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout_4->addWidget(label_21);

        verticalLayoutWidget_5 = new QWidget(tab_3);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(1230, 50, 61, 231));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_25 = new QLabel(verticalLayoutWidget_5);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        verticalLayout_5->addWidget(label_25);

        label_22 = new QLabel(verticalLayoutWidget_5);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        verticalLayout_5->addWidget(label_22);

        label_24 = new QLabel(verticalLayoutWidget_5);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        verticalLayout_5->addWidget(label_24);

        label_23 = new QLabel(verticalLayoutWidget_5);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        verticalLayout_5->addWidget(label_23);

        verticalLayoutWidget_11 = new QWidget(tab_3);
        verticalLayoutWidget_11->setObjectName(QString::fromUtf8("verticalLayoutWidget_11"));
        verticalLayoutWidget_11->setGeometry(QRect(1310, 50, 71, 231));
        verticalLayout_11 = new QVBoxLayout(verticalLayoutWidget_11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_26 = new QLabel(verticalLayoutWidget_11);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        verticalLayout_11->addWidget(label_26);

        label_27 = new QLabel(verticalLayoutWidget_11);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        verticalLayout_11->addWidget(label_27);

        label_28 = new QLabel(verticalLayoutWidget_11);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        verticalLayout_11->addWidget(label_28);

        label_29 = new QLabel(verticalLayoutWidget_11);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        verticalLayout_11->addWidget(label_29);

        label_58 = new QLabel(tab_3);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(1130, 470, 72, 21));
        label_59 = new QLabel(tab_3);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(1130, 520, 72, 31));
        progressBar_3 = new QProgressBar(tab_3);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setGeometry(QRect(1210, 470, 118, 23));
        progressBar_3->setValue(24);
        progressBar_4 = new QProgressBar(tab_3);
        progressBar_4->setObjectName(QString::fromUtf8("progressBar_4"));
        progressBar_4->setGeometry(QRect(1210, 520, 118, 23));
        progressBar_4->setValue(24);
        label_60 = new QLabel(tab_3);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(1120, 390, 91, 31));
        label_61 = new QLabel(tab_3);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(1270, 390, 101, 31));
        dial_9 = new QDial(tab_3);
        dial_9->setObjectName(QString::fromUtf8("dial_9"));
        dial_9->setGeometry(QRect(1550, 530, 161, 111));
        label_62 = new QLabel(tab_3);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setGeometry(QRect(1540, 500, 181, 21));
        lcdNumber_19 = new QLCDNumber(tab_3);
        lcdNumber_19->setObjectName(QString::fromUtf8("lcdNumber_19"));
        lcdNumber_19->setGeometry(QRect(1560, 650, 131, 23));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        graph_plot = new QCustomPlot(tab_4);
        graph_plot->setObjectName(QString::fromUtf8("graph_plot"));
        graph_plot->setGeometry(QRect(30, 40, 1661, 491));
        dial_10 = new QDial(tab_4);
        dial_10->setObjectName(QString::fromUtf8("dial_10"));
        dial_10->setGeometry(QRect(30, 540, 161, 111));
        dial_11 = new QDial(tab_4);
        dial_11->setObjectName(QString::fromUtf8("dial_11"));
        dial_11->setGeometry(QRect(240, 540, 161, 111));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        treeView = new QTreeView(tab_5);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(0, 10, 341, 441));
        verticalLayoutWidget_2 = new QWidget(tab_5);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(410, 50, 271, 431));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_12 = new QPushButton(verticalLayoutWidget_2);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        verticalLayout_2->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(verticalLayoutWidget_2);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        verticalLayout_2->addWidget(pushButton_13);

        pushButton_14 = new QPushButton(verticalLayoutWidget_2);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        verticalLayout_2->addWidget(pushButton_14);

        pushButton_15 = new QPushButton(verticalLayoutWidget_2);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        verticalLayout_2->addWidget(pushButton_15);

        pushButton_16 = new QPushButton(verticalLayoutWidget_2);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));

        verticalLayout_2->addWidget(pushButton_16);

        verticalLayoutWidget_3 = new QWidget(tab_5);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(710, 50, 221, 431));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_3 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_3->addWidget(lineEdit_3);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_3->addWidget(lineEdit_2);

        lineEdit = new QLineEdit(verticalLayoutWidget_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_3->addWidget(lineEdit);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout_3->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout_3->addWidget(lineEdit_5);

        lineEdit_6 = new QLineEdit(tab_5);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(470, 20, 113, 21));
        lineEdit_7 = new QLineEdit(tab_5);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(740, 20, 113, 21));
        lcdNumber_9 = new QLCDNumber(tab_5);
        lcdNumber_9->setObjectName(QString::fromUtf8("lcdNumber_9"));
        lcdNumber_9->setGeometry(QRect(620, 22, 91, 21));
        pushButton_17 = new QPushButton(tab_5);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setGeometry(QRect(1000, 90, 93, 28));
        textEdit_3 = new QTextEdit(tab_5);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(950, 50, 141, 31));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabWidget->addTab(tab_6, QString());
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 780, 751, 131));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/Image/more.png);"));
        textBrowser_7 = new QTextBrowser(centralwidget);
        textBrowser_7->setObjectName(QString::fromUtf8("textBrowser_7"));
        textBrowser_7->setGeometry(QRect(1230, 790, 491, 101));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "HM013", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "LeftMICFF        LeftMICFB       RightMICFF      RightMICFB", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", " \345\257\274\345\205\245", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "             PGA", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", " IR\346\265\213\350\257\225", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", " \350\247\246\346\221\270\346\265\213\350\257\225", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "     \344\272\247 \346\265\213 \345\212\237 \350\203\275", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "        \351\237\263\351\242\221\345\234\272\346\231\257", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", " \344\274\240\346\204\237\345\231\250\346\265\213\350\257\225", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", " ANC PASS ", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", " ANC OFF", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", " ANC ON", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\227\245\346\234\237\357\274\232", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "   \346\237\245\346\211\276USB", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\227\245\345\277\227\344\277\241\346\201\257\357\274\232</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "  \345\212\237\350\203\275", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\344\270\255\346\226\207", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "English", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", " \350\257\255\350\250\200(Language)", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	<span style=\" font-size:11pt; font-weight:600; text-decoration: underline; color:#ff0000;\">\350\256\270\345\217\257\350\257\201</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt; font-weight:600; text-decoration: underline; color:#ff0000;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt; font-weight:600; text-decora"
                        "tion: underline; color:#ff0000;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt; font-weight:600; text-decoration: underline; color:#ff0000;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ffffff;\">\345\210\235\346\254\241\344\275\277\347\224\250\346\234\211\346\225\210\346\234\237\346\230\257\344\270\200\344\270\252\346\234\210\357\274\214\350\277\207\346\234\237\350\257\267\350\201\224\347\263\273</span></p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">\350\257\267\350\276\223\345\205\245Lincese</span></p></body></html>", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\347\241\256\350\256\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", " \350\256\276\347\275\256", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "   \344\270\262\345\217\243\350\260\203\350\257\225\344\277\241\346\201\257", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "   \344\270\262\345\217\243\345\217\267", nullptr));
        comboBox_7->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240", nullptr));

        label_9->setText(QCoreApplication::translate("MainWindow", "    \346\263\242\347\211\271\347\216\207", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "115000", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "1152000", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "9600", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211", nullptr));

        label_10->setText(QCoreApplication::translate("MainWindow", "    \345\201\234\346\255\242\344\275\215", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "    \346\225\260\346\215\256\344\275\215", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "  \345\245\207\345\201\266\346\240\241\351\252\214", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "    \346\265\201\346\216\247\345\210\266", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));

        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "8", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("MainWindow", "10", nullptr));

        comboBox_5->setItemText(0, QCoreApplication::translate("MainWindow", "\345\245\207\346\225\260", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("MainWindow", "\345\201\266\346\225\260", nullptr));

        comboBox_6->setItemText(0, QCoreApplication::translate("MainWindow", "\347\241\254\344\273\266", nullptr));
        comboBox_6->setItemText(1, QCoreApplication::translate("MainWindow", "\346\227\240", nullptr));

        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", " \346\220\234\345\257\273", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "  \345\217\221\351\200\201", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", " \346\216\245\346\224\266\345\214\272\346\270\205\351\231\244", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "  \345\217\221\351\200\201\345\214\272\346\270\205\351\231\244", nullptr));
        checkSendHexBox->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\215\201\345\205\255\350\277\233\345\210\266", nullptr));
        checkRecHexBox->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\345\215\201\345\205\255\350\277\233\345\210\266", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "  \344\270\273 \350\200\263", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "  \345\211\257\350\200\263", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\345\207\272\345\205\245\347\233\222\347\212\266\346\200\201:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\344\275\251\346\210\264\347\212\266\346\200\201:", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "TWS\347\212\266\346\200\201:", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\350\223\235\347\211\231\350\277\236\346\216\245:", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "off", nullptr));
        label_58->setText(QCoreApplication::translate("MainWindow", "\344\270\273\350\200\263\347\224\265\346\261\240", nullptr));
        label_59->setText(QCoreApplication::translate("MainWindow", "\345\211\257\350\200\263\347\224\265\346\261\240", nullptr));
        label_60->setText(QCoreApplication::translate("MainWindow", " \345\216\213\346\204\237\346\223\215\344\275\234\357\274\232", nullptr));
        label_61->setText(QCoreApplication::translate("MainWindow", "\346\227\240", nullptr));
        label_62->setText(QCoreApplication::translate("MainWindow", "       \345\216\213\346\204\237\351\230\200\345\200\274", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "  \345\216\213\346\204\237", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", " \347\224\237\344\272\247\346\214\207\346\240\207", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "\344\272\247\346\265\213", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "\345\216\213\346\204\237\345\274\200\345\247\213", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "\345\216\213\346\204\237\345\201\234\346\255\242", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "\345\216\213\346\204\237\346\240\241\351\252\214\345\274\200\345\247\213", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", " \345\216\213\346\204\237\346\240\241\351\252\214\345\201\234\346\255\242", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainWindow", "\346\210\220\345\212\237:\345\244\261\350\264\245 ?", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "\346\210\220\345\212\237:\345\244\261\350\264\245 ?", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "\346\210\220\345\212\237:\345\244\261\350\264\245 ?", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "\346\210\220\345\212\237:\345\244\261\350\264\245 ?", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("MainWindow", "\346\210\220\345\212\237:\345\244\261\350\264\245 ?", nullptr));
        lineEdit_6->setText(QCoreApplication::translate("MainWindow", "   \346\265\213\350\257\225\351\200\211\351\241\271", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("MainWindow", "   \346\265\213\350\257\225\347\212\266\346\200\201", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", " \347\241\256\350\256\244", nullptr));
        textEdit_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\276\223\345\205\245\345\216\213\346\265\213\346\254\241\346\225\260</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "  \351\237\263\351\242\221\346\216\247\345\210\266", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
