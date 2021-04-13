#include "modo_p2.h"

int p2(char board[15][24],int height,int width, char sqr[3][3], int pie_types[8])
    {
        int restric3 = restric3(pie_types);
        int restric4 = restric4(int height, int width, int pie_types);
        if (!(restric3 && restric4))
        {
            return EXIT_FAILURE;
        }
        int coor_height = 0, coor_width = 0;

        for(coor_height = 0; coor_height < height; coor_height += 3)
        {
            printf("\n\n ||new line %d||\n", coor_height);
            for(coor_width = 0;coor_width < width; coor_width += 3)
            {
        }
