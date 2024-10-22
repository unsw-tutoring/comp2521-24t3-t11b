#include "Graph.h"

void doDfs(Graph g, int v, bool *visited) {
    if (visited[v]) return;
    visited[v] = true;

    for (int i = 0; i < GraphNumVertices(g); i++) {
        if (GraphIsAdjacent(g, v, i)) {
            doDfs(g, i, visited);
        }
    }
}

void dfs(Graph g, int src) {
    bool *visited = calloc(GraphNumVertices(g), sizeof(bool));

    doDfs(g, src, visited);
}
