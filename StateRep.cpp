#include "Node.h"

using namespace std;

// constructors ------------------

StateRep::StateRep() {
    this->state = { {1, 2, 3},
                    {4, 5, 6}, 
                    {7, 8, 0} };
    this->totalCost = 0;
    this->heuristicCost = 0;
}

StateRep::StateRep(int state[][], double totalCost, double heuristicCost) {
    this->state = state;
    this->totalCost = totalCost;
    this->heuristicCost = heuristicCost;
}

// state ----------------------

int StateRep::setState(state[][]) {
    this->state = state;
}

int[][] StateRep::getState() const {
    return this->state; 
}

void StateRep::printState() const {
    for (unsigned int i = 0; i < 3; ++i) {
        for (unsigned int j = 0; j < 3; ++j) {
            cout << state[i][j]
        }
    }
}

// totalCost ------------------------

double StateRep::setTotalCost() {

}

double StateRep::getTotalCost() const {
    return this->totalCost(); 
}

// heuristicCost -------------------------

double StateRep::setHeuristicCost() {

}

double StateRep::getHeuristicCost() const {
    return this->heuristicCost; 
}