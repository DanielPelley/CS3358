//
// Created by danie on 9/19/2024.
//
#ifndef DATASTRUCTANDALGASSIGNMENT1_HOMEWORKLIST_H
#define DATASTRUCTANDALGASSIGNMENT1_HOMEWORKLIST_H
using namespace std;


struct Node {
    string homeworkName;
    int dueDate;
    Node *next = nullptr;

    Node(string hwkName, int date);


};


class HomeWorkList {
private:
    Node* head;

public:
    HomeWorkList();

    void insertAssignment(string assignmentName, int year, int month, int day);
    void removeAssignment(string nameOfHomeworkToDelete);
    void displayCurrentAssignments();
         ~HomeWorkList();

    int dateToInt(int year, int month, int day);

    void displayEarliestAssignment();

    void displayAssignment(const Node *assignment) const;
};



#endif