#include <stdio.h>
#include <stdlib.h>

struct list {
    struct node *head;
    //
    int length;
    struct node *tail;
};

struct node {
    int value;
    struct node *next;
};

// return the number of nodes in a linked list, given its head
int listLength(struct node *list);

// use a while loop
int listLength(struct node *list) {
    int length = 0;
    struct node *curr = list;
    while (curr != NULL) {
        length += 1;
        curr = curr->next;
    }

    return length;
}

// use a for loop
int listLength(struct node *list) {
    int length = 0;
    for (struct node *curr = list; curr != NULL; curr = curr->next) {
        length += 1;
    }
    return length;
}
