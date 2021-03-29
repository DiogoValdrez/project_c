#include <stdio.h>
#include <stdlib.h>

void init_board(char board[15][24], int height, int width);
void draw_board(char board[15][24], int height, int width);

int main()
{
    int height, width;
    char board[15][24];
    printf("Imput the height and width of the board: \n");
    scanf(" %d %d", &height, &width);
    
    init_board(board, height, width);
    draw_board(board, height, width);
    return EXIT_SUCCESS;
}

void init_board(char board[15][24], int height, int width)
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

void draw_board(char board[15][24],int height, int width)
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