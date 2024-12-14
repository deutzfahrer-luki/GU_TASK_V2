#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
#include "util/date.h"

class Task
{
public:
    Task(int id, const std::string& description, const Date& birthday, const std::string& assignee, const std::string& state)
        : id(id), description(description), birthday(&birthday), assignee(assignee), state(state) {}

    void setDone() {
        if (state != "done") {
            state = "done";
            std::cout << "Task " << id << " marked as done.\n";
        }
    }

    int getId() const { return this->id; }
    std::string getDescription() const { return this->description; }
    std::string getAssignee() const { return this->assignee; }
    std::string getState() const { return this->state; }
    const Date* getBirthday() const { return this->birthday; }

private:
    const Date* birthday; // Verwaltet keinen Speicher, nur ein Verweis
    int id;
    std::string description;
    std::string assignee;
    std::string state;
};

#endif // TASK_H
