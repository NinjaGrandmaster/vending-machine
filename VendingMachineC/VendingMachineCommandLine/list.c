#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

#include "list.h"

/* create new node */
struct Node* newNode(int key, char* item, double price) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->key = key;
    /* allocate memory to hold item name */
    node->item = malloc(strlen(item) + 1);
    /* copy item name to allocated memory*/
    strcpy(node->item, item);
    node ->price = price;

    return node;
}

/* print list */
void printList(struct Node* head) {
    struct Node* current = head;
    while (current) {
        printf("%d: %s - $%.2f\n", current->key, current->item, current->price);
        current = current->next;
    }
}

/* add to end of list */
void append(struct Node** head, int key, char* item, double price) {
    struct Node* current = *head;
    struct Node* node = newNode(key, item, price);

    if(current == NULL) {
        *head = node;
    } else {
        /* find last node */
        while (current->next != NULL) {
            current = current->next;
        }
        /* add new node at end */
        current->next = node;   
    }
}

/* free memory used by list */
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* tmp = 0;

    while (current) {
        tmp = current->next;
        free(current->item);
        free(current);
        current = tmp;
    }
    
}

/* check if item exists in a list */
/* true = item exists, false = item does not exist */
bool exists(struct Node* head, int key) {
    struct Node* current = head;

    while(current != NULL) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }

    return false;
}

/* get the price of an item in the list */
/* returns 0.0 if item is not in list, other wise returns price from list*/
double getPrice(struct Node* head, int key) {
    struct Node* current = head;

    while(current != NULL) {
        if (current->key == key) {
            return current->price;
        }
        current = current->next;
    }

    return 0.0;
}

/* get the name of an item in the list */
/* returns empty string if item is not in list, other wise returns name from list*/
char* getName(struct Node* head, int key) {
    struct Node* current = head;

    while(current != NULL) {
        if (current->key == key) {
            return current->item;
        }
        current = current->next;
    }

    return "";
}