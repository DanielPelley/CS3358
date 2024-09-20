#include <iostream>
#include "HomeWorkList.h"

using namespace std;

Node::Node(string hwkName, int date) {
    homeworkName = hwkName;
    dueDate = date;
}

HomeWorkList::HomeWorkList() {
    head = nullptr;
}

void HomeWorkList::insertAssignment(string assignmentName, int year, int month, int day) {
    int dueDate = dateToInt(year, month, day);
    Node* newHwk = new Node(assignmentName, dueDate);
    //Checks to see if head is empty and replaces it, and if not - then it traverses
    if(head == nullptr || newHwk->dueDate < head->dueDate){
        newHwk->next = head;
        head = newHwk;
    }else{
        Node* traverse = head;
        while(traverse->next != nullptr && traverse->next->dueDate < newHwk->dueDate){
            traverse = traverse->next;
        }

        newHwk->next = traverse->next;
        traverse->next = newHwk;

    }
}
    // removes assignments
void HomeWorkList::removeAssignment(string nameOfHomeworkToDelete) {
    if (head == nullptr) {
        cout << "No Assignments \n";
        return;
    }

    // If the head node needs to be deleted
    if (head->homeworkName == nameOfHomeworkToDelete) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Assignment '" << nameOfHomeworkToDelete << "' deleted." << endl << endl;
        return;
    }

    // Finds the assignment that needs to be deleted
    Node* traverse = head;
    while (traverse->next != nullptr && traverse->next->homeworkName != nameOfHomeworkToDelete) {
        traverse = traverse->next;
    }

    // then deletes
    if (traverse->next != nullptr) {
        Node* temp = traverse->next;
        traverse->next = traverse->next->next;
        delete temp;
        cout << "Assignment '" << nameOfHomeworkToDelete << "' deleted.\n";
    } else {
        cout << "Assignment isn't in the list.\n";
    }
}

void HomeWorkList::displayCurrentAssignments() {
    if (head == nullptr) {
        cout << "None in the list yet." << endl << endl;
        return;
    }
    //converts back to readable english
    Node* temp = head;
    cout << "My current assignments:\n";
    while (temp != nullptr) {
        displayAssignment(temp);
        temp = temp->next;
    }

    cout << endl << endl;
}

void HomeWorkList::displayAssignment(const Node *assignment) const {
    int year = assignment->dueDate / 10000;
    int month = (assignment->dueDate / 100) % 100;
    int day = assignment->dueDate % 100;
    cout << "Assignment: " << assignment->homeworkName << ", Due Date: " << year << "-" << month << "-" << day << "\n";
}

HomeWorkList::~HomeWorkList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}
// converts to storable data
int HomeWorkList::dateToInt(int year, int month, int day){
    return 10000 * year + 100 * month + day;
}

void HomeWorkList::displayEarliestAssignment() {

    cout << "Earliest Due:" << endl;

    if (head == nullptr){
        cout << "No Assignments!" << endl << endl;
        return;
    }
    displayAssignment(head);
    cout << endl << endl;
}

