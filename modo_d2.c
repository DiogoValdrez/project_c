#include "modo_d2.h"

/** \brief Função que executa o modo de disparo 2. Dentro da cada matriz a função dispara por uma ordem especifica em que
 *         o primeiro disparo é a coordenada central da matriz. Dispara sobre todas as coordenadas da matriz
 *         ou até ter encotrado uma peça inteira. De seguida a função repete o mesmo processo para todas as
 *         matrizes 3x3 do tabuleiro, ou até ter encontrado todas as peças.
 *
 * \param height -> dimensão da altura do tabuleiro
 * \param width -> dimensão da larura do tabuleiro
 * \param pie_types -> a matriz pie_types, que representa o número de peças de cada tipo
 */

int d2(int height ,int width, int pie_types[8])
{
    int i, j, y;
    int init_coor_height = 0, init_coor_width = 0;
    int shot, piece, tries = 0;
    int remain, first_shot;
    int remaining_pie[8];
    char shot_board[15][24];
    char character, x;
    //Variaveis para calcular o tempo total do modo de disparo
    int tf, ti, dt;
    ti = (unsigned)time(NULL);
    //Colocar na matriz remaining_pie o numero total de quadriculas que tem cada tipo de peça
    for (i=0;i<8;i++)
    {
        remaining_pie[i] = pie_types[i] * (i+1);
    }
    //Inicializar a matriz de disparos shot_board com um espaco em cada coordenada
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            shot_board[i][j] = ' ';
        }
    }
    //for loop principal da função que irá assim passar por todas as matrizes
    //do tabuleiro pela ordem pré-definida
    for (init_coor_height = 1; init_coor_height < height; init_coor_height += 3)
    {
        for (init_coor_width = 1; init_coor_width < width; init_coor_width += 3)
        {
            piece = 9;
            remain = 0;
            first_shot = 0;
            //Verificar se ainda há peças por descobrir
            for (i=0;i<8;i++)
            {
                if (remaining_pie[i] != 0)
                {
                    remain = 1;
                }
            }
            //Se todas as peças ja tiverem sido encontradas
            if (remain == 0)
            {
                //Cálculo do tempo de jogo
                tf = (unsigned)time(NULL);
                dt = tf - ti;
                //Print do numero de jogadas e do tempo que demorou, bem como do tabuleiro de disparos
                printf("Fim de jogo: %d jogadas ", tries);
                printf("em %d segundos.", dt);
                drawBoard(shot_board, height, width);
                return EXIT_SUCCESS;
            }
            //1º Quadriicula da Matriz
            //Transformação de cordenadas
            x = init_coor_width + 'A';
            y = height - init_coor_height;
            //Disparo do computador
            printf("%c%d\n", x, y);
            //Resposta ao disparo do computador
            scanf(" %c", &character);
            shot_board[init_coor_height][init_coor_width] = character;
            tries ++;
            //Caso tenha acertado numa peça
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
            //Caso tenhamos chegado ao fim de uma peça
            if (piece == 0)
            {
                continue;
            }

            //2º Quadriicula da Matriz
            x = init_coor_width + 'A';
            y = height - (init_coor_height - 1);
            printf("%c%d\n", x, y);
            scanf(" %c", &character);
            shot_board[init_coor_height - 1][init_coor_width] = character;
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

            //3º Quadriicula da Matriz
            x = init_coor_width + 'A';
            y = height - (init_coor_height + 1);
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
                    piece = shot + 1;
                    first_shot = 1;
                }
                piece -= 1;
            }
            if (piece == 0)
            {
                continue;
            }

            //4º Quadriicula da Matriz
            x = (init_coor_width - 1) + 'A';
            y = height - (init_coor_height);
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

            //5º Quadriicula da Matriz
            x = (init_coor_width + 1) + 'A';
            y = height - (init_coor_height);
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
                    piece = shot + 1;
                    first_shot = 1;
                }
                piece -= 1;
            }
            if (piece == 0)
            {
                continue;
            }

            //6º Quadriicula da Matriz
            x = (init_coor_width - 1) + 'A';
            y = height - (init_coor_height - 1);
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
                    piece = shot + 1;
                    first_shot = 1;
                }
                piece -= 1;
            }
            if (piece == 0)
            {
                continue;
            }

            //7º Quadriicula da Matriz
            x = (init_coor_width + 1) + 'A';
            y = height - (init_coor_height + 1);
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

            //8º Quadriicula da Matriz
            x = (init_coor_width + 1) + 'A';
            y = height - (init_coor_height - 1);
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
            //9º
            x = (init_coor_width - 1) + 'A';
            y = height - (init_coor_height + 1);
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
    //Caso tenha chegado ao final do tabuleiro
    //Cálculo do tempo de jogo
    tf = (unsigned)time(NULL);
    dt = tf - ti;
    //Print do número de jogadas e do tempo que demorou, bem como do tabuleiro de disparos
    printf("Fim de jogo: %d jogadas ", tries);
    printf("em %d segundos.", dt);
    drawBoard(shot_board, height, width);
    return EXIT_SUCCESS;
}
