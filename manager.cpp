#include "task.h"
#include "manager.h"


/*
 * expand
 * class: Manager
 * paramters: none
 * return: none
 * description: Doubles the storage capacity for the tasks.
 */
void Manager::expand() {
    l = 2 * l;
    Task* temp = new Task[l];
    for(int i = 0; i < l/2; ++i) {
        temp[i] = tasks[i];
    }
    delete [] tasks;
    tasks = temp;
}

/*
 * addTask
 * class Manager
 * parameters:
 *       t - The task being appended to the list.
 * return: none
 * description: Adds a given task to end of the list.
 */
void Manager::addTask(Task t) {
    if(l <= n) {
        expand();
    }
    tasks[n] = t;
    n++;
}

/*
 * getTask
 * class: Manager
 * parameters:
 *      ndx - The ndx of the task being retrieved.
 * return: The task held at ndx or an empty task if that task does not exist.
 */
Task Manager::getTask(int ndx) {
    if(ndx < 0 || n < ndx) {
        return Task();
    }
    return tasks[n];
}

/*
 * setTask
 * class: Manager
 * parameters:
 *      t - The new task being taking the place of the previous task.
 *      ndx - The index of the task.
 */
void Manager::setTask(Task t, int ndx) {
    if(ndx < 0 || n < ndx) {
        // do nothing
        return;
    }
    tasks[ndx] = t;
}

/*
 * promote
 * class: Manager
 * paramaters:
 *      ndx: The ndx of the task being promoted in priority
 *      spot: the ndx of the spot it's being promoted it.
 * description: 
 */
void Manager::promote(int ndx, int number) {
    if(ndx < 0 || n < ndx || number < 1 || (ndx-number) < 0 ){
        // do nothing
        return;
    }
    Task temp = getTask(ndx-number);
    setTask(getTask(ndx),ndx-number);
    for(int i = ndx-number+1; i < ndx; ++i) {
        Task t = getTask(i);
        setTask(temp,i);
        temp = t;
    }

}

void Manager::demote(int ndx, int number) {
}
