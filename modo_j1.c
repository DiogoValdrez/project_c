#include "modo_j1.h"

int j1(char board[15][24], int height, int width, char sqr[3][3], int pie_types[8], int modo_posicion)
{
    char character;
    int y, x, i, num_blocks = 0, tries = 0, shooted = 0;
    if(modo_posicion==1){
        p1(board, height, width, sqr, pie_types);
    }else if (modo_posicion==2){
        printf("modo posicionamento 2");
    }else{
        return EXIT_FAILURE;
    }
    for(i = 0; i < 8; i++){
        num_blocks = num_blocks + (i+1)*pie_types[i];
    }
    printf("NUmber of blocks: %d", num_blocks);
    drawBoard(board, height, width);
    while(shooted < num_blocks){
        scanf(" %c%d", &character, &y);//fazer check se scanf esta bem com um if
        x = (int)character - 97;
        printf("%c\n", board[height-y][x]);
        if(board[height-y][x] != '-'){//resolver problema dos already shooted
            shooted ++;   
        }
        tries ++;
    }
    printf("Number of tries: %d", tries);
    return EXIT_SUCCESS;
}