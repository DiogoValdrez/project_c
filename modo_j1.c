#include "modo_j1.h"

/** \brief Função que executa o modo de jogo 1, chamando o modo de posicionamento desejado
 *         e processando o imput do utilizador
 *
 * \param board[15][24] char -> matriz onde está o tabuleiro
 * \param height int -> altura do tabuleiro
 * \param width int -> largura do tabuleiro
 * \param sqr[3][3] char -> matrix 3x3 que ajuda na colocação de cada peça
 * \param pie_types[8] int -> matriz onde estão os numeros de peças de cada tipo
 * \param modo_posicion int -> modo de posicionamento
 */
int mj1(char board[15][24], int height, int width, char sqr[3][3], int pie_types[8], int modo_posicion)
{
    char character;
    int y, x, i, ti, tf, dt;
    int num_blocks = 0, tries = 0, shooted = 0;

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

    // Loop principal onde é recebido o imput do jogado e verificado
    while(shooted < num_blocks){
        scanf(" %c%d", &character, &y);
        x = (int)character - 65;
        printf("%c\n", board[height-y][x]);
        if(board[height-y][x] != '-'){
            shooted ++;
        }
        tries ++;
    }
    // Método utilizado em varias partes do codigo para medir o tempo
    tf = (unsigned)time(NULL);
    dt = tf - ti;

    printf("Fim de jogo: %d jogadas em ", tries);
    printf("%d segundos", dt);
    return EXIT_SUCCESS;
}
