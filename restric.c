#include "restric.h"

/*Function that checks whether the piece that was put in the board
can be there considering the restrictions returning a 0 in case
 it's well positioned and any other number in case it shouldn't be there*/
int restric01(char board[15][24], int coor_height,int coor_width, int width)
{
    if (!(coor_height == 0 || coor_width == 0) )
    {
        if (board[coor_height][coor_width] != '-' &&
            (board[coor_height+1][coor_width-1] != '-' || board[coor_height][coor_width-1] != '-'|| board[coor_height-1][coor_width-1] != '-' || board[coor_height-1][coor_width] != '-' ||board[coor_height-1][coor_width +1] != '-'))// 0x0
        {
            return 0;
        }
        if (board[coor_height+1][coor_width] != '-' &&
            (board[coor_height+2][coor_width-1] != '-' || board[coor_height+1][coor_width-1] != '-' || board[coor_height][coor_width-1] != '-'))// 1x0
        {
            return 0;
        }
        if (board[coor_height+2][coor_width] != '-' &&
            (board[coor_height+2][coor_width-1] != '-' || board[coor_height+1][coor_width-1] != '-'))// 2x0
        {
            return 0;
        }
        if (board[coor_height][coor_width+1] != '-' &&
                (board[coor_height-1][coor_width] != '-' || board[coor_height-1][coor_width+1] != '-' || board[coor_height-1][coor_width+2] != '-'))// 0x1
        {
            return 0;
        }
        if (board[coor_height][coor_width+2] != '-' && ((coor_width+2) != width - 1) &&
            (board[coor_height-1][coor_width+1] != '-' || board[coor_height-1][coor_width+2] != '-' || board[coor_height-1][coor_width+3] != '-'))// 0x2
        {
            return 0;
        }
        if (board[coor_height][coor_width+2] != '-' && ((coor_width+2) == width-1) &&
            (board[coor_height-1][coor_width+1] != '-' || board[coor_height-1][coor_width+2] != '-' ))// 0x2
        {
            return 0;
        }

        return 1;
    }else if (coor_height == 0 && coor_width != 0)
    {
        if (board[coor_height][coor_width] != '-' &&
            (board[coor_height][coor_width-1] != '-' || board[coor_height+1][coor_width-1] != '-'))// 0x0
        {
            return 0;
        }
        if (board[coor_height+1][coor_width] != '-' &&
                (board[coor_height+2][coor_width-1] != '-' || board[coor_height+1][coor_width-1] != '-' || board[coor_height][coor_width-1] != '-'))// 1x0
        {
            return 0;
        }
        if (board[coor_height+2][coor_width] != '-' &&
            (board[coor_height+2][coor_width-1] != '-' || board[coor_height+1][coor_width-1] != '-'))// 2x0
        {
            return 0;
        }
        return 1;
        }else if (coor_height != 0 && coor_width == 0)
        {
        if (board[coor_height][coor_width] != '-' &&
            (board[coor_height-1][coor_width] != '-' || board[coor_height-1][coor_width+1] != '-'))// 0x0
        {
                        return 0;
        }
        if (board[coor_height][coor_width+1] != '-' &&
            (board[coor_height-1][coor_width] != '-' || board[coor_height-1][coor_width+1] != '-' || board[coor_height-1][coor_width+2] != '-'))// 0x1
        {
                        return 0;
        }
        if (board[coor_height][coor_width+2] != '-' &&
            (board[coor_height-1][coor_width+1] != '-' || board[coor_height-1][coor_width+2] != '-' || board[coor_height-1][coor_width+3] != '-'))// 0x2
        {
                        return 0;
        }
            return 1;
        }else
        {
            return 1;
        }
}

//Function to check restrict 2
int restric2(int height, int width)
{
    int max_pieces = (height * width)/9;
    return max_pieces;
}

int restric3(pie_types[8])
{
    int i;
    for (i=1;i<8;i++)
        {
            if (pie_types[i]>pie_types[i-1])
            {
                return 0;
            }
        }
    return 1;
}

int restric4(int height, int width, int pie_types[8])
{
    int i, max_pieces,n_pieces = 0;

    for (i=0;i<8;i++)
    {
        n_pieces = n_pieces + pie_types[i];
    }
    max_pieces = (height * width / 9) / 2;
    if (n_pieces <= max_pieces)
    {
        return 1;
    }else
    {
        return 0;
    }

}
