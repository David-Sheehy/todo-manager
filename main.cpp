#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include "manager.h"
#include "task.h"

using namespace std;
enum command {ADD,AMEND,DEMOTE,HELP,LIST,PROMOTE,REMOVE,SWAP};
void displayHelp(ostream& os);
bool isNumeric(const char*);

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
    int comInd = -1;                // The index of the command in argv
    int lc = -1;                    // number of arguments for a command
    int x = -1, y = -1;             // Hold argument values.
    ifstream fin;                   // The input filestream
    ofstream fout;                  // The output filestream.

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
            comInd = i;
            lc = (argc - comInd - 1);
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

    fin.open(filename.c_str());
    m.read(fin);
    fin.close();

    // read in the file.
    // do the command
    switch(command) {
        case ADD:
            if(0 < lc) {
                Task t;
                t.setTitle(argv[comInd+1]);
                for(int i = comInd+2; i < argc; ++i) {
                    t.addItem(argv[i]);
                }
                m.addTask(t);
                fout.open(filename.c_str());
                m.write(fout);
                fout.close();
            }
            else {
                cout << "Invalid number of arguments." << endl;
                exit(1);
            }
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
            // there are several options for this.
            // If there is no arguments past the command, it will list
            // everything. If there is one it will only list that one. If there
            // are two it will list an inclusive range.
            switch(lc) {
                case 0:
                    cout << m;
                    break;
                case 1:
                    if(isNumeric(argv[comInd+1])) {
                        x = atoi(argv[comInd+1]);
                        if(0 <= x && x < m.getNumberOfTasks()) {
                            cout << "(" << x << ")" << m.getTask(x) << endl;
                        }
                        else {
                            cout << "Error. Task does not exist." << endl;
                            exit(1);
                        }
                    }
                    else {
                        cout << "Non numeric argument given for list." << endl;
                        exit(1);
                    }
                    break;
                case 2:
                    if(isNumeric(argv[comInd+1]) && isNumeric(argv[comInd+2])){
                        x = atoi(argv[comInd+1]);
                        y = atoi(argv[comInd+2]);
                        if(0 <= x && x < y) {
                        for(int i = x; i <= y && i < m.getNumberOfTasks(); ++i) {
                            cout << "(" << i << ")" << m.getTask(i) << endl;
                        }
                        }
                    }
                    else {
                        cout << "Non numeric argument given for list." << endl;
                        exit(1);
                    }
                    break;
                default:
                    displayHelp(cout);
                    exit(1);
                    break;
            }
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
 * isNumeric
 * class: None
 * description: Check if a given cstring contains only numeric characters.
 * parameters:
 *      s - The cstring being checked.
 * return: Whether a cstring contains only numeric decimal characters.
 */
bool isNumeric(const char *s) {
    int n = strlen(s);
    for(int i = 0; i < n; ++i) {
        if(s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
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
    os << "    add   [ <task. [<items>]]" << endl;
    os << "    amend [n <command> [<args>]]" << endl; 
    os << "    demote [n count]       Demotes the nth task count times." << endl;
    os << "    help                   Display this message." << endl;
    os << "    list [][n][n]          List all the tasks and their items, or  " << endl;
    os << "                           a task or display a range of tasks." << endl;
    os << "    promote [n count]      Promotes the nth task count times." << endl;
    os << "    remove [n]             Removes task n from the list."<< endl;
    os << "    swap [n m]             swaps the priority of task n and task m." << endl;
    os << "" << endl;
    os << "type todo-manager help <command> for more infromation on that command. " << endl;
}
