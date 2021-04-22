/*Batalha naval
Autores: Diogo Valdrez 99914, Pedro Raposo 100059
Descrição : ...
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

int main(int argc, char *argv[])
{
    int option, i;
    int height = 9,width = 9, modo_game = 0, modo_posicion = 1, modo_shot = 1, nothelped = 1, used = 0, pused = 0;
    int pie_types[8] = {0,0,0,0,0,0,0,0};
    char board[15][24], sqr[3][3];

    while((option = getopt(argc, argv, "ht:j:p:d:1:2:3:4:5:6:7:8:")) != -1)
    {
      switch(option){
        case 'h':
            printf("* Print a help message\n");
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

    if((used && modo_game != 2 && nothelped) ||(pused && modo_posicion != 2 && nothelped)){
        printf(" *Print help message\n");
    }

    switch(modo_game)
    {
    case 0:
        initBoard(board, height, width);
        printf("* ================================\n");
        printf("* Modo de Jogo 0\n");
        printf("* ================================\n");
        printf("%dx%d", height, width);
        mj0(board, height, width, sqr, pie_types, modo_posicion);
        drawBoard(board, height, width);
        break;
    case 1:
        initBoard(board, height, width);
        printf("* ================================\n");
        printf("* Modo de Jogo 1\n");
        printf("* Insira as coordenadas de disparo\n");
        printf("* ================================\n");
        printf("%dx%d", height, width);
        mj1(board, height, width, sqr, pie_types, modo_posicion);
        drawBoard(board, height, width);
        break;
    case 2:
        printf("* ==================================================\n");
        printf("* Modo de Jogo 2\n");
        printf("* Modo de disparo %d\n", modo_shot);
        printf("* Crie um tabuleiro com as características indicadas\n");
        printf("* Responda aos disparos do programa\n");
        printf("* ==================================================\n");
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
//Function that checks whether the value is a multiple of 3
int mult(int value)
{
    if(value%3 == 0)
    {
        return 0;
    }else{
        return 1;
    }
}
