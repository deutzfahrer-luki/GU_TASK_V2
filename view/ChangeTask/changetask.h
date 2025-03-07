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
#include "util/date.h"


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
    void initializeStateDropdownChange(QComboBox* comboBox);
    void initializeStateDropdownAdd(QComboBox* comboBox);

    void initializeUserDropdownChange(QComboBox* comboBox);
    void initializeUserDropdownAdd(QComboBox* comboBox);

    void setDateByTasks();
    void setDescriptionByTasks(QLineEdit* descLine);

    void setDateToday();

    void updateTasks();

    void addTasks();

private:
    Ui::ChangeTask *ui;
    void getTaskId();
    long indexTask_;

};

#endif // CHANGETASK_H
