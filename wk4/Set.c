#include "Set.h"

struct set {
    int *items;
    int capacity;
    int numItems;
};

// Creates a new empty set
Set SetNew(void) {
    struct set *new = malloc(sizeof(struct set));
    new->items = malloc(sizeof(int) * 8);
    new->capacity = 8;
    new->numItems = 0;

    return new;
}

// Frees memory allocated to the set
void SetFree(Set s) {
    free(s->items);
    free(s);
}

// Inserts an element into the set
void SetInsert(Set s, int elem) {
    if (SetContains(s, elem)) return;

    if (s->capacity == s->numItems) {
        s->items = realloc(s->items, s->capacity * 2 * sizeof(int));
        s->capacity *= 2;
    }

    s->items[s->numItems++] = elem;
}

// Deletes an element from the set
void SetDelete(Set s, int elem);

// Returns true if the given element is in the set, and false otherwise
bool SetContains(Set s, int elem) {
    for (int i = 0; i < s->numItems; i++) {
        if (s->items[i] == elem) {
            return true;
        }
    }

    return false;
}

// Returns the number of elements in the set
int SetSize(Set s) {
    return s->numItems;
}
