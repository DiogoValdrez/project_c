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

int mult(int value);


int main()
{

    int height, width;
    char board[15][24];
    char sqr[3][3];
    do//talvez fazer uma função disto
    {
        printf("Imput the height and width of the board: \n");
        printf("Both coordenates must be multiples of 3.\n");
        printf("->The height must be between 9 and 15;\n");
        printf("->The width must be between 9 and 24;\n");
        scanf(" %d %d", &height, &width);
    } while (height < 9 || height > 15 || width < 9 || width > 24 || mult(width)==1 || mult(height)==1);

    initBoard(board, height, width);
    drawBoard(board, height, width);
    printf("feito");
    p1(board,height, width, sqr);
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
