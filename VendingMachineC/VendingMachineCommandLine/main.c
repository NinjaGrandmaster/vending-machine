#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"

double getCoins(double price);

int main(int argc, char *argv[]) {

    struct Node* vendItems = NULL; /* list containing all items in vending machine*/

    /* add initial items to vending machine */
    append(&vendItems, 1, "Almonds", 1.00);
    append(&vendItems, 2, "Chocolate", 1.25);
    append(&vendItems, 3, "Bagel", 2.50);

    if( argc == 2 ) {
        printf("The argument supplied is %s\n", argv[1]);

        if (!strcmp("-l", argv[1])){
            printList(vendItems);
        } else {
            printf("Unknown commands\n");
        }
    }
    else {
        printf("Incorrect amount of arguments supplied.\n");
    }

    freeList(vendItems);
    return 0;
} /* end of main*/

/* get coins from the user until enough is entered to purchase item*/
double getCoins(double price){
    double coinSum = 0.0;
    int coin;
    while (coinSum < price)
    {
        printf("Amount needed: $%.2f\n", price);
        printf("Current Balance: $%.2f\n", coinSum);
        printf("Enter coin\n1: Penny\n2: Nickle\n3: Dime\n4: Quarter\n");
        scanf("%d", &coin);
        switch (coin) {
        case 1:
            coinSum += .01;
            break;
        case 2:
            coinSum += .05;
            break;
        case 3:
            coinSum += .10;
            break;
        case 4:
            coinSum += .25;
            break;        
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    
    return coinSum;
}