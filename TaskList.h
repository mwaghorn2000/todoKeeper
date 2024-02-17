#pragma once
#include <vector>
#include "Task.h"

class TaskList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const Task &task);
    void removeTask(int index);
    void markTaskComplete(int index);
    std::vector<Task> getTasks() const;
};