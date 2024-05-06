#ifndef Astar_Misplaced_Class_H
#define Astar_Misplaced_Class_H

#include "Problem.h"
#include "StateRep.h"

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

class AstarMisplacedSolver{

public:

//A* with the Misplaced Tile heuristic Search.
// std::vector<std::vector<int> > aStarSearch(const vector<int>& initial, const vector<int>& goal);
Puzzle* aStarSearch(const vector<int>& initial, const vector<int>& goal);

//Calculate h(n).
int misplacedTileHeuristic(const vector<int>& current, const vector<int>& goal);

//Generate all possible states that can be reached.
vector<Puzzle> generateSuccessors(const Puzzle& current);



private:

    

};


#endif // Astart_Misplaced_Class_H