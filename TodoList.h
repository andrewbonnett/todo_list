#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <fstream>
#include <vector>
#include "TodoListInterface.h" 

using namespace std;

class TodoList : public TodoListInterface {

private:
    vector<string> dueDates;
    vector<string> tasks;
    int numItems;

public:
    TodoList();
    ~TodoList();
        
    void add(string _duedate, string _task);
    
    int remove(string _task);
    
    void printTodoList();
    
    void printDaysTasks(string _date);

};
#endif