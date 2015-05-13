#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
    private:
        std::string title;
        std::string* items;
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
        
        void addItem(std::string sb, int priority = 0);
        void removeItem(int priority = 0);


        void setItem(std::string sb, int n);
        std::string getItem(int n);
};
#endif
