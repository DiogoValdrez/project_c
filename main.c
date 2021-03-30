/*Batalha naval
Autores: Diogo Valdrez 99914, Pedro Raposo 100059
Data: 20/04/2021 ??
Descrição : ...
*/
#include <stdio.h>
#include <stdlib.h>

void init_board(char board[15][24], int height, int width);
void draw_board(char board[15][24], int height, int width);
int mult(int value);
void pieces(char id_piece,int id_var,char board[15][24],int coor_height,int coor_width);
int restric_0_1(char board[15][24], int coor_height, int coor_width);

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
    } while (height < 9 || height > 15 || width < 9 || width > 24 || mult(width)==1 || mult(height)==1);


    init_board(board, height, width);
    draw_board(board, height, width);


    return EXIT_SUCCESS;
}
//Function that checks whether the value is a multiple of 3
int mult(int value)
{
    if(value%3 == 0)
    {
        return 0;
    }else{
        return 1;
    }
}
//Function that initializes the game board
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
//Function that draws the game board
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
/*Function that changes each 3x3 matrix for the piece
that is suposed to put in it*/
void pieces(char id_piece,int id_var,char board[15][24],int coor_height,int coor_width)
{
    switch (id_piece)
    {
        case 0:
            break;
        case 1:
            switch (id_var)
            {
                case 1:
                    board[coor_height][coor_width] = id_piece;
                    break;
                case 2:
                    board[coor_height][coor_width+1] = id_piece;
                    break;
                case 3:
                    board[coor_height][coor_width+2] = id_piece;
                    break;
                case 4:
                    board[coor_height+1][coor_width] = id_piece;
                    break;
                case 5:
                    board[coor_height+1][coor_width+1] = id_piece;
                    break;
                case 6:
                    board[coor_height+1][coor_width+2] = id_piece;
                    break;
                case 7:
                    board[coor_height+2][coor_width] = id_piece;
                    break;
                case 8:
                    board[coor_height+2][coor_width+1] = id_piece;
                    break;
                case 9:
                    board[coor_height+2][coor_width+2] = id_piece;
                    break;
                }
            break;
        case 2:
            switch (id_var)
            {
                case 1:
                    board[coor_height][coor_width] = id_piece;
                    board[coor_height][coor_width+1] = id_piece;
                    break;
                case 2:
                    board[coor_height][coor_width+1] = id_piece;
                    board[coor_height][coor_width+2] = id_piece;
                    break;
                case 3:
                    board[coor_height+1][coor_width] = id_piece;
                    board[coor_height+1][coor_width+1] = id_piece;
                    break;
                case 4:
                    board[coor_height+1][coor_width+1] = id_piece;
                    board[coor_height+1][coor_width+2] = id_piece;
                    break;
                case 5:
                    board[coor_height+2][coor_width] = id_piece;
                    board[coor_height+2][coor_width+1] = id_piece;
                    break;
                case 6:
                    board[coor_height+2][coor_width+1] = id_piece;
                    board[coor_height+2][coor_width+1] = id_piece;
                    break;
                case 7:
                    board[coor_height][coor_width] = id_piece;
                    board[coor_height+1][coor_width] = id_piece;
                    break;
                case 8:
                    board[coor_height+1][coor_width] = id_piece;
                    board[coor_height+2][coor_width] = id_piece;
                    break;
                case 9:
                    board[coor_height][coor_width+1] = id_piece;
                    board[coor_height+1][coor_width+1] = id_piece;
                    break;
                case 10:
                    board[coor_height+1][coor_width+1] = id_piece;
                    board[coor_height+2][coor_width+1] = id_piece;
                    break;
                case 11:
                    board[coor_height][coor_width+2] = id_piece;
                    board[coor_height+1][coor_width+2] = id_piece;
                    break;
                case 12:
                    board[coor_height+1][coor_width+2] = id_piece;
                    board[coor_height+1][coor_width+2] = id_piece;
                    break;

            }
            break;
        case 3:
            switch(id_var)
            {
                case 1:
                    board[coor_height][coor_width] = id_piece;
                    board[coor_height][coor_width+1] = id_piece;
                    board[coor_height][coor_width+2] = id_piece;
                    break;
                case 2:
                    board[coor_height+1][coor_width] = id_piece;
                    board[coor_height+1][coor_width+1] = id_piece;
                    board[coor_height+1][coor_width+2] = id_piece;
                    break;
                case 3:
                    board[coor_height+2][coor_width] = id_piece;
                    board[coor_height+2][coor_width+1] = id_piece;
                    board[coor_height+2][coor_width+2] = id_piece;
                    break;
                case 4:
                    board[coor_height][coor_width] = id_piece;
                    board[coor_height+1][coor_width] = id_piece;
                    board[coor_height+2][coor_width] = id_piece;
                    break;
                case 5:
                    board[coor_height][coor_width+1] = id_piece;
                    board[coor_height+1][coor_width+1] = id_piece;
                    board[coor_height+2][coor_width+1] = id_piece;
                    break;
                case 6:
                    board[coor_height][coor_width+2] = id_piece;
                    board[coor_height+1][coor_width+2] = id_piece;
                    board[coor_height+2][coor_width+2] = id_piece;
                    break;
            }
            break;
        case 4:
            switch(id_var)
            {
                case 1:
                    board[coor_height][coor_width] = id_piece;
                    board[coor_height][coor_width+1] = id_piece;
                    board[coor_height+1][coor_width] = id_piece;
                    board[coor_height+1][coor_width+1] = id_piece;
                    break;
                case 2:
                    board[coor_height][coor_width+1] = id_piece;
                    board[coor_height][coor_width+2] = id_piece;
                    board[coor_height+1][coor_width+1] = id_piece;
                    board[coor_height+1][coor_width+2] = id_piece;
                    break;
                case 3:
                    board[coor_height+1][coor_width] = id_piece;
                    board[coor_height+1][coor_width+1] = id_piece;
                    board[coor_height+2][coor_width] = id_piece;
                    board[coor_height+2][coor_width+1] = id_piece;
                    break;
                case 4:
                    board[coor_height+1][coor_width+1] = id_piece;
                    board[coor_height+1][coor_width+2] = id_piece;
                    board[coor_height+2][coor_width+1] = id_piece;
                    board[coor_height+2][coor_width+2] = id_piece;
                    break;
            }
            break;
        case 5:
            switch(id_var)
            {
                case 1:
                    board[coor_height][coor_width] = id_piece;
                    board[coor_height][coor_width+1] = id_piece;
                    board[coor_height][coor_width+2] = id_piece;
                    board[coor_height+1][coor_width+1] = id_piece;
                    board[coor_height+2][coor_width+1] = id_piece;
                    break;
                case 2:
                    board[coor_height][coor_width] = id_piece;
                    board[coor_height+1][coor_width] = id_piece;
                    board[coor_height+2][coor_width] = id_piece;
                    board[coor_height+1][coor_width+1] = id_piece;
                    board[coor_height+1][coor_width+2] = id_piece;
                    break;
                case 3:
                    board[coor_height+2][coor_width] = id_piece;
                    board[coor_height+2][coor_width+1] = id_piece;
                    board[coor_height+2][coor_width+2] = id_piece;
                    board[coor_height][coor_width+1] = id_piece;
                    board[coor_height+1][coor_width+1] = id_piece;
                    break;
                case 4:
                    board[coor_height][coor_width+2] = id_piece;
                    board[coor_height+1][coor_width+2] = id_piece;
                    board[coor_height+2][coor_width+2] = id_piece;
                    board[coor_height+1][coor_width] = id_piece;
                    board[coor_height+1][coor_width+1] = id_piece;
                    break;
            }
            break;
        case 6:
            switch(id_var)
            {
                case 1:
                    board[coor_height][coor_width+1] = id_piece;
                    board[coor_height+1][coor_width] = id_piece;
                    board[coor_height+2][coor_width] = id_piece;
                    board[coor_height+2][coor_width+1] = id_piece;
                    board[coor_height+2][coor_width+2] = id_piece;
                    board[coor_height+1][coor_width+2] = id_piece;
                    break;
                case 2:
                    board[coor_height+1][coor_width] = id_piece;
                    board[coor_height][coor_width+1] = id_piece;
                    board[coor_height][coor_width+2] = id_piece;
                    board[coor_height+1][coor_width+2] = id_piece;
                    board[coor_height+2][coor_width+2] = id_piece;
                    board[coor_height+2][coor_width+1] = id_piece;
                    break;
                case 3:
                    board[coor_height+2][coor_width+1] = id_piece;
                    board[coor_height+1][coor_width] = id_piece;
                    board[coor_height][coor_width] = id_piece;
                    board[coor_height][coor_width+1] = id_piece;
                    board[coor_height][coor_width+2] = id_piece;
                    board[coor_height+1][coor_width+2] = id_piece;
                    break;
                case 4:
                    board[coor_height+1][coor_width+2] = id_piece;
                    board[coor_height][coor_width+1] = id_piece;
                    board[coor_height][coor_width] = id_piece;
                    board[coor_height+1][coor_width] = id_piece;
                    board[coor_height+2][coor_width] = id_piece;
                    board[coor_height+2][coor_width+1] = id_piece;
                    break;
            }
            break;
        case 7:
            switch(id_var)
            {
                case 1:
                    board[coor_height][coor_width] = id_piece;
                    board[coor_height+1][coor_width] = id_piece;
                    board[coor_height+2][coor_width] = id_piece;
                    board[coor_height][coor_width+2] = id_piece;
                    board[coor_height+1][coor_width+2] = id_piece;
                    board[coor_height+2][coor_width+2] = id_piece;
                    board[coor_height+1][coor_width+1] = id_piece;
                    break;
                case 2:
                    board[coor_height][coor_width] = id_piece;
                    board[coor_height][coor_width+1] = id_piece;
                    board[coor_height][coor_width+2] = id_piece;
                    board[coor_height+2][coor_width] = id_piece;
                    board[coor_height+2][coor_width+1] = id_piece;
                    board[coor_height+2][coor_width+2] = id_piece;
                    board[coor_height+1][coor_width+1] = id_piece;
                    break;
            }
            break;
        case 8:
            board[coor_height][coor_width] = id_piece;
            board[coor_height][coor_width+1] = id_piece;
            board[coor_height][coor_width+2] = id_piece;
            board[coor_height+1][coor_width] = id_piece;
            board[coor_height+1][coor_width+2] = id_piece;
            board[coor_height+2][coor_width] = id_piece;
            board[coor_height+2][coor_width+1] = id_piece;
            board[coor_height+2][coor_width+2] = id_piece;

            break;
        default:
            EXIT_FAILURE;

    }
    return;
}

/*Function that checks whether the piece that was put in the board
can be there considering the restrictions returning a 0 in case
 it's well positioned and any other number in case it shouldn't be there*/
 int restric_0_1(char board[15][24], int coor_height,int coor_width)
 {
     int i;
     if (!(coor_height == 0 || coor_width == 0) )
     {
        if (board[coor_height][coor_width] != '-' &&
            (board[coor_height+1][coor_width-1] != '-' || board[coor_height][coor_width-1] != '-'|| board[coor_height-1][coor_width-1] != '-' || board[coor_height-1][coor_width] != '-' ||board[coor_height-1][coor_width +1] != '-'))// 0x0
        {
            return 1;
        }
        if (board[coor_height+1][coor_width] != '-' &&
            (board[coor_height+2][coor_width-1] != '-' || board[coor_height+1][coor_width-1] != '-' || board[coor_height][coor_width-1] != '-'))// 1x0
        {
            return 1;
        }
        if (board[coor_height+2][coor_width] != '-' &&
            (board[coor_height+2][coor_width-1] != '-' || board[coor_height+1][coor_width-1] != '-'))// 2x0
        {
            return 1;
        }
         if (board[coor_height][coor_width+1] != '-' &&
              (board[coor_height-1][coor_width] != '-' || board[coor_height-1][coor_width+1] != '-' || board[coor_height-1][coor_width+2] != '-'))// 0x1
        {
            return 1;
        }
        if (board[coor_height][coor_width+2] != '-' &&
            (board[coor_height-1][coor_width+1] != '-' || board[coor_height-1][coor_width+2] != '-'))// 0x2
        {
            return 1;
        }
        return 0;
     }else if (coor_height == 0 && coor_width != 0)
     {
            if (board[coor_height][coor_width] != '-' &&
                (board[coor_height][coor_width-1] != '-' || board[coor_height+1][coor_width-1] != '-'))// 0x0
            {
                return 1;
            }
            if (board[coor_height+1][coor_width] != '-' &&
                    (board[coor_height+2][coor_width-1] != '-' || board[coor_height+1][coor_width-1] != '-' || board[coor_height][coor_width-1] != '-'))// 1x0
            {
                         return 1;
            }
            if (board[coor_height+2][coor_width] != '-' &&
                (board[coor_height+2][coor_width-1] != '-' || board[coor_height+1][coor_width-1] != '-'))// 2x0
            {
                         return 1;
            }
            return 0;
         }else if (coor_height != 0 && coor_width == 0)
         {
            if (board[coor_height][coor_width] != '-' &&
                (board[coor_height-1][coor_width] != '-' || board[coor_height-1][coor_width+1] != '-'))// 0x0
            {
                         return 1;
            }
            if (board[coor_height][coor_width+1] != '-' &&
                (board[coor_height-1][coor_width] != '-' || board[coor_height-1][coor_width+1] != '-' || board[coor_height-1][coor_width+2] != '-'))// 0x1
            {
                         return 1;
            }
            if (board[coor_height][coor_width+2] != '-' &&
                (board[coor_height-1][coor_width+1] != '-' || board[coor_height-1][coor_width+2] != '-'))// 0x2
            {
                         return 1;
            }
            return 0;
         }else
         {
             return 0;
         }

 }

