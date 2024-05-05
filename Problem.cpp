#include "Problem.h"

Problem::Problem(std::vector<std::vector<int>>& init, std::vector<std::vector<int>>&goal, std::vector<std::string> ops) {
    this->initialState = init;
    this->goalState = goal;
    this->operators = ops;
}

std::vector<std::vector<int>> Problem::getInitalState() {
    return initialState;
}

std::vector<std::vector<int>> Problem::getGoalState() {
    return goalState;
}

std::vector<std::string> Problem::getOperators() {
    return operators;
}

// Returns the position of the blank tile in 2d array as a tuple
std::pair<int, int> Problem::getBlankPos(std::vector<std::vector<int>>& state) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (state[i][j] == 0) {
                return {i,j};
            }
        }
    }
    return {-1, -1}; 
}

// Returns new position of the blank tile in 2d array
std::pair<int, int> Problem::getNewPos(std::string opName, std::pair<int, int> blankPos) {
    int row = blankPos.first;
    int col = blankPos.second;

    if (opName == "up") {
    } else if (opName == "down") {
        return {row + 1, col};
    } else if (opName == "left") {
        return {row, col - 1};
    } else if (opName == "right") {
        return {row, col + 1};
    }
    return {-1, -1}; 
}

std::vector<std::vector<int>> Problem::applyOperation(std::vector<std::vector<int>>& state, std::string opName) {
    std::pair<int, int> blankPos = getBlankPos(state);
    std::pair<int, int> newPos = getNewPos(opName, blankPos);

    //check for illegal moves
    if (newPos.first < 0 || newPos.first >= 3 || newPos.second < 0 || newPos.second >= 3) {
            return state;
    }

    //swap blank tile with moved tile
    std::vector<std::vector<int>> newState = state;
    std::swap(newState[blankPos.first][blankPos.second], newState[newPos.first][newPos.second]);

    return newState;
}