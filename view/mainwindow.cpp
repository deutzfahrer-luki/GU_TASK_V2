#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tasktablemodel.h"
#include "model/task.h"
#include "data/dataTask.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    // Erstelle ein neues Modell und setze die Aufgabenliste
    TaskTableModel *model = new TaskTableModel(this);
    model->setTasks(tasks);

    ui->setupUi(this);

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AddTaskButton_clicked()
{
    AddTasks *addTasksDialog = new AddTasks(this);
    addTasksDialog->exec();
}
