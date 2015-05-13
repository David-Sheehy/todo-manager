#ifndef MANAGER_H
#define MANAGER_H
#include "task"

class Manager {
    private:
        int l;
        int n;
        Task* tasks;

        void grow();
    public:

        ~Manager() {
            delete [] tasks;
        }

        Manager() {
            l = 8;
            n = 0;
            tasks = new Task[l];
        }

        void addTask(Task t);

        Task getTask(int n);
        void removeTask(int n);
};
#endif
