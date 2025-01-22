#include "changetask.h"
#include "ui_changetask.h"

ChangeTask::ChangeTask(QWidget *parent, long indexTask)
    : QDialog(parent), indexTask_(indexTask)
    , ui(new Ui::ChangeTask)
{
    ui->setupUi(this);
    setDescription("HALLO");
    initializeStateDropdown(ui->comboBoxState);
    initializeUserDropdown(ui->comboBoxUser);

}

ChangeTask::~ChangeTask()
{
    delete ui;
}
/*
void ChangeTask::getTaskId()
{
    QItemSelectionModel *selectionModel = ui->tableView->selectionModel();

    if (!selectionModel->hasSelection()) {
        QMessageBox::warning(this, "Fehler", "Bitte wählen Sie eine Zeile aus, um sie zu löschen.");
        return;
    }

    QModelIndexList selectedRows = selectionModel->selectedRows();
    if (!selectedRows.isEmpty()) {
        int rowToDelete = selectedRows.first().row();
        tasks.removeAt(rowToDelete);
        m_model->setTasks(tasks);
        QMessageBox::information(this, "Erfolg", "Der Task wurde erfolgreich gelöscht.");
    }
}

*/


void ChangeTask::setDescription(const QString& desc) {
    ui->DescLine->setText(desc);
}

void ChangeTask::initializeStateDropdown(QComboBox* comboBox) {
    //comboBox->addItem(QString::fromStdString(relativeDueToString(tasks[indexTask_].getStateRelative())), QVariant(0));
    //std::cout<<relativeDueToString(tasks[indexTask_].getStateRelative())<<std::endl;
    //ERROR
    std::cout<<indexTask_<<std::endl;
    for (int i = static_cast<int>(RelativeDue::Irrelevant)+1; i <= static_cast<int>(RelativeDue::Later); ++i) {
        RelativeDue state = static_cast<RelativeDue>(i);
        comboBox->addItem(QString::fromStdString(relativeDueToString(state)), QVariant(i));
    }
}

void ChangeTask::initializeUserDropdown(QComboBox* comboBox) {
    for (const User& user : users) {
        comboBox->addItem(QString::fromStdString(user.getFullName()));
    }
}
