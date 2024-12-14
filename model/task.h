#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>

class Task
{
public:
    Task(int id, const std::string& description, const std::string& due, const std::string& assignee, const std::string& state) {
        this->id = id;
        this->description = description;
        this->due = due;
        this->assignee = assignee;
        this->state = state;
    }

    void setDone() {
        state = "done";
    }

    int getId() const { return this->id; }

    std::string getDescription() const { return this->description; }
private:
    int id;
    std::string description;
    std::string due;
    std::string assignee;
    std::string state;
};

#endif // TASK_H
