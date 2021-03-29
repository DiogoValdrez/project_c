#include <stdio.h>
#include <stdlib.h>

void init_board(char board[15][24], int height, int width);
void draw_board(char board[15][24], int height, int width);
int mult(int value);

int main()
{
    int height, width;
    char board[15][24];
    do
    {
        printf("Imput the height and width of the board: \n");
        printf("Both coordenates must be multiples of 3.\n");
        printf("->The height must be between 9 and 15;\n");
        printf("->The width must be between 9 and 24;\n");
        scanf(" %d %d", &height, &width);
    } while (height < 9 || height > 15 || width < 9 || width > 24 || mult(width) || mult(height)==1);
    
    
    init_board(board, height, width);
    draw_board(board, height, width);
    return EXIT_SUCCESS;
}

int mult(int value)
{
    if(value%3 == 0)
    {
        return 0;
    }else{
        return 1;
    }
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