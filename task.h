#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>

class Task {
    private:
        std::string title;
        std::string* items;
        int n;
        int len;

        void expand(); 
    public:

        ~Task() {
            std::cout << "KILL TASK " << std::endl;
            delete [] items;
        }

        Task() {
            title = "";
            n = 0;
            len = 8;
            items = new std::string[len];
        };

        Task(std::string title) {
            this->title = title;
            n = 0;
            len = 8;
            items = new std::string[len];
        };

        /**
         * Task
         * class: Task
         * description: The copy constructor.
         * Parameters:
         *      o
         */
        Task(const Task& o);
        
        /**
         * operator=
         * class; Task
         * description: Create a deep copy of another task object.
         */
        Task& operator=(const Task& o);

        void addItem(std::string sb);
        void removeItem(int priority = 0);


        void setItem(std::string sb, int n);
        std::string getItem(int n);

        void setTitle(std::string s) {
            this->title = s;
        }

        std::string getTitle() {
            return title;
        }

};
#endif
