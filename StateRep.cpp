#include "StateRep.h"

using namespace std;

// constructors ------------------

StateRep::StateRep() {
    this->state = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    this->totalCost = 0;
    this->heuristicCost = 0;
}

StateRep::StateRep(vector<vector<int>> state) {
    this->state = state;
    this->totalCost = 0;
    this->heuristicCost = 0;
}

StateRep::StateRep(vector<vector<int>> state, double totalCost, double heuristicCost) {
    this->state = state;
    this->totalCost = totalCost;
    this->heuristicCost = heuristicCost;
}

// state ----------------------

void StateRep::setState(vector<vector<int>>) {
    this->state = state;
}

const vector<vector<int>> & StateRep::getState() const {
    return this->state;
}

void StateRep::printState() const {
    for (unsigned int i = 0; i < state.size(); ++i) {
        for (unsigned int j = 0; j < state[i].size(); ++j) {
            cout << state[i][j] << " ";
        }
        cout << endl;
    }
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