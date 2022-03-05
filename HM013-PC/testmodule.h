#ifndef TESTMODULE_H
#define TESTMODULE_H

#include <QDialog>

namespace Ui {
class TestModule;
}

class TestModule : public QDialog
{
    Q_OBJECT

public:
    explicit TestModule(QWidget *parent = nullptr);
    ~TestModule();

private:
    Ui::TestModule *ui;
};

#endif // TESTMODULE_H
