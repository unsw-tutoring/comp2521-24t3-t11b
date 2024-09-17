#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "List.h"

// struct list {
//     struct node *head;
// };

// int doListLength(struct node *l) {
//     if (l == NULL) return 0;

//     // return 1 + ListLength(l->next);
// }

// int ListLength(struct list *l) {
//     return doListLength(l->head);
// }

// create a new empty list
struct node *ListNew() {
    return NULL;
}

// add item to end of list
List ListAdd(List l, int val) {
    // malloc a new node
    List newNode = malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = val;

    // if empty list
    if (l == NULL) {
        return newNode;
    }

    // add to end of list
    List curr = l;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    return l;
}

// delete the first item with value 'val' from list -- recursively
// if 'val' is not in the list, do nothing
// returns the head of the new linked list
struct node *ListDelete(struct node *l, int val) {
    if (l == NULL) return NULL;
    if (l->data == val) {
        struct node *newHead = l->next;
        free(l);
        return newHead;
    }

    l->next = ListDelete(l->next, val);
    return l;
}

// delete all odd numbers from list -- recursively
struct node *ListDeleteOdds(struct node *l) {
    // TODO
    return NULL;
}

// delete every second node (second, fourth, sixth, etc. node)
struct node *ListDeleteSecond(struct node *l) {
    // TODO
    return NULL;
}

// prints out the linked list
void ListPrint(struct node *l) {
    // TODO
}

// prints out the linked list in reverse
void ListPrintReverse(struct node *l) {
    // TODO
}

// returns length of linked list
int ListLength(struct node *l) {
    if (l == NULL) return 0;

    return 1 + ListLength(l->next);
}

// returns number of odd nodes in linked list
int ListCountOdd(struct node *l) {
    if (l == NULL) return 0;

    int n = ListCountOdd(l->next);
    if (l->data % 2 == 0) {
        return n;
    } else {
        return 1 + n;
    }
}
// int ListCountOdd(struct node *l) {
//     if (l == NULL) return 0;

//     return (l->data % 2) + ListCountOdd(l->next);
// }

// check if list is sorted in non-descending order; 1->2->2->3
bool ListIsSorted(struct node *l) {
    if (l == NULL) return true;
    if (l->next == NULL) return true;

    if (l->data > l->next->data) {
        return false;
    }

    bool ifTheRestOfTheListIsSorted = ListIsSorted(l->next);
    if (ifTheRestOfTheListIsSorted) return true;
    return false;
}

// bool ListIsSorted(struct node *l) {
//     if (l == NULL || l->next == NULL) return true;
//     return (l->data <= l->next->data) && ListIsSorted(l->next);
// }

// ! THE FOLLOWING TWO EXAMPLES SHOW TWO COMMON TRICKS / TECHNIQUES YOU CAN
// ! USE WHEN CODING RECURSIVELY. TAKE NOTE OF THESE.

// multiply each element in the list by it's position
// e.g. 1st node gets multiplied by 1, 2nd node get multiplied by 2, etc.
void ListTransform(struct node *l) {
    // TODO
    return;
}

// multiply each element in the list by it's position
// e.g. 1st node gets multiplied by 1, 2nd node get multiplied by 2, etc.
void ListTransformAlternate(struct node *l) {
    // TODO
    return;
}
