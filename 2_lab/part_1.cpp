#include <iostream>
#include <iomanip>

using namespace std;

int **genRandMatrix(int size, int maxValue)
{
    int **arr = new int*[size];
    int yach = 0;
    for(int i = 0; i < size; i++)
    {
        arr[i] = new int[size];
        for (short j = 0; j < size; j++)
        {
            arr[i][j] = yach;
            yach++;
        }
    }
    return arr;
}

void print_2_mas(int** mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout <<std::setw(2) << mas[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void print_1_mas(int* mas, int size)
{
    for (int i = 0; i < size*size; i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << "\n";
}

void right_diagonal(int** mas, int* das, int size)
{
    int now = 0;
    int j = 0;
    for (int i = size-1; i > -size; i--)
    {
        int y = i;
        if (y < 0)
        {
            y = 0;
            j++;
        }
        for (int x = j; x < size && y < size; x++, y++)
        {
            das[now] = mas[x][y];
            now++;
        }
    }
}

void left_diagonal(int** mas, int* das, int size)
{
    int now = 0;
    int j = 0;
    for (int i = 0; i < size*2; i++)
    {
        int y = i;
        if (y > size - 1)
        {
            y = size - 1;
            j++;
        }
        for (int x = j; x < size && y >= 0; x++, y--)
        {
            das[now] = mas[x][y];
            now++;
        }
        
    }
    
}

void spiral_center(int** mas, int* das, int size)
{
    int now = 0;
    int i, j, per;
    if (size%2==1)
    {
        i = size/2;
        j = size/2;
        per = size/2+1;
    }
    else if (size==2)
    {
        i = size/2;
        j = 0;
        per = size/2+1;
    }
    else
    {
        i = size/2;
        j = size/2-1;
        per = size/2;
    }

    for (; per > 0;)
    {
        for (; j < size-per; j++)
        {
            das[now] = mas[i][j];
            now++;
        }

        for (; i > -1+per; i--)
        {
            das[now] = mas[i][j];
            now++;
        }
        per--;
        for (; j > -1+per; j--)
        {
            das[now] = mas[i][j];
            now++;
        }

        for (; i < size-per; i++)
        {
            das[now] = mas[i][j];
            now++;
        }
    }
    
}

void spiral_left_angle(int **mas, int *das, int size)
{
    int now = 0;
    int i = 0;
    int j = 0;
    int per = 1;
    for (; per < (size<=4?3:size-2);)
    {
        for (; j < size-per; j++)
        {
            das[now] = mas[i][j];
            now++;
        }

        for (; i < size-per; i++)
        {
            das[now] = mas[i][j];
            now++;
        }

        for (; j > -1+per; j--)
        {
            das[now] = mas[i][j];
            now++;
        }
        per++;
        for (; i > -1+per; i--)
        {
            das[now] = mas[i][j];
            now++;
        }
        das[now] = mas[i][j];
    }
}

int main()
{
    int size = 4;
    int** mas = genRandMatrix(size, 10);
    int* das = new int[size*size];

    cout << "MATRIX:\n";
    print_2_mas(mas, size);
    cout << "_______________________\n";

    cout << "left_diagonal\n";
    left_diagonal(mas, das, size);
    print_1_mas(das, size);

    cout << "\nright_diagonal\n";
    right_diagonal(mas, das, size);
    print_1_mas(das, size);

    cout << "\nspiral_center\n";
    spiral_center(mas, das, size);
    print_1_mas(das, size);

    cout << "\nspiral_left_angle\n";
    spiral_left_angle(mas, das, size);
    print_1_mas(das, size);
}