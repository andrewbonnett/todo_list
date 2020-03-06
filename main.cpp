/*
#include <iostream>
#include <string>
#include <vector>

#include "TodoList.h"

using namespace std;

int main(int argc, char *argv[]) {
    TodoList todo;  //calls the constructor.
                    //constructor instantiates vector of dueDates and Tasks
                    //print out each argument
                    //convert arguments to string and add to vector of string
    vector<string> arguments;
    for (int i = 0; i < argc; i++) {
        arguments.push_back(argv[i]);
    }
    
    if (argc == 1) {return 1;}
    
    //compares argument[1] to see if it is "add"
    if (arguments[1] == "add") {
        cout << "The add function has been called " << endl;
        todo.add(arguments[2], arguments[3]);   //void add(string _duedate, string _task); (RUNTIME ERR Segmentation Fault)
    }
    
    //compares argument[1] to see if it is "remove"
    else if (arguments[1] == "remove") {
        cout << "The remove function has been called " << endl;
        int removeSuccessful;                           //function Returns 1 if it removes an item, 0 otherwise
        cout << "arguements[2] " << arguments[2] << endl;
        removeSuccessful = todo.remove(arguments[2]);  //int remove(string _task);
        if (removeSuccessful == 1) {
            cout << "The task " << arguments[2] << " has been succesfully removed." << endl;
        }
        else {
            cout << "The task " << arguments[2] << " was NOT succesfully removed." << endl;
        }
    }
    
    //compares argument[1] to see if it is "printList"
    else if (arguments[1] == "printList") {
        cout << "The printList function has been called " << endl;
        todo.printTodoList();
    }
    
    //compares argument[1] to see if it is "printDay"
    else if (arguments[1] == "printDay") {
        cout << "The printDay function has been called for " << arguments[2] << endl;
        todo.printDaysTasks(arguments[2]);            //void printDaysTasks(string _date);
    }
    
    return 0;
}
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "TodoList.h"
using namespace std;


int main(int argc, char *argv[]){
    TodoList todo;
    
    
    if(argc > 0){
        string command = argv[1];
        if(command == "add"){
            string duedate = argv[2];
            string task = argv[3];
            todo.add(duedate, task);
        }    
        else if(command == "remove"){
            string task = argv[2];
            todo.remove(task);
        }
        
        else if(command == "printDay"){
            string duedate = argv[2];
            todo.printDaysTasks(duedate);
        }
        
        else if(command == "printList"){
            todo.printTodoList();
        }
            
            }
            
            
        
   }