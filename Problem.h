#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include <string>
#include <algorithm>

class Problem {
private:
    std::vector<std::vector<int>> initialState;
    std::vector<std::vector<int>> goalState;
    std::vector<std::string> operators;
    std::pair<int, int> getBlankPos(std::vector<std::vector<int>>& state);
    std::pair<int, int> getNewPos(std::string opName, std::pair<int, int> blankPos);

public:
    Problem(std::vector<std::vector<int>>& init, std::vector<std::vector<int>>&goal, std::vector<std::string> ops);
    std::vector<std::vector<int>> getInitalState();
    std::vector<std::vector<int>> getGoalState();
    std::vector<std::string> getOperators();
    std::vector<std::vector<int>> applyOperation(std::vector<std::vector<int>>& state, std::string opName);
};
#endif