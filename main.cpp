#include <iostream>
#include "Problem.h"
#include "StateRep.h"
#include <string>
#include <vector>

void inputPuzzle(std::vector<std::vector<int>> userDefinedPuzzle)
{
    std::string order_string[3] = {"first", "second", "third"};
    std::cout << "Enter your puzzle, use a zero to represent the blank\n";
    for (int i = 0; i < 3; i++){//set up an user defined puzzle
        std::cout << "Enter the " << order_string[i] << " row, use space or tabs between numbers: ";
        for (int j = 0; j < 3; j++)
        {
            std::cin >> userDefinedPuzzle[i][j];
        }
    }
}

int main()
{   
    Operator up("Up", -3);
    Operator left("Left", -1);
    Operator right("Right", 1);
    Operator down("Down", 3);
    std::vector<Operator> operators = {up, down, left, right};
    std::vector<std::vector<int>> userDefinedPuzzle;
    std::vector<std::vector<int>> defaultPuzzle = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    int PuzzleChoice;
    std::cout << "Welcome to XXX (change this to your student ID) 8 puzzle solver.\n";
    std::cout << "Type '1' to use a default puzzle, or '2' to enter your own puzzle.\n";
    if (PuzzleChoice == 2) {//set up an user defined puzzle
        inputPuzzle(userDefinedPuzzle);
    } 

    int AlgorithmChoice;
    std::cout << "Enter your choice of algorithm (1/2/3)\n";
    std::cout << "1. Uniform Cost Search\n";
    std::cout << "2. A* with the Misplaced Tile heuristic.\n";
    std::cout << "3. A* with the Euclidean distance heuristic.\n";
    std::cin >> AlgorithmChoice;

    if(AlgorithmChoice == 1){
        std::cout << "executing Uniform Cost Search\n";
    }
    else if(AlgorithmChoice == 2){
        std::cout << "executing A* with the Misplaced Tile heuristic\n";
    }
    else if(AlgorithmChoice == 3){
        std::cout << "executing A* with the Euclidean distance heuristic\n";
    }
    else{
        std::cout << "Invalid algorithm choice.\n";
        return 1;
    }

    return 0;
}
