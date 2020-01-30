/* Nikhil Anand */

#include <stdio.h>
#include <stdlib.h>

/*Value gets the value of the card number entered*/
int value(char card_name[]) {
    int val = 0;
    switch(card_name[0]) {
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            break;
        default:
            val = atoi(card_name);
            if((val < 1) || (val > 10)) {
                puts("I don't understand that value!");
                return 0;
            }
    }
    return val;
}

/* whatCount determines if the count goes up or down 1 based on inputed number */
int whatCount(char card_name[], int count) {
    int val = value(card_name);
    if((val > 2) && (val < 7)) {
        count++;
    } else if(val == 10) {
        count--;
    }
    return (count);
}

/* counter handles everything else*/
void counter() {
    char card_name[3];
    int start = 0;
    int updated = start;
    while (card_name[0] != 'X')
    {
        puts("Enter the card_name: ");
        scanf("%2s", card_name);
        if(card_name[0] == 'X') {
            break;
        }
        updated = whatCount(card_name, updated);
        printf("Current Count: %d\n", updated);
    }
}

int main()
{
  counter();
  return 0;
}
