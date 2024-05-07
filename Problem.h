#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include <iostream>
#include <array>
#include <string>
using namespace std;

#define PUZZLE_SIZE 3

class Problem {
public:
    //default consturctor
    Problem() {};
    // Constructor that initializes the puzzle with a given state and optionally depth information.
    Problem(vector<vector<int>>& mv, int depth = 0) : h(0), g(0) {
        for (size_t i = 0; i < PUZZLE_SIZE; ++i) {
            for (size_t j = 0; j < PUZZLE_SIZE; ++j) {
                tiles[i * PUZZLE_SIZE + j] = mv[i][j];
                if (tiles[i * PUZZLE_SIZE + j] == 0) {
                    zero_row = i;
                    zero_col = j;
                }
            }
        }
    }

    // Overloads '<' for sorting purposes based on the heuristic and path cost.
    bool operator<(const Problem& other) const {
        if (g + h == other.g + other.h) {
            return h > other.h;
        }
        return g + h > other.g + other.h;
    }

    // Compare equality of two Puzzle states based on their tile configurations
    bool operator==(const Problem& other) const {
        return tiles == other.tiles;
    }

    friend ostream& operator<<(ostream& os, const Problem& p) {
        for (size_t i = 0; i < PUZZLE_SIZE; ++i) {
            for (size_t j = 0; j < PUZZLE_SIZE; ++j) {
                cout << p.tiles[i * PUZZLE_SIZE + j] << " ";
            }
            cout << endl;
        }
        return os;
    }

    int getIndexOfRowCol(int row, int col) const {
        return tiles[row * PUZZLE_SIZE + col];
    }
    void setIndexOfRowCol(int row, int col, int value) {
        tiles[row * PUZZLE_SIZE + col] = value;
        if (value == 0) {
            zero_row = row;
            zero_col = col;
        }
    }

    int getZeroRow() { return zero_row; }
    int getZeroCol() { return zero_col; }

    string getName() { return name; }

    double getG() { return g; }
    double getH() { return h; }

    void setG(double gg) { g = gg; }
    void setH(double hh) { h = hh; }

    void setParent(Problem* p) {
        parent = p;
    }
    //HashString to indicate if the current puzzle entered the A* (BFS) alraedy, puzzles are expected to enter and excute only once
    string getHashString() {
        name = "";
        for (size_t i = 0; i < PUZZLE_SIZE; ++i) {
            for (size_t j = 0; j < PUZZLE_SIZE; ++j) {
                name += to_string(tiles[i * PUZZLE_SIZE + j]);
            }
        }
        return name;
    }

    string op = "";

private:
    string name = "";
    array<int, PUZZLE_SIZE* PUZZLE_SIZE> tiles;
    size_t zero_row = -1;
    size_t zero_col = -1;

    Problem* parent = nullptr;

    double g, h;

};

#endif