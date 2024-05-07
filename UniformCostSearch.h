#include <set>
#include <string>
#include <queue>
#include <cmath>
#include "Problem.h"

// define movement directions
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

//ints to keep track of max queue size + #expanded nodes
int XXX = 1;
int YYY;
int ZZZ;

class UniformCostSearch {
public:
    UniformCostSearch(Problem& goal) : goal(goal) {};

    bool solveProblem(Problem& current) {
        cout << "Expanding state" << endl;
        cout << current << endl;

        priority_queue<Problem> mq;
        set<string> vis;

        //save current puzzle into priority queue
        mq.push(current);
        vis.insert(current.getHashString());

        while (!mq.empty()) {
            Problem top = mq.top();
            mq.pop();

            if (top == goal) {
                ZZZ = top.getG();

                cout << "We solved the puzzle!" << endl;
                cout << "Use the move list: " << top.op << endl;

                return true;
            }

            //iterate through possible moves
            for (int i = 0; i < 4; i++) {
                int nx = top.getZeroRow() + dx[i];
                int ny = top.getZeroCol() + dy[i];

                if (nx < 0 || nx > PUZZLE_SIZE - 1 || ny < 0 || ny > PUZZLE_SIZE - 1)
                    continue;

                int value = top.getIndexOfRowCol(nx, ny);
                int zero_row = top.getZeroRow();
                int zero_col = top.getZeroCol();

                Problem temp = top;
                temp.setIndexOfRowCol(nx, ny, 0);
                temp.setIndexOfRowCol(zero_row, zero_col, value);
                temp.setG(top.getG() + 1);
                temp.setH(0);

                //expanding process
                if (vis.find(temp.getHashString()) == vis.end()) {
                    cout << "The best state to expand with g(n)=" << temp.getG();
                    cout << " and h(n)=" << temp.getH() << " is..." << endl;
                    cout << temp << endl;

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

                    mq.push(temp);
                    XXX++;
                    YYY = max(YYY, (int)mq.size());
                    vis.insert(temp.getHashString());
                }
            }
        }

        return false;
    };

protected:
    Problem goal;
};