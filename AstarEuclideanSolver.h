#ifndef ASTAR_EUCLIDEAN_SOLVER_H
#define ASTAR_EUCLIDEAN_SOLVER_H

#include <set>
#include <string>
#include <queue>
#include <cmath>
#include "Problem.h"

//define movement directions
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

//its to keep track of max queue size + #expanded nodes
int XXX = 1; //1 bc initial state alr in queue
int YYY;
int ZZZ;
class EuclideanDistanceSolver {
public:
    EuclideanDistanceSolver(Problem& goal) : goal(goal) {};

    //calc euclidean distance between goal/curr
    virtual double heuristicFunction(Problem &current) {
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

    bool solveProblem(Problem& current) {
        cout << "Expanding state" << endl;
        cout << current << endl;

        //store puzzles based on total cost (f(n) = g(n) + h(n))
        priority_queue<Problem> mq;
        //set to keep track of visited states
        set<string> vis;

        //save initial puzzle into priority_queue
        mq.push(current);
       //mark initial state as visited
        vis.insert(current.getHashString());

        while (!mq.empty()) {
            //get puzzle w lowest total cost
            Problem top = mq.top();
            mq.pop();

            //check if current state is goal
            if (top == goal) {
                ZZZ = top.getG();//store depth of goal node

                cout << "Finally, we had solved this puzzle!" << endl;
                cout << "Use the move list: " << top.op << endl;

                return true;
            }

            //iterate through possible moves 
            for (int i = 0; i < 4; i++) {
                int nx = top.getZeroRow() + dx[i];
                int ny = top.getZeroCol() + dy[i];

                //check if move is within bounds
                if (nx < 0 || nx > PUZZLE_SIZE - 1 || ny < 0 || ny > PUZZLE_SIZE - 1)
                    continue;
                
                //get val of tile @ new position
                int value = top.getIndexOfRowCol(nx, ny);
                int zero_row = top.getZeroRow();
                int zero_col = top.getZeroCol();

                //create new puzzle by moving 0 tile to new position
                Problem temp = top;
                temp.setIndexOfRowCol(nx, ny, 0);
                temp.setIndexOfRowCol(zero_row, zero_col, value);
                temp.setG(top.getG() + 1); //increment depth
                temp.setH(heuristicFunction(temp)); //calc heuristic val

                //check if new state has been visited before
                if (vis.find(temp.getHashString()) == vis.end()) {
                    cout << "The best state to expand with g(n)=" << temp.getG();
                    cout << " and h(n)=" << temp.getH() << " is..." << endl;
                    cout << temp << endl;

                    //update move list
                    switch (i)
                    {
                    case 0:
                        temp.op += "D";
                        break;

                    case 1:
                        temp.op += "U";
                        break;

                    case 2:
                        temp.op += "R";
                        break;

                    case 3:
                        temp.op += "L";
                        break;
                    }

                    mq.push(temp); //add new state to priority queue
                    XXX++; //increment # of expanded nodes
                    YYY = max(YYY, (int)mq.size()); //update max queue size
                    vis.insert(temp.getHashString()); //mark new state visited
                }
            }
        }

        return false;
    };

protected:
    Problem goal;
};

#endif // ASTAR_EUCLIDEAN_SOLVER_H
