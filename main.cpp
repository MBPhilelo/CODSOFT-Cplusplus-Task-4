#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    Task(const string& description) : description(description), completed(false) {}

    string getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }

    void markAsCompleted() {
        completed = true;
    }

private:
    string description;
    bool completed;
};

class ToDoListManager {
public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". [" << (tasks[i].isCompleted() ? "x" : " ") << "] " << tasks[i].getDescription() << endl;
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks[index - 1].markAsCompleted();
    }

    void removeTask(size_t index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
    }

private:
    vector<Task> tasks;
};

void displayMenu() {
    cout << "To-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    ToDoListManager manager;
    int choice;
    string description;
    size_t taskNumber;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore newline character after choice input

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, description);
                manager.addTask(description);
                break;
            case 2:
                manager.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                manager.markTaskAsCompleted(taskNumber);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                manager.removeTask(taskNumber);
                break;
            case 5:
                cout << "Exiting the To-Do List Manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
