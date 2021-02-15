#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINE 7
#define COLUMN 12

void arrFiller(int arr[LINE][COLUMN]);
void arrPrinter(int arr[LINE][COLUMN]);
void findMin(int arr[LINE][COLUMN]);
void findMax(int arr[LINE][COLUMN]);

int main()
{
    int arr[LINE][COLUMN];
    arrFiller(arr);
    printf("\t Your array: \n");
    arrPrinter(arr);
    findMax(arr);
    findMin(arr);
    return 0;
}


void arrFiller(int arr[LINE][COLUMN])
{
    int stime;
    long ltime;
    ltime = time (NULL);
    stime = (unsigned int) ltime/2;
    srand(stime);
    int i,j;
    for(i = 0; i < LINE; i++)
    {
        for(j = 0; j < COLUMN; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
}


void arrPrinter(int arr[LINE][COLUMN])
{
    int i,j;
    for(i = 0; i < LINE; i++)
    {
        for(j = 0; j < COLUMN; j++)
        {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
}


void findMax(int arr[LINE][COLUMN])
{
    int i, j;
    int row, counter, temp = 0;
    for(i = 0; i < LINE; i++)
    {
        counter = 0;
        for(j = 0; j < COLUMN; j++)
        {
            counter += arr[i][j];
        }
        if(temp < counter)
        {
            temp = counter;
            row = i;
        }
    }
    printf("\nMaximal row: ");
    for(j = 0; j < COLUMN; j++)
    {
        printf("%d ", arr[row][j]);
    }
    printf("\tSum of elements = %d ", temp);
}

void findMin(int arr[LINE][COLUMN])
{
    int i, j;
    int row, counter, temp = 99;
    for(i = 0; i < LINE; i++)
    {
        counter = 0;
        for(j = 0; j < COLUMN; j++)
        {
            counter += arr[i][j];
        }
        if(temp > counter)
        {
            temp = counter;
            row = i;
        }
    }
    printf("\nMinimal row: ");
    for(j = 0; j < COLUMN; j++)
    {
        printf("%d ", arr[row][j]);
    }
    printf("\tSum of elements = %d ", temp);
}
