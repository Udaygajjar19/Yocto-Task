#include <stdio.h>
#include "header.h"

int main() {
    char choice[10];

    while (1) {
        printf("\nSelect a function to execute:\n");
        printf("1. Data_Type_Size\n");
        printf("2. eqloop\n");
        printf("3. HextoIntgerOutput\n");
        printf("4. SqueezeOutput\n");
        printf("5. RemoveCharacter\n");
        printf("6. SetbitOutput\n");
        printf("7. InvertedbitOutput\n");
        printf("8. RightrotateOutput\n");
        printf("9. BitcountOutput\n");
        printf("0. Quit\n");
        printf("Enter your choice (0-9): ");
        scanf(" %[^\n]", choice);

        // Clear leftover newline to avoid issues with getchar
        while (getchar() != '\n');

        switch (choice[0]) {
            case '1':
                Data_Type_Size();
                break;
            case '2':
                eqloop();
                break;
            case '3':
                HextoIntgerOutput();  // now safe to call
                break;
            case '4':
                SqueezeOutput();
                break;
            case '5':
                RemoveCharacter();
                break;
            case '6':
                SetbitOutput();
                break;
            case '7':
                InvertedbitOutput();
                break;
            case '8':
                RightrotateOutput();
                break;
            case '9':
                BitcountOutput();
                break;
            case '0':
                printf("Exiting program\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 0 and 9.\n");
        }
    }

    return 0;
}

