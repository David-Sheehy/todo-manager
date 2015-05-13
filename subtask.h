#ifndef SUBTASK_H
#define SUBTASK_H

#include <string>
#include <ostream>

class Subtask {
    private:
        std::string msg;
        int priority;
    public:

        // Default constructor
        Subtask() {
            this->msg = "";
            this->startTime = -1;
            this->stopTime = -1;
            this->priority = -1;
        }

        Subtask(std::string msg, int priority) {
            this->msg = msg;
            this->priority = priority;
        }

        std::string getMessage() {
            return msg;
        }

        void setMessage(std::string msg) {
            this->msg = msg;
        }

        int getPriority() {
            return priority;
        }

        void setPriority(int priority) {
            this->priority = priority;
        }

        bool operator<(const Subtask&);
};

#endif
