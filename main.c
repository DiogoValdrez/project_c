#include <stdio.h>
#include <stdlib.h>

void board(int height, int width);

int main()
{
    int height, width;
    printf("Insert the board size in the following format: height, width: \n");
    scanf(" %d %d", &height, &width);
    board(height, width);
    return EXIT_SUCCESS;
}

void board(int height, int width)
{
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("-");
        }  
        printf("\n");      
    }
    return;
}