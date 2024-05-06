#ifndef STATEREP_H
#define STATEREP_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
All info relevant to state

- state rep, as a 3x3 2D array
    1 2 3 
    4 5 6
    7 8 0 
    
    0 is representing the blank tile 

- total cost
- heuristic cost
*/ 

const int puzzleDim = 3; 

class StateRep {
    private: 
        vector<vector<int>> state;
        double totalCost; 
        double heuristicCost; 

    public: 
        StateRep();
        StateRep(vector<vector<int>> state);
        StateRep(vector<vector<int>> state, double totalCost, double heuristicCost);

        void setState(vector<vector<int>> state);
        const vector<vector<int>> & getState() const; 
        void printState() const; 

        void setTotalCost(double totalCost);
        double getTotalCost() const;

        void setHeuristicCost(double heuristicCost);
        double getHeuristicCost() const;

};

#endif