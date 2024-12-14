#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tasktablemodel.h"
#include "model/task.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QVector<Task> tasks = {
        Task(1, "Finish project", "2024-09-30", "Alice, Bob", "open"),
        Task(2, "Prepare meeting", "2024-10-05", "Charlie", "open"),
        Task(3, "Write report", "2024-10-15", "Alice, Eve", "closed")
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

