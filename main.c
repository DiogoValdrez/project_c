/*Batalha naval
Autores: Diogo Valdrez 99914, Pedro Raposo 100059
Descrição : ...
*/

#include <unistd.h>
#include <stdio.h>
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
    int option;
    int height = 9,width = 9, modo_game = 0, modo_posicion = 1, modo_shot = 1, nothelped = 1;
    int pie_types[8] = {0,0,0,0,0,0,0,0};
    char board[15][24], sqr[3][3];

    while((option = getopt(argc, argv, "ht:j:p:d:1:2:3:4:5:6:7:8:")) != -1)
    {
      switch(option){
        case 'h':
            printf("Print a help message\n");
            nothelped = 0;
            break;
        case 't':
             sscanf(optarg,"%dx%d", &height, &width);
             if (height < 9 || height > 15 || width < 9 || width > 24 || mult(width)==1 || mult(height)==1)
             {
                 height = 9;
                 width = 9;
             }
             printf("Height :%d\n", height);
             printf("Width :%d\n", width);
             break;
        case 'j':
            sscanf(optarg, "%d", &modo_game);
            break;
        case 'p':
            sscanf(optarg, "%d", &modo_posicion);
            break;
        case 'd':
            if (modo_game==2)
            {
                sscanf(optarg, "%d", &modo_shot);
            }else if(nothelped){
                printf("Print help message\n");
                nothelped = 0;
            }
            break;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        if (modo_game == 2 || modo_posicion == 2)
            {
                switch (option)
                {
                    case '1':
                        sscanf(optarg, "%d", &pie_types[0]);
                        break;
                    case '2':
                        sscanf(optarg, "%d", &pie_types[1]);
                        break;
                    case '3':
                        sscanf(optarg, "%d", &pie_types[2]);
                        break;
                    case '4':
                        sscanf(optarg, "%d", &pie_types[3]);
                        break;
                    case '5':
                        sscanf(optarg, "%d", &pie_types[4]);
                        break;
                    case '6':
                        sscanf(optarg, "%d", &pie_types[5]);
                        break;
                    case '7':
                        sscanf(optarg, "%d", &pie_types[6]);
                        break;
                    case '8':
                        sscanf(optarg, "%d", &pie_types[7]);
                        break;
                }
            }else if(modo_posicion == 1 && nothelped){
                printf("Print help message\n");
                nothelped = 0;
            }
        break;
        }
    }

    switch(modo_game)
    {
    case 0:
        initBoard(board, height, width);
        mj0(board, height, width, sqr, pie_types, modo_posicion);
        drawBoard(board, height, width);
        break;
    case 1:
        initBoard(board, height, width);
        mj1(board, height, width, sqr, pie_types, modo_posicion);
        drawBoard(board, height, width);
        break;
    case 2:
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
