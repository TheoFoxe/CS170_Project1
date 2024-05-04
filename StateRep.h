#ifndef STATEREP_H
#define STATEREP_H

#include <iostream>
#include <vector>
#include <string>

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
        int state[puzzleDim][puzzleDim] = { {1, 2, 3}, 
                                            {4, 5, 6}, 
                                            {7, 8, 0}}; 
        double totalCost = 0; 
        double heuristicCost = 0; 

    public: 
        StateRep();
        StateRep(int state[puzzleDim][puzzleDim]);
        StateRep(int state[puzzleDim][puzzleDim], double totalCost, double heuristicCost);

        void setState(int state[puzzleDim][puzzleDim]);
        void printState() const; 

        void setTotalCost(double totalCost);
        double getTotalCost() const;

        void setHeuristicCost(double heuristicCost);
        double getHeuristicCost() const;

};

#endif