#include <stdio.h>

int main() {
    char userChoice;

     do {
        printf("Menu:\n");
        printf("A - Execute Function 1\n");
        printf("B - Execute Function 2\n");
        printf("C - Execute Function 3\n");
        printf("D - Exit\n");

        printf("Enter your choice: ");
        choice = getchar();  // Read a character

        // Clear the input buffer
        while (getchar() != '\n');

        switch (choice) {
            case 'A':
                scanMatrix();
                break;

            case 'B':
                int i=0;
                int j=0;
                scanf("%d %d",&i,&j);
                ifHasPath(i,j);
                break;

            case 'C':
                int i=0;
                int j=0;
                scanf("%d %d",&i,&j);
                function3();
                break;

            case 'D':
                printf("Exiting the program. Goodbye!\n");
                break;
        }
    } while (choice != 'D');  // Continue the loop until the user chooses to exit
    return 0;
}
