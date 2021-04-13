/*Batalha naval
Autores: Diogo Valdrez 99914, Pedro Raposo 100059
Data: 20/04/2021 ??
Descrição : ...
*/
//introdução em ingles?

#include "board.h"
#include "pieces.h"
#include "restric.h"
#include "modo_p1.h"
#include "modo_p2.h"
#include <unistd.h>
#include <stdio.h>

int mult(int value);


int main(int argc, char *argv[])
{
    int option;
    int height = 9,width = 9, modo_game=0, modo_posicion = 1, modo_shot = 1;
    int pie_types[8] = {0,0,0,0,0,0,0,0};
    while((option = getopt(argc, argv, "ht:j:p:d:1:2:3:4:5:6:7:8:")) != -1)
    {
      switch(option){
        case 'h':
            printf("Print a help message\n");
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
            printf("Modo jogo = %d\n", modo_game);
            break;
         case 'p':
            sscanf(optarg, "%d", &modo_posicion);
            printf("Modo posicionamento = %d\n", modo_posicion);
            break;
         case 'd':
            if (modo_game==2)
            {
                sscanf(optarg, "%d", &modo_shot);
                printf("Modo shot = %d\n", modo_shot);
            }else
            {
                printf("Print help message\n");
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
                        //printf("piece 1 = %d", pie_types[0]);
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
            }else
            {
                printf("Print help message\n");
            }
            break;
      }
    }
    printf("Pieces\n");
    int i;
    for (i= 0; i<8;i++)
    {
        printf("Piece %d = %d\n",i+1,pie_types[i]);
    }

    //Resttriction 2 which apllies if modo_posicion = 2, maybe make a
    //Separate function for this
    if (modo_posicion== 2)
    {
        for(i=1;i<8;i++)
        {
            if (pie_types[i] > pie_types[i-1])
            {
                return EXIT_FAILURE;
            }
        }
    }
    char board[15][24];
    char sqr[3][3];
    initBoard(board, height, width);
    p1(board,height, width, sqr, pie_types);
    drawBoard(board, height, width);

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
