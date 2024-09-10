#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
    int length;
};

struct list *listNew(void) {
    struct list *list = malloc(sizeof(struct list));
    list->head = NULL;
    list->length = 0;
    return list;
}

void listInsert(struct list *list, int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = list->head;

    list->head = newNode;
    list->length++;
}

// delete the first instance of node with 'value' from the linked list
void listDelete(struct list *list, int value) {
    assert(list != NULL);

    if (list->head == NULL) return;

    if (list->head->value == value) {
        struct node *newHead = list->head->next;
        free(list->head);
        list->head = newHead;
        list->length--;
        return;
    }

    struct node *prev = list->head;
    struct node *curr = list->head->next;

    while (curr != NULL) {
        if (curr->value == value) {
            prev->next = curr->next;
            free(curr);
            list->length--;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    return;
}

int listLength(struct list *list) {
    return list->length;
}

int main(void) {
    struct list *list = listNew();

    listInsert(list, 1);
    listInsert(list, 2);
    listInsert(list, 3);
    listInsert(list, 4);
    listInsert(list, 5);

    listDelete(list, 3);

    // print list
    for (struct node *curr = list->head; curr != NULL; curr = curr->next) {
        printf("%d\n", curr->value);
    }

    return 0;
}
