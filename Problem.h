#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include <string>

struct Operator {
    std::string name;
    int changePos; // Index that represents where tile moves to in a 1D vector.

    Operator(std::string& name, int index) {
        name = name;
        changePos = index;
    }
};

class Problem {
private:
    std::vector<int> initialState;
    std::vector<int> goalState;
    std::vector<Operator> operators;

public:
    Problem(std::vector<int>& init, std::vector<int>&goal, std::vector<Operator> ops);
    std::vector<int> getInitalState();
    std::vector<int> getGoalState();
    std::vector<Operator> getOperators();
};
#endif