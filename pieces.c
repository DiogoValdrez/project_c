#include "pieces.h"

/** \brief Função que transforma o tipo de peça e a variante numa peça posta numa matriz 3x3
 *
 * \param id_piece -> o tipo de peça
 * \param id_var -> a variante da peça
 * \param sqr -> matriz 3x3
 */

void pieces(char id_piece,int id_var,char board[15][24],int coor_height,int coor_width,char sqr[3][3])
{
    switch (id_piece)
    {
        case '0':
            break;
        case '1':
            switch (id_var)
            {
                case 1:
                    sqr[0][0] = id_piece;
                    break;
                case 2:
                    sqr[0][1] = id_piece;
                    break;
                case 3:
                    sqr[0][2] = id_piece;
                    break;
                case 4:
                    sqr[1][0] = id_piece;
                    break;
                case 5:
                    sqr[1][1] = id_piece;
                    break;
                case 6:
                    sqr[1][2] = id_piece;
                    break;
                case 7:
                    sqr[2][0] = id_piece;
                    break;
                case 8:
                    sqr[2][1] = id_piece;
                    break;
                case 9:
                    sqr[2][2] = id_piece;
                    break;
                }
            break;
        case '2':
            switch (id_var)
            {
                case 1:
                    sqr[0][0] = id_piece;
                    sqr[0][1] = id_piece;
                    break;
                case 2:
                    sqr[0][1] = id_piece;
                    sqr[0][2] = id_piece;
                    break;
                case 3:
                    sqr[1][0] = id_piece;
                    sqr[1][1] = id_piece;
                    break;
                case 4:
                    sqr[1][1] = id_piece;
                    sqr[1][2] = id_piece;
                    break;
                case 5:
                    sqr[2][0] = id_piece;
                    sqr[2][1] = id_piece;
                    break;
                case 6:
                    sqr[2][1] = id_piece;
                    sqr[2][2] = id_piece;
                    break;
                case 7:
                    sqr[0][0] = id_piece;
                    sqr[1][0] = id_piece;
                    break;
                case 8:
                    sqr[1][0] = id_piece;
                    sqr[2][0] = id_piece;
                    break;
                case 9:
                    sqr[0][1] = id_piece;
                    sqr[1][1] = id_piece;
                    break;
                case 10:
                    sqr[1][1] = id_piece;
                    sqr[2][1] = id_piece;
                    break;
                case 11:
                    sqr[0][2] = id_piece;
                    sqr[1][2] = id_piece;
                    break;
                case 12:
                    sqr[1][2] = id_piece;
                    sqr[2][2] = id_piece;
                    break;

            }
            break;
        case '3':
            switch(id_var)
            {
                case 1:
                    sqr[0][0] = id_piece;
                    sqr[0][1] = id_piece;
                    sqr[0][2] = id_piece;
                    break;
                case 2:
                    sqr[1][0] = id_piece;
                    sqr[1][1] = id_piece;
                    sqr[1][2] = id_piece;
                    break;
                case 3:
                    sqr[2][0] = id_piece;
                    sqr[2][1] = id_piece;
                    sqr[2][2] = id_piece;
                    break;
                case 4:
                    sqr[0][0] = id_piece;
                    sqr[1][0] = id_piece;
                    sqr[2][0] = id_piece;
                    break;
                case 5:
                    sqr[0][1] = id_piece;
                    sqr[1][1] = id_piece;
                    sqr[2][1] = id_piece;
                    break;
                case 6:
                    sqr[0][2] = id_piece;
                    sqr[1][2] = id_piece;
                    sqr[2][2] = id_piece;
                    break;
            }
            break;
        case '4':
            switch(id_var)
            {
                case 1:
                    sqr[0][0] = id_piece;
                    sqr[0][1] = id_piece;
                    sqr[1][0] = id_piece;
                    sqr[1][1] = id_piece;
                    break;
                case 2:
                    sqr[0][1] = id_piece;
                    sqr[0][2] = id_piece;
                    sqr[1][1] = id_piece;
                    sqr[1][2] = id_piece;
                    break;
                case 3:
                    sqr[1][0] = id_piece;
                    sqr[1][1] = id_piece;
                    sqr[2][0] = id_piece;
                    sqr[2][1] = id_piece;
                    break;
                case 4:
                    sqr[1][1] = id_piece;
                    sqr[1][2] = id_piece;
                    sqr[2][1] = id_piece;
                    sqr[2][2] = id_piece;
                    break;
            }
            break;
        case '5':
            switch(id_var)
            {
                case 1:
                    sqr[0][0] = id_piece;
                    sqr[0][1] = id_piece;
                    sqr[0][2] = id_piece;
                    sqr[1][1] = id_piece;
                    sqr[2][1] = id_piece;
                    break;
                case 2:
                    sqr[0][0] = id_piece;
                    sqr[1][0] = id_piece;
                    sqr[2][0] = id_piece;
                    sqr[1][1] = id_piece;
                    sqr[1][2] = id_piece;
                    break;
                case 3:
                    sqr[2][0] = id_piece;
                    sqr[2][1] = id_piece;
                    sqr[2][2] = id_piece;
                    sqr[0][1] = id_piece;
                    sqr[1][1] = id_piece;
                    break;
                case 4:
                    sqr[0][2] = id_piece;
                    sqr[1][2] = id_piece;
                    sqr[2][2] = id_piece;
                    sqr[1][0] = id_piece;
                    sqr[1][1] = id_piece;
                    break;
            }
            break;
        case '6':
            switch(id_var)
            {
                case 1:
                    sqr[0][1] = id_piece;
                    sqr[1][0] = id_piece;
                    sqr[2][0] = id_piece;
                    sqr[2][1] = id_piece;
                    sqr[2][2] = id_piece;
                    sqr[1][2] = id_piece;
                    break;
                case 2:
                    sqr[1][0] = id_piece;
                    sqr[0][1] = id_piece;
                    sqr[0][2] = id_piece;
                    sqr[1][2] = id_piece;
                    sqr[2][2] = id_piece;
                    sqr[2][1] = id_piece;
                    break;
                case 3:
                    sqr[2][1] = id_piece;
                    sqr[1][0] = id_piece;
                    sqr[0][0] = id_piece;
                    sqr[0][1] = id_piece;
                    sqr[0][2] = id_piece;
                    sqr[1][2] = id_piece;
                    break;
                case 4:
                    sqr[1][2] = id_piece;
                    sqr[0][1] = id_piece;
                    sqr[0][0] = id_piece;
                    sqr[1][0] = id_piece;
                    sqr[2][0] = id_piece;
                    sqr[2][1] = id_piece;
                    break;
            }
            break;
        case '7':
            switch(id_var)
            {
                case 1:
                    sqr[0][0] = id_piece;
                    sqr[1][0] = id_piece;
                    sqr[2][0] = id_piece;
                    sqr[0][2] = id_piece;
                    sqr[1][2] = id_piece;
                    sqr[2][2] = id_piece;
                    sqr[1][1] = id_piece;
                    break;
                case 2:
                    sqr[0][0] = id_piece;
                    sqr[0][1] = id_piece;
                    sqr[0][2] = id_piece;
                    sqr[2][0] = id_piece;
                    sqr[2][1] = id_piece;
                    sqr[2][2] = id_piece;
                    sqr[1][1] = id_piece;
                    break;
            }
            break;
        case '8':
            sqr[0][0] = id_piece;
            sqr[0][1] = id_piece;
            sqr[0][2] = id_piece;
            sqr[1][0] = id_piece;
            sqr[1][2] = id_piece;
            sqr[2][0] = id_piece;
            sqr[2][1] = id_piece;
            sqr[2][2] = id_piece;

            break;
        default:
            return;

    }
}
/** \brief Função que coloca a matriz 3x3 que contem a peça
 *
 * \param board -> tabuleiro de jogo
 * \param coor_height -> coordenada da altura do tabuleiro em que queremos colocar a matriz
 * \param coor_width -> coordenada da largura do tabuleiro em que queremos colocar a matriz
 * \param sqr -> matriz 3x3 onde vem a peça
 */
void sqr_board(char board[15][24],int coor_height,int coor_width, char sqr[3][3])
{
    int i, j;
    for( i = 0; i < 3; i++)
    {
        for( j = 0; j < 3; j++)
        {
            if(sqr[i][j] != '\0')
            {
                board[i+coor_height][j+coor_width] = sqr[i][j];
            }
        }
    }
}


/** \brief Funcão que reinicia a matriz 3x3
 *
 * \param sqr -> matriz 3x3
 */
void del_sqr(char sqr[3][3])
{
    int i, j;
    for( i = 0; i < 3; i++)
        {
        for( j = 0; j < 3; j++)
        {
            sqr[i][j] = '\0';
        }
    }
}

/** \brief Funcão que coloca os espaços no tabuleiro onde a matriz vai ser colocada a '-'
 *
 * \param board -> tabuleiro de jogo
 * \param coor_height -> coordenada da altura do tabuleiro em que queremos colocar a matriz
 * \param coor_width -> coordenada da largura do tabuleiro em que queremos colocar a matriz
 */
void ctrl_Z(char board[15][24],int coor_height,int coor_width)
{
    int i, j;
    for( i = coor_height; i < coor_height+3; i++)
    {
        for( j = coor_width; j < coor_width+3; j++)
        {
            board[i][j] = '-';
        }
    }
}






