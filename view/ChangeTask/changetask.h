#ifndef CHANGETASK_H
#define CHANGETASK_H

#include <QDialog>

namespace Ui {
class ChangeTask;
}

class ChangeTask : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeTask(QWidget *parent = nullptr);
    ~ChangeTask();

private:
    Ui::ChangeTask *ui;
};

#endif // CHANGETASK_H
