#include "StateRep.h"

using namespace std;

// constructors ------------------

StateRep::StateRep(int state[puzzleDim][puzzleDim]) {
    setState(state);
}

StateRep::StateRep(int state[puzzleDim][puzzleDim], double totalCost, double heuristicCost) {
    setState(state);
    this->totalCost = totalCost;
    this->heuristicCost = heuristicCost;
}

// state ----------------------

void StateRep::setState(int state[puzzleDim][puzzleDim]) {
    for (unsigned int i = 0; i < 3; ++i) {
        for (unsigned int j = 0; j < 3; ++j) {
            this->state[i][j] = state[i][j];
        }
    }
}

void StateRep::printState() const {
    for (unsigned int i = 0; i < puzzleDim; ++i) {
        for (unsigned int j = 0; j < puzzleDim; ++j) {
            cout << state[i][j] << " ";
        }
        cout << "\n";
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