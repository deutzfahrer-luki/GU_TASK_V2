#ifndef ADDTASKS_H
#define ADDTASKS_H

#include <QDialog>
#include <QComboBox>

#include <QPushButton>
#include <QDialogButtonBox>

#include "data/dataTask.h"
#include "model/RelativeDue.h"
#include "model/task.h"
#include "model/user.h"
#include "data/dataTask.h"


namespace Ui {
class AddTasks;
}

class AddTasks : public QDialog
{
    Q_OBJECT

public:
    explicit AddTasks(QWidget *parent = nullptr);
    ~AddTasks();

    QString getDescription() const;
    QDate getDate() const;
    QString getSelectedUser() const;
    QString getSelectedState() const;

public slots:
    void addTask();

signals:
    void taskAdded(const Task& task); // Neues Signal

private:
    Ui::AddTasks *ui;
};

#endif // ADDTASKS_H
