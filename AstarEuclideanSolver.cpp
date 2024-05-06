#include "AstarEuclideanSolver.h"
#include "Problem.h"

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

// Euclidean distance heuristic from curr to goal
double euclideanDistanceHeuristic(const vector<vector<int> >& current, const vector<vector<int> >& goal) {
    double distance = 0.0;
    // iterating over the current state
    for (size_t i = 0; i < current.size(); ++i) {
        for (size_t j = 0; j < current[i].size(); ++j) {
            int value = current[i][j];
            if (value != 0) { //ignore empty tile
                // Find position of value in the goal state
                for (size_t k = 0; k < goal.size(); ++k) {
                    vector<int>::const_iterator it = find(goal[k].begin(), goal[k].end(), value);
                    if (it != goal[k].end()) {
                        //calculate euclidean distance/add to total distance
                        int goal_row = k;
                        int goal_col = std::distance(it, goal[k].begin()); 
                        distance += sqrt(pow(i - goal_row, 2) + pow(j - goal_col, 2));
                        break;
                    }
                }
            }
        }
    }
    return distance;
}

// Generate successors of the current puzzle state
vector<vector<vector<int> > > generateSuccessors(const vector<vector<int> >& current) {
    vector<vector<vector<int> > > successors; 
    // Locate position of the empty tile (0)
    int zero_row, zero_col;

    for (size_t i = 0; i < current.size(); ++i) {
        vector<int>::const_iterator it = find(current[i].begin(), current[i].end(), 0);
        if (it != current[i].end()) {
            zero_row = i;
            zero_col = distance(current[i].begin(), it);
            break;
        }
    }
    vector<pair<int, int> > moves;
    moves.push_back(std::make_pair(-1, 0));
    moves.push_back(std::make_pair(1, 0));
    moves.push_back(std::make_pair(0, -1));
    moves.push_back(std::make_pair(0, 1));



//loop over possible moves
    for (const auto& move : moves) {
        int new_row = zero_row + move.first;
        int new_col = zero_col + move.second;
        //check if move is within bounds
        if (new_row >= 0 && new_row < current.size() && new_col >= 0 && new_col < current[new_row].size()) {
            //swap the empty tile w/ adjacent tile n create new state
            vector<vector<int> > new_state = current; 
            swap(new_state[zero_row][zero_col], new_state[new_row][new_col]);
            successors.push_back(new_state);
        }
    }

    return successors;
}

// A* Search Algorithm with the Euclidean Distance heuristic.
vector<vector<int> > aStarSearch(const vector<vector<int> >& initial, const vector<vector<int> >& goal) {
    priority_queue<Node> open_list;
    map<vector<vector<int> >, double> best_cost; 
    vector<vector<int> > initial_state = initial;
    double initial_h = euclideanDistanceHeuristic(initial_state, goal); 
    //add to list
    Node newState;
    newState.state = initial_state;
    newState.g = 0.0;
    newState.h = initial_h;
    open_list.push(newState);

    best_cost[initial_state] = 0.0;

    while (!open_list.empty()) {
        auto current = open_list.top();
        open_list.pop();
        //check if curr state == goal
        if (current.state == goal) {
            return current.state;
        }
        //generate n explore successors
        auto successors = generateSuccessors(current.state);
        for (const auto& successor : successors) {
            //calculate cost of successor
            double current_cost = current.g + 1; // Assuming each step cost is 1
            //check if successor hasn't been visited/has lower cost
            if (best_cost.find(successor) == best_cost.end() || current_cost < best_cost[successor]) {
                //calculate heuristic val for successor
                double h = euclideanDistanceHeuristic(successor, goal);
                //add successor/cost to list
                newState.state = successor;
                newState.g = current_cost;
                newState.h = h;
                open_list.push(newState);

                best_cost[successor] = current_cost; //update best cost
            }
        }
    }
    vector<vector<int> > noSol;
    return noSol; // No solution found
}
