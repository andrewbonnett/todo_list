#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include "TodoList.h"

using namespace std;

TodoList::TodoList() {
    
    vector <string> dueDates;
    ifstream editFile;
    editFile.open("TodoList.txt");
    numItems = 0;
    
    while(!editFile.eof()) {
        string temp;
        getline(editFile, temp);
        //cout << "The io file is being looked through " << endl;
        //cout << temp << endl;
        //cout << temp.length() << endl;
        
        if (temp.length() > 0) {
            stringstream ss(temp);      //declare a stringstream holding the entire line
            string dueDate;             
            string taskparse;           
            string fulltask;
            
            ss >> dueDate;//read the first word in the stringstream to DueDate
            //cout << "This is the dueDate in the file: " << dueDate << endl;
            dueDates.push_back(dueDate); //add the first word in the stringstream to the vector of duedates
            
            while(ss >> taskparse) {
                fulltask.append(taskparse);
                fulltask.append(" ");
            }
            //cout << "This is the task in the file: " << fulltask << endl;
            tasks.push_back(fulltask);
            numItems++;
        }
        
    }
    //cout << "numItems = " << numItems << endl;
    
    editFile.close();
}

TodoList::~TodoList() {
    //destructor **save to TodoList.txt**
    //open the file for writing
    //write out the class variables to the file
    //close the file
    ofstream editFile;
    editFile.open("TodoList.txt");
    string combine;
    //cout << "numItems = " << numItems << endl;
    //cout << dueDates[1] << endl;
    //cout << dueDates.size() << endl;
    for (int i = 0; i < dueDates.size(); i++) {
        if (!dueDates[i].empty()) {
            combine = dueDates[i] + " " + tasks[i];
            editFile << combine << endl; //**DESTRUCTOR NOT ACCESSING CLASS VARIABLE dueDates or tasks
        //cout << "."; //this line is not printing;
        }
    }
    editFile.close();
    
    //cout << "The destructor has been called" << endl;

}

void TodoList::add(string _duedate, string _task) {
    dueDates.push_back(_duedate);
    tasks.push_back(_task);
    //for (int i = 0; i < numItems; i++) {
        //cout << "Item " << i << ": " << dueDates[i] << " " << tasks[i] << endl;
        
    //}
}
    
int TodoList::remove(string _task) {
    //Returns 1 if it removes an item, 0 otherwise
    int r = 0;
    _task.append(" ");
    for (int i = 0; i < dueDates.size(); i++) {
        cout << _task << "." << endl;
        cout << tasks[i] << "." << endl;
        if (_task == tasks[i]) {
            dueDates[i].erase();
            tasks[i].erase();
            r = 1;
        }
        if (r == 1) {
            if (i != dueDates.size()-1) {
                dueDates[i] = dueDates[i+1];
                tasks[i] = tasks[i+1];
            }
            if (i == dueDates.size()-1) {
                dueDates[i].erase();
                tasks[i].erase();   
            }
        }
    }
    return r;
}
    
void TodoList::printTodoList() {
    cout << "Number of items: " << dueDates.size() << endl;
    for (int i = 0; i < dueDates.size(); i++) {
        if (!dueDates[i].empty()) {cout << "Item " << i << ": " << dueDates[i] << " " << tasks[i] << endl;}
    }
}
    
void TodoList::printDaysTasks(string _date) {
    for (int i = 0; i < numItems; i++) {
        if (_date == dueDates[i]) {
        cout << "Item " << i << ": " << dueDates[i] << " " << tasks[i] << endl;
        }
    }
    
}