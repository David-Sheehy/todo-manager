#include <string>
#include "task.h"
//TODO Test the expand function
//TODO Test the adding subtask function
//TODO Implement and test the removeSubtask, setSubtask, and getSubtask
//     functions.

/*
 * expand
 * class: Task
 * parameters - none
 * return - none
 * description: Doubles the capacity of the subtasks.
 */
void expand() {
    len = 2 * len;
    std::string* temp = new std::string[len];
    
    for(int i = 0; i < len/2; ++i) {
        temp[i] = items[i];
    }

    delete [] items;
    items = temp;
}

/*
 * addSubtask
 * class: Task
 * Parameters:
 *      sb - The Subtask being added.
 */
void Task::addItem(std::string sb) {
    if(len <= n) {
        expand();
    } 

    items[n] = sb;
    n++;
};

/*
 * removeSubtask
 * class: Task
 * paramters:
 *      priority - The index of the subtask being moved.
 * return: None
 * description: Removes a subtask with a given priority and updates all the
 *              tasks below it to have a higher priority.
 */
void Task::removeItem(int priority) {
};

void Task::setItem(std::string sb, int n) {
};

std::string Task::getItem(int n) {
};
