#include <stdio.h>
#include <stdlib.h>


void draw_board(char board[15][24], int height, int width);

int main()
{
    int height, width;
    scanf("%d", &height);
    scanf("%d", &width);
    char board[15][24];
    int i, j;
    for ( i = 0; i < height; i++)
    {
        for ( j = 0; j < width; j++)
        {
            board[i][j] = '-';
        }

    }
    draw_board(board, height, width);
    return EXIT_SUCCESS;
}



void draw_board(char board[15][24],int height, int width)
{
    int i, j;
    for (i = 0; i < height; i++)
    {
        for ( j = 0; j < width; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    return ;
}