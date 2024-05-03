#include <iostream>
#include "Problem.h"
#include <string>
#include <vector>

void inputPuzzle()
{
    std::cout << "Enter your puzzle, use a zero to represent the blank\n";
}

int main()
{
    //building a default puzzle
    //1 2 3
    //4 5 6
    //7 8 0
    std::vector<int>initialState = {{0,0,0,0,0,0,0,0}};
    std::vector<int>GoalState = {1,2,3,4,5,6,7,8,0}; 
    Operator up("Up", 2);
    Operator left("Left", 4);
    Operator right("Right", 6);
    Operator down("Down", 8);
    std::vector<Operator> operators = {up, down, left, right};
    
    int choice;
    std::cout << "Welcome to XXX (change this to your student ID) 8 puzzle solver.\n";
    std::cout << "Type '1' to use a default puzzle, or '2' to enter your own puzzle.\n";
    Problem puzzle(initialState, GoalState, operators);
    if (choice == 2) {
        //inputpuzzle to get userinput
    } else {
        
        // Set up a default puzzle
    }
    return 0;
}