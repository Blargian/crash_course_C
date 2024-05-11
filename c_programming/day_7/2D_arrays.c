#include <stdio.h>
#include <stdlib.h>

void print2DArrayWithPointer(int* array, int rows, int cols)
{
    for (int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%d\t", array[i*cols+j]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv)
{
    const int rows = 5;
    const int cols = 4;
    int counter = 0;
    int* array2D = (int*)malloc(sizeof(int)*rows*cols);
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            array2D[cols*i + j] = counter++;
            printf("%d ", array2D[cols*i + j]);
        }
        printf("\n");
    }

    // Print 2D array with function defined above
    print2DArrayWithPointer(array2D, 5, 4);
    free(array2D);
    return 0;
}
