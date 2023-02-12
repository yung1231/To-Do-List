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


  void removeTask(string taskNum) {
    int num = stoi(taskNum);
    if (num < 1 || num > tasks.size()) {
      cout << "Task not found." << endl;
      return;
    }

    tasks.erase(tasks.begin() + num - 1);
    cout << "Task removed." << endl;
  }

  void editTask(string taskNum, string name, string description) {
    int num = stoi(taskNum);
    if (num < 1 || num > tasks.size()) {
      cout << "Task not found." << endl;
      return;
    }

    tasks[num - 1].first = name;
    tasks[num - 1].second = description;
    cout << "Task edited." << endl;
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

  bool isEmpty() const {
      return tasks.empty();
  }
};

bool isNumber(string str) {
  for (char c : str) {
    if (!isdigit(c)) {
      cout << "Please enter the number" <<endl;
      return false;
    }
  }
  return true;
}

int main() {
  cout << "Enter your name: ";
  string userName;
  getline(cin, userName);
  ToDoList list(userName);
  list.readList();

  string choice;
  string taskNum;
  string name, description;
  bool isNum;

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
    cout << "4. Edit Task" << endl;
    cout << "5. Quit" << endl;
    isNum = false;
    while(!isNum){
      cout << endl;
      cout << "Enter your choice: ";
      cin >> choice;
      isNum = isNumber(choice);
    }
    int choiceNum = stoi(choice);
    

    switch (choiceNum) {
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
        isNum = false;
        if (!list.isEmpty()) {
          while(!isNum){
            cout << endl;
            cout << "Enter task number to remove: ";
            cin >> taskNum;
            isNum = isNumber(taskNum);
          }
          list.removeTask(taskNum);
          list.saveList();
        } else {
          cout << "The task is empty." << endl;
        }
        break;
      case 4:
        isNum = false;
        if (!list.isEmpty()) {
          while(!isNum){
            cout << endl;
            cout << "Enter task number to edit: ";
            cin >> taskNum;
            isNum = isNumber(taskNum);
          }
          cout << "Enter task name: ";
          cin.ignore();
          getline(cin, name);
          cout << "Enter task description: ";
          getline(cin, description);
          list.editTask(taskNum, name, description);
          list.saveList();
        } else {
          cout << "The task is empty." << endl;
        }
        break;
      case 5:
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