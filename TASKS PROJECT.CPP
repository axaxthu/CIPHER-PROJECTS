#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;
    string category;
    bool completed;

    Task(string description, string category) {
        this->description = description;
        this->category = category;
        this->completed = false;
    }
};

vector<Task> NotesAdded;

void displayTasks() {
    if (NotesAdded.empty()) {
        cout << "No tasks added yet." << endl;
        return;
    }

    cout << "\nTasks:\n";
    for (int i = 0; i < NotesAdded.size(); ++i) {
        cout << i + 1 << ". " << NotesAdded[i].description << " [" << NotesAdded[i].category << "] "
             << (NotesAdded[i].completed ? "(Completed)" : "(Pending)") << "\n";
    }
}

void addTask() {
    string description, category;
    cout << "Enter the Description: ";
    cin.ignore(); // Ignore any remaining newline characters in the input buffer
    getline(cin, description); // Read entire line including spaces
    cout << "Enter the Category: ";
    getline(cin, category); // Read entire line including spaces

    Task task(description, category);
    NotesAdded.push_back(task);

    cout << "Task added successfully." << endl;
}

void markTaskAsCompleted() {
    if (NotesAdded.empty()) {
        cout << "No tasks added yet." << endl;
        return;
    }

    int index;
    cout << "Enter the index of the task to mark as completed: ";
    cin >> index;

    if (index < 1 || index > NotesAdded.size()) {
        cout << "Invalid task index." << endl;
        return;
    }

    NotesAdded[index - 1].completed = true;
    cout << "Task marked as completed." << endl;
}

void deleteTask() {
    if (NotesAdded.empty()) {
        cout << "No tasks added yet." << endl;
        return;
    }

    int index;
    cout << "Enter the index of the task to delete: ";
    cin >> index;

    if (index < 1 || index > NotesAdded.size()) {
        cout << "Invalid task index." << endl;
        return;
    }

    NotesAdded.erase(NotesAdded.begin() + index - 1);
    cout << "Task deleted." << endl;
}

void filterTaskByCategory() {
    if (NotesAdded.empty()) {
        cout << "No tasks added yet." << endl;
        return;
    }

    string category;
    cout << "Enter the category to filter by: ";
    cin.ignore(); // Ignore any remaining newline characters in the input buffer
    getline(cin, category); // Read entire line including spaces

    cout << "\nTasks in category '" << category << "':\n";
    bool found = false;
    for (int i = 0; i < NotesAdded.size(); ++i) {
        if (NotesAdded[i].category == category) {
            found = true;
            cout << i + 1 << ". " << NotesAdded[i].description << " [" << NotesAdded[i].category << "] "
                 << (NotesAdded[i].completed ? "(Completed)" : "(Pending)") << "\n";
        }
    }

    if (!found) {
        cout << "No tasks found in category '" << category << "'." << endl;
    }
}

void displayMenu() {
    int choice;
    do {
        cout << "\nMenu:\n"
             << "1. Add Task\n"
             << "2. View Tasks\n"
             << "3. Mark Task as Completed\n"
             << "4. Delete Task\n"
             << "5. Filter Tasks By Category\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                filterTaskByCategory();
                break;
            case 6:
                cout << "Goodbye! Please do the tasks on time." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }
    } while (choice != 6);
}

int main() {
    displayMenu();
    return 0;
}
