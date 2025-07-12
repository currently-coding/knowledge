
#include <stdio.h>

typedef enum {exit = 00, chocolate_bar = 11, smarties = 12, hot_chocolate = 13, peanut_butter_cups = 14} sweets; 

int main(){

    int switchNumber = 0;
    printf("\nPlease choose: \n");
    printf("11: chocolate bar\n");
    printf("12: smarties \n");
    printf("13: hot chocolate \n");
    printf("14: peanut butter cups \n");
    printf("00: exit \n\n");

    
    while (1) {
        
        scanf("%d", &switchNumber);

        switch (switchNumber)
        {
            case chocolate_bar:
                printf("You got a chocolate bar\n");
                return 0;
            case smarties:
                printf("You got smarties\n");
                return 0;
            case hot_chocolate:
                printf("You got a hot chocolate\n");
                return 0;
            case peanut_butter_cups:
                printf("You got peanut butter cups\n");
                return 0;
            case exit:
                return 0; 
            default: printf("This sweet is not available, please enter a valid number: \n");
            break;
        }
    }
}