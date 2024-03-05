#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(string desc) {
        tasks.push_back(Task(desc));
    }

    void displayTasks() {
        cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " - ";
            if (tasks[i].completed)
                cout << "Completed";
            else
                cout << "Pending";
            cout << endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
        } else {
            cout << "Invalid task index!\n";
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task index!\n";
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    string taskDescription;

    do {
        cout << "\n1. Add Task\n2. Display Tasks\n3. Mark Task Completed\n4. Remove Task\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore(); // Ignore previous newline character
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.displayTasks();
                break;
            case 3:
                size_t index;
                cout << "Enter task number to mark as completed: ";
                cin >> index;
                todoList.markTaskCompleted(index);
                break;
            case 4:
                size_t removeIndex;
                cout << "Enter task number to remove: ";
                cin >> removeIndex;
                todoList.removeTask(removeIndex);
                break;
            case 0:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice! Please try again.";
                break;
        }
    } while (choice != 0);

    return 0;
}
