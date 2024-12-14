#ifndef TASK_H
#define TASK_H

#include <string>
#include <chrono>
#include <vector>
#include <stdexcept>
#include "TaskStatus.h"

class Task
{
public:
    /*
    Task(int taskId, const std::string& desc, std::chrono::system_clock::time_point due, const std::string& assignee, TaskStatus taskStatus) {
        this->id = taskId;
        // ...
    }
    */

    // std::string& -> Referenz. Verhindert, das gesamter String kopiert wird
    // const -> übergebener String darf nicht verändert werden
    Task(int taskId, const std::string& desc, std::chrono::system_clock::time_point due, const std::string& assignee, TaskStatus taskStatus)
        : id(taskId), dueDate(due), assignee(assignee), status(taskStatus) {
        setDescription(desc);
    }

    // Getter-Methoden
    // const garantiert, dass eigenschaften von this nicht verändert werden. Damit sind diese Methoden auch für const objekte verfügbar
    int getId() const { return id; }
    std::string getDescription() const { return description; }
    std::chrono::system_clock::time_point getDueDate() const { return dueDate; }
    std::string getAssignee() const { return assignee; }
    TaskStatus getStatus() const { return status; }

    // Setter-Methoden
    void setDescription(const std::string& desc)
    {
        if (desc.empty())
            throw std::invalid_argument("Description is not allowed to be empty");
        description = desc;
    }

    void setDueDate(const std::chrono::system_clock::time_point& due) { dueDate = due; }
    void setAssignee(const std::string& assignee) { this->assignee = assignee; }
    void setStatus(TaskStatus taskStatus) { status = taskStatus; }

    // Optionale Methode: Fälligkeitsdatum als lesbare Zeichenkette
    std::string getDueDateString() const {
        std::time_t due_time = std::chrono::system_clock::to_time_t(dueDate);
        return std::ctime(&due_time);  // Achtung: ctime enthält einen Zeilenumbruch
    }

private:
    int id;
    std::string description;
    std::chrono::system_clock::time_point dueDate;
    std::string assignee;
    TaskStatus status;
};

#endif // TASK_H
