#include "modo_p2.h"

int p2(char board[15][24],int height,int width, char sqr[3][3], int pie_types[8])
{
    int help = 0;
    int restric03 = restric3(pie_types);
    int restric04 = restric4(height,width,pie_types);
    if (!(restric03 && restric04))
    {
        return EXIT_FAILURE;
    }
    int coor_height = 0, coor_width = 0;
    int id_piece = 0, id_var = 0;
    int rep_8 = 0, rep_1000 = 0;

    do
    {
        for(coor_height = 0; coor_height < height; coor_height += 3)
        {
            for(coor_width = 0;coor_width < width; coor_width += 3)
            {
                rep_8 = 0;
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
                    sqr_board(board, coor_height, coor_width, sqr);
                    if (restric01( board, coor_height, coor_width, width))
                    {
                            printf("%d\n", id_piece);
                            printf("%d\n", help);
                            help++;
                            if (help == 1500){
                                return EXIT_FAILURE;
                            }
                            break;
                    }
                    switch (id_piece)
                    {
                        case 1:
                            for (id_var = 1; id_var < 10; id_var++)
                            {
                                ctrl_Z(board,coor_height,coor_width);
                                del_sqr(sqr);
                                pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                                sqr_board(board, coor_height, coor_width, sqr);
                                if (restric01( board, coor_height, coor_width, width))
                                {
                                    break;
                                }
                            }
                            break;
                        case 2:
                            for (id_var = 1; id_var < 13; id_var++)
                            {
                                ctrl_Z(board,coor_height,coor_width);
                                del_sqr(sqr);
                                pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                                sqr_board(board, coor_height, coor_width, sqr);
                                if (restric01( board, coor_height, coor_width, width))
                                {
                                    break;
                                }
                            }
                            break;
                        case 3:
                            for (id_var = 1; id_var < 7; id_var++)
                            {
                                ctrl_Z(board,coor_height,coor_width);
                                del_sqr(sqr);
                                pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                                sqr_board(board, coor_height, coor_width, sqr);
                                if (restric01( board, coor_height, coor_width, width))
                                {
                                    break;
                                }
                            }
                            break;
                        case 4:
                        case 5:
                        case 6:
                            for (id_var = 1; id_var < 5; id_var++)
                            {
                                ctrl_Z(board,coor_height,coor_width);
                                del_sqr(sqr);
                                pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                                sqr_board(board, coor_height, coor_width, sqr);
                                if (restric01( board, coor_height, coor_width, width))
                                {
                                    break;
                                }
                            }
                            break;
                        case 7:
                            for (id_var = 1; id_var < 3; id_var++)
                            {
                                ctrl_Z(board,coor_height,coor_width);
                                del_sqr(sqr);
                                pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                                sqr_board(board, coor_height, coor_width, sqr);
                                if (restric01( board, coor_height, coor_width, width))
                                {
                                    break;
                                }
                            }
                            break;
                        default:
                            break;
                    }
                    rep_8 ++;
                }while(!(restric01( board, coor_height, coor_width, width)) && rep_8 <8);
                if (rep_8 == 8)
                {
                    break;
                }

            }
            if (rep_8 == 8)
            {
                break;
            }

        }
    if (rep_8==8)
    {
        rep_1000 ++;
        coor_width = 0;
        coor_height = 0;
    }
    if (rep_1000 == 1000)
    {
        return EXIT_FAILURE;
    }
    }while(!(restric01(board, coor_height, coor_width, width)));

    return EXIT_SUCCESS;
}

