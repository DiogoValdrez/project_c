#include "modo_j1.h"

int mj1(char board[15][24], int height, int width, char sqr[3][3], int pie_types[8], int modo_posicion)
{
    char character;
    int y, x, i, num_blocks = 0, tries = 0, shooted = 0;
    int ti, tf, dt;
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
    for(i = 0; i < 8; i++){
        num_blocks = num_blocks + (i+1)*pie_types[i];
    }
    ti = (unsigned)time(NULL);
    while(shooted < num_blocks){
        scanf(" %c%d", &character, &y);//fazer check se scanf esta bem com um if
        x = (int)character - 65;
        printf("%c\n", board[height-y][x]);
        if(board[height-y][x] != '-'){//resolver problema dos already shooted
            shooted ++;   
        }
        tries ++;
    }
    tf = (unsigned)time(NULL);
    dt = tf - ti;
    printf("Fim de jogo: %d jogadas em ", tries);
    printf("%d segundos", dt);
    return EXIT_SUCCESS;
}