#ifndef CHANGETASK_H
#define CHANGETASK_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QDialogButtonBox>
//#include "ui_changetask.h"
#include "model/RelativeDue.h"
#include "model/user.h"
#include "data/dataTask.h"

namespace Ui {
class ChangeTask;
}

class ChangeTask : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeTask(QWidget *parent = nullptr);
    ~ChangeTask();

public slots:
    void setDescription(const QString& desc);
    void initializeStateDropdown(QComboBox* comboBox);
    void initializeUserDropdown(QComboBox* comboBox);

private:
    Ui::ChangeTask *ui;
};

#endif // CHANGETASK_H
