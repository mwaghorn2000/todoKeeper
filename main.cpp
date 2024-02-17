#include <iostream>
#include "TaskList.h"
#include "Task.h"
#include <iomanip>

void runChoice(int choice, TaskList* tl);
void listTasks(TaskList* tl);
void addTask(TaskList* tl);
void removeTask(TaskList* tl);
void completeTask(TaskList* tl);


int main() {
    bool running = true;
    std::cout << "\nWelcome to Task Keeper!\n";

    TaskList tl;

    while (running) {
        std::cout << "\n1. Add Task\n";
        std::cout << "2. Remove Task\n";
        std::cout << "3. Complete Task\n";
        std::cout << "4. List Tasks\n";
        std::cout << "5. Exit" << endl;

        std::cout << "\nChoice: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input
            std::cout << "Invalid input. Please enter a number between 1 and 5.\n";
            continue; // Skip the rest of the loop iteration
        }

        runChoice(choice, &tl);
    }
}

void runChoice(int choice, TaskList* tl) {
    if (choice == 1) {
        addTask(tl);
    } else if (choice == 2) {
        removeTask(tl);
    } else if (choice == 3) {
        completeTask(tl);
    } else if (choice == 4) {
        listTasks(tl);
    } else if (choice == 5) {
        exit(0);
    } else {
        std::cout << "Invalid input. Please enter a number between 1 and 5.\n";
    }
}

void addTask(TaskList*  tl) {
    std::cout << "Enter description for task: ";
    std::string desc;
    cin.ignore();
    getline(std::cin, desc);
    
    Task newTask = Task(desc);
    tl->addTask(newTask);
}

void listTasks(TaskList* tl) {
    std::cout << "\n-----All Tasks-----\n\n";

    std::vector<Task> tasks = tl->getTasks();

    for (int i = 0; i < tasks.size(); i++) {
        std::cout << std::left << std::setw(30) << tasks[i].getDescription();
        if (tasks[i].isCompleted() == false) {
            std::cout << "\t Uncompleted\n";
        } else {
            std::cout << "\t Completed\n";
        }
    }

    std::cout << "\n-------------------\n";
}

void removeTask(TaskList* tl) {
    std::cout << "\nIndex of task you wish to remove: ";
    int index;
    std::cin >> index; 

    tl->removeTask(index);
}

void completeTask(TaskList* tl) {
    std::cout << "\nIndex of task you have completed: ";
    int index;
    std::cin >> index;

    tl->markTaskComplete(index);
}