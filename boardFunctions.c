// David Leonel Melo - 2021129559

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AUX 9
#define N 10

void freeBoard(char** p, int numRows) //Liberta a matriz
{
    int i;

    for(i=0; i < numRows ; i++)
        free(p[i]);

    free(p);
}

char** createBoard(int numRows, int numCols) //Cria a matriz alocando memória dinamicamente
{
    char **p = NULL;

    p = malloc(sizeof(char*) * numRows);

    if(p == NULL){free(p) ; return NULL;}

    for(int i=0 ; i < numRows; i++)
    {
        p[i] = malloc(sizeof(char) * numCols);
        if(p[i] == NULL)
        {
            freeBoard(p, i-1);
            return NULL;
        }

        for(int j=0; j < numCols; j++)
            p[i][j] = ' ';
    }

    return p;
}


void PrintBoard(char **mat,int board,int player) // Mostra a matriz com a indicação do jogador e tabuleiro
{
    printf("\n\nPLAYER %d MOVES IN BOARD %d\n",player, board+1);

    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[0][1],mat[0][2],mat[0][3],  mat[1][1],mat[1][2],mat[1][3],  mat[2][1],mat[2][2],mat[2][3]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[0][4],mat[0][5],mat[0][6],  mat[1][4],mat[1][5],mat[1][6],  mat[2][4],mat[2][5],mat[2][6]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[0][7],mat[0][8],mat[0][9],  mat[1][7],mat[1][8],mat[1][9],  mat[2][7],mat[2][8],mat[2][9]);
    printf("\n-------|-------|-------");
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[3][1],mat[3][2],mat[3][3],  mat[4][1],mat[4][2],mat[4][3],  mat[5][1],mat[5][2],mat[5][3]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[3][4],mat[3][5],mat[3][6],  mat[4][4],mat[4][5],mat[4][6],  mat[5][4],mat[5][5],mat[5][6]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[3][7],mat[3][8],mat[3][9],  mat[4][7],mat[4][8],mat[4][9],  mat[5][7],mat[5][8],mat[5][9]);
    printf("\n-------|-------|-------");
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[6][1],mat[6][2],mat[6][3],  mat[7][1],mat[7][2],mat[7][3],  mat[8][1],mat[8][2],mat[8][3]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[6][4],mat[6][5],mat[6][6],  mat[7][4],mat[7][5],mat[7][6],  mat[8][4],mat[8][5],mat[8][6]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[6][7],mat[6][8],mat[6][9],  mat[7][7],mat[7][8],mat[7][9],  mat[8][7],mat[8][8],mat[8][9]);
    printf("\n-------|-------|-------");
}

void PrintBoardFinal(char **mat) // Mostra a matriz
{
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[0][1],mat[0][2],mat[0][3],  mat[1][1],mat[1][2],mat[1][3],  mat[2][1],mat[2][2],mat[2][3]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[0][4],mat[0][5],mat[0][6],  mat[1][4],mat[1][5],mat[1][6],  mat[2][4],mat[2][5],mat[2][6]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[0][7],mat[0][8],mat[0][9],  mat[1][7],mat[1][8],mat[1][9],  mat[2][7],mat[2][8],mat[2][9]);
    printf("\n-------|-------|-------");
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[3][1],mat[3][2],mat[3][3],  mat[4][1],mat[4][2],mat[4][3],  mat[5][1],mat[5][2],mat[5][3]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[3][4],mat[3][5],mat[3][6],  mat[4][4],mat[4][5],mat[4][6],  mat[5][4],mat[5][5],mat[5][6]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[3][7],mat[3][8],mat[3][9],  mat[4][7],mat[4][8],mat[4][9],  mat[5][7],mat[5][8],mat[5][9]);
    printf("\n-------|-------|-------");
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[6][1],mat[6][2],mat[6][3],  mat[7][1],mat[7][2],mat[7][3],  mat[8][1],mat[8][2],mat[8][3]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[6][4],mat[6][5],mat[6][6],  mat[7][4],mat[7][5],mat[7][6],  mat[8][4],mat[8][5],mat[8][6]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[6][7],mat[6][8],mat[6][9],  mat[7][7],mat[7][8],mat[7][9],  mat[8][7],mat[8][8],mat[8][9]);
    printf("\n-------|-------|-------");
}


int FullBoard(char **mat,int board) // Verifica se o tabuleiro está cheio
{
    int empty_count = 0;

    for(int i = 1 ; i < N ; i++)
    {
        if(mat[board][i] == ' ')
            empty_count++;
    }

    if(empty_count == 0)
        return 1;
    else
        return 0;
}

int AvailableBoards(char **mat) // Verifica quantos tabuleiros estão disponíveis para jogar
{
    int available_boards = 8;
    int aux_mat[AUX];
    int a = 0;

    for(int i = 0 ; i < 8 ; i++)
    {
        if(mat[i][0] != ' ')
            available_boards --;

        if(mat[i][0] == ' ') {
            aux_mat[a] = i;
            a++;
        }
    }

    for(int j = 0 , aux; j < a ; j++)
    {
        aux = FullBoard(mat,aux_mat[j]);

        if(aux == 1)
            available_boards--;
    }

    return available_boards;
}
