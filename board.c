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
}

//Function that draws the game board
void drawBoard(char board[15][24],int height, int width)
{
    int i, j;

    printf("\n");

    for (i = 0; i < height; i++)
    {
        if((height - i) < 10)
        {
            printf("%d ", (height - i));;
        }else{
            printf("%d", (height - i));;
        }

        for (j = 0; j < width; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("  ");

    for (i = 0; i < width; i++)
    {
        char num = i + 'A';
        printf("%c ", num);
    }
    printf("\n");

    return ;
}