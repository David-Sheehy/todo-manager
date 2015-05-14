#include <string>
#include "task.h"
//TODO Test the expand function
//TODO Test the adding subtask function
//TODO test the removeSubtask, setSubtask, and getSubtask
//     functions.


/**
 * Task
 * class: Task
 * description: The copy constructor.
 * Parameters:
 *      o
 */
Task::Task(const Task& o) {
    this->n = o.n;
    this->len = o.len;
    this->items = new std::string[len];
    for(int i = 0; i < n; ++i) {
        this->items[i] = o.items[i];
    }
};


/**
 * operator=
 * class; Task
 * description: Create a deep copy of another task object.
 */
Task& Task::operator=(const Task& o) {
    if(this != &o) {
        delete [] this->items;
        this->n = o.n;
        this->len = o.len;
        this->items = new std::string[len];
        for(int i = 0; i < n; ++i) {
            this->items[i] = o.items[i];
        }
    }
    return *this;
}

/*
 * expand
 * class: Task
 * description: Doubles the capacity of the subtasks.
 * parameters - none
 * return - none
 */
void Task::expand() {
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
 * description: Removes a subtask with a given priority and updates all the
 *              tasks below it to have a higher priority.
 * paramters:
 *      priority - The index of the subtask being moved.
 * return: None
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
 * description: Modifies a given subtask.
 * Parameters:
 *      sb - The new contents for a subtask.
 *      n - The index of the subtask being modified.
 * return: none
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
    return this->items[ndx];
};
