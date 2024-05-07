#ifndef ASTAR_MISPLACED_SOLVER_H
#define ASTAR_MISPLACED_SOLVER_H

#include <set>
#include <string>
#include <queue>
#include <cmath>
#include "Problem.h"
#include "UniformCostSearch.h"

double heuristicFunction(Puzzle &current) {
        return 0.0;
    };

// Calculate the heuristic cost using the Misplaced Tile heuristic
class MisplacedTileSolver : public UniformCostSolver {
public:
    //set up goal puzzle
    MisplacedTileSolver(Puzzle& goal) : UniformCostSolver(goal) {};
    virtual double heuristicFunction(Puzzle& current) override {
        double misplaced = 0;
        for (size_t i = 0; i < PUZZLE_SIZE; ++i) {
            for (size_t j = 0; j < PUZZLE_SIZE; ++j) {
                if (current.getIndexOfRowCol(i, j) != 0 && current.getIndexOfRowCol(i, j) != goal.getIndexOfRowCol(i, j)) {
                    misplaced++;
                }
            }
        }
        return misplaced;
    };
};


#endif // ASTAR_MISPLACED_SOLVER_H