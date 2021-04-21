#include "modo_j0.h"

int mj0(char board[15][24], int height, int width, char sqr[3][3], int pie_types[8], int modo_posicion)
{
    int i;
    if(modo_posicion==1){
        p1(board, height, width, sqr, pie_types);
    }else if (modo_posicion==2){
        for(i = 0; i < 8; i++){
            printf(" %d", pie_types[i]);
        }
        printf("\n");
        p2(board, height, width, sqr, pie_types);
    }else{
        return EXIT_FAILURE;
    }  
    return EXIT_SUCCESS;
}