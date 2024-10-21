#include "Graph.h"

struct node {
    int v;
    struct node *next;
};

struct graph {
    int nV;
    struct node **adjList;
};

Graph GraphNew(int nV) {
    Graph g = malloc(sizeof(struct graph));
    g->nV = nV;
    g->adjList = calloc(nV, sizeof(struct node *));
}

static struct node *insertInOrder(struct node *list, int v) {
    if (list == NULL || list->v > v) {
        struct node *new = malloc(sizeof(struct node));
        new->next = list;
        new->v = v;
        return new;
    }
    list->next = insertInOrder(list->next, v);
    return list;
}

void GraphAddEdge(Graph g, int v, int u) {
    g->adjList[u] = insertInOrder(g->adjList[u], v);
    g->adjList[v] = insertInOrder(g->adjList[v], u);
}
