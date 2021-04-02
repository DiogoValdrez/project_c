#include "modo_p1.h"

int p1(char board[15][24],int height,int width, char sqr[3][3]){
    int coor_height = 0;
    int coor_width = 0;
    int id_var; 
    int rep = 0;
    int num_pieces = 0;
    srand((unsigned)time(NULL));

    for(int j = 0; j < height; j += 3){
        for(int i = 0;i < width; i += 3){
            if(num_pieces < restric2(height, width)){
                do{
                    ctrl_Z(board,coor_height,coor_width);
                    del_sqr(sqr);
                    int id_piece = rand()%9;
                    switch(id_piece)
                    {
                        case 0:
                            id_var =  0;
                            break;
                        case 1:
                            id_var = rand()%8 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case 2:
                            id_var = rand()%11 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case 3:
                            id_var = rand()%5 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case 4:
                            id_var = rand()%3 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case 5:
                            id_var = rand()%3 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case 6:
                            id_var = rand()%3 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case 7:
                            id_var = rand()%1 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case 8:
                            id_var = 0;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break; 
                        default:
                            return EXIT_FAILURE;  

                    }
                    sqr_board(board, coor_height, coor_width, sqr);
                    rep++;
                }while(!(restric01(board, coor_height, coor_width)) || rep < 3);
                num_pieces++;
            }else{
                return num_pieces;
            }
        }
    }
    return num_pieces;
}