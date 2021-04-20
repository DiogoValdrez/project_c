#include "modo_j2.h"

int mj2(char board[15][24], int height, int width, int pie_types[8], int modo_shot)
{
    if(modo_shot==1){
        d1(board, height, width);
    }else if (modo_shot==2){
        d2(board, height, width);
    }else if (modo_shot==2){
        d3(board, height, width);
    }else{
        return EXIT_FAILURE;
    }  
    return EXIT_SUCCESS;
}