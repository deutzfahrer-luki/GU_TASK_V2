#ifndef CHANGETASK_H
#define CHANGETASK_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QDateEdit>
//#include "ui_changetask.h"
#include "model/RelativeDue.h"
#include "model/user.h"
#include "data/dataTask.h"
#include "view/AddTask/addtasks.h"


namespace Ui {
class ChangeTask;
}

class ChangeTask : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeTask(QWidget *parent = nullptr, long indexTask=-1);
    ~ChangeTask();

signals:
    void taskAdded(const Task& task);

public slots:
    void setDescription(QLineEdit* descLine);
    void updateTasks();

private:
    Ui::ChangeTask *ui;
    void getTaskId();
    long indexTask_;

};

#endif // CHANGETASK_H
