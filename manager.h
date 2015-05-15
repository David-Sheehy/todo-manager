#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include "task.h"
#include <iostream>

class Manager {
    private:
        int l;
        int n;

        std::string filename;
        Task* tasks;

        void expand();
    public:

        ~Manager() {
            delete  [] tasks;
            tasks = NULL;
        }

        Manager() {
            l = 8;
            n = 0;
            tasks = new Task[l];
        }

        int getNumberOfTasks() const {
            return this->n;
        }

        // Task potioning.
        void addTask(Task t);
        Task getTask(int ndx) const;
        void setTask(Task t, int ndx);
        void swapTasks(int ndx1, int ndx2);
        void removeTask(int ndx);

        void promote(int ndx, int number=1);
        void demote(int ndx, int number=1);

        // arbitrary task modifying functions
        // These  modify a specified task stored by the manager.
        bool removeItem(int task, int item);
        bool setItem(int task, int item, std::string s);
        bool addItem(int task, std::string item);


        friend std::ostream& operator<<(std::ostream&, const Manager&);
        friend std::istream& operator<<(std::istream&, Manager&);
};
#endif
