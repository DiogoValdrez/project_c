#include "modo_j0.h"

int j0(char board[15][24], int height, int width, char sqr[3][3], int pie_types[8], int modo_posicion)
{
    if(modo_posicion==1){
        p1(board, height, width, sqr, pie_types);
    }else if (modo_posicion==2){
        printf("modo posicionamento 2");
    }else{
        return EXIT_FAILURE;
    }  
    return EXIT_SUCCESS;
}