/*Batalha naval
Autores: Diogo Valdrez 99914, Pedro Raposo 100059
Descrição : Projeto Batalha Naval
            Realizado como projeto intermédio para a UC Programação
*/

#include <unistd.h>
#include <stdio.h>
#include <getopt.h>
#include "board.h"
#include "pieces.h"
#include "restric.h"
#include "modo_p1.h"
#include "modo_p2.h"
#include "modo_j0.h"
#include "modo_j1.h"
#include "modo_j2.h"
#include "modo_d1.h"
#include "modo_d2.h"
#include "modo_d3.h"

int mult(int value);

/** \brief Função main, recebe os argumentos colocados no terminal e executa
 *         o modo de jogo especificado com as defenições especificadas.
 *
 * \param argc int -> número de argumentos colocados pelo utilizador
 * \param argv[] char* -> argumentos recebidos
 */
int main(int argc, char *argv[])
{
    int option, i;
    int height = 9,width = 9, modo_game = 0, modo_posicion = 1, modo_shot = 1, nothelped = 1, used = 0, pused = 0;
    int pie_types[8] = {0,0,0,0,0,0,0,0};
    char board[15][24], sqr[3][3];

    // Loop que processa dos argumentos recebidos e os grava nas suas respetivas variáveis.
    while((option = getopt(argc, argv, "ht:j:p:d:1:2:3:4:5:6:7:8:")) != -1)
    {
      switch(option){
        case 'h':
            printf("* ==========================================================\n");
            printf("* Projeto Batalha Naval\n");
            printf("* Argumentos:\n");
            printf("*     -h               Help message\n");
            printf("*     -t               Dimensões do tabuleiro(AlturaxLargura)\n");
            printf("*     -p               Modo de posicionamento\n");
            printf("*     -d               Modo de disparo\n");
            printf("*     -1               Número de peças do tipo 1\n");
            printf("*     -2               Número de peças do tipo 2\n");
            printf("*     -3               Número de peças do tipo 3\n");
            printf("*     -4               Número de peças do tipo 4\n");
            printf("*     -5               Número de peças do tipo 5\n");
            printf("*     -6               Número de peças do tipo 6\n");
            printf("*     -7               Número de peças do tipo 7\n");
            printf("*     -8               Número de peças do tipo 8\n");
            nothelped = 0;
            break;
        case 't':
             sscanf(optarg,"%dx%d", &height, &width);
             if (height < 9 || height > 15 || width < 9 || width > 24 || mult(width)==1 || mult(height)==1)
             {
                 height = 9;
                 width = 9;
             }
             break;
        case 'j':
            sscanf(optarg, "%d", &modo_game);
            break;
        case 'p':
            sscanf(optarg, "%d", &modo_posicion);
            break;
        case 'd':
            sscanf(optarg, "%d", &modo_shot);
            used = 1;
            break;
        case '1':
            sscanf(optarg, "%d", &pie_types[0]);
            pused = 1;
            break;
        case '2':
            sscanf(optarg, "%d", &pie_types[1]);
            pused = 1;
            break;
        case '3':
            sscanf(optarg, "%d", &pie_types[2]);
            pused = 1;
            break;
        case '4':
            sscanf(optarg, "%d", &pie_types[3]);
            pused = 1;
            break;
        case '5':
            sscanf(optarg, "%d", &pie_types[4]);
            pused = 1;
            break;
        case '6':
            sscanf(optarg, "%d", &pie_types[5]);
            pused = 1;
            break;
        case '7':
            sscanf(optarg, "%d", &pie_types[6]);
            pused = 1;
            break;
        case '8':
            sscanf(optarg, "%d", &pie_types[7]);
            pused = 1;
            break;
        }
    }

    // Condição que permite a escrita da help message nos casos especificados no enunciado
    if((used && modo_game != 2 && nothelped) ||(pused && modo_posicion != 2 && nothelped)){
            printf("* ==========================================================\n");
            printf("* Projeto Batalha Naval\n");
            printf("* Argumentos:\n");
            printf("*     -h               Help message\n");
            printf("*     -t               Dimensões do tabuleiro(AlturaxLargura)\n");
            printf("*     -p               Modo de posicionamento\n");
            printf("*     -d               Modo de disparo\n");
            printf("*     -1               Número de peças do tipo 1\n");
            printf("*     -2               Número de peças do tipo 2\n");
            printf("*     -3               Número de peças do tipo 3\n");
            printf("*     -4               Número de peças do tipo 4\n");
            printf("*     -5               Número de peças do tipo 5\n");
            printf("*     -6               Número de peças do tipo 6\n");
            printf("*     -7               Número de peças do tipo 7\n");
            printf("*     -8               Número de peças do tipo 8\n");
    }

    // Seleção do modo de jogo
    switch(modo_game)
    {
    case 0:
        initBoard(board, height, width);
        printf("* ==========================================================\n");
        printf("* Modo de Jogo 0\n");
        printf("* Modo de posicionamento %d\n", modo_posicion);
        printf("* ==========================================================\n");
        printf("%dx%d", height, width);
        mj0(board, height, width, sqr, pie_types, modo_posicion);
        drawBoard(board, height, width);
        break;
    case 1:
        initBoard(board, height, width);
        printf("* ==========================================================\n");
        printf("* Modo de Jogo 1\n");
        printf("* Modo de posicionamento %d\n", modo_posicion);
        printf("* Insira as coordenadas de disparo\n");
        printf("* ==========================================================\n");
        printf("%dx%d", height, width);
        mj1(board, height, width, sqr, pie_types, modo_posicion);
        drawBoard(board, height, width);
        break;
    case 2:
        printf("* ==========================================================\n");
        printf("* Modo de Jogo 2\n");
        printf("* Modo de disparo %d\n", modo_shot);
        printf("* Crie um tabuleiro com as características indicadas\n");
        printf("* Responda aos disparos do programa\n");
        printf("* ==========================================================\n");
        printf("%dx%d", height, width);
        for(i = 0; i < 8; i++){
            printf(" %d", pie_types[i]);
        }
        printf("\n");
        mj2(height, width, modo_shot, pie_types);
        break;
    }
    return EXIT_SUCCESS;
}
/** \brief Função de ajuda que verifica a multipliidade por 3 de um valor
 *
 * \param value int -> valor a ser verificado
 * \return int -> é retornado 1 se o valor não for multiplo
 *
 */
int mult(int value)
{
    if(value%3 == 0)
    {
        return 0;
    }else{
        return 1;
    }
}
