#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tasktablemodel.h"
#include "model/task.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    QVector<Task> tasks = {
        Task(1,"Finsh Homework", Date(2024,12,24), User("Lukas", "Koppl", Date(2007,9,22)), RelativeDue::Irrelevant),
        Task(2, "finish school", Date("2030-12-24"), User("Lukas", "Koppl", Date(2007,9,22)), RelativeDue::Irrelevant),
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

void MainWindow::on_AddTaskButton_clicked()
{
    AddTasks *addTasksDialog = new AddTasks(this);
    addTasksDialog->exec();
}
