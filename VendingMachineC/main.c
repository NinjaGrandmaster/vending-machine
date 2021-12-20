#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

double getCoins(double price);

int main() {
    int numItems = 3;
    /* Initial items in vending machine and their prices stored in seperate arrays*/
    char items_arr[3][20] = {
        "Almonds",
        "Chocolate",
        "Bagel"
    };
    double item_price[3] = {
        1.00,
        1.25,
        2.50
    };

    int vendingAction;
    int item;

    while (1) {
        /* ask user if they are purchasing or adding item to machine*/
        printf("Select an action \n1: Puchase Item\n2: Add Item\n3: Exit\n");
        scanf("%d", &vendingAction);

        switch (vendingAction)
        {
            case 1:
                printf("Select an Item\n");
                /* display items in vending machine with price*/
                for (int i = 0; i < numItems; i++) {
                    printf("%d: %s - $%.2f\n", i, items_arr + i, item_price[i]);
                }
                scanf("%d", &item); /* get item selected by user */

                double price = item_price[item]; /* get price of item */

                double enteredCurrency = getCoins(price); /* get coins from user */

                printf("\nVending %s\n\n", items_arr + item); /* vend item */

                /* calculate and return change*/
                double change = enteredCurrency - price;
                printf("Dispencing change\n");
                printf("Change = $%.2f\n", change);

                break;

            case 2:
                printf("Add\n");
                break;
            
            case 3:
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