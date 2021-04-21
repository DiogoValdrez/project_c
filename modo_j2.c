#include "modo_j2.h"

int mj2(int height, int width, int modo_shot, int pie_types[8])
{
    if(modo_shot==1){
        d1( height, width, pie_types);
    }else if (modo_shot==2){
        d2( height, width, pie_types);
    }else if (modo_shot==2){
        //d3(board, height, width);
        return 1;
    }else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
