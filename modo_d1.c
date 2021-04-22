#include "modo_d1.h"

int d1(int height ,int width,int pie_types[8])
{
    srand((unsigned)time(NULL));
    char shot_board[15][24];
    int remaining_pie[8];
    int height_rand_coord;
    int width_rand_coord;
    int tries = 0;
    int i, j, y, shot, remain = 0;
    char x, character;
    int tf, ti, dt;
    ti = (unsigned)time(NULL);
    for (i=0;i<height;i++)
    {
        for (j=0;j<width;j++)
        {
            shot_board[i][j] = ' ';
        }
    }
    for (i=0;i<8;i++)
    {
        remaining_pie[i] = pie_types[i] * (i+1);
    }

    do
    {
        remain = 0;

        tries ++;
        do
        {
            height_rand_coord = rand()%height;
            width_rand_coord = rand()%width;
        }while(shot_board[height_rand_coord][width_rand_coord] != ' ');
        x = width_rand_coord + 'A';
        y = height - height_rand_coord;
        printf("%c%d\n", x, y);
        scanf(" %c", &character);
        if (character != '-')
        {
            shot = (int)character - 49;
            remaining_pie[shot] -= 1;
        }
        for (i=0;i<8;i++)
        {
            if (remaining_pie[i] != 0)
            {
                remain = 1;
            }
        }
        shot_board[height_rand_coord][width_rand_coord] = character;
    }while(remain && (tries <= height*width));
    tf = (unsigned)time(NULL);
    dt = tf - ti;
    printf("Fim de jogo: %d jogadas ", tries);
    printf("em %d segundos.", dt);
    drawBoard(shot_board, height, width);
    return EXIT_SUCCESS;
}
