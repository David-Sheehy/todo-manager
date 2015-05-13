#include <string>
#include "task.h"
#include "subtask.h"
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
    Subtask* temp = new Subtask[len];
    
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
void Task::addSubtask(Subtask sb) {
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
void Task::removeSubtask(int priority) {

};

void Task::setSubtask(Subtask sb, int n) {
};

Subtask Task::getSubtask(int n) {
};
