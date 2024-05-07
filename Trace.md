# A trace of the Euclidean distance A* on the following problem:

 - GoalPuzzle

```
 {1, 2, 3}
 {4, 5 ,6}
 {7, 8, 0}
 ```

 - currentPuzzle

 ```
 {1, 0, 3}
 {4, 2, 6}
 {7, 5, 8}
 ```

executing A* with the Euclidean distance heuristic
Expanding state
```
{1, 0, 3}
{4, 2, 6}
{7, 5, 8}
```

The best state to expand with g(n)=1 and h(n)=2 is...
```
{1, 2, 3}
{4, 0, 6}
{7, 5, 8}
```

The best state to expand with g(n)=1 and h(n)=4 is...
```
{1, 3, 0}
{4, 2, 6}
{7, 5, 8}
```

The best state to expand with g(n)=1 and h(n)=4 is...
```
{0, 1, 3}
{4, 2, 6}
{7, 5, 8}
```

The best state to expand with g(n)=2 and h(n)=1 is...
```
{1, 2, 3}
{4, 5, 6}
{7, 0, 8}
```

The best state to expand with g(n)=2 and h(n)=3 is...
```
{1, 2, 3}
{4, 6, 0}
{7, 5, 8}
```

The best state to expand with g(n)=2 and h(n)=3 is...
```
{1, 2, 3}
{0, 4, 6}
{7, 5, 8}
```

The best state to expand with g(n)=3 and h(n)=0 is...
```
{1, 2, 3}
{4, 5, 6}
{7, 8, 0}
```

The best state to expand with g(n)=3 and h(n)=2 is...
```
{1, 2, 3}
{4, 5, 6}
{0, 7, 8}
```

Finally we had solved this puzzle!
Use the move list: DDR
To solve this problem the search algorithm expanded a total of 9 nodes.
The maximum number of nodes in the queue at any one time: 6.
The depth of the goal node was  3.