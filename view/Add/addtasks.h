#ifndef ADDTASKS_H
#define ADDTASKS_H

#include <QDialog>
#include <QComboBox>

namespace Ui {
class AddTasks;
}

class AddTasks : public QDialog
{
    Q_OBJECT

public:
    explicit AddTasks(QWidget *parent = nullptr);
    ~AddTasks();

private:
    Ui::AddTasks *ui;
    void initializeStateDropdown(QComboBox* comboBox);
};

#endif // ADDTASKS_H
