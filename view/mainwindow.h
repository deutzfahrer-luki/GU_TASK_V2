#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QTableWidget>
#include <QMessageBox>
#include "viewController//tasktablemodel.h"
#include "model/task.h"
#include "data/dataTask.h"
#include "view/AddTask/addtasks.h"
#include "view/AddUser/addusers.h"
#include "view/ChangeTask/changetask.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void AddTaskButton_clicked();
    void AddUserButton_clicked();
    void DeleteTask_clicked();
    void ChangeTask_clicked();

private:
    Ui::MainWindow *ui;
    TaskTableModel *m_model; 
    long getTaskIndexId();
};
#endif // MAINWINDOW_H
