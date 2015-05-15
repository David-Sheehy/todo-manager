#include <fstream>
#include <iostream>
#include <string>
#include "manager.h"
#include "task.h"

using namespace std;

/*
 * displayHelp
 * class: None
 * description: Display a brief message detailing the commands and how to use
 *              them. The output stream is modified.
 * parameters:
 *      os - The output stream being displayed to.
 * return: None.
 */
void displayHelp(ostream& os);

/*
 * listAllTasks
 * class: None
 * description: Lists all the tasks by order of priority. The output stream is
 *              modified. The Manager is unchanged.
 * parameters:
 *      os - The output stream being written to.
 * return: None
 */
void listAllTasks(ostream &os, const Manager &m);

/*
 * listTask
 * class: None
 * description: Lists an arbitrary task. The output stream is modified. The
 *              manager is unchanged.
 * parameters:
 *      os - The output stream being written to.
 *      ndx - The index of the task being listed.
 */
void listTask(ostream& os,const Manager &m, int ndx);

/*
 * listSequence
 * class: None
 * description: List a sequence of tasks begining from the start priority to
 *              end priority. The output stream is modified, but the Manager is
 *              unchanged.
 * paramaters:
 *          os - The output stream
 *          m - The manager of tasks.
 *          start - The begining index of the tasks being listed.
 *          end - The end index of the tasks being listed.
 * return: None.
 */
void listSequence(ostream& os,const Manager &m, int start, int end);

/*
 * amendTask
 * class: None
 * description: Modifies a given task held in the manager. The manager is
 *              modified, but the Task is not.
 * paramaters:
 *      m - The manager.
 *      ndx - The index of the task being modified.
 *      t - The new Task.
 * return: Whether the amendment was successful.
 */
bool amendTask(Manager *m,int ndx,const Task &t);

/*
 * amendTaskItem
 * class: None
 * description: Amends a specific item in a specific task. The manager and the
 *              task held in the manager is modified.
 * paramaters:
 *      m - The manager.
 *      task - The index of the task being modified.
 *      item - The index of the item being modified.
 *      s - The new string value for the item.
 * return: Whether the amendment was successful.
 */
bool amendTaskItem(Manager *m, int task, int item, string s);

/*
 * createTask
 * class: None
 * description: Adds a task to the manager.
 * paramaters:
 *      m - The manager.
 *      t - The task being added to the manager.
 * return: Whether the addition was successful.
 */
bool createTask(Manager *m, const Task &t);

/*
 * removeTask
 * class: None
 * description: Removes a given task from the manager. The manager is modified.
 * paramaters:
 *      m - The manager.
 *      ndx - The index of the task being removed.
 * return: Whether the removal was successful.
 */
bool removeTask(Manager *m, int ndx);

/*
 * removeTaskItem
 * class: None
 * description: Removes an item from a task. The task held in the manager is
 *              modified.
 * paramaters:
 *      m - The manager.
 *      task - The index of the task.
 *      item - The index of the item.
 * return: Whether the item removal was successful.
 */
bool removeTaskItem(Manager *m,int task, int item);

/*
 * amendTaskPriority
 * class: None
 * description: Changes a task priority.
 * paramaters:
 *      m - The manager.
 *      task - The index of the task being amended.
 *      mod - The amount the priority is modified by.
 * return: Whether the promotion or demotion is successful.
 */
bool amendTaskPriority(Manager *m, int task, int mod);

/*
 * amendTaskItemPriority
 * class: None
 * description: Changes an item from a task priority. The task held in the
 *              manager is modified.
 * paramaters:
 *      m - The manager.
 *      task - The index of the task.
 *      item - The index of the item in the task being modified.
 *      mod - The number of spots it's being promoted or demoted.
 * return: Whether the promotion or demotion was successful.
 */
bool amendTaskItemPriority(Manager *m, int task, int item, int mod);

int main(int argc, char** argv) {
    // handle the arguments
    Manager m;

    /*
    if(argc < 2) {
        displayHelp(cout);
        return 1;
    }
    for(int i = 1; i < argc; ++i) {
        cout << argv[i] << endl;
    }
    listAllTasks(cout,m);

    // Test the output operator for task
    return 0;
    */
}

void displayHelp(ostream & os) {
    os << "usage: todo-manager <command> [<args>]" << endl;
    os << "The commands are: " << endl;
    os << "    amend [n <command> [<args>]]" << endl; 
    os << "    help                   Display this message." << endl;
    os << "    list [n][n m]          List all the tasks and their item, or  " << endl;
    os << "                           a task or display a range of tasks." << endl;
    os << "    remove [n]             Removes task n from the list."<< endl;
    os << "    swap [n m]             swaps the priority of task n and task m." << endl;
    os << "" << endl;
    os << "type todo-manager help <command> for more infromation on that command. " << endl;
}

void listAllTasks(ostream &os, const Manager &m) {
    os << m;
}
