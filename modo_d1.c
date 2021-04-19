#include "modo_d1.h"

int d1(char board[15][24], int height ,int width)
{
    srand((unsigned)time(NULL));
    char shot_board[15][24];
    char pieces_board_save[15][24];
    char pieces_board[15][24];
    int height_rand_coord;
    int width_rand_coord;
    int shot_and_board_equal = 0, piece_boards_equal = 0;
    int tries = 0;

    int i,j;
    for (i=0;i<height;i++)
    {
        for (j=0;j<width;j++)
        {
            pieces_board[i][j] = ' ';
            if (board[i][j] != '-' )
            {
                pieces_board_save[i][j] = board[i][j];
            }else
            {
                pieces_board_save[i][j] = ' ';
            }
        }
    }
    for (i=0;i<height;i++)
    {
        for (j=0;j<width;j++)
        {
            shot_board[i][j] = ' ';
        }
    }
    do
    {
        tries ++;
        do
        {
            height_rand_coord = rand()%height;
            width_rand_coord = rand()%width;
        }while(shot_board[height_rand_coord][width_rand_coord] != ' ');
        if (shot_board[height_rand_coord][width_rand_coord] == ' ')
        {
            shot_board[height_rand_coord][width_rand_coord] = board[height_rand_coord][width_rand_coord];
            if (board[height_rand_coord][width_rand_coord] != '-')
            {
                pieces_board[height_rand_coord][width_rand_coord] = board[height_rand_coord][width_rand_coord];
            }
        }
        shot_and_board_equal = 1;
        piece_boards_equal = 1;
        for (i=0;i<height;i++)
        {
            for (j=0;j<width;j++)
            {
                if (shot_board[i][j] != board[i][j])
                {
                    shot_and_board_equal = 0;
                }
                if (pieces_board[i][j] != pieces_board_save[i][j])
                {
                    piece_boards_equal = 0;
                }
            }
        }
    }while(!(piece_boards_equal)  && !(shot_and_board_equal));
    drawBoard(pieces_board,height, width);
    printf("Tries: %d", tries);
    return EXIT_SUCCESS;
}
