#include <stdio.h>
#include "my_mat.h"

int main() {
    char userChoice;

     do {
        
        
        
        userChoice = getchar();  // Read a character

        // Clear the input buffer
        //while (getchar() != '\n');

        switch (userChoice) {
            case 'A':
                scanMatrix();
                printf("\n");
                break;

            case 'B':
                int i=0;
                int j=0;
                scanf("%d %d",&i,&j);
                ifHasPath(i,j);
                printf("\n");
                break;

            case 'C':
                int k=0;
                int s=0;
                scanf("%d %d",&k,&s);
                //floydWarshall(k,s);
                printf("%d",printLength(k,s));
                printf("\n");
                break;

            case 'D':
                break;
            default:
                break;
    
        }
    } while (userChoice != 'D');  // Continue the loop until the user chooses to exit
    return 0;
}
