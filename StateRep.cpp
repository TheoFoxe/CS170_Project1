#include "StateRep.h"

using namespace std;

// constructors ------------------

StateRep::StateRep(vector<vector<int>> state) {
    setState(state);
}

StateRep::StateRep(vector<vector<int>> state, double totalCost, double heuristicCost) {
    setState(state);
    this->totalCost = totalCost;
    this->heuristicCost = heuristicCost;
}

// state ----------------------

void StateRep::setState(const vector<vector<int>>& state) {
    this->state = state;
}

void StateRep::printState() const {
    for (unsigned int i = 0; i < puzzleDim; ++i) {
        for (unsigned int j = 0; j < puzzleDim; ++j) {
            cout << state[i][j] << " ";
        }
        cout << "\n";
    }
}

const vector<vector<int>>& StateRep::getState() const {
    return state;
}

// totalCost ------------------------

void StateRep::setTotalCost(double totalCost) {
    this->totalCost = totalCost;
}

double StateRep::getTotalCost() const {
    return this->totalCost; 
}

// heuristicCost -------------------------

void StateRep::setHeuristicCost(double heuristicCost) {
    this->heuristicCost = heuristicCost;
}

double StateRep::getHeuristicCost() const {
    return this->heuristicCost; 
}