#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class ToDoList {
private:
  vector<pair<string, string>> tasks;
  string userName;

public:
  ToDoList(string name) : userName(name) {}

  void addTask(string name, string description) {
    tasks.push_back(make_pair(name, description));
  }

  void viewTasks() {
    cout << endl;
    if (tasks.empty()) {
      cout << "You are great, there is no task." << endl;
    } else {
      cout << "Tasks:" << endl;
      int count = 1;
      for (auto task : tasks) {
        if (task.second.empty())
          cout << count << ". " << task.first << endl;
        else
          cout << count << ". " << task.first << " - " << task.second << endl;
        count++;
      }
    }
    cout << endl;
  }

  void removeTask(int taskNum) {
    if (tasks.empty()) {
      cout << "There is no task to remove." << endl;
      return;
    }

    if (taskNum < 1 || taskNum > tasks.size()) {
      cout << "Task not found." << endl;
      return;
    }

    tasks.erase(tasks.begin() + taskNum - 1);
    cout << "Task removed." << endl;
  }

  void saveList() {
    ofstream file(userName + "_todolist");
    for (auto task : tasks)
      file << task.first << " - " << task.second << endl;
    file.close();
  }

  void readList() {
    ifstream file(userName + "_todolist");
    string line;
    while (getline(file, line)) {
      int pos = line.find(" - ");
      string name = line.substr(0, pos);
      string description = line.substr(pos + 3);
      tasks.push_back(make_pair(name, description));
    }
    file.close();
  }
};

int main() {
  cout << "Enter your name: ";
  string userName;
  getline(cin, userName);
  ToDoList list(userName);
  list.readList();

  int choice;
  int taskNum;
  string name, description;

  cout << R"(
Welcome to your To-Do List
       _________
      /  To-Do  \
      |   List  |
      |_________|)" << endl;

  while (true) {
    cout << endl;
    cout << "Main Menu:" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Remove Task" << endl;
    // cout << "4. Save List" << endl;
    cout << "4. Quit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << endl;
        cout << "Enter task name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter task description: ";
        getline(cin, description);
        list.addTask(name, description);
        list.saveList();
        break;
      case 2:
        list.viewTasks();
        break;
      case 3:
        cout << endl;
        cout << "Enter task number to remove: ";
        cin >> taskNum;
        list.removeTask(taskNum);
        list.saveList();
        break;
      // case 4:
      //   list.saveList();
      //   break;
      case 4:
        return 0;
        break;
      default:
        cout << "Invalid choice." << endl;
        break;
    }
    cout << "-----------------------------------" << endl;
  }

  return 0;
}