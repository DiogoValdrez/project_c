#include "modo_j2.h"

/** \brief Função que executa o modo de jogo 2, chamando o modo de disparo desejado
 *
 * \param height int -> altura do tabuleiro
 * \param width int -> largura do tabuleiro
 * \param modo_shot int -> modo de disparo
 * \param pie_types[8] int -> matriz com o numero de peças de cada tipo
 */
int mj2(int height, int width, int modo_shot, int pie_types[8])
{
    if(modo_shot==1){
        d1(height, width, pie_types);
    }else if (modo_shot==2){
        d2(height, width, pie_types);
    }else if (modo_shot==3){
        d3(height, width, pie_types);
    }else{
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
