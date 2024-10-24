#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

// returns an array of length nV containing the shortest
// distance between src and each vertex.
// For an undirected, unweighted graph.
int *findShortestDistance(Graph g, int src) {
    bool *visited = calloc(GraphNumVertices(g), sizeof(bool));
    int *dist = malloc(GraphNumVertices(g) * sizeof(int));
    Queue q = QueueNew();

    dist[src] = 0;
    visited[src] = true;
    QueueEnqueue(q, src);

    while (!QueueIsEmpty(q)) {
        int v = QueueDequeue(q);

        for (int w = 0; w < GraphNumVertices(g); w++) {
            if (GraphIsAdjacent(g, v, w) && !visited[w]) {
                QueueEnqueue(q, w);
                visited[w] = true;
                dist[w] = dist[v] + 1;
            }
        }
    }

    free(visited);
    QueueFree(q);

    return dist;
}
