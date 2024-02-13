#include <stdio.h>
#include "my_mat.h"




int main() {
    char userChoice;
    
     do { 
        
        userChoice = getchar();  // Read a character

        
        switch (userChoice) {
            case 'A':
                scanMatrix();
               
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
            // case EOF:
            //     break;
            default:
                break;
    
        }
    } while (userChoice != 'D' && userChoice != EOF);  // Continue the loop until the user chooses to exit
    return 0;
}
