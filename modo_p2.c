#include "modo_p2.h"
/** \brief Função que executa o modo de posicionamento 2. Escolhe aleatoriamente o tipo da peça
 *         a colocar das que estão em pie_types e ainda não foram colocadas ou uma matriz vazia.
 *         Escolhe aleatoriamente uma variante e coloca-a na matriz sqr que depois a coloca no tabuleiro.
 *         Verifica se a restrição 1 está a ser cumprida. Caso não esteja testa todas as variantes dessa peça.
 *         Se no final não for possivel colocar a peça repete-se o processo de escolher aleatoriamente uma peça
 *         e o processo é repetido. Repete o processo para todas as matrizes 3x3 do tabuleiro.
 *
 * \param board -> matriz que representa o tabuleiro onde as peças vão ser colocadas
 * \param height -> dimensão da altura do tabuleiro
 * \param width -> dimensão da larura do tabuleiro
 * \param sqr -> matriz 3x3 que representa cada peça
 * \param pie_types -> a matriz pie_types, que representa o número de peças de cada tipo
 */


int p2(char board[15][24],int height,int width, char sqr[3][3], int pie_types[8])
{
    
    //Se a restrição 3 e 4 não forem cumpridas acaba o programa
    restric3(pie_types);
    restric4(height,width,pie_types);  
    int coor_height = 0, coor_width = 0;
    int id_var = 0;
    int rep_8 = 0, rep_1000 = 0;
    int l, i;
    int pie_types_save [8];
    int pie_types_tested[8] = {0,0,0,0,0,0,0,0};
    char id_piece;
    srand((unsigned)time(NULL));

    //Salvaguardar pie_types em pie_types_save
    for (l = 0; l < 8; l++)
    {
        pie_types_save[l] = pie_types[l];
    }

    //Loop Principal da funcão
    do
    {
        initBoard(board, height, width);
        //Repor pie_types ao seu valor inicial
        for (l = 0; l < 8; l++)
        {
            pie_types[l] = pie_types_save[l];
        }       
        //For loop que "varre" todas as matrizes do tabuleiro
        for(coor_height = 0; coor_height < height; coor_height += 3)
        {
            for(coor_width = 0;coor_width < width; coor_width += 3)
            {
                rep_8 = 0;
                ctrl_Z(board,coor_height,coor_width);
                del_sqr(sqr);
                for (l = 0; l < 8; l++)
                {
                    pie_types_tested[l] = 0;
                }

                do
                {                   
                    ctrl_Z(board,coor_height,coor_width);
                    del_sqr(sqr);
                    //Escolher um tipo de peça aleatório
                    do
                    {
                        id_piece = rand()%9 + '0';
                        if (id_piece == '0')
                        {
                            break;
                        }                     
                    }while(pie_types[id_piece - '0'- 1] == 0 || pie_types_tested[id_piece - '0'- 1] != 0);

                    //Escolher uma variante de peça aleatória
                    switch(id_piece)
                    {
                        case '0':
                            id_var =  0;
                            break;
                        case '1':
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
                            id_var = 1;
                            pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                            break;
                        default:
                            return EXIT_FAILURE;

                    }
                    sqr_board(board, coor_height, coor_width, sqr);                    
                    //Caso restrição 1 não esteja cumprida, experimentar todas as variantes da peça
                    if (!(restric01( board, coor_height, coor_width, width)))
                    {

                        switch (id_piece)
                        {
                            case '1':
                                for (id_var = 1; id_var < 10; id_var++)
                                {
                                    ctrl_Z(board,coor_height,coor_width);
                                    del_sqr(sqr);
                                    pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                                    sqr_board(board, coor_height, coor_width, sqr);
                                    if (restric01( board, coor_height, coor_width, width))
                                    {
                                        break;
                                    }
                                }
                                break;
                            case '2':
                                for (id_var = 1; id_var < 13; id_var++)
                                {
                                    ctrl_Z(board,coor_height,coor_width);
                                    del_sqr(sqr);
                                    pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                                    sqr_board(board, coor_height, coor_width, sqr);
                                    if (restric01( board, coor_height, coor_width, width))
                                    {
                                        break;
                                    }
                                }
                                break;
                            case '3':
                                for (id_var = 1; id_var < 7; id_var++)
                                {
                                    ctrl_Z(board,coor_height,coor_width);
                                    del_sqr(sqr);
                                    pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                                    sqr_board(board, coor_height, coor_width, sqr);
                                    if (restric01( board, coor_height, coor_width, width))
                                    {
                                        break;
                                    }
                                }
                                break;
                            case '4':
                                for (id_var = 1; id_var < 5; id_var++)
                                {
                                    ctrl_Z(board,coor_height,coor_width);
                                    del_sqr(sqr);
                                    pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                                    sqr_board(board, coor_height, coor_width, sqr);
                                    if (restric01( board, coor_height, coor_width, width))
                                    {
                                        break;
                                    }
                                }
                                break;
                            case '5':
                                for (id_var = 1; id_var < 5; id_var++)
                                {
                                    ctrl_Z(board,coor_height,coor_width);
                                    del_sqr(sqr);
                                    pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                                    sqr_board(board, coor_height, coor_width, sqr);
                                    if (restric01( board, coor_height, coor_width, width))
                                    {
                                        break;
                                    }
                                }
                                break;
                            case '6':
                                for (id_var = 1; id_var < 5; id_var++)
                                {
                                    ctrl_Z(board,coor_height,coor_width);
                                    del_sqr(sqr);
                                    pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                                    sqr_board(board, coor_height, coor_width, sqr);
                                    if (restric01( board, coor_height, coor_width, width))
                                    {
                                        break;
                                    }
                                }
                                break;
                            case '7':
                                for (id_var = 1; id_var < 3; id_var++)
                                {
                                    ctrl_Z(board,coor_height,coor_width);
                                    del_sqr(sqr);
                                    pieces(id_piece,id_var,board,coor_height,coor_width,sqr);
                                    sqr_board(board, coor_height, coor_width, sqr);
                                    if (restric01( board, coor_height, coor_width, width))
                                    {
                                        break;
                                    }
                                }
                                break;
                            default:
                                break;
                        }
                        
                        if (!(restric01( board, coor_height, coor_width, width)) && rep_8 <8)
                        {
                            rep_8 = rep_8 + 1;
                            pie_types_tested [id_piece - '0'- 1] ++;
                        }
                    }                    
                }while(!(restric01( board, coor_height, coor_width, width)) && rep_8 <8);
                
                //Se a restrição 1 estiver a ser cumprida, tirar essa peça à matriz pie_types
                if(restric01( board, coor_height, coor_width, width) && id_piece != '0')
                {
                    pie_types[id_piece - '0'- 1] --;
                }                
                if (rep_8 == 8)
                {
                    break;
                }
            } 
            if (rep_8 == 8)
            {
                break;
            }
        }
        //Caso tem havido 8 repeticões do processo anterior, voltar ao início do tabuleiro
        if (rep_8==8)
        {
            rep_1000 ++;
            coor_width = 0;
            coor_height = 0;
            initBoard(board, height, width);
        }
        if (rep_1000 == 1000)
        {
            puts("-1");
            exit(0);
        }
    }while(rep_8 == 8 && rep_1000<1000);

    //Repor o valor inicial da matriz pie_types
    for(i= 0; i < 8; i++)
    {
        pie_types[i] = pie_types_save[i];
    }

    return EXIT_SUCCESS;
}

