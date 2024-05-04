#ifndef STATEREP_H
#define STATEREP_H

#include <vector>
#include <string>

/*
All info relevant to state

- state rep, as a 2D array
    1 2 3 
    4 5 6
    7 8 * 
- total cost
- heuristic cost
*/

//struct Node 

class StateRep {
    private: 
        int state[3][3]; 
        double totalCost; 
        double heuristicCost; 

    public: 
        StateRep(); //constructor
        StateRep(state[][], double totalCost, double heuristicCost);

        int setState(state[][]);
        int getState() const;
        void printState() const; 

        double setTotalCost(double totalCost);
        double getTotalCost() const;

        double setHeuristicCost(double heuristicCost);
        double getHeuristicCost() const;

};

#endif