#ifndef ASTAR_EUCLIDEAN_SOLVER_H
#define ASTAR_EUCLIDEAN_SOLVER_H

#include <set>
#include <string>
#include <queue>
#include <cmath>
#include "Problem.h"
#include "UniformCostSearch.h"

class EuclideanDistanceSolver : public UniformCostSearch {
public:
    EuclideanDistanceSolver(Problem &goal) : UniformCostSearch(goal){};
    virtual double heuristicFunction(Problem &current){ 
        double distance = 0.0;
        for (int i = 0; i < PUZZLE_SIZE; ++i) {
            for (int j = 0; j < PUZZLE_SIZE; ++j) {
                int value = current.getIndexOfRowCol(i, j);
                if (value != 0) {
                    // Find position of value/tile in the goal state
                    for (size_t k = 0; k < PUZZLE_SIZE; ++k) {
                        for (size_t m = 0; m < PUZZLE_SIZE; ++m) {
                            if (value == goal.getIndexOfRowCol(k, m)) {
                                int goal_row = k;
                                int goal_col = m;
                                //calc + add euclidean distance to total distance
                                distance += sqrt(pow(i - goal_row, 2) + pow(j - goal_col, 2));
                                k = PUZZLE_SIZE;
                                m = PUZZLE_SIZE;
                            }
                        }
                    }
                }
            }
        }
        return distance;
    };
};

#endif // ASTAR_EUCLIDEAN_SOLVER_H