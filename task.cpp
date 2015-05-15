#include <string>
#include <sstream>
#include "task.h"

const int LINE_SIZE = 256;
//TODO finsih commenting


/**
 * Task
 * class: Task
 * description: The copy constructor.
 * Parameters:
 *      o
 */
Task::Task(const Task& o) {
    this->title = o.title;
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
        this->title = o.title;
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
 * return: whether the item was removed.
 */
bool Task::removeItem(int priority) {
    bool result = true;
    if( n <= priority || priority < 0) {
        // do nothing
        return result;
    }

    for(int i = priority; i < n-1; ++i) {
        this->items[i] = this->items[i+1];
    }
    n--;
    return result;
};


/*
 * setIteem
 * class: Task
 * description: Modifies a given subtask.
 * Parameters:
 *      sb - The new contents for a subtask.
 *      n - The index of the subtask being modified.
 * return: Whether the item was modified.
 */
bool Task::setItem(int ndx, std::string sb) {
    if( n <= ndx || ndx < 0) {
        // do nothing
        return false;
    }
    this->items[ndx] = sb;
    return true;
};

std::string Task::getItem(int ndx) const {
    if(n <= ndx || ndx < 0) {
        return "";
    }
    return this->items[ndx];
};

/*
 * operator<<
 * class: Friend to Task
 * description: Prints a human readable representation of the  task to an
 *              output stream.
 * parameters:
 *      os - The output stream
 *      t - The task being printed.
 * return: A reference to the output stream to allow for chaining.
 */
std::ostream& operator<<(std::ostream &os, const Task& t) {
    os << t.getTitle() << std::endl;
    for(int i = 0; i < t.getNumberOfItems(); ++i) {
        os << "\t" << i << " - " << t.getItem(i) << std::endl;
    }
    return os;
}

/*
 * write
 * class: Task
 * description: Prints out a comma seperated representation of this task.
 *              Commas in the title or in the task are escape charactered out.
 * parameters:
 *      os - The output stream being written to.
 * return: none
 */
void Task::write(std::ostream &os) const {
    os << this->getNumberOfItems()+1 << std::endl;
    os << this->getTitle() << std::endl;
    for(int i = 0; i < this->getNumberOfItems(); ++i) {
        os << this->items[i] << std::endl;
    }
}

/*
 * read
 * class: Task
 * description: Reads in a task from the form of a comma seperated list.
 * parameters:
 *      is - The input stream being read from.
 * return: none.
 */
void Task::read(std::istream &is) {
    int number = -1;
    char line[LINE_SIZE];
    is >> number;
    is.get();
    is.getline(line,LINE_SIZE);
    this->setTitle(line);
    for(int i = 1; i < number; ++i) {
        is.getline(line,LINE_SIZE);
        this->addItem(line);
    }
}
