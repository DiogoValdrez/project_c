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
    char id_piece;
    int id_var = 0;
    int rep_8 = 0, rep_1000 = 0;
    srand((unsigned)time(NULL));
    int pie_types_save [8] ;
    int l, i;
    for (l=0;l<8;l++)
    {
        pie_types_save[l] = pie_types[l];
    }
    int pie_types_tested[8] = {0,0,0,0,0,0,0,0};

    do
    {
        initBoard(board, height, width);
        for (l=0;l<8;l++)
        {
        pie_types[l] = pie_types_save[l];
        }
        for(coor_height = 0; coor_height < height; coor_height += 3)
        {
            for(coor_width = 0;coor_width < width; coor_width += 3)
            {
                rep_8 = 0;
                ctrl_Z(board,coor_height,coor_width);
                del_sqr(sqr);
                for (l=0;l<8;l++)
                {
                    pie_types_tested[l] = 0;
                }

                do
                {
                    ctrl_Z(board,coor_height,coor_width);
                    del_sqr(sqr);
                    do
                    {
                        id_piece = rand()%9 + '0';
                        if (id_piece == '0')
                        {
                            break;
                        }
                    }while(pie_types[id_piece - '0'- 1] == 0 || pie_types_tested[id_piece - '0'- 1] != 0);

                    switch(id_piece)
                    {
                        case '0':
                            id_var =  0;
                            break;
                        case '1':
                            id_var = rand()%9 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case '2':
                            id_var = rand()%12 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case '3':
                            id_var = rand()%6 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case '4':
                            id_var = rand()%4 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case '5':
                            id_var = rand()%4 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case '6':
                            id_var = rand()%4 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case '7':
                            id_var = rand()%2 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case '8':
                            id_var = 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        default:
                            return EXIT_FAILURE;

                    }
                    sqr_board(board, coor_height, coor_width, sqr);
                    if (!(restric01( board, coor_height, coor_width, width)))
                    {

                        switch (id_piece)
                        {
                            case '1':
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
                            case '2':
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
                            case '3':
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
                            case '4':
                                for (id_var = 1; id_var < 5; id_var++)
                                {
                                    ctrl_Z(board,coor_height,coor_width);
                                    del_sqr(sqr);
                                    pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                                    sqr_board(board, coor_height, coor_width, sqr);
                                    if (restric01( board, coor_height, coor_width, width))
                                    {
                                        printf("%c %d\n", id_piece, id_var);
                                        break;
                                    }
                                }
                                break;
                            case '5':
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
                            case '6':
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
                            case '7':
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

                        if (!(restric01( board, coor_height, coor_width, width)) && rep_8 <8)
                        {
                            rep_8 = rep_8 + 1;
                            pie_types_tested [id_piece - '0'- 1] ++;
                        }
                    }
                }while(!(restric01( board, coor_height, coor_width, width)) && rep_8 <8);

                if(restric01( board, coor_height, coor_width, width))
                {
                    pie_types[id_piece - '0'- 1] --;
                }
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
        initBoard(board, height, width);

    }
    if (rep_1000 == 1000)
    {
        return EXIT_FAILURE;
    }
    }while(rep_8 == 8 && rep_1000<1000);
    for(i= 0; i < 8; i++){
        pie_types[i] = pie_types_save[i];
    }

    return EXIT_SUCCESS;
}

