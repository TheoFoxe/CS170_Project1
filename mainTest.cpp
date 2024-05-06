#include <iostream>

#include "StateRep.h"

#include <string>
#include <vector>
#include "MisplacedTest.cpp"
using namespace std;
void displayPuzzle(std::vector<std::vector<int>>& Puzzle)
{
    std::cout << "This is your current pazzle\n";
    for (size_t i = 0; i < 3; i++){//display current puzzle;
        std::cout << "\n";
        for (size_t j = 0; j < 3; j++)
        {
            std::cout << Puzzle[i][j];
        }
    }
}

void inputPuzzle(std::vector<std::vector<int>>& userDefinedPuzzle)
{
    std::string order_string[3] = {"first", "second", "third"};
    std::cout << "Enter your puzzle, use a zero to represent the blank\n";
    for (size_t i = 0; i < 3; i++){//set up an user defined puzzle
        std::cout << "Enter the " << order_string[i] << " row, use space or tabs between numbers: ";
        for (size_t j = 0; j < 3; j++)
        {
            std::cin >> userDefinedPuzzle[i][j];
        }
    }
}

int main()
{   
    std::vector<std::string> operators = {"up", "down", "left", "right"};
    std::vector<std::vector<int>> goalPuzzle = {//index 0 in puzzles
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };    
    std::vector<std::vector<int>> defaultPuzzle = {//index 1 in puzzles
        {1, 2, 3},
        {4, 5, 6},
        {7, 0, 8}
    };
    std::vector<std::vector<int>> userDefinedPuzzle = {//index 2 in puzzles
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    size_t PuzzleChoice;
    std::vector<std::vector<std::vector<int>>> puzzles;//Define a vector of 2D vector puzzles  
    puzzles.push_back(goalPuzzle);
    puzzles.push_back(defaultPuzzle);
    puzzles.push_back(userDefinedPuzzle);
    std::cout << "Welcome to XXX (change this to your student ID) 8 puzzle solver."<<endl;
    std::cout << "Type '1' to use a default puzzle, or '2' to enter your own puzzle."<<endl;
    std::cin >> PuzzleChoice;
    if(PuzzleChoice == 1){//display default puzzle
        displayPuzzle(defaultPuzzle);
    }
    else if(PuzzleChoice == 2) {//set up an user defined puzzle and display
        inputPuzzle(userDefinedPuzzle);
        displayPuzzle(userDefinedPuzzle);
    } ;

  

    int AlgorithmChoice;
    std::cout << "Enter your choice of algorithm (1/2/3)\n";
    std::cout << "1. Uniform Cost Search\n";
    std::cout << "2. A* with the Misplaced Tile heuristic.\n";
    std::cout << "3. A* with the Euclidean distance heuristic.\n";
    std::cin >> AlgorithmChoice;

   
    std::vector<StateRep> solutionPath;
    
    if(AlgorithmChoice == 2){
        std::cout << "executing A* with the Misplaced Tile heuristic\n";
        aStarSearch(puzzles[PuzzleChoice], puzzles[0]);

    };
    return 0;
}
    