#include <stdio.h>
#include <stdlib.h>

void init_board(char board[15][24], int height, int width);
void draw_board(char board[15][24], int height, int width);
int mult(int value);
void pecas(int id_peca,int id_variante,char board[15][24],int coor_height,int coor_width);

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
    board[0][0] = '1';
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

void pecas(int id_peca,int id_variante,char board[15][24],int coor_height,int coor_width)
{
    char peca_id1;
    switch (id_peca)
    {
        case 0:
            break;
        case 1:
            peca_id1 = '1';
            switch (id_variante)
            {
                case 1:
                    board[coor_height][coor_width] = peca_id1;
                    break;
                case 2:
                    board[coor_height][coor_width+1] = peca_id1;
                    break;
                case 3:
                    board[coor_height][coor_width+2] = peca_id1;
                    break;
                case 4:
                    board[coor_height+1][coor_width] = peca_id1;
                    break;
                case 5:
                    board[coor_height+1][coor_width+1] = peca_id1;
                    break;
                case 6:
                    board[coor_height+1][coor_width+2] = peca_id1;
                    break;
                case 7:
                    board[coor_height+2][coor_width] = peca_id1;
                    break;
                case 8:
                    board[coor_height+2][coor_width+1] = peca_id1;
                    break;
                case 9:
                    board[coor_height+2][coor_width+2] = peca_id1;
                    break;
                }
            break;
        case 2:
            peca_id1 = '2';
            switch (id_variante)
            {
                case 1:
                    board[coor_height][coor_width] = peca_id1;
                    board[coor_height][coor_width+1] = peca_id1;
                    break;
                case 2:
                    board[coor_height][coor_width+1] = peca_id1;
                    board[coor_height][coor_width+2] = peca_id1;
                    break;
                case 3:
                    board[coor_height+1][coor_width] = peca_id1;
                    board[coor_height+1][coor_width+1] = peca_id1;
                    break;
                case 4:
                    board[coor_height+1][coor_width+1] = peca_id1;
                    board[coor_height+1][coor_width+2] = peca_id1;
                    break;
                case 5:
                    board[coor_height+2][coor_width] = peca_id1;
                    board[coor_height+2][coor_width+1] = peca_id1;
                    break;
                case 6:
                    board[coor_height+2][coor_width+1] = peca_id1;
                    board[coor_height+2][coor_width+1] = peca_id1;
                    break;
                case 7:
                    board[coor_height][coor_width] = peca_id1;
                    board[coor_height+1][coor_width] = peca_id1;
                    break;
                case 8:
                    board[coor_height+1][coor_width] = peca_id1;
                    board[coor_height+2][coor_width] = peca_id1;
                    break;
                case 9:
                    board[coor_height][coor_width+1] = peca_id1;
                    board[coor_height+1][coor_width+1] = peca_id1;
                    break;
                case 10:
                    board[coor_height+1][coor_width+1] = peca_id1;
                    board[coor_height+2][coor_width+1] = peca_id1;
                    break;
                case 11:
                    board[coor_height][coor_width+2] = peca_id1;
                    board[coor_height+1][coor_width+2] = peca_id1;
                    break;
                case 12:
                    board[coor_height+1][coor_width+2] = peca_id1;
                    board[coor_height+1][coor_width+2] = peca_id1;
                    break;

            }
            break;
        case 3:
            peca_id1 = '3';
            switch(id_variante)
            {
                case 1:
                    board[coor_height][coor_width] = peca_id1;
                    board[coor_height][coor_width+1] = peca_id1;
                    board[coor_height][coor_width+2] = peca_id1;
                    break;
                case 2:
                    board[coor_height+1][coor_width] = peca_id1;
                    board[coor_height+1][coor_width+1] = peca_id1;
                    board[coor_height+1][coor_width+2] = peca_id1;
                    break;
                case 3:
                    board[coor_height+2][coor_width] = peca_id1;
                    board[coor_height+2][coor_width+1] = peca_id1;
                    board[coor_height+2][coor_width+2] = peca_id1;
                    break;
                case 4:
                    board[coor_height][coor_width] = peca_id1;
                    board[coor_height+1][coor_width] = peca_id1;
                    board[coor_height+2][coor_width] = peca_id1;
                    break;
                case 5:
                    board[coor_height][coor_width+1] = peca_id1;
                    board[coor_height+1][coor_width+1] = peca_id1;
                    board[coor_height+2][coor_width+1] = peca_id1;
                    break;
                case 6:
                    board[coor_height][coor_width+2] = peca_id1;
                    board[coor_height+1][coor_width+2] = peca_id1;
                    board[coor_height+2][coor_width+2] = peca_id1;
                    break;
            }
            break;
        case 4:
            peca_id1 = '4';
            switch(id_variante)
            {
                case 1:
                    board[coor_height][coor_width] = peca_id1;
                    board[coor_height][coor_width+1] = peca_id1;
                    board[coor_height+1][coor_width] = peca_id1;
                    board[coor_height+1][coor_width+1] = peca_id1;
                    break;
                case 2:
                    board[coor_height][coor_width+1] = peca_id1;
                    board[coor_height][coor_width+2] = peca_id1;
                    board[coor_height+1][coor_width+1] = peca_id1;
                    board[coor_height+1][coor_width+2] = peca_id1;
                    break;
                case 3:
                    board[coor_height+1][coor_width] = peca_id1;
                    board[coor_height+1][coor_width+1] = peca_id1;
                    board[coor_height+2][coor_width] = peca_id1;
                    board[coor_height+2][coor_width+1] = peca_id1;
                    break;
                case 4:
                    board[coor_height+1][coor_width+1] = peca_id1;
                    board[coor_height+1][coor_width+2] = peca_id1;
                    board[coor_height+2][coor_width+1] = peca_id1;
                    board[coor_height+2][coor_width+2] = peca_id1;
                    break;
            }
            break;
        case 5:
            peca_id1 = '5';
            switch(id_variante)
            {
                case 1:
                    board[coor_height][coor_width] = peca_id1;
                    board[coor_height][coor_width+1] = peca_id1;
                    board[coor_height][coor_width+2] = peca_id1;
                    board[coor_height+1][coor_width+1] = peca_id1;
                    board[coor_height+2][coor_width+1] = peca_id1;
                    break;
                case 2:
                    board[coor_height][coor_width] = peca_id1;
                    board[coor_height+1][coor_width] = peca_id1;
                    board[coor_height+2][coor_width] = peca_id1;
                    board[coor_height+1][coor_width+1] = peca_id1;
                    board[coor_height+1][coor_width+2] = peca_id1;
                    break;
                case 3:
                    board[coor_height+2][coor_width] = peca_id1;
                    board[coor_height+2][coor_width+1] = peca_id1;
                    board[coor_height+2][coor_width+2] = peca_id1;
                    board[coor_height][coor_width+1] = peca_id1;
                    board[coor_height+1][coor_width+1] = peca_id1;
                    break;
                case 4:
                    board[coor_height][coor_width+2] = peca_id1;
                    board[coor_height+1][coor_width+2] = peca_id1;
                    board[coor_height+2][coor_width+2] = peca_id1;
                    board[coor_height+1][coor_width] = peca_id1;
                    board[coor_height+1][coor_width+1] = peca_id1;
                    break;
            }
            break;
        case 6:
            peca_id1 = '6';
            switch(id_variante)
            {
                case 1:
                    board[coor_height][coor_width+1] = peca_id1;
                    board[coor_height+1][coor_width] = peca_id1;
                    board[coor_height+2][coor_width] = peca_id1;
                    board[coor_height+2][coor_width+1] = peca_id1;
                    board[coor_height+2][coor_width+2] = peca_id1;
                    board[coor_height+1][coor_width+2] = peca_id1;
                    break;
                case 2:
                    board[coor_height+1][coor_width] = peca_id1;
                    board[coor_height][coor_width+1] = peca_id1;
                    board[coor_height][coor_width+2] = peca_id1;
                    board[coor_height+1][coor_width+2] = peca_id1;
                    board[coor_height+2][coor_width+2] = peca_id1;
                    board[coor_height+2][coor_width+1] = peca_id1;
                    break;
                case 3:
                    board[coor_height+2][coor_width+1] = peca_id1;
                    board[coor_height+1][coor_width] = peca_id1;
                    board[coor_height][coor_width] = peca_id1;
                    board[coor_height][coor_width+1] = peca_id1;
                    board[coor_height][coor_width+2] = peca_id1;
                    board[coor_height+1][coor_width+2] = peca_id1;
                    break;
                case 4:
                    board[coor_height+1][coor_width+2] = peca_id1;
                    board[coor_height][coor_width+1] = peca_id1;
                    board[coor_height][coor_width] = peca_id1;
                    board[coor_height+1][coor_width] = peca_id1;
                    board[coor_height+2][coor_width] = peca_id1;
                    board[coor_height+2][coor_width+1] = peca_id1;
                    break;
            }
            break;
        case 7:
            peca_id1 = '7';
            switch(id_variante)
            {
                case 1:
                    board[coor_height][coor_width] = peca_id1;
                    board[coor_height+1][coor_width] = peca_id1;
                    board[coor_height+2][coor_width] = peca_id1;
                    board[coor_height][coor_width+2] = peca_id1;
                    board[coor_height+1][coor_width+2] = peca_id1;
                    board[coor_height+2][coor_width+2] = peca_id1;
                    board[coor_height+1][coor_width+1] = peca_id1;
                    break;
                case 2:
                    board[coor_height][coor_width] = peca_id1;
                    board[coor_height][coor_width+1] = peca_id1;
                    board[coor_height][coor_width+2] = peca_id1;
                    board[coor_height+2][coor_width] = peca_id1;
                    board[coor_height+2][coor_width+1] = peca_id1;
                    board[coor_height+2][coor_width+2] = peca_id1;
                    board[coor_height+1][coor_width+1] = peca_id1;
                    break;
            }
            break;
        case 8:
            peca_id1 = '8';
            board[coor_height][coor_width] = peca_id1;
            board[coor_height][coor_width+1] = peca_id1;
            board[coor_height][coor_width+2] = peca_id1;
            board[coor_height+1][coor_width] = peca_id1;
            board[coor_height+1][coor_width+2] = peca_id1;
            board[coor_height+2][coor_width] = peca_id1;
            board[coor_height+2][coor_width+1] = peca_id1;
            board[coor_height+2][coor_width+2] = peca_id1;

            break;
        default:
            EXIT_FAILURE;

    }
    return;
}




