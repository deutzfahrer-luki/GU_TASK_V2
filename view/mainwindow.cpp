#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tasktablemodel.h"
#include "model/task.h"
#include "data/dataTask.h"
#include "view/Add/addtasks.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    m_model = new TaskTableModel(this);
    m_model->setTasks(tasks);

    ui->setupUi(this);

    ui->tableView->setModel(m_model);
    connect(ui->AddTaskButton, &QPushButton::clicked, this, &MainWindow::AddTaskButton_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddTaskButton_clicked()
{
    AddTasks *addTasksDialog = new AddTasks(this);
    connect(addTasksDialog, &AddTasks::taskAdded, this, [this](const Task& task) {
        tasks.append(task);
        m_model->setTasks(tasks);
    });
    addTasksDialog->exec();
}
