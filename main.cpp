#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "manager.h"
#include "task.h"

using namespace std;
enum command {ADD,AMEND,DEMOTE,HELP,LIST,PROMOTE,REMOVE,SWAP};
void displayHelp(ostream& os);

/*
 * main
 * class: None
 */
int main(int argc, char **argv) {
    Manager m;
    string filename = "~/todo.txt"; // default file
    bool invalidArgs = argc < 2;
    bool parsing = true;
    int command = -1;               // The switch code for command

    // scan the command line arguments
    for(int i = 1; i < argc && !invalidArgs && parsing; ++i) {
        string s = argv[i];
        // determine what type of argument it is
        if(s[0] == '-') {
            // option
            // check if it has the necessary arguments given
            // set the associated flags
            if(s.compare("-f") == 0 || s.compare("--file") == 0) {
                // check if there is another argument, which should be the file
                // name.
                if(1 < (argc-i)) {
                    filename = argv[i+1];
                    i++;
                }
                else {
                    invalidArgs = true;
                }
            }
            else {
                // There are no other options I recognize at the moment.
                invalidArgs = true;
            }
        }
        else {
            // it's a command
            parsing = false;
            if(s.compare("add") == 0) {
                command = ADD;
            }
            else if(s.compare("amend") == 0) {
                command = AMEND;
            }
            else if(s.compare("demote") == 0) {
                command = DEMOTE;
            }
            else if(s.compare("help") == 0) {
                command = HELP;
            }
            else if(s.compare("list") == 0) {
                command = LIST;
            }
            else if(s.compare("promote") == 0) {
                command = PROMOTE;
            }
            else if(s.compare("remove") == 0) {
                command = REMOVE;
            }
            else if(s.compare("swap") == 0) {
                command = SWAP;
            }
            else {
                invalidArgs = true;
            }
        }
        
    }

    if(invalidArgs) {
        displayHelp(cout);
        exit(1);
    }

    // read in the file.
    ifstream infile(filename);
    // do the command
    switch(command) {
        case ADD:
            cout << "add task" << endl;
            break;
        case AMEND:
            cout << "amend" << endl;
            break;
        case DEMOTE:
            cout << "demote" << endl;
            break;
        case HELP:
            cout << "help" << endl;
            break;
        case LIST:
            cout << "list" << endl;
            break;
        case PROMOTE:
            cout << "promote" << endl;
            break;
        case REMOVE:
            cout << "remove" << endl;
            break;
        case SWAP:
            cout << "Swap" << endl;
            break;
        default:
            displayHelp(cout);
            exit(1);
            break;
    }
    
    return 0;
}

/*
 * displayHelp
 * class: None
 * description: Display a brief message detailing the commands and how to use
 *              them. The output stream is modified.
 * parameters:
 *      os - The output stream being displayed to.
 * return: None.
 */
void displayHelp(ostream & os) {
    os << "usage: todo-manager [-f <filename>] [<command> [<args>]]" << endl;
    os << "The commands are: " << endl;
    os << "    amend [n <command> [<args>]]" << endl; 
    os << "    demote [n count]       Demotes the nth task count times." << endl;
    os << "    help                   Display this message." << endl;
    os << "    list [n][n m]          List all the tasks and their item, or  " << endl;
    os << "                           a task or display a range of tasks." << endl;
    os << "    promote [n count]      Promotes the nth task count times." << endl;
    os << "    remove [n]             Removes task n from the list."<< endl;
    os << "    swap [n m]             swaps the priority of task n and task m." << endl;
    os << "" << endl;
    os << "type todo-manager help <command> for more infromation on that command. " << endl;
}
