#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include "task.h"

class Manager {
    private:
        int l;
        int n;

        std::string filename;
        Task* tasks;

        void expand();
    public:

        ~Manager() {
            delete [] tasks;
        }

        Manager() {
            l = 8;
            n = 0;
            tasks = new Task[l];
        }

        int getNumberOfTasks() {
            return this->n;
        }

        void addTask(Task t);
        Task getTask(int ndx);
        void setTask(Task t, int ndx);
        void removeTask(int ndx);

        void promote(int ndx, int number=1);
        void demote(int ndx, int number=1);
};
#endif
