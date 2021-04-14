#include "modo_p2.h"

int p2(char board[15][24],int height,int width, char sqr[3][3], int pie_types[8])
{
    int restric03 = restric3(pie_types);
    int restric04 = restric4(height,width,pie_types);
    if (!(restric03 && restric04))
    {
        return EXIT_FAILURE;
    }
    int coor_height = 0, coor_width = 0;
    int id_piece = 0, id_var = 0;

    for(coor_height = 0; coor_height < height; coor_height += 3)
    {
        printf("\n\n ||new line %d||\n", coor_height);
        for(coor_width = 0;coor_width < width; coor_width += 3)
        {
            do
            {
                ctrl_Z(board,coor_height,coor_width);
                del_sqr(sqr);
                id_piece = choose_piece(pie_types);
                if (id_piece != 0)
                {
                    id_var = choose_rand_variant(id_piece);
                }
                pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                if (!(restric01(char board[15][24], int coor_height,int coor_width, int width))
                {
                    do
                    {
                        switch(id_piece)
                        {
                            case
                        }

                    }while(!(restric01(char board[15][24], int coor_height,int coor_width, int width)));
                }

            }while();
        }
    }
}
