#ifndef TASK_H
#define TASK_H

#include "subtask.h"
#include <string>

class Task {
    private:
        std::string title;
        Subtask* items;
        int priority;
        int n;
        int len;

        void expand(); 
    public:

        ~Task() {
            delete [] items;
        }

        Task() {
            title = "";
            items = NULL;
            priority = -1;
            n = 0;
            l = 0;
        }

        Task(std::string title, int priority) {
            this->title = title;
            this->priority = priority;
            n = 0;
            l = 8;
            items = new Subtask[l];
        }
        
        void addSubtask(Subtask sb, int priority = 0);
        void removeSubtask(int priority = 0);


        void setSubtask(Subtask sb, int n);
        Subtask getSubtask(int n);
};
#endif
