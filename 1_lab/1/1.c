#include <stdio.h>
#include <stdlib.h>

int *genRandArray(int size, int maxValue)
{
    int *arr = malloc(sizeof(int) * (size + 1) );
    arr[0] = size;
    for (short i = 1; i < size + 1; i++)
    {
        arr[i] = rand() % maxValue;
    }
    return arr;
}

void print(int *arr)
{
    printf("%d: ", arr[0]);
    for (short i = 1; i < arr[0] + 1; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    int size = rand() % 10;
    int maxValue = 100;
    int *arr = genRandArray(size, maxValue);
    print(arr);
    free(arr);
}