#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

#include<stdbool.h>

struct Node {
    int key;
    char* item;
    double price;
    struct Node *next;
};

/* function to create new nodes */
struct Node* newNode(int key, char* item, double price);
/* display the list */
void printList(struct Node* head);
/* add item to list */
void append(struct Node** head, int key, char* item, double price);
/* free memeory after using list */
void freeList(struct Node* head);
/* check if an item exists in a list */
bool exists(struct Node* head, int key);
/* get the price of an item from the list  */
double getPrice(struct Node* head, int key);
/* get the name of an item from the list */
char* getName(struct Node* head, int key);

#endif