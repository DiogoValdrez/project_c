#include "modo_p1.h"

/** \brief Função que executa o modo de posicionamento 1. Escolhe aleatoriamente o tipo e variante da peça
 *         a colocar, coloca-a na matriz sqr que depois a coloca no tabuleiro. É verificado se a restrição 1
 *         está a ser cumprida. Caso não esteja repete o processo até 3 vezes, onde finalemente cloca uma peça
 *         do tipo 1. Repete o processo para todas as matrizes 3x3 do tabuleiro
 *
 * \param board -> matriz que representa o tabuleiro onde as peças vão ser colocadas
 * \param height -> dimensão da altura do tabuleiro
 * \param width -> dimensão da larura do tabuleiro
 * \param sqr -> matriz 3x3 que representa cada peça
 * \param pie_types -> a matriz pie_types, que representa o número de peças de cada tipo
 */


int p1(char board[15][24], int height ,int width, char sqr[3][3], int pie_types[8])
{
    int coor_height = 0, coor_width = 0, num_pieces = 0;
    int id_var, rep, i;
    char id_piece;
    srand((unsigned)time(NULL));

    //For loop principal da função, passando assim por todas as matrzies 3x3 do tabuleiro
    for(coor_height = 0; coor_height < height; coor_height += 3)
    {
        for(coor_width = 0;coor_width < width; coor_width += 3)
        {
            //Caso a restrição 2 esteja a ser cumprida
            if(num_pieces < restric2(height, width))
            {
                rep = 0;
                //Do while que tenta colocar a peça aleatoria enquanto a restrição 1 não for
                //cumprida ou seja a 3ª repetição
                do
                {
                    //Garante que não ha nada colocado nos espaços das matrizes que vão ser usados
                    ctrl_Z(board,coor_height,coor_width);
                    del_sqr(sqr);
                    //Escolha aleatória do tipo de peça
                    id_piece = rand()%9 + '0';
                    switch(id_piece)
                    {
                        case '0':
                            id_var =  0;
                            break;
                        case '1':
                            //Escolha aleatória da variante de peça
                            id_var = rand()%9 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case '2':
                            id_var = rand()%12 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case '3':
                            id_var = rand()%6 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case '4':
                            id_var = rand()%4 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case '5':
                            id_var = rand()%4 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case '6':
                            id_var = rand()%4 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case '7':
                            id_var = rand()%2 + 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        case '8':
                            id_var = 0;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        default:
                            return EXIT_FAILURE;

                    }
                    sqr_board(board, coor_height, coor_width, sqr);
                    rep+=1;
                }while(!(restric01(board, coor_height, coor_width, width)) && (rep < 3));
                //Caso tenha atingido a 3ª repetição coloca uma peça do tipo 1, variante 5
                if((rep == 3) && !(restric01(board, coor_height, coor_width, width))){
                    id_piece = '1';
                    id_var = 5;
                    ctrl_Z(board,coor_height,coor_width);
                    del_sqr(sqr);
                    pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                    sqr_board(board, coor_height, coor_width, sqr);
                }
                //Caso o tipo de peça ser diferente duma matriz vazia, adicionar à matriz pie_types 1 elemento
                if(id_piece != '0'){
                    pie_types[(int)id_piece-49] += 1;
                }
                num_pieces+=1;
            }else
            {
                for(i = 0; i < 8; i++)
                {
                    printf(" %d", pie_types[i]);
                }
                printf("\n");
                return EXIT_SUCCESS;
            }
        }
    }
    for(i = 0; i < 8; i++)
    {
        printf(" %d", pie_types[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}
