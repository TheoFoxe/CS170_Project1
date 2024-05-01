#include "Problem.h"

Problem::Problem(std::vector<int>& init, std::vector<int>&goal, std::vector<Operator> ops) {
    initialState = init;
    goalState = goal;
    operators = ops;
}

std::vector<int> Problem::getInitalState() {
    return initialState;
}

std::vector<int> Problem::getGoalState() {
    return goalState;
}

std::vector<Operator> Problem::getOperators() {
    return operators;
}