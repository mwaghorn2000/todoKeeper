#pragma once
#include <string>
using namespace std;

class Task {
private:
    string description;
    bool completed;
public:
    Task(string& desc);

    void setDescription(const string& desc);
    string getDescription() const;

    void markCompleted();
    bool isCompleted() const;
};