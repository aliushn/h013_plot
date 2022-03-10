#include "testmodule.h"
#include "ui_testmodule.h"

TestModule::TestModule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestModule)
{
    ui->setupUi(this);
}

TestModule::~TestModule()
{
    delete ui;
}

void TestModule::on_textBrowser_sourceChanged(const QUrl &arg1)
{

}


void TestModule::on_pushButton_clicked()
{

}

