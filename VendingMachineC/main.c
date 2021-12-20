#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "list.h"

double getCoins(double price);

int main() {

    int numItems = 3; /* counter to keep track of number of items in dending machine for assigning key to additonal items*/
    int vendingAction; /* used to ask user the vending action the would like to perform - purchase, add, exit. */
    int itemNum; /* used to ask user which item the would like form vending machine */
    double newItemPrice;
    char newItemName[25];


    struct Node* vendItems = NULL; /* list containing all items in vending machine*/

    /* add initial items to vending machine */
    append(&vendItems, 1, "Almonds", 1.00);
    append(&vendItems, 2, "Chocolate", 1.25);
    append(&vendItems, 3, "Bagel", 2.50);

    while (1) {
        /* ask user if they are purchasing or adding item to machine*/
        printf("Select an action \n1: Puchase Item\n2: Add Item\n3: Exit\n");
        scanf("%d", &vendingAction);

        switch (vendingAction)
        {
            case 1:
                /* display items in vending machine*/
                printList(vendItems);
                /* get item selected by user */
                printf("Select an Item\n");
                scanf("%d", &itemNum);

                bool itemExists = exists(vendItems, itemNum); /* check if items exist */

                if (itemExists)
                {
                    /* get name and price of item from list */
                    char* itemName = getName(vendItems, itemNum);
                    double itemPrice = getPrice(vendItems, itemNum);

                    printf("Selected: %s - $%.2f\n", itemName, itemPrice);

                    double enteredCurrency = getCoins(itemPrice); /* get coins from user */

                    printf("\nVending %s\n\n", itemName); /* vend item */

                    /* calculate and return change*/
                    double change = enteredCurrency - itemPrice;
                    printf("Dispencing change\n");
                    printf("Change = $%.2f\n\n", change);

                } else {
                    /* item does not exist */
                    printf("Invalid Choice\n");
                }

                break;

            case 2:
                printf("Enter item name: ");
                scanf("%s", newItemName);

                printf("Enter item price: ");
                scanf("%lf", &newItemPrice);

                numItems += 1; /* increment num items counter */

                append(&vendItems, numItems, newItemName, newItemPrice); /* add item to list */

                printf("Item added: %s - $%.2f\n\n", newItemName, newItemPrice);
                break;
            
            case 3:
                freeList(vendItems); /* free memory used to store list on exit*/
                exit(0);
                break;
            
            default:
                printf("invalid choice\n");
                break;
        }
    }

    return 0;
} /* end of main*/

/* get coins from the user until enough is entered to purchase item*/
double getCoins(double price){
    double coinSum = 0.0;
    int coin;
    while (coinSum < price)
    {
        printf("Amount needed %.2f\n", price);
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

        printf("Current amount: %.2f\n", coinSum);
    }
    
    return coinSum;
}