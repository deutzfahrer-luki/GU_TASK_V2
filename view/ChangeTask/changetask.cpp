#include "changetask.h"
#include "ui_changetask.h"

ChangeTask::ChangeTask(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChangeTask)
{
    ui->setupUi(this);
}

ChangeTask::~ChangeTask()
{
    delete ui;
}
