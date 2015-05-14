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
    temp.addItem("test item 1.");
    temp.addItem("yay ☺");
    //cout << "Empty manager." << endl;
    //cout << m << endl;

    //cout << "ADDING TASK" << endl;
    m.addTask(temp);
    //cout << m << endl;

    //cout << "ADDING TASK" << endl;
    m.addTask(Task("Anonymoust testing task ;3"));
    //cout << m << endl;


   // cout << "ADDING TASK" << endl;
    m.addTask(Task("Another testing task."));
  //  cout << m << endl;

    /*

    // Test the swap task function
    cout << "Swapping task 0 and task 2" << endl;
    m.swapTasks(0,2);
    cout << m << endl;

    cout << "Swapping task 1 and task 2" << endl;
    m.swapTasks(1,2);
    cout << m << endl;

    cout << "Swapping 0 and 2" << endl;
    m.swapTasks(0,2);
    cout << m << endl;
    */

    // test the task promotion/demotion
    cout << m << endl << endl;
    cout << "Promoting task 2 by 2" << endl;
    cout << "(" << m.getTask(2).getTitle() << ") to position 0" << endl;
    m.promote(2,2);
    cout << m;
    cout << endl;

    cout << "Promoting task 1 by 1" << endl;
    cout << "(" << m.getTask(1).getTitle() << ") to position 0" << endl;
    m.promote(1,1);
    cout << m;
    cout << endl;

    // These should not change anything
    m.promote(3,0);
    m.promote(0,0);
    m.promote(1,33);
    m.promote(0,-1);
    m.promote(-1,0);

    /*
    cout << "Demoting task 1 by 1" << endl;
    cout << "(" << m.getTask(1).getTitle() << ") to position 2" << endl;
    m.demote(1,1);
    cout << m;
    cout << endl;
    */

    cout << endl;
    cout << "Adding some tasks." << endl;
    m.addTask(Task("anony task"));
    m.addTask(Task("kitties are cute task"));

    cout << endl;
    cout << endl;
    cout << endl;
    cout << m;
    cout << "Demoting task 0 by 3" << endl;
    cout << "(" << m.getTask(0).getTitle() << ") to position 3" << endl;
    m.demote(0,3);
    cout << m;
    cout << endl;

    /*
    cout << endl;
    cout << "Promoting task 3 by 3" << endl;
    cout << "(" << m.getTask(3).getTitle() << ") to position 0" << endl;
    m.promote(3,3);
    cout << m;
    cout << endl;
    */


}
