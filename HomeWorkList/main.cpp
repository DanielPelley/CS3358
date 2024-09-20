#include <iostream>
#include "HomeWorkList.h"

int main() {

    HomeWorkList hwkList;

    hwkList.insertAssignment("Math hwk", 2024, 8, 4);
    hwkList.insertAssignment("Science hwk", 2024, 8, 5);
    hwkList.insertAssignment("More Science hwk", 2024, 8, 1);
    hwkList.insertAssignment("Biology hwk", 2024, 8, 9);
    hwkList.insertAssignment("English hwk", 2024, 8, 6);


    hwkList.displayEarliestAssignment();

    hwkList.displayCurrentAssignments();
    hwkList.removeAssignment("English hwk");
    hwkList.displayCurrentAssignments();

    return 0;
}
