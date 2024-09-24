#include <iostream>
#include <string>
using namespace std;

// Node structure for Task
struct TaskNode {
    int taskID;
    string description;
    int priority;
    TaskNode* next;
};

// Head of the linked list
TaskNode* head = NULL;

// Function to add a task based on priority
void addTask(int id, string desc, int priority) {
    TaskNode* newTask = new TaskNode;
    newTask->taskID = id;
    newTask->description = desc;
    newTask->priority = priority;
    newTask->next = NULL;

    if (head == NULL || head->priority < priority) {
        newTask->next = head;
        head = newTask;
    } else {
        TaskNode* current = head;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        }
        newTask->next = current->next;
        current->next = newTask;
    }
    cout << "Task added successfully!\n";
}

// Function to view all tasks
void viewTasks() {
    if (head == NULL) {
        cout << "No tasks available.\n";
        return;
    }
    TaskNode* temp = head;
    cout << "Task List:\n";
    while (temp != NULL) {
        cout << "ID: " << temp->taskID << ", Description: " << temp->description
             << ", Priority: " << temp->priority << endl;
        temp = temp->next;
    }
}

// Function to remove the highest priority task
void removeHighestPriorityTask() {
    if (head == NULL) {
        cout << "No tasks available to remove.\n";
        return;
    }
    TaskNode* temp = head;
    head = head->next;
    delete temp;
    cout << "Highest priority task removed successfully!\n";
}

// Function to remove a task by its ID
void removeTaskByID(int id) {
    if (head == NULL) {
        cout << "No tasks available.\n";
        return;
    }

    if (head->taskID == id) {
        TaskNode* temp = head;
        head = head->next;
        delete temp;
        cout << "Task with ID " << id << " removed successfully!\n";
        return;
    }

    TaskNode* current = head;
    TaskNode* prev = NULL;
    
    while (current != NULL && current->taskID != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Task with ID " << id << " not found.\n";
        return;
    }

    prev->next = current->next;
    delete current;
    cout << "Task with ID " << id << " removed successfully!\n";
}

// Menu function to display options
void menu() {
    int choice;
    do {
        cout << "\nTask Management System\n";
        cout << "1. Add a new task\n";
        cout << "2. View all tasks\n";
        cout << "3. Remove the highest priority task\n";
        cout << "4. Remove a task by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, priority;
                string desc;
                cout << "Enter Task ID: ";
                cin >> id;
                cout << "Enter Task Description: ";
                cin.ignore(); // To ignore newline left by previous cin
                getline(cin, desc);
                cout << "Enter Task Priority: ";
                cin >> priority;
                addTask(id, desc, priority);
                break;
            }
            case 2:
                viewTasks();
                break;
            case 3:
                removeHighestPriorityTask();
                break;
            case 4: {
                int id;
                cout << "Enter Task ID to remove: ";
                cin >> id;
                removeTaskByID(id);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

// Main function
int main() {
    menu();
    return 0;
}
