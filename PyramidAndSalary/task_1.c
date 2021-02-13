#include <stdio.h>
#include <stdlib.h>

void info(char *symbols)                                                          // function gives info and initialize with loop "for" char array symbols
{
    int i;
    printf("\tYou need to enter 3 symbols, by which will be built pyramid!\n");
    for(i=0; i<3; i++)
    {
        printf("\nPlease, enter symbol #%d : ", i+1);
        scanf("%s", &symbols[i]);
    }
}

void pyramid(char *symbols)                                                       // function builds pyramid with two loops "for" and two-dimensional array
{
    int arr[6][11] = {{0,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,1,2,1,0,0,0,0},{0,0,0,1,2,3,2,1,0,0,0},{0,0,1,2,3,3,3,2,1,0,0},{0,1,2,3,3,3,3,3,2,1,0},{1,2,3,3,3,3,3,3,3,2,1}};  // array 6x11(pyramid size)
    int i, j;
    for(i=0; i<6; i++)                            // loop, used to go around array's rows
    {
        for(j=0; j<11; j++)                       // loop, used to go around array's columns
        {
            if(arr[i][j] == 0)                    // if current element of array is 0, then program prints "space"
            {
                printf("   ");
            }
            if(arr[i][j] == 1)                    // if current element of array is 1, then program prints symbol which was entered first
            {
                printf(" %c ", symbols[0]);
            }
            if(arr[i][j] == 2)                    // if current element of array is 2, then program prints symbol which was entered second
            {
                printf(" %c ", symbols[1]);
            }
            if(arr[i][j] == 3)                    // if current element of array is 1, then program prints symbol which was entered first
            {
                printf(" %c ", symbols[2]);
            }
        }
        printf("\n\n");                           // it is needed to go to the next row
    }
}

int main()
{
    char sym[3];
    info(sym);
    printf("\n\n");
    pyramid(sym);
    return 0;
}
