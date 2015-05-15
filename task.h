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

        int getNumberOfItems() const{
            return n;
        }

        void addItem(std::string sb);
        bool removeItem(int priority = 0);

        bool setItem(int n, std::string sb);
        std::string getItem(int n) const;

        void setTitle(std::string s) {
            this->title = s;
        }

        std::string getTitle() const {
            return title;
        }

        friend std::ostream& operator<<(std::ostream&, const Task&);
        friend std::istream& operator>>(std::istream&, Task&);
};
#endif
