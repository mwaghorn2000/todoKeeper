#include "Task.h"
using namespace std;

Task::Task(string& desc) : description(desc), completed(false) {}

void Task::markCompleted() {
    completed = true;
}

bool Task::isCompleted() const {
    return completed;
}

string Task::getDescription() const {
    return description;
}

void Task::setDescription(const std::string& desc) {
    description = desc;
}