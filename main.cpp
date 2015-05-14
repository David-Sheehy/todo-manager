#include <fstream>
#include <iostream>
#include <string>
#include "manager.h"
#include "task.h"

using namespace std;

int main(int argc, char** argv) {
    bool customFile = false;;
    string customFileName = "";

    Manager m;
    // handle the arguments
    Task temp("Finish this project.");
    
    //cout << "ADDING TASK" << endl;
    m.addTask(temp);

}
