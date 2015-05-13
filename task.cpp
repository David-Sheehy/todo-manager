#include <string>
#include "task.h"
//TODO Test the expand function
//TODO Test the adding subtask function
//TODO test the removeSubtask, setSubtask, and getSubtask
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
 * addItem
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
 * removeItem
 * class: Task
 * paramters:
 *      priority - The index of the subtask being moved.
 * return: None
 * description: Removes a subtask with a given priority and updates all the
 *              tasks below it to have a higher priority.
 */
void Task::removeItem(int priority) {
    if( n <= priority || priority < 0) {
        // do nothing
        return;
    }

    for(int i = priority; i < n-1; ++i) {
        this->items[i] = this->items[i+1];
    }
    n--;
};


/*
 * setIteem
 * class: Task
 * Parameters:
 *      sb - The new contents for a subtask.
 *      n - The index of the subtask being modified.
 * return: none
 * description: Modifies a given subtask.
 */
void Task::setItem(std::string sb, int ndx) {
    if( n <= ndx || ndx < 0) {
        // do nothing
        return;
    }
    this->items[ndx] = sb;
};

std::string Task::getItem(int ndx) {
    if(n <= ndx || ndx < 0) {
        return "";
    }
    return this->itemx[ndx];
};
