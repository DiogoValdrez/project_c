#include "restric.h"

/** \brief Função que verifica se uma peça que foi posta no tabuleiro pode ou não estar lá
 *         de acordo com as restrições 0 e 1
 *
 * \param board[15][24] char -> matriz onde está o tabuleiro
 * \param coor_height int -> coordenada da altura no canto superior esquerdo de cada quadricula 3x3
 * \param coor_width int -> coordenada da largura no canto superior esquerdo de cada quadricula 3x3
 * \param width int -> largura do tabuleiro
 * \return int -> retorna 1 caso as restrições sejam cumpridas, 0 em caso contrário
 *
 */
int restric01(char board[15][24], int coor_height,int coor_width, int width)
{
    // Quadricula da peça fora das margens do tabuleiro
    if (!(coor_height == 0 || coor_width == 0) )
    {
        if (board[coor_height][coor_width] != '-' &&
            (board[coor_height+1][coor_width-1] != '-' || board[coor_height][coor_width-1] != '-'|| board[coor_height-1][coor_width-1] != '-' || board[coor_height-1][coor_width] != '-' ||board[coor_height-1][coor_width +1] != '-'))// 0x0
        {
            return 0;
        }
        if (board[coor_height+1][coor_width] != '-' &&
            (board[coor_height+2][coor_width-1] != '-' || board[coor_height+1][coor_width-1] != '-' || board[coor_height][coor_width-1] != '-'))// 1x0
        {
            return 0;
        }
        if (board[coor_height+2][coor_width] != '-' &&
            (board[coor_height+2][coor_width-1] != '-' || board[coor_height+1][coor_width-1] != '-'))// 2x0
        {
            return 0;
        }
        if (board[coor_height][coor_width+1] != '-' &&
                (board[coor_height-1][coor_width] != '-' || board[coor_height-1][coor_width+1] != '-' || board[coor_height-1][coor_width+2] != '-'))// 0x1
        {
            return 0;
        }
        if (board[coor_height][coor_width+2] != '-' && ((coor_width+2) != width - 1) &&
            (board[coor_height-1][coor_width+1] != '-' || board[coor_height-1][coor_width+2] != '-' || board[coor_height-1][coor_width+3] != '-'))// 0x2
        {
            return 0;
        }
        if (board[coor_height][coor_width+2] != '-' && ((coor_width+2) == width-1) &&
            (board[coor_height-1][coor_width+1] != '-' || board[coor_height-1][coor_width+2] != '-' ))// 0x2
        {
            return 0;
        }

        return 1;
    // Quadricula da peça no topo do tabuleiro(mas não nos cantos)
    }else if (coor_height == 0 && coor_width != 0)
    {
        if (board[coor_height][coor_width] != '-' &&
            (board[coor_height][coor_width-1] != '-' || board[coor_height+1][coor_width-1] != '-'))// 0x0
        {
            return 0;
        }
        if (board[coor_height+1][coor_width] != '-' &&
                (board[coor_height+2][coor_width-1] != '-' || board[coor_height+1][coor_width-1] != '-' || board[coor_height][coor_width-1] != '-'))// 1x0
        {
            return 0;
        }
        if (board[coor_height+2][coor_width] != '-' &&
            (board[coor_height+2][coor_width-1] != '-' || board[coor_height+1][coor_width-1] != '-'))// 2x0
        {
            return 0;
        }
        return 1;
        }else if (coor_height != 0 && coor_width == 0)
        {
        if (board[coor_height][coor_width] != '-' &&
            (board[coor_height-1][coor_width] != '-' || board[coor_height-1][coor_width+1] != '-'))// 0x0
        {
                        return 0;
        }
        if (board[coor_height][coor_width+1] != '-' &&
            (board[coor_height-1][coor_width] != '-' || board[coor_height-1][coor_width+1] != '-' || board[coor_height-1][coor_width+2] != '-'))// 0x1
        {
                        return 0;
        }
        if (board[coor_height][coor_width+2] != '-' &&
            (board[coor_height-1][coor_width+1] != '-' || board[coor_height-1][coor_width+2] != '-' || board[coor_height-1][coor_width+3] != '-'))// 0x2
        {
                        return 0;
        }
            return 1;
        }else
        {
            return 1;
        }
}


/** \brief Função que verifica a restrição 2
 *
 * \param height int -> altura do tabuleiro
 * \param width int -> largura do tabuleiro
 * \return int -> numero máximo de peças
 *
 */
int restric2(int height, int width)
{
    int max_pieces = (height * width)/9;
    return max_pieces;
}

/** \brief Função que verifica se se o número de peças pode ser o intruduzido,
 *         de acordo com a restrição 3, colocando -1 no terminal e terminando o programa.
 *
 * \param pie_types[8] int -> matriz com o numero de peças de cada tipo
 * \return int -> é retornado 1 caso a restrição seja cumprida
 */
int restric3(int pie_types[8])
{
    int i;
    for (i=1;i<8;i++)
        {
            if (pie_types[i]>pie_types[i-1])
            {
                printf("-1\n");
                exit(0);
            }
        }
    return 1;
}

/** \brief Função que verifica se se o número de peças pode ser o intruduzido,
 *         de acordo com a restrição 4, colocando -1 no terminal e terminando o programa.
 *
 * \param height int -> altura do tabuleiro
 * \param width int -> largura do tabuleiro
 * \param pie_types[8] int -> matriz com o numero de peças de cada tipo
 * \return int -> é retornado 1 caso a restrição seja cumprida
 *
 */
int restric4(int height, int width, int pie_types[8])
{
    int i, max_pieces,n_pieces = 0;

    for (i=0;i<8;i++)
    {
        n_pieces = n_pieces + pie_types[i];
    }
    max_pieces = (height * width / 9) / 2;
    if (n_pieces <= max_pieces)
    {
        return 1;
    }else
    {
        printf("-1\n");
        exit(0);
    }

}
