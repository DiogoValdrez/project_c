#include "modo_d1.h"

/** \brief Função que executa o modo de disparo 1
 *
 * \param height int -> altura do tabuleiro
 * \param width int -> largura do tabuleiro
 * \param pie_types[8] int -> matriz com o numero de peças de cada tipo
 */
int d1(int height ,int width,int pie_types[8])
{
    char shot_board[15][24];
    int remaining_pie[8];
    int height_rand_coord, width_rand_coord;
    int tf, ti, dt, i, j, y, shot;
    int tries = 0, remain = 0;
    char x, character;
    srand((unsigned)time(NULL));

    ti = (unsigned)time(NULL);
    // Loop que preenche a matriz com espaços
    for (i=0;i<height;i++)
    {
        for (j=0;j<width;j++)
        {
            shot_board[i][j] = ' ';
        }
    }
    // Loop que inicializa os valores da matriz onde estão as peças restantes de cada tipo
    for (i=0;i<8;i++)
    {
        remaining_pie[i] = pie_types[i] * (i+1);
    }
    // Loop principal onde o input do utilizador é recebido
    do
    {
        remain = 0;
        tries ++;
        // Loop onde são criadas coordenadas aleatórios, desde que estas correspondam a
        // coordenadas onde não houve disparos até ao momento
        do
        {
            height_rand_coord = rand()%height;
            width_rand_coord = rand()%width;
        }while(shot_board[height_rand_coord][width_rand_coord] != ' ');
        // Transformação das coordenas do programa para coordenadas percetiveis para o utilizador
        x = width_rand_coord + 'A';
        y = height - height_rand_coord;

        printf("%c%d\n", x, y);
        scanf(" %c", &character);

        if (character != '-')
        {
            // Transformação do input do utilizador em coordenadas de computador
            shot = (int)character - 49;
            remaining_pie[shot] -= 1;
        }
        for (i=0;i<8;i++)
        {
            if (remaining_pie[i] != 0)
            {
                remain = 1;
            }
        }
        // Colocação do disparo no tabuleiro a ser imprimido no final
        shot_board[height_rand_coord][width_rand_coord] = character;
    }while(remain && (tries < height*width));
    // Medição de tempo atravez da variação do tempo em segundos
    tf = (unsigned)time(NULL);
    dt = tf - ti;

    printf("Fim de jogo: %d jogadas ", tries);
    printf("em %d segundos.", dt);
    drawBoard(shot_board, height, width);

    return EXIT_SUCCESS;
}
