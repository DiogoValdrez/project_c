#include "modo_d3.h"

int d3(int height ,int width, int pie_types[8])
{
    int i,j;
    int init_coor_height = 0;
    int init_coor_width = 0;
    int y;
    char shot_board[15][24];
    int shot, piece, tries = 0;
    char character, x;
    int remain, first_shot;
    int remaining_pie[8];
    int tf, ti, dt;
    ti = (unsigned)time(NULL);
    int xpto = 0;
    int temp_height, temp_width;
    for (i=0;i<8;i++)
    {
        remaining_pie[i] = pie_types[i] * (i+1);
    }
    for (i=0;i<height;i++)
    {
        for (j=0;j<width;j++)
        {
           shot_board[i][j] = ' ';
        }
    }
    for (init_coor_height=1;init_coor_height<height; init_coor_height+=3)
    {
        for (init_coor_width=1;init_coor_width<width; init_coor_width+=3)
        {
            if (xpto)
            {
                for (i=0;i<3;i++)
                {
                    for (j=0;j<3;j++)
                    {
                        if (shot_board[temp_height + i][temp_width + j] == character)
                        {
                            if (shot_board[temp_height + i + 1][temp_width + j] == ' ' && temp_height + i + 1 < height)
                            {
                                shot_board[temp_height + i + 1][temp_width + j] = 'x';
                            }
                            if (shot_board[temp_height + i ][temp_width + j + 1] == ' ' && temp_width + i + 1 < width)
                            {
                                shot_board[temp_height + i][temp_width + j + 1] = 'x';
                            }
                            if (shot_board[temp_height + i + 1][temp_width + j + 1] == ' ' && temp_height + i + 1 < height && temp_width + i + 1 < width)
                            {
                                shot_board[temp_height + i + 1][temp_width + j + 1] = 'x';
                            }
                            if (shot_board[temp_height + i - 1][temp_width + j - 1] == ' ' && temp_height + i - 1 >= 0 && temp_width + j - 1 >= 0)
                            {
                                shot_board[temp_height + i - 1][temp_width + j - 1] = 'x';
                            }
                            if (shot_board[temp_height + i ][temp_width + j - 1] == ' ' && temp_width + j - 1 >= 0 )
                            {
                                shot_board[temp_height + i][temp_width + j - 1] = 'x';
                            }
                            if (shot_board[temp_height + i - 1][temp_width + j] == ' ' && temp_height + i - 1 >= 0)
                            {
                                shot_board[temp_height + i - 1][temp_width + j] = 'x';
                            }
                            if (shot_board[temp_height + i -1][temp_width + j + 1] == ' ' && temp_height + i - 1 >= 0 && temp_width + i + 1 < width)
                            {
                                shot_board[temp_height + i - 1][temp_width + j + 1] = 'x';
                            }
                            if (shot_board[temp_height + i + 1][temp_width + j - 1] == ' ' && temp_height + i + 1 < height && temp_width + j - 1 >= 0)
                            {
                                shot_board[temp_height + i + 1][temp_width + j - 1] = 'x';
                            }
                        }
                    }
                }
            }
            temp_width = init_coor_width - 1;
            temp_height = init_coor_height -1;
            xpto = 1;
            piece = 9;
            remain = 0;
            first_shot = 0;
            for (i=0;i<8;i++)
            {
                if (remaining_pie[i] != 0)
                {
                    remain = 1;
                }
            }
            if (remain == 0)
            {
                tf = (unsigned)time(NULL);
                dt = tf - ti;
                printf("Fim de jogo: %d jogadas ", tries);
                printf("em %d segundos.", dt);
                drawBoard(shot_board, height, width);
                return EXIT_SUCCESS;
            }
            //1º
            x = init_coor_width + 'A';
            y = height - init_coor_height;
            if (shot_board[init_coor_height][init_coor_width] != 'x')
            {
                printf("%c%d\n", x, y);
                scanf(" %c", &character);
                shot_board[init_coor_height][init_coor_width] = character;
                tries ++;
                if (character != '-')
                {
                    shot = (int)character - 49;
                    remaining_pie[shot] -= 1;
                    if (piece != shot && first_shot == 0)
                    {
                        piece = shot+1 ;
                        first_shot = 1;

                    }
                    piece -= 1;
                }
                if (piece == 0)
                {
                    continue;
                }
            }
            //2º
            x = init_coor_width + 'A';
            y = height - (init_coor_height - 1);
            if (shot_board[init_coor_height - 1 ][init_coor_width] != 'x')
            {
                printf("%c%d\n", x, y);
                scanf(" %c", &character);
                shot_board[init_coor_height-1][init_coor_width] = character;
                tries ++;
                if (character != '-')
                {
                    shot = (int)character - 49;
                    remaining_pie[shot] -= 1;
                    if (piece != shot && first_shot == 0)
                    {
                        piece = shot+1 ;
                        first_shot = 1;

                    }
                    piece -= 1;
                }
                if (piece == 0)
                {
                    continue;
                }
            }
            //3º
            x = init_coor_width + 'A';
            y = height - (init_coor_height + 1);
            if (shot_board[init_coor_height + 1][init_coor_width] != 'x')
            {
                printf("%c%d\n", x, y);
                scanf(" %c", &character);
                shot_board[init_coor_height + 1][init_coor_width] = character;
                tries ++;
                if (character != '-')
                {
                    shot = (int)character - 49;
                    remaining_pie[shot] -= 1;
                    if (piece != shot && first_shot == 0)
                    {
                        piece = shot +1;
                        first_shot = 1;

                    }
                    piece -= 1;
                }
                if (piece == 0)
                {
                    continue;
                }
            }
            //4º
            x = (init_coor_width - 1) + 'A';
            y = height - (init_coor_height);
            if (shot_board[init_coor_height][init_coor_width - 1] != 'x')
            {
                printf("%c%d\n", x, y);
                scanf(" %c", &character);
                shot_board[init_coor_height][init_coor_width - 1] = character;
                tries ++;
                if (character != '-')
                {
                    shot = (int)character - 49;
                    remaining_pie[shot] -= 1;
                    if (piece != shot && first_shot == 0)
                    {
                        piece = shot+ 1 ;
                        first_shot = 1;
                    }
                    piece -= 1;
                }
                if (piece == 0)
                {
                    continue;
                }
            }
            //5º
            x = (init_coor_width + 1) + 'A';
            y = height - (init_coor_height);
            if (shot_board[init_coor_height][init_coor_width + 1] != 'x')
            {
                printf("%c%d\n", x, y);
                scanf(" %c", &character);
                shot_board[init_coor_height][init_coor_width + 1] = character;
                tries ++;
                if (character != '-')
                {
                    shot = (int)character - 49;
                    remaining_pie[shot] -= 1;
                    if (piece != shot && first_shot == 0)
                    {
                        piece = shot  +1;
                        first_shot = 1;
                    }
                    piece -= 1;
                }
                if (piece == 0)
                {
                    continue;
                }
            }
            //6º
            x = (init_coor_width - 1) + 'A';
            y = height - (init_coor_height - 1);
            if (shot_board[init_coor_height - 1][init_coor_width - 1] != 'x')
            {
                printf("%c%d\n", x, y);
                scanf(" %c", &character);
                shot_board[init_coor_height - 1][init_coor_width - 1] = character;
                tries ++;
                if (character != '-')
                {
                    shot = (int)character - 49;
                    remaining_pie[shot] -= 1;
                    if (piece != shot && first_shot == 0)
                    {
                        piece = shot  + 1;
                        first_shot = 1;
                    }
                    piece -= 1;
                }
                if (piece == 0)
                {
                    continue;
                }
            }
            //7º
            x = (init_coor_width + 1) + 'A';
            y = height - (init_coor_height + 1);
            if (shot_board[init_coor_height + 1][init_coor_width + 1] != 'x')
            {
                printf("%c%d\n", x, y);
                scanf(" %c", &character);
                shot_board[init_coor_height + 1][init_coor_width + 1] = character;
                tries ++;
                if (character != '-')
                {
                    shot = (int)character - 49;
                    remaining_pie[shot] -= 1;
                    if (piece != shot && first_shot == 0)
                    {
                        piece = shot + 1;
                        first_shot = 1;
                    }
                    piece -= 1;
                }
                if (piece == 0)
                {
                    continue;
                }
            }
            //8º
            x = (init_coor_width + 1) + 'A';
            y = height - (init_coor_height - 1);
            if (shot_board[init_coor_height - 1][init_coor_width + 1] != 'x')
            {
                printf("%c%d\n", x, y);
                scanf(" %c", &character);
                shot_board[init_coor_height - 1][init_coor_width + 1] = character;
                tries ++;
                if (character != '-')
                {
                    shot = (int)character - 49;
                    remaining_pie[shot] -= 1;
                    if (piece != shot && first_shot == 0)
                    {
                        piece = shot + 1 ;
                        first_shot = 1;
                    }
                    piece -= 1;
                }
                if (piece == 0)
                {
                    continue;
                }
            }
            //9º
            x = (init_coor_width - 1) + 'A';
            y = height - (init_coor_height + 1);
            if (shot_board[init_coor_height + 1][init_coor_width - 1] != 'x')
            {
                printf("%c%d\n", x, y);
                scanf(" %c", &character);
                shot_board[init_coor_height + 1][init_coor_width - 1] = character;
                tries ++;
                if (character != '-')
                {
                    shot = (int)character - 49;
                    remaining_pie[shot] -= 1;
                    if (piece != shot && first_shot == 0)
                    {
                        piece = shot + 1;
                        first_shot = 1;
                    }

                    piece -= 1;
                }
                if (piece == 0)
                {
                    continue;
                }
            }

        }
    }
    tf = (unsigned)time(NULL);
    dt = tf - ti;
    printf("Fim de jogo: %d jogadas ", tries);
    printf("em %d segundos.", dt);
    drawBoard(shot_board, height, width);
    return EXIT_SUCCESS;
}

