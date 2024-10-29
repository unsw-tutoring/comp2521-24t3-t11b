/*
---> Important roads <---

A developer is planning a suburb, and they have represented the roads they
plan to build as edges in a connected, undirected graph.

However, due to budget cuts, they have decided to remove some roads.
A road is important if removing it would disconnect the graph.

Your task is to write a function to identify the important roads, so the
developer knows which roads can't be removed.

Implement the function importantRoads(Graph g), which prints the important
roads, each followed by a newline.

Roads should be printed in the form u-v, where u is the index of the
lower-numbered vertex and v is the index of the higher-numbered vertex.
They should be ordered in increasing order of u then v.

For example, if the graph is

0 --- 1 --- 6
|     |       7
|     |      /
2 --- 3 --- 4 --- 5

then your function should print
1-6
3-4
4-5
4-7
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

// checks if goal is reachable from curr
bool isReachable(Graph g, int curr, int goal, bool *visited) {
    visited[curr] = true;

    if (curr == goal) return true;

    for (int i = 0; i < GraphNumVertices(g); i++) {
        if (GraphIsAdjacent(g, curr, i) && !visited[i]) {
            if (isReachable(g, i, goal, visited)) {
                return true;
            }
        }
    }

    return false;
}

void importantRoads(Graph g) {
    // loop through every edge in the graph
    for (int i = 0; i < GraphNumVertices(g); i++) {
        for (int j = i + 1; j < GraphNumVertices(g); j++) {
            if (GraphIsAdjacent(g, i, j)) {
                GraphRemoveEdge(g, i, j);
                // check if I can still reach every node
                bool *visited = calloc(GraphNumVertices(g), sizeof(bool));
                if (!isReachable(g, i, j, visited)) {
                    printf("%d-%d\n", i, j);
                }
                free(visited);

                GraphAddEdge(g, i, j);
            }
        }
    }
}
