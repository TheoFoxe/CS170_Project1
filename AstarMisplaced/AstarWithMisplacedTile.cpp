#include "AstarMisplacedSolver.h"
#include "Problem.h"

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int misplacedTileHeuristic(const vector<int>& current, const vector<int>& goal) {
    int misplaced = 0;
    for (size_t i = 0; i < current.size(); i++) {
        if (current[i] != 0 && current[i] != goal[i]) {
            misplaced++;
        }
    }
    return misplaced;
}

// Generate successors of the current puzzle state
vector<Puzzle> generateSuccessors(const Puzzle& current) {
    vector<Puzzle> successors;
    int row = current.zero_index / 3;
    int col = current.zero_index % 3;
    vector<pair<int, int>> moves = {{row - 1, col}, {row + 1, col}, {row, col - 1}, {row, col + 1}};

    for (auto& move : moves) {
        int new_row = move.first;
        int new_col = move.second;
        if (new_row >= 0 && new_row < 3 && new_col >= 0 && new_col < 3) {
            vector<int> new_tiles = current.tiles;
            swap(new_tiles[current.zero_index], new_tiles[new_row * 3 + new_col]);
            successors.emplace_back(new_tiles, const_cast<Puzzle*>(&current), current.g + 1);
        }
    }

    return successors;
}

// A* Search Algorithm with the Misplaced Tile heuristic.
Puzzle* aStarSearch(const vector<int>& initial, const vector<int>& goal) {
    priority_queue<Puzzle> open_list;
    map<vector<int>, int> best_cost;
    Puzzle* initial_puzzle = new Puzzle(initial);
    initial_puzzle->h = misplacedTileHeuristic(initial, goal);
    initial_puzzle->f = initial_puzzle->g + initial_puzzle->h;
    open_list.push(*initial_puzzle);
    best_cost[initial] = 0;

    while (!open_list.empty()) {
        Puzzle current = open_list.top();
        open_list.pop();

        if (current.tiles == goal) {
            return new Puzzle(current.tiles, current.parent, current.g);
        }

        vector<Puzzle> successors = generateSuccessors(current);
        for (Puzzle& successor : successors) {
            int current_cost = successor.g;
            if (best_cost.find(successor.tiles) == best_cost.end() || current_cost < best_cost[successor.tiles]) {
                successor.h = misplacedTileHeuristic(successor.tiles, goal);
                successor.f = successor.g + successor.h;
                open_list.push(successor);
                best_cost[successor.tiles] = current_cost;
            }
        }
    }
    return nullptr;
}