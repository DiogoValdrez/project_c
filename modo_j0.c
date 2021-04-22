#include "modo_j0.h"

/** \brief Função que executa o modo de jogo 0, chamando o modo de posicionamento desejado
 *
 * \param board[15][24] char -> matriz onde está o tabuleiro
 * \param height int -> altura do tabuleiro
 * \param width int -> largura do tabuleiro
 * \param sqr[3][3] char -> matrix 3x3 que ajuda na colocação de cada peça
 * \param pie_types[8] int -> matriz onde estão os numeros de peças de cada tipo
 * \param modo_posicion int -> modo de posicionamento
 */
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
