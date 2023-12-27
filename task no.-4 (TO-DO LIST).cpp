#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    string description;
    bool completed;
};
void addTask(vector<Task> &taskList, const string &description) {
    Task newTask = {description, false};
    taskList.push_back(newTask);
    cout << "Task added successfully.\n";
}

void viewTasks(const vector<Task> &taskList) {
    cout << "Task List:\n";
    for (size_t i = 0; i < taskList.size(); ++i) {
        cout << i + 1 << ". ";
        if (taskList[i].completed) {
            cout << "[Completed] ";
        }
        cout << taskList[i].description << endl;
    }
}

void markTaskAsCompleted(vector<Task> &taskList, size_t index) {
    if (index >= 0 && index < taskList.size()) {
        taskList[index].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

void removeTask(vector<Task> &taskList, size_t index) {
    if (index >= 0 && index < taskList.size()) {
        taskList.erase(taskList.begin() + index);
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

int main() {
    vector<Task> taskList;

    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                cin.ignore();
                string description;
                getline(cin, description);
                addTask(taskList, description);
                break;
            }
            case 2:
                viewTasks(taskList);
                break;
            case 3: {
                viewTasks(taskList);
                cout << "Enter the index of the task to mark as completed: ";
                size_t index;
                cin >> index;
                markTaskAsCompleted(taskList, index - 1);
                break;
            }
            case 4: {
                viewTasks(taskList);
                cout << "Enter the index of the task to remove: ";
                size_t index;
                cin >> index;
                removeTask(taskList, index - 1);
                break;
            }
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    }

    return 0;
}

