#include "TaskList.h"
#include "Task.h"
#include <iostream>

void TaskList::addTask(const Task &task) {
    tasks.push_back(task);
}

void TaskList::removeTask(int index) {
    if (index < 0 || index >= tasks.size()) {
        std::cout << "Error removing task, Index out of range" << std::endl;
        return;
    }
    tasks.erase(tasks.begin() + index);
}

void TaskList::markTaskComplete(int index) {
    if (index < 0 || index >= tasks.size()) {
        std::cout << "Error marking task as complete, Index out of range" << std::endl;
        return;
    }

    tasks.at(index).markCompleted();
    std::cout << "marked task " << index << " completed" << std::endl; 
}

std::vector<Task> TaskList::getTasks() const {
    return tasks;
}