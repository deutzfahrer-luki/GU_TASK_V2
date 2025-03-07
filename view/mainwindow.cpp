#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tasktablemodel.h"
#include "model/task.h"
#include "data/dataTask.h"
#include "view/AddUser/addusers.h"
#include "view/ChangeTask/changetask.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    m_model = new TaskTableModel(this);
    m_model->setTasks(tasks);

    ui->setupUi(this);
/*
    ui->tableView->setModel(m_model);
    connect(ui->AddTaskButton, &QPushButton::clicked, this, &MainWindow::AddTaskButton_clicked);
    connect(ui->AddUserButton, &QPushButton::clicked, this, &MainWindow::AddUserButton_clicked);
    connect(ui->DeleteTaskButton, &QPushButton::clicked, this, &MainWindow::DeleteTask_clicked);
    connect(ui->ChangeTaskButton, &QPushButton::clicked, this, &MainWindow::ChangeTask_clicked);
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddTaskButton_clicked()
{
    ChangeTask *changeTask = new ChangeTask(this);
    changeTask->exec();
    m_model->setTasks(tasks);
}

void MainWindow::AddUserButton_clicked()
{
    AddUsers *addUsersDialog = new AddUsers(this);
    addUsersDialog->exec();
}

void MainWindow::DeleteTask_clicked() {
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

void MainWindow::ChangeTask_clicked()
{
    long taskIndexOfVectorArray = getTaskIndexId();
    if (taskIndexOfVectorArray>=0)
    {
        ChangeTask *changeTask = new ChangeTask(this,taskIndexOfVectorArray);
        changeTask->exec();
        m_model->setTasks(tasks);
    }
}


long MainWindow::getTaskIndexId()
{
    QItemSelectionModel *selectionModel = ui->tableView->selectionModel();
    QModelIndexList selectedRows = selectionModel->selectedRows();
    if (!selectedRows.isEmpty()) {
        int rowToDelete = selectedRows.first().row();
        return rowToDelete;
    }
    else {
        QMessageBox::warning(this, "Fehler", "Bitte wählen Sie eine Zeile aus.");
        return -1;
    }
}

void MainWindow::on_reateTask_triggered()
{

}


void MainWindow::on_actiondeleteTask_triggered()
{

}

