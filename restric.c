#include "restric.h"

/*Function that checks whether the piece that was put in the board
can be there considering the restrictions returning a 0 in case
 it's well positioned and any other number in case it shouldn't be there*/
int restric01(char board[15][24], int coor_height,int coor_width)
{
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

//Function to check restrict 2
int restric2(int height, int width)
{
    int max_pieces = (height * width)/9;
    return max_pieces;
}