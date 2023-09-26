#include <iostream>

using namespace std;

int **genRandMatrix(int size, int maxValue)
{
    int **arr = new int*[size + 1];
    arr[0] = new int[1];
    arr[0][0] = size;
    for(int i = 1; i < size + 1; i++)
    {
        int sizestr = rand() % 10;
        arr[i] = new int[sizestr + 1];
        arr[i][0] = sizestr;
        for (short j = 1; j < sizestr + 1; j++)
            arr[i][j] = rand() % maxValue;
    }
    return arr;
}

void print(int **matrix)
{
    printf("%d\n",matrix[0][0]);
    for (int i = 1; i < matrix[0][0] + 1; i++)
    {
        printf("%d: ",matrix[i][0]);
        for (int j = 1; j < matrix[i][0] + 1; j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
}

void free_matrix(int **matrix)
{
    int size = matrix[0][0] + 1;
    for (int i = 0; i < size; i++)
        delete [] matrix[i];
    delete [] matrix;
}

int main()
{
    int size = rand() % 10;
    int maxValue = 100;
    int **matrix = genRandMatrix(size, maxValue);
    print(matrix);
    free_matrix(matrix);
}