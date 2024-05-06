#ifndef ASTAR_EUCLIDEAN_SOLVER_H
#define ASTAR_EUCLIDEAN_SOLVER_H

#include <vector>

struct Node
{
    std::vector<std::vector<int> > state; // Here
    double g;                            // Cost from start node to current node
    double h;                            // Heuristic value (Euclidean distance)
};

// A* Search Algorithm with the Euclidean Distance heuristic.
std::vector<std::vector<int> > aStarSearch(const std::vector<std::vector<int> > &initial, const std::vector<std::vector<int> > &goal); // Here

const std::__1::vector<std::__1::vector<int> > &NewFunction();

#endif // ASTAR_EUCLIDEAN_SOLVER_H
