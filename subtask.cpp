#include "task.h"

/*
 * operator<
 * class: Task
 * description:
 *      Determine whether this Task is considered to be of lower value
 *      (priority) than another task. A task is considered lower if the
 *      priority is lower, or if the the priorities are equal than the stopTime
 *      is lower.
 * parameters:
 *          o - The Task that this is being compared to.
 * return: Whether this task has a higher priority than another task.
 */
bool Task::operator<(const Task& o) {
    return this->priority < o.priority;
}

