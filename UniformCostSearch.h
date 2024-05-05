#ifndef UNIFORM_COST_SEARCH_H
#define UNIFORM_COST_SEARCH_H

#include <vector>
#include "Problem.h"
#include "StateRep.h"
#include <queue>

class UniformCostSearch {
    private:
        bool isGoalState(StateRep& state, Problem& problem);
        std::vector<StateRep> generateSuccessors(StateRep& state, Problem& problem);
    public:
        std::vector<StateRep> UCS(Problem& problem);
};

#endif