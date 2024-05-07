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
        //initialize tiles based on input
        for (size_t i = 0; i < PUZZLE_SIZE; ++i) {
            for (size_t j = 0; j < PUZZLE_SIZE; ++j) {
                tiles[i * PUZZLE_SIZE + j] = mv[i][j];
                //find position of */0 file
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
            return h > other.h; //compare + prioritize the one w higher heuristic value
        }
        return g + h > other.g + other.h; //sort by total path cost + heuristic val
    }

    // Compare equality of two Puzzle states based on their tile configurations
    bool operator==(const Problem& other) const {
        return tiles == other.tiles;
    }

    //output stream operator to print puzzle state
    friend ostream& operator<<(ostream& os, const Problem& p) {
        for (size_t i = 0; i < PUZZLE_SIZE; ++i) {
            for (size_t j = 0; j < PUZZLE_SIZE; ++j) {
                cout << p.tiles[i * PUZZLE_SIZE + j] << " "; //print each tile val
            }
            cout << endl;
        }
        return os;
    }

    //getter for value @ specific row + column
    int getIndexOfRowCol(int row, int col) const {
        return tiles[row * PUZZLE_SIZE + col];
    }

    //setter for value @ specific row + column
    void setIndexOfRowCol(int row, int col, int value) {
        tiles[row * PUZZLE_SIZE + col] = value;
        if (value == 0) {
            zero_row = row;
            zero_col = col;
        }
    }

    //getters for zero row/column
    int getZeroRow() { return zero_row; }
    int getZeroCol() { return zero_col; }

    //getter for name of puzzle
    string getName() { return name; }

    //getter for g which is cost from initial state to curr state
    double getG() { return g; }
    //getter h which is heuristic cost from curr to goal state
    double getH() { return h; }

    //setters for g & h
    void setG(double gg) { g = gg; }
    void setH(double hh) { h = hh; }

    //set parent/problem state
    void setParent(Problem* p) {
        parent = p;
    }
    //HashString to indicate if the current puzzle entered the A* (BFS) alraedy, puzzles are expected to enter and excute only once
    string getHashString() {
        name = "";
        for (size_t i = 0; i < PUZZLE_SIZE; ++i) {
            for (size_t j = 0; j < PUZZLE_SIZE; ++j) {
                name += to_string(tiles[i * PUZZLE_SIZE + j]); //convert tile configurations to a string
            }
        }
        return name; //return hash string
    }

    string op = ""; //operation string for debugging purposes

private:
    string name = ""; //name of puzzle
    array<int, PUZZLE_SIZE* PUZZLE_SIZE> tiles; //tiles representing puzzle state
    size_t zero_row = -1; //row position of 0 tile
    size_t zero_col = -1; //col position of 0 tile

    Problem* parent = nullptr; //problem/parent state

    double g, h; //g = cost from initial state to curr, g = heuristic cost from curr to goal

};

#endif