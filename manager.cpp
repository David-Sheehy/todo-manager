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
 * return: A copy of the task held at ndx or an empty task if that task does
 *         not exist.
 */
Task Manager::getTask(int ndx) {
    if(ndx < 0 || n < ndx) {
        return Task();
    }
    return tasks[ndx];
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
 * description: Moves a task up the list.
 * paramaters:
 *      ndx: The ndx of the task being promoted in priority
 *      number: Number of spots it's being moved up.
 * return: None.
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

/*
 * demote
 * class: Manager
 * description: Move a task a number of spots down the list.
 * parameters:
 *      ndx: The index of the task being demoted.
 *      number: The number of spots it's moving down.
 * return: None.
 */
void Manager::demote(int ndx, int number) {
    // needs to be implemented :c
   if(ndx < 0 || n < ndx || number < 1 || n < (number +ndx)) {
       // do nothing
       return;
   }
   Task temp = getTask(ndx+number);
   setTask(getTask(ndx),ndx+number);
   for(int i = ndx+number-1; ndx <= i; --i) {
       Task t = getTask(i);
       setTask(temp,i);
       temp = t;
   }
}


/*
 * removeItem
 * class: Manager
 * description: Removes a given item from a given task. The items in the task
 *              below it are promoted. This will fail if the manager does not
 *              contain a given task, or if that task does not contain a given
 *              item.
 * paramaters:
 *          task: The index of the task being removed.
 *          item: The index of the item being removed.
 * return: whether the removal was successful.
 */
bool Manager::removeItem(int task, int item) {
    bool result = true;;
    if(task < this->getNumberOfTasks()) {
        result = this->tasks[task].removeItem(item);
    }
    else {
        result = false;
    }
    return result;
}
