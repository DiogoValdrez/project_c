#ifndef PIECES_HPP
#define PIECES_HPP
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pieces(char id_piece,int id_var,char board[15][24],int coor_height,int coor_width, char sqr[3][3]);
void sqr_board(char board[15][24],int coor_height,int coor_width, char sqr[3][3]);
void del_sqr(char sqr[3][3]);
void ctrl_Z(char board[15][24],int coor_height,int coor_width);
int choose_piece(int pie_types[8]);
int choose_rand_variant(int id_piece);

#endif
