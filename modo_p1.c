#include "modo_p1.h"


int p1(char board[15][24],int height,int width, char sqr[3][3], int pie_types[8])
{
    int coor_height;
    int coor_width;
    int id_var;
    int rep;
    int num_pieces = 0;
    char id_piece;
    srand((unsigned)time(NULL));

    
    for(coor_height = 0; coor_height < height; coor_height += 3)
    {
        printf("\n\n ||new line %d||\n", coor_height);
        for(coor_width = 0;coor_width < width; coor_width += 3)
        {
            printf("\n new colum %d\n", coor_width);
            if(num_pieces < restric2(height, width))
            {
                rep = 0;
                do
                {
                    ctrl_Z(board,coor_height,coor_width);
                    del_sqr(sqr);
                    id_piece = rand()%9 + '0';
                    printf("|%c", id_piece);
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
                            id_var = 0;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        default:
                            return EXIT_FAILURE;

                    }
                    sqr_board(board, coor_height, coor_width, sqr);
                    rep+=1;
                    printf("(%d/",!(restric01(board, coor_height, coor_width, width)));
                    printf("%d)", rep);
                }while(!(restric01(board, coor_height, coor_width, width)) && (rep < 3));
                if((rep == 3) && !(restric01(board, coor_height, coor_width, width))){
                    id_piece = '1';
                    id_var = 5;
                    ctrl_Z(board,coor_height,coor_width);
                    del_sqr(sqr);
                    pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                    sqr_board(board, coor_height, coor_width, sqr);
                }
                if(id_piece != '0'){
                    pie_types[(int)id_piece-49] += 1;
                }
                num_pieces+=1;
            }else{
                return EXIT_SUCCESS;
            }
        }
    }
    return EXIT_SUCCESS;
}
