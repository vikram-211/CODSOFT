#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(std::string desc) : description(desc), completed(false) {}
};

void addTask(std::vector<Task>& tasks) {
    std::string taskDesc;
    std::cin.ignore();  // Clear input buffer
    std::cout << "Enter task description: ";
    std::getline(std::cin, taskDesc);
    tasks.push_back(Task(taskDesc));
    std::cout << "Task added successfully!\n";
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list.\n";
        return;
    }

    std::cout << "\n=== To-Do List ===\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". [" << (tasks[i].completed ? "✔" : " ") << "] "
                  << tasks[i].description << "\n";
    }
    std::cout << std::endl;
}

void markTaskCompleted(std::vector<Task>& tasks) {
    int index;
    std::cout << "Enter task number to mark as completed: ";
    std::cin >> index;

    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        std::cout << "Task marked as completed.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

void removeTask(std::vector<Task>& tasks) {
    int index;
    std::cout << "Enter task number to remove: ";
    std::cin >> index;

    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        std::cout << "Task removed.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;

    do {
        std::cout << "\n=== TO-DO LIST MENU ===\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: markTaskCompleted(tasks); break;
            case 4: removeTask(tasks); break;
            case 5: std::cout << "Exiting To-Do List Manager.\n"; break;
            default: std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
