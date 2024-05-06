
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <functional> 
#include <cstddef>  
#include <list>
#include "problem.h"

using namespace std;

 struct Puzzle {
    vector<vector<int>> tiles;
    size_t zero_row, zero_col;
    Puzzle* parent;
    int g, h, f;
    

    Puzzle(const vector<vector<int>>& t, Puzzle* p = nullptr, int g_cost = 0)
        : tiles(t), parent(p), g(g_cost), h(0), f(0) {
        // Locate the blank tile (0)
        for (size_t i = 0; i < tiles.size(); ++i) {
            for (size_t j = 0; j < tiles[i].size(); ++j) {
                if (tiles[i][j] == 0) {
                    zero_row = i;
                    zero_col = j;
                    break;
                }
            }
        }
    }
 


 bool operator<(const Puzzle& other) const {
        return f > other.f; // Min-heap priority queue (using greater-than)
    }

    // Hash for storing Puzzle tiles in unordered map/set
    struct Hash {
        size_t operator()(const vector<vector<int>>& tiles) const {
            size_t hash = 0;
            std::hash<int> int_hash;

            for (const auto& row : tiles) {
                for (const auto& val : row) {
                    hash = hash * 31 + int_hash(val);
                }
            }
            return hash;
        }
    };

    // Compare equality of two Puzzle states based on their tile configurations
    bool operator==(const Puzzle& other) const {
        return tiles == other.tiles;
    }

    // Print the current state
    void printState() const {
        cout << "State:" << endl;
        for (const auto& row : tiles) {
            for (const auto& tile : row) {
                cout << tile << " ";
            }
            cout << endl;
        }
        cout << "Cost (g): " << g << ", Heuristic Cost (h): " << h << ", Total Cost (f): " << f << endl;
        cout << "-----------------------" << endl;
    }
};

// Calculate the heuristic cost using the Misplaced Tile heuristic
int misplacedTileHeuristic(const vector<vector<int>>& current, const vector<vector<int>>& goal) {
    int misplaced = 0;
    for (size_t i = 0; i < current.size(); ++i) {
        for (size_t j = 0; j < current[i].size(); ++j) {
            if (current[i][j] != 0 && current[i][j] != goal[i][j]) {
                misplaced++;
            }
        }
    }
    return misplaced;
}

// Generate successors of the current puzzle state by moving the blank tile
std::vector<Puzzle> generateSuccessors(const Puzzle& current) {
    std::vector<Puzzle> successors;
    // Use `int` to represent directions correctly
    std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

    for (const auto& dir : directions) {
        // Convert to signed integers for calculation
        int new_row = static_cast<int>(current.zero_row) + dir.first;
        int new_col = static_cast<int>(current.zero_col) + dir.second;

        // Ensure that the new row and column are within bounds
        if (new_row >= 0 && new_row < static_cast<int>(current.tiles.size()) &&
            new_col >= 0 && new_col < static_cast<int>(current.tiles[0].size())) {
            // Perform the swap using `size_t` indices
            std::vector<std::vector<int>> new_tiles = current.tiles;
            std::swap(new_tiles[static_cast<size_t>(current.zero_row)][static_cast<size_t>(current.zero_col)],
                      new_tiles[static_cast<size_t>(new_row)][static_cast<size_t>(new_col)]);
            successors.emplace_back(new_tiles, const_cast<Puzzle*>(&current), current.g + 1);
        }
    }

    return successors;
}

void aStarSearch(const vector<vector<int>>& initial, const vector<vector<int>>& goal) {
    priority_queue<Puzzle> frontier;
    unordered_set<vector<vector<int>>, Puzzle::Hash> explored;
    unordered_map<vector<vector<int>>, int, Puzzle::Hash> best_cost;
    std::list<Puzzle> expansion_history; // Linked list to store the history of expanded nodes

    Puzzle* initial_puzzle = new Puzzle(initial);
    initial_puzzle->h = misplacedTileHeuristic(initial, goal);
    initial_puzzle->f = initial_puzzle->g + initial_puzzle->h;
    frontier.push(*initial_puzzle);
    best_cost[initial] = 0;

    int total_expanded = 0;

    while (!frontier.empty()) {
        Puzzle current = frontier.top();
        frontier.pop();

        if (current.tiles == goal) {
            cout << "Goal state reached:" << endl;
            current.printState();
            cout << "Total number of expanded nodes: " << total_expanded << endl;
            // Print all the states that have been expanded
            cout << "Expansion History:" << endl;
            for (const auto& state : expansion_history) {
                state.printState();
            }
            return;
        }

        explored.insert(current.tiles);
        total_expanded++;

        // Store the current state in the linked list
        expansion_history.push_back(current);

        vector<Puzzle> successors = generateSuccessors(current);
        for (Puzzle& successor : successors) {
            if (explored.find(successor.tiles) != explored.end()) {
                continue; // Skip already explored states
            }

            int current_cost = successor.g;
            if (best_cost.find(successor.tiles) == best_cost.end() || current_cost < best_cost[successor.tiles]) {
                successor.h = misplacedTileHeuristic(successor.tiles, goal);
                successor.f = successor.g + successor.h;
                frontier.push(successor);
                best_cost[successor.tiles] = current_cost;
            }
        }
    }

    cout << "No solution found." << endl;
}
  // Test to call the algorithm:
