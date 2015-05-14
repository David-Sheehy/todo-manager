#include <fstream>
#include <iostream>
#include <string>
#include "manager.h"
#include "task.h"

using namespace std;

int main(int argc, char** argv) {
    bool customFile = false;;
    string customFileName = "";

    Manager m;
    // handle the arguments
    Task temp("Finish this project.");
    temp.addItem("Finish testing the task functionality.");                 // 0
    temp.addItem("Create an operator<< for the task and manager classes."); // 1
    temp.addItem("This item exists only for testing purposes.");            // 2
    temp.addItem("Finish writing/testing the manager functions.");          // 3
    temp.addItem("Decide on how I want to handle file input/output.");      // 4
    temp.addItem("Another testing item. :3");                               // 5
    temp.addItem("Design and create the interface.");                       // 6
    
    //cout << "ADDING TASK" << endl;
    m.addTask(temp);

    // print everything currently in the manager
    for(int i = 0; i < m.getNumberOfTasks(); ++i) {
        Task t = m.getTask(i);
        cout << t.getTitle() << endl;
        for(int j = 0; j < t.getNumberOfItems(); ++j) {
            cout << "\t " << j << " - " << t.getItem(j) << endl;
        }
    }

    // print everything currently in the manager
    m.removeItem(0,2);
    m.removeItem(1,2);
    m.removeItem(0,4);
    for(int i = 0; i < m.getNumberOfTasks(); ++i) {
        Task t = m.getTask(i);
        cout << t.getTitle() << endl;
        for(int j = 0; j < t.getNumberOfItems(); ++j) {
            cout << "\t " << j << " - " << t.getItem(j) << endl;
        }
    }
}
