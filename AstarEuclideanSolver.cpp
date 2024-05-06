#include "AstarEuclideanSolver.h"
#include "Problem.h"

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

// Euclidean distance heuristic
double euclideanDistanceHeuristic(const vector<vector<int> >& current, const vector<vector<int> >& goal) { // Add space here
    double distance = 0.0;
    for (size_t i = 0; i < current.size(); ++i) {
        for (size_t j = 0; j < current[i].size(); ++j) {
            int value = current[i][j];
            if (value != 0) {
                // Find position of value in the goal state
                for (size_t k = 0; k < goal.size(); ++k) {
                    auto it = find(goal[k].begin(), goal[k].end(), value);
                    if (it != goal[k].end()) {
                        int goal_row = k;
                        int goal_col = std::distance(it, goal[k].begin()); // Error might be here
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
vector<vector<vector<int> > > generateSuccessors(const vector<vector<int> >& current) { // Add space here
    vector<vector<vector<int> > > successors; // Add space here
    // Locate the position of the empty tile (0)
    int zero_row, zero_col;
    for (size_t i = 0; i < current.size(); ++i) {
        auto it = find(current[i].begin(), current[i].end(), 0);
        if (it != current[i].end()) {
            zero_row = i;
            zero_col = distance(current[i].begin(), it);
            break;
        }
    }
    vector<pair<int, int> > moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Add space here

    for (const auto& move : moves) {
        int new_row = zero_row + move.first;
        int new_col = zero_col + move.second;
        if (new_row >= 0 && new_row < current.size() && new_col >= 0 && new_col < current[new_row].size()) {
            // Create a new state by swapping the empty tile with the adjacent tile
            vector<vector<int> > new_state = current; // Add space here
            swap(new_state[zero_row][zero_col], new_state[new_row][new_col]);
            successors.push_back(new_state);
        }
    }

    return successors;
}

// A* Search Algorithm with the Euclidean Distance heuristic.
vector<vector<int> > aStarSearch(const vector<vector<int> >& initial, const vector<vector<int> >& goal) { // Add space here
    priority_queue<Node> open_list;
    map<vector<vector<int> >, double> best_cost; // Add space here
    vector<vector<int> > initial_state = initial; // Add space here
    double initial_h = euclideanDistanceHeuristic(initial_state, goal); // Error might be here
    open_list.push({initial_state, 0.0, initial_h});
    best_cost[initial_state] = 0.0;

    while (!open_list.empty()) {
        auto current = open_list.top();
        open_list.pop();

        if (current.state == goal) {
            return current.state;
        }

        auto successors = generateSuccessors(current.state);
        for (const auto& successor : successors) {
            double current_cost = current.g + 1; // Assuming each step cost is 1
            if (best_cost.find(successor) == best_cost.end() || current_cost < best_cost[successor]) {
                double h = euclideanDistanceHeuristic(successor, goal);
                open_list.push({successor, current_cost, h});
                best_cost[successor] = current_cost;
            }
        }
    }
    return {}; // No solution found
}