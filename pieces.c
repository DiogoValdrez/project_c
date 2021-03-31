#include "pieces.h"

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