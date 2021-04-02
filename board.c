#include "board.h"

//Function that initializes the game board
void initBoard(char board[15][24], int height, int width)
{
    int i, j;
    for ( i = 0; i < height; i++)
    {
        for ( j = 0; j < width; j++)
        {
            board[i][j] = '-';
        }

    }
    return;
}

//Function that draws the game board
void drawBoard(char board[15][24],int height, int width)
{
    int i, j, k;

    printf("\n");

    for (i = 0; i < height; i++)
    {
        if((height - i) < 10)
        {
            printf("%d  ", (height - i));;
        }else{
            printf("%d ", (height - i));;
        }

        for (j = 0; j < width; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("   ");

    for (k = 0; k < width; k++)
    {
        char num ='A' + k;
        printf("%c ", num);
    }
    printf("\n");
    return;
}
