#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tasktablemodel.h"
#include "model/task.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QVector<Task> tasks = {
        Task(1,"Finsh Homework", Date(2024,12,24), "LK", "LOW")
    };

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

