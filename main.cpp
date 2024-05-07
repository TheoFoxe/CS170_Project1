#include <iostream>
#include <string>
#include <vector>

#include "Problem.h"
#include "AstarEuclideanSolver.h"
using namespace std;

void inputPuzzle(std::vector<std::vector<int>>& userDefinedPuzzle)
{
    std::string order_string[3] = {"first", "second", "third"};
    std::cout << "Enter your puzzle, use a zero to represent the blank\n";
    for (int i = 0; i < PUZZLE_SIZE; i++){//set up an user defined puzzle
        std::cout << "Enter the " << order_string[i] << " row, use space or tabs between numbers: ";
        for (int j = 0; j < PUZZLE_SIZE; j++)
        {
            std::cin >> userDefinedPuzzle[i][j];
        }
    }
    cout << endl;
}

int main()
{   
    std::vector<std::vector<int>> goalPuzzleContent = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    Problem goalPuzzle(goalPuzzleContent);

    std::vector<std::vector<int>> defaultPuzzleContent = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 0, 8}
    };

    std::vector<std::vector<int>> userDefinedPuzzleContent = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    Problem currentPuzzle;

    size_t PuzzleChoice;

    std::cout << "Welcome to XXX (change this to your student ID) 8 puzzle solver.\n";
    std::cout << "Type '1' to use a default puzzle, or '2' to enter your own puzzle.\n";
    std::cin >> PuzzleChoice;
    if(PuzzleChoice == 1){//display default puzzle
        currentPuzzle = Problem(defaultPuzzleContent);
    }
    else if (PuzzleChoice == 2) {//set up an user defined puzzle and display
        inputPuzzle(userDefinedPuzzleContent);
        currentPuzzle = Problem(userDefinedPuzzleContent);
    }
    else {
        cout << "Error choice" << endl;
        return 0;
    }
    cout << currentPuzzle << endl;

    int AlgorithmChoice;
    std::cout << "Enter your choice of algorithm (1/2/3)\n";
    std::cout << "1. Uniform Cost Search\n";
    std::cout << "2. A* with the Misplaced Tile heuristic.\n";
    std::cout << "3. A* with the Euclidean distance heuristic.\n";
    std::cin >> AlgorithmChoice;

    bool is_solved = false;
    // if(AlgorithmChoice == 1){
    //     std::cout << "executing Uniform Cost Search\n";
    //     UniformCostSolver solver(goalPuzzle);
    //     is_solved = solver.solvePuzzle(currentPuzzle);
    // }
    // else if(AlgorithmChoice == 2){
    //     std::cout << "executing A* with the Misplaced Tile heuristic\n";
    //     MisplacedTileSolver solver(goalPuzzle);
    //     is_solved = solver.solvePuzzle(currentPuzzle);
    // }
    // else if(AlgorithmChoice == 3){
    //     std::cout << "executing A* with the Euclidean distance heuristic\n";
    //     EuclideanDistanceSolver solver(goalPuzzle);
    //     is_solved = solver.solvePuzzle(currentPuzzle);
    // }
    if(AlgorithmChoice == 3){
        std::cout << "executing A* with the Euclidean distance heuristic\n";
        EuclideanDistanceSolver solver(goalPuzzle);
        is_solved = solver.solveProblem(currentPuzzle);
    }
    else{
        std::cout << "Invalid algorithm choice.\n";
        return 1;
    }

    if (is_solved) {
        cout << "To solve this problem the search algorithm expanded a total of " << XXX << " nodes." << endl;
        cout << "The maximum number of nodes in the queue at any one time: " << YYY << "." << endl;
        cout << "The depth of the goal node was  " << ZZZ << "." << endl;
    }
    else {
        cout << "The puzzle is impossible to solve" << endl;
    }

    return 0;
}